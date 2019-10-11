#include "EcmaScriptPlatform.hpp"
#include "scripting/utils/EcmaScriptUtils.hpp"

#include <libplatform/libplatform.h>

#include "spdlog/spdlog.h"

#include <fmt/format.h>

#include <memory>
#include <string>

namespace inexor {
namespace scripting {

	EcmaScriptPlatform::EcmaScriptPlatform(
		LoggingModulePtr logging_module,
		EntitySystemModulePtr entity_system_module,
		UtilModulePtr util_module
	)
	{
		this->logging_module = logging_module;
		this->entity_system_module = entity_system_module;
		this->util_module = util_module;
	}

	EcmaScriptPlatform::~EcmaScriptPlatform()
	{
	}

	void EcmaScriptPlatform::init()
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

		logging_module->init();
		entity_system_module->init();
		util_module->init();
	}

	void EcmaScriptPlatform::shutdown()
	{
		util_module->shutdown();
		entity_system_module->shutdown();
		logging_module->shutdown();

		// Tear down V8.
		v8::V8::Dispose();
		v8::V8::ShutdownPlatform();
	}

	/// Returns the platform.
	v8::Platform* EcmaScriptPlatform::get_platform()
	{
		return platform.get();
	}

	void EcmaScriptPlatform::require_module(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		v8::Isolate* isolate = args.GetIsolate();
		v8::Local<v8::Context> context = isolate->GetCurrentContext();
		v8::Local<v8::Object> global = context->Global();

		// Resolve "this" from an wrapped external
		v8::Local<v8::External> ext_platform = args.Data().As<v8::External>();
		EcmaScriptPlatform* self = static_cast<EcmaScriptPlatform*>(ext_platform->Value());

		v8::String::Utf8Value str(isolate, args[0]);
		std::string module_name = c_str(str);
		spdlog::info("Loading module {}", module_name);
		if (module_name == "logging")
		{
			self->logging_module->create(isolate, context, global);
		} else if (module_name == "entity-system")
		{
			self->entity_system_module->create(isolate, context, global);
		} else if (module_name == "util")
		{
			self->util_module->create(isolate, context, global);
		}
	}

	std::string EcmaScriptPlatform::report_exception(v8::Isolate* isolate, v8::TryCatch* try_catch)
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

}
}
