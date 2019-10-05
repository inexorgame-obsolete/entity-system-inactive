#include "LoggingModule.hpp"
#include "EcmaScriptUtils.hpp"

#include "spdlog/spdlog.h"

namespace inexor {
namespace scripting {

	LoggingModule::LoggingModule(
		LogManagerPtr log_manager
	)
	{
		this->log_manager = log_manager;
	}

	LoggingModule::~LoggingModule()
	{
	}

	void LoggingModule::init()
	{
	}

	void LoggingModule::shutdown()
	{
	}

	void LoggingModule::create(v8::Isolate* isolate, v8::Local<v8::Context> context, v8::Local<v8::Object> parent)
	{
		// Create module object
		v8::Local<v8::Object> logging_module = v8::Local<v8::Object>::New(isolate, v8::Object::New(isolate));
		// Create module function callbacks
		//  TODO: create function for getting a logger with these methods: logger.debug(), logger.info(), logger.warning() and logger.error()
		// Create sub module(s)
		//  TODO: add log manager
		// Set module object in parent module object
		parent->Set(context, v8::String::NewFromUtf8(isolate, "logging"), logging_module);

	}

}
}
