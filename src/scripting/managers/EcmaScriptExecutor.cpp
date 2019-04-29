#include "EcmaScriptExecutor.hpp"

#include <v8/v8.h>
#include <v8/libplatform/libplatform.h>

#include "spdlog/spdlog.h"

#include <memory>
#include <string>
#include <fstream>
#include <streambuf>

namespace inexor {
namespace scripting {

	EcmaScriptExecutor::EcmaScriptExecutor()
	{
	}

	EcmaScriptExecutor::~EcmaScriptExecutor()
	{
	}

	void EcmaScriptExecutor::init()
	{
		std::string pwd = "";

		// Initialize V8.

		// v8::V8::InitializeICUDefaultLocation(pwd.c_str());

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
	}

	void EcmaScriptExecutor::shutdown()
	{
		// Tear down V8.
		v8::V8::Dispose();
		v8::V8::ShutdownPlatform();
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
			v8::Isolate::Scope isolate_scope(isolate);
			// Create a stack-allocated handle scope.
			v8::HandleScope handle_scope(isolate);

			/// Context
			///
			/// To allow separate JavaScript applications to run in the same
			/// isolate a context must be specified for each one. This is to
			/// avoid them interfering with each other, for example by changing
			/// the builtin objects provided.
			v8::Local<v8::Context> context = v8::Context::New(isolate);

			// Enter the context for compiling and running the hello world script.
			v8::Context::Scope context_scope(context);
			{
				// Create a string containing the JavaScript source code.
				// v8::Local<v8::String> source = v8::String::NewFromUtf8(isolate, "'Hello' + ', World!'", v8::NewStringType::kNormal).ToLocalChecked();
				v8::Local<v8::String> source = v8::String::NewFromUtf8(isolate, load_file(path).c_str(), v8::NewStringType::kNormal).ToLocalChecked();

				// Compile the source code.
				v8::Local<v8::Script> script = v8::Script::Compile(context, source).ToLocalChecked();

				// Run the script to get the result.
				v8::Local<v8::Value> result = script->Run(context).ToLocalChecked();

				// Convert the result to an UTF8 string and print it.
				v8::String::Utf8Value utf8(isolate, result);
				spdlog::info("{}", *utf8);

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
