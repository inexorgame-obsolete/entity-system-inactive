#include "EcmaScriptExecutor.hpp"

#include <v8/v8.h>
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
		EcmaScriptLoggingModuleInitializerPtr logging_module_initializer
	)
	{
		this->logging_module_initializer = logging_module_initializer;
	}

	EcmaScriptExecutor::~EcmaScriptExecutor()
	{
	}

	void EcmaScriptExecutor::init()
	{
		// Initialize V8.

		// Our library has no i18n support!
		// v8::V8::InitializeICUDefaultLocation(pwd.c_str());

		// Our static v8 library does not yet have support for builtins!
		//
		// But if we are going to integrate the builtins, we should load the
		// "external startup data" from within our binary and load the data
		// using v8::SetNativesDataBlob().
		//
		//
		// You can compile V8 with external startup data ("snapshot") or without.
		// If you compiled with snapshot data, call V8::InitializeExternalStartupData
		// as shown in the Hello World example code. You don't call
		// v8::SetNativesDataBlob directly.
		//
		// Otherwise, the solution is to compile without snapshot data. Then,
		// you don't need to call either of the aforementioned functions at all.
		// Here's one answer on how to configure this in your build process.
		// Note, using snapshot data decreases process start-up time.
		// v8::V8::InitializeExternalStartupData(pwd.c_str());

		platform = v8::platform::NewDefaultPlatform();
		v8::V8::InitializePlatform(platform.get());
		v8::V8::Initialize();

		logging_module_initializer->init();
	}

	void EcmaScriptExecutor::shutdown()
	{
		logging_module_initializer->shutdown();

		// Tear down V8.
		v8::V8::Dispose();
		v8::V8::ShutdownPlatform();
	}


	// Extracts a C string from a V8 Utf8Value.
	const char* c_str(const v8::String::Utf8Value& value)
	{
		return *value ? *value : "<string conversion failed>";
	}

	std::string ReportException(v8::Isolate* isolate, v8::TryCatch* try_catch)
	{
		std::string exception_message = "";
		v8::HandleScope handle_scope(isolate);
		v8::String::Utf8Value exception(isolate, try_catch->Exception());
		const char* exception_string = c_str(exception);
		v8::Local<v8::Message> message = try_catch->Message();
		if (message.IsEmpty()) {
			// V8 didn't provide any extra information about this error; just
			// print the exception.
			exception_message += fmt::format("{}\n", exception_string);
		} else {
			// Print (filename):(line number): (message).
			v8::String::Utf8Value filename(isolate, message->GetScriptOrigin().ResourceName());
			v8::Local<v8::Context> context(isolate->GetCurrentContext());
			int linenum = message->GetLineNumber(context).FromJust();
			exception_message += fmt::format("{}:{}: {}\n", c_str(filename), linenum, exception_string);
			// Print line of source code.
			v8::String::Utf8Value sourceline(isolate, message->GetSourceLine(context).ToLocalChecked());
			exception_message += fmt::format("{}\n", c_str(sourceline));
			// Print wavy underline (GetUnderline is deprecated).
//			int start = message->GetStartColumn(context).FromJust();
//			for (int i = 0; i < start; i++)
//			{
//				fprintf(stderr, " ");
//			}
//			int end = message->GetEndColumn(context).FromJust();
//			for (int i = start; i < end; i++)
//			{
//				fprintf(stderr, "^");
//			}
//			fprintf(stderr, "\n");
			v8::Local<v8::Value> stack_trace_string;
			if (try_catch->StackTrace(context).ToLocal(&stack_trace_string)
				&& stack_trace_string->IsString()
				&& v8::Local<v8::String>::Cast(stack_trace_string)->Length() > 0
			)
			{
				v8::String::Utf8Value stack_trace(isolate, stack_trace_string);
				exception_message += fmt::format("{}\n", c_str(stack_trace));
			}
		}
		return exception_message;
	}

	void require_module(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		v8::Isolate* isolate = args.GetIsolate();

		// Resolve "this"
		v8::Local<v8::External> _self = args.Data().As<v8::External>();
		EcmaScriptExecutor* self = static_cast<EcmaScriptExecutor*>(_self->Value());

		v8::String::Utf8Value str(isolate, args[0]);
		std::string module_name = c_str(str);
		spdlog::info("Loading module {}", module_name);
		if (module_name == "logging")
		{
			self->logging_module_initializer->initialize_module(isolate);
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


			v8::Local<v8::External> self = v8::External::New(isolate, (void *) this);
			v8::Local<v8::FunctionTemplate> _require_module = v8::FunctionTemplate::New(isolate, require_module, self.As<v8::Value>());

			// Create a template for the global object and set the
			// built-in global functions.
			// The object template with all functions has to be created before
			// the context is
			v8::Local<v8::ObjectTemplate> global = v8::ObjectTemplate::New(isolate);
			// "require" is the only what we provide in the global object by default.
			// Everything else goes to the module initializers
			global->Set(v8::String::NewFromUtf8(isolate, "require"), _require_module);

			// Context
			//
			// To allow separate JavaScript applications to run in the same
			// isolate a context must be specified for each one. This is to
			// avoid them interfering with each other, for example by changing
			// the builtin objects provided.
			v8::Local<v8::Context> context = v8::Context::New(isolate, NULL, global);

//			global->Set(v8::String::NewFromUtf8(isolate, "_executor"), v8::External::New(isolate, this));
//			context->Global()->Set(v8::String::New("foo"),v8::FunctionTemplate::New(
//			    [](const v8::Arguments  &args) -> v8::Handle<v8::Value>{
//			         reinterpret_cast<Foo*>(reinterpret_cast<v8::External*>(*(args.This()->Get(v8::String::New("engine"))))->Value())->foo();
//			         return v8::Undefined();
//			})->GetFunction());

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
						spdlog::error("Failed to execute script '{}'::\n{}", path, ReportException(isolate, &try_catch));
					}

				} else {
					spdlog::error("Failed to compile script '{}':\n{}", path, ReportException(isolate, &try_catch));
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
