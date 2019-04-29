#include "EcmaScriptLoggingModuleInitializer.hpp"

#include "v8/v8.h"
// #include <v8/libplatform/libplatform.h>

#include "spdlog/spdlog.h"

#include <memory>
#include <string>

namespace inexor {
namespace scripting {

	EcmaScriptLoggingModuleInitializer::EcmaScriptLoggingModuleInitializer(
		LogManagerPtr log_manager
	)
	{
		this->log_manager = log_manager;
	}

	EcmaScriptLoggingModuleInitializer::~EcmaScriptLoggingModuleInitializer()
	{
	}

	void EcmaScriptLoggingModuleInitializer::init()
	{
	}

	void EcmaScriptLoggingModuleInitializer::shutdown()
	{
	}

	// Extracts a C string from a V8 Utf8Value.
	const char* log_c_str(const v8::String::Utf8Value& value)
	{
		return *value ? *value : "<string conversion failed>";
	}

	// TODO: create global object logger with these methods: logger.debug(), logger.info(), logger.warning() and logger.error()
	void log_info(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		v8::String::Utf8Value str(args.GetIsolate(), args[0]);
		spdlog::info("{}", log_c_str(str));
	}

	void EcmaScriptLoggingModuleInitializer::initialize_module(v8::Isolate* isolate)
	{
		v8::Local<v8::Context> context = isolate->GetCurrentContext();
		v8::Local<v8::Object> global = context->Global();
		v8::Local<v8::FunctionTemplate> _log_info = v8::FunctionTemplate::New(isolate, log_info);
		v8::Local<v8::Function> function = _log_info->GetFunction(context).ToLocalChecked();
		// v8::Local<v8::> __log_info =
		global->Set(context, v8::String::NewFromUtf8(isolate, "log"), function);
		// global->Set(v8::String::NewFromUtf8(isolate, "log"), );
		// TODO: add log manager
	}

}
}
