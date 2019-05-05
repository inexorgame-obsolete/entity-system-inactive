#include "EcmaScriptInterpreter.hpp"
#include "scripting/managers/EcmaScriptPlatform.hpp"

#include <v8/libplatform/libplatform.h>

#include "spdlog/spdlog.h"

namespace inexor {
namespace scripting {

	EcmaScriptInterpreter::EcmaScriptInterpreter(
		std::string name,
		EcmaScriptPlatformPtr ecma_script_platform
	)
	{
		this->name = name;
		this->ecma_script_platform = ecma_script_platform;
//		this->isolate = nullptr;
		this->initialized = false;
		this->running = false;
	}

	EcmaScriptInterpreter::~EcmaScriptInterpreter()
	{
	}

	void EcmaScriptInterpreter::queue_command(std::string command)
	{
		spdlog::info("EcmaScriptInterpreter [{}] queue_command: {}", name, command);
		command_queue.push_back(command);
	}

	void EcmaScriptInterpreter::exit()
	{
		running = false;
	}

	bool EcmaScriptInterpreter::is_initialized()
	{
		return initialized;
	}

	bool EcmaScriptInterpreter::is_running()
	{
		return running;
	}

	// Thread local
	void EcmaScriptInterpreter::run_context()
	{
		spdlog::info("EcmaScriptInterpreter [{}] init_context", name);
		/// Isolate
		///
		/// An Isolate is an independant copy of the V8 runtime which
		/// includes its own heap. Two different Isolates can run in
		/// parallel and can be seen as entierly different sandboxed
		/// instances of a V8 runtime.
		v8::Isolate::CreateParams create_params;
		create_params.array_buffer_allocator = v8::ArrayBuffer::Allocator::NewDefaultAllocator();
		v8::Isolate* isolate = v8::Isolate::New(create_params);

		{
			// Create the isolate scope.
			v8::Isolate::Scope isolate_scope(isolate);

			// Create a stack-allocated handle scope.
			v8::HandleScope handle_scope(isolate);

			// Create a handle to the ecma script platform. We need it in "require".
			v8::Local<v8::External> ext_platform = v8::External::New(isolate, (void *) ecma_script_platform.get());

			// Create a template for the global object and set the
			// built-in global functions.
			// The object template with all functions has to be created before
			// the context is
			v8::Local<v8::ObjectTemplate> global = v8::ObjectTemplate::New(isolate);

			// Actually, "require" is the only what we provide in the global
			// object by default. Everything else is provided by the modules
			// itself.
			global->Set(v8::String::NewFromUtf8(isolate, "require"), v8::FunctionTemplate::New(isolate, EcmaScriptPlatform::require_module, ext_platform.As<v8::Value>()));

			// Context
			//
			// To allow separate JavaScript applications to run in the same
			// isolate a context must be specified for each one. This is to
			// avoid them interfering with each other, for example by changing
			// the builtin objects provided.
			v8::Local<v8::Context> context = v8::Context::New(isolate, NULL, global);

			// Now we are ready to receive commands
			initialized = true;
			spdlog::info("EcmaScriptInterpreter [{}] initialized", name);

			spdlog::info("EcmaScriptInterpreter [{}] run_context", name);
			running = true;
			while (running)
			{
				while (running && !command_queue.empty())
				{
					std::string command = command_queue.front();
					command_queue.pop_front();
					// v8::HandleScope handle_scope(context->GetIsolate());
					v8::Context::Scope context_scope(context);
					execute(isolate, command);
					// Process messages
					while (v8::platform::PumpMessageLoop(ecma_script_platform->get_platform(), isolate)) continue;
				}
				std::this_thread::sleep_for(std::chrono::milliseconds(50));
			}
			// Process remaining messages
			while (v8::platform::PumpMessageLoop(ecma_script_platform->get_platform(), isolate)) continue;

		}

		spdlog::info("EcmaScriptInterpreter [{}] dispose isolate", name);

		// Dispose the isolate
		isolate->Dispose();
		initialized = false;

	}

	// Thread local
	void EcmaScriptInterpreter::execute(v8::Isolate* isolate, std::string command)
	{
		spdlog::info("EcmaScriptInterpreter [{}] do_execute({})", name, command);

		//
		v8::Local<v8::Context> context = isolate->GetCurrentContext();

		v8::HandleScope handle_scope(isolate);

		v8::TryCatch try_catch(isolate);

		// Enter the context for compiling and running the hello world script.
		v8::Context::Scope context_scope(context);
		// v8::Local<v8::Context> context(isolate->GetCurrentContext());

		v8::Local<v8::String> source = v8::String::NewFromUtf8(isolate, command.c_str(), v8::NewStringType::kNormal).ToLocalChecked();

		// Compile the source code.
		v8::MaybeLocal<v8::Script> o_script = v8::Script::Compile(context, source);
		if (!o_script.IsEmpty())
		{
			v8::Local<v8::Script> script = o_script.ToLocalChecked();
			// Run the script to get the result.
			v8::MaybeLocal<v8::Value> o_result = script->Run(context);
			if (!o_result.IsEmpty())
			{
				// Convert the result to an UTF8 string and print it.
				v8::String::Utf8Value utf8(isolate, o_result.ToLocalChecked());
				spdlog::info("EcmaScriptInterpreter [{}] Result: {}", name, *utf8);
			} else {
				spdlog::error("Failed to execute command '{}'::\n{}", command, EcmaScriptPlatform::report_exception(isolate, &try_catch));
			}
		} else {
			spdlog::error("Failed to compile command '{}':\n{}", command, EcmaScriptPlatform::report_exception(isolate, &try_catch));
		}
	}

}
}
