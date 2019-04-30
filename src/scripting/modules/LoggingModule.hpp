#pragma once

#include "logging/managers/LogManager.hpp"

#include "v8/v8.h"
#include "v8/v8-platform.h"

#include <string>

namespace inexor {
namespace scripting {

	using LogManagerPtr = std::shared_ptr<inexor::logging::LogManager>;

	/// @class LoggingModule
    /// @brief Module for accessing the inexor logging from ECMA-Script.
	class LoggingModule
	{
		public:

			/// Constructor.
			LoggingModule(
				LogManagerPtr log_manager
			);

			/// Destructor.
			~LoggingModule();

			/// Initialization of the LoggingModule.
			void init();

			/// Shuts down the LoggingModule.
			void shutdown();

			/// Creates the EntitySystemModule.
			void create(v8::Isolate* isolate, v8::Local<v8::Context> context, v8::Local<v8::Object> parent);

		private:

			/// The log manager.
			LogManagerPtr log_manager;

	};

}
}
