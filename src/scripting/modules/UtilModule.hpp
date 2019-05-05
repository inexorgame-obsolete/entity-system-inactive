#pragma once

#include "logging/managers/LogManager.hpp"

#include "v8.h"
#include "v8-platform.h"

namespace inexor {
namespace scripting {

	using LogManagerPtr = std::shared_ptr<inexor::logging::LogManager>;

	/// @class UtilModule
    /// @brief Module for utility functions.
	class UtilModule
	{
		public:

			/// Constructor.
			UtilModule();

			/// Destructor.
			~UtilModule();

			/// Initialization of the UtilModule.
			void init();

			/// Shuts down the UtilModule.
			void shutdown();

			/// Creates the EntitySystemModule.
			void create(v8::Isolate* isolate, v8::Local<v8::Context> context, v8::Local<v8::Object> parent);

		private:

			/// Simple logging to spdlog::info()
			static void log(const v8::FunctionCallbackInfo<v8::Value>& args);

			/// Sleep for millis
			static void sleep(const v8::FunctionCallbackInfo<v8::Value>& args);

	};

}
}
