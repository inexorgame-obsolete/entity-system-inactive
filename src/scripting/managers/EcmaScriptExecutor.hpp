#pragma once

#include "scripting/modules/LoggingModule.hpp"
#include "scripting/modules/EntitySystemModule.hpp"
#include "scripting/modules/UtilModule.hpp"

#include "v8/v8.h"

#include <string>

namespace inexor {
namespace scripting {

	using LoggingModulePtr = std::shared_ptr<LoggingModule>;
	using EntitySystemModulePtr = std::shared_ptr<EntitySystemModule>;
	using UtilModulePtr = std::shared_ptr<UtilModule>;

	/// @class EcmaScriptExecutor
    /// @brief Service for executing ECMA scripts.
	class EcmaScriptExecutor
		: public std::enable_shared_from_this<EcmaScriptExecutor>
	{
		public:

			/// Constructor.
			EcmaScriptExecutor(
				LoggingModulePtr logging_module,
				EntitySystemModulePtr entity_system_module,
				UtilModulePtr util_module
			);

			/// Destructor.
			~EcmaScriptExecutor();

			/// Initialization of the EcmaScriptExecutor.
			void init();

			/// Shuts down the EcmaScriptExecutor.
			void shutdown();

			/// Executes the given ECMA script once.
			/// @param path The path to the script
			/// @param detached If true, the script is executed in it's own thread.
			void execute_once(std::string path, bool detached);

			static void require_module(const v8::FunctionCallbackInfo<v8::Value>& args);

		private:

			/// Executes the given ECMA script.
			void execute(std::string path);

			/// Loads the file into a string.
			std::string load_file(std::string path);

			/// The v8 platform.
			std::unique_ptr<v8::Platform> platform;

			/// The logging module.
			LoggingModulePtr logging_module;

			/// The entity system module.
			EntitySystemModulePtr entity_system_module;

			/// The util module.
			UtilModulePtr util_module;

	};

}
}
