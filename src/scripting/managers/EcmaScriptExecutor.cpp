#include "EcmaScriptExecutor.hpp"
#include "scripting/modules/EcmaScriptUtils.hpp"

#include <v8/libplatform/libplatform.h>

#include "spdlog/spdlog.h"

#include <fmt/format.h>

#include <memory>
#include <string>
#include <fstream>
#include <streambuf>

namespace inexor {
namespace scripting {

	EcmaScriptExecutor::EcmaScriptExecutor(
		EcmaScriptPlatformPtr ecma_script_platform
	)
	{
		this->ecma_script_platform = ecma_script_platform;
	}

	EcmaScriptExecutor::~EcmaScriptExecutor()
	{
	}

	void EcmaScriptExecutor::init()
	{
	}

	void EcmaScriptExecutor::shutdown()
	{
	}

	void EcmaScriptExecutor::execute_once(std::string path, bool detached)
	{
		if (!detached)
		{
			execute(path);
		} else {
			std::thread ecma_script_thread([this, path](){
				this->execute(path);
			});
			ecma_script_thread.detach();
		}
	}

	void EcmaScriptExecutor::execute(std::string path)
	{
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

			// Create a handle to the EcmaScriptPlatform. We need it in "require".
			// v8::Local<v8::External> self = v8::External::New(isolate, (void *) this);
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

			// Enter the context for compiling and running the hello world script.
			v8::Context::Scope context_scope(context);
			{
				// Create a string containing the JavaScript source code.
				// v8::Local<v8::String> source = v8::String::NewFromUtf8(isolate, "'Hello' + ', World!'", v8::NewStringType::kNormal).ToLocalChecked();
				v8::Local<v8::String> source = v8::String::NewFromUtf8(isolate, load_file(path).c_str(), v8::NewStringType::kNormal).ToLocalChecked();

				// Compile the source code.
				v8::TryCatch try_catch(isolate);
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
						spdlog::info("Result: {}", *utf8);
					} else {
						spdlog::error("Failed to execute script '{}'::\n{}", path, EcmaScriptPlatform::report_exception(isolate, &try_catch));
					}
				} else {
					spdlog::error("Failed to compile script '{}':\n{}", path, EcmaScriptPlatform::report_exception(isolate, &try_catch));
				}
			}
		}

		// Dispose the isolate
		isolate->Dispose();
	}

	std::string EcmaScriptExecutor::load_file(std::string path)
	{
		std::ifstream t(path);
		std::string str((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
		return str;
	}

}
}
