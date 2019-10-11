#include "UtilModule.hpp"
#include "scripting/utils/EcmaScriptUtils.hpp"

#include "spdlog/spdlog.h"

namespace inexor {
namespace scripting {

	UtilModule::UtilModule()
	{
	}

	UtilModule::~UtilModule()
	{
	}

	void UtilModule::init()
	{
	}

	void UtilModule::shutdown()
	{
	}

	void UtilModule::log(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		v8::String::Utf8Value str(args.GetIsolate(), args[0]);
		spdlog::info("{}", c_str(str));
	}

	void UtilModule::sleep(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		v8::Isolate* isolate = args.GetIsolate();
		if (args.Length() > 0)
		{
			int duration = args[0]->IntegerValue(isolate->GetCurrentContext()).ToChecked();
			std::this_thread::sleep_for(std::chrono::milliseconds(duration));
		}
	}

	void UtilModule::create(v8::Isolate* isolate, v8::Local<v8::Context> context, v8::Local<v8::Object> parent)
	{
		// Set function callbacks in parent module object
		parent->Set(context, v8::String::NewFromUtf8(isolate, "log"), v8::Function::New(context, UtilModule::log).ToLocalChecked());
		parent->Set(context, v8::String::NewFromUtf8(isolate, "sleep"), v8::Function::New(context, UtilModule::sleep).ToLocalChecked());
	}

}
}
