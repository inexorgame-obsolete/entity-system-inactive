#pragma once

#include "logging/managers/LogManager.hpp"

#include "v8/v8-platform.h"

#include <string>

namespace inexor {
namespace scripting {

	using LogManagerPtr = std::shared_ptr<inexor::logging::LogManager>;

	/// @class EcmaScriptLoggingModuleInitializer
    /// @brief Service for executing ECMA scripts.
	class EcmaScriptLoggingModuleInitializer
	{
		public:

			/// Constructor.
			EcmaScriptLoggingModuleInitializer(
				LogManagerPtr log_manager
			);

			/// Destructor.
			~EcmaScriptLoggingModuleInitializer();

			/// Initialization of the EcmaScriptLoggingModuleInitializer.
			void init();

			/// Shuts down the EcmaScriptLoggingModuleInitializer.
			void shutdown();

			/// Initializes the module.
			void initialize_module(v8::Isolate* isolate);

		private:

			/// The log manager.
			LogManagerPtr log_manager;

	};

}
}
