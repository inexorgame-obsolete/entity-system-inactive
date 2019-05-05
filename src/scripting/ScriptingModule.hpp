#pragma once

#include "scripting/managers/EcmaScriptPlatform.hpp"
#include "scripting/managers/ScriptExecutor.hpp"
#include "scripting/managers/EcmaScriptInterpreterManager.hpp"

namespace inexor {
namespace scripting {

	using EcmaScriptPlatformPtr = std::shared_ptr<EcmaScriptPlatform>;
	using ScriptExecutorPtr = std::shared_ptr<ScriptExecutor>;
	using EcmaScriptInterpreterManagerPtr = std::shared_ptr<EcmaScriptInterpreterManager>;

    /// @class ScriptingModule
    /// @brief This module provides the integration of the script engines.
	class ScriptingModule
	{
		public:

			/// @brief Constructs the scripting module.
            /// @note The dependencies of this class will be injected automatically.
            /// @param ecma_script_platform The EcmaScript platform.
            /// @param script_executor Service for executing scripts.
            /// @param ecma_script_interpreter_manager Manages the ecma script interpreters.
			ScriptingModule(
				EcmaScriptPlatformPtr ecma_script_platform,
				ScriptExecutorPtr script_executor,
				EcmaScriptInterpreterManagerPtr ecma_script_interpreter_manager
			);

            /// Destructor.
			~ScriptingModule();

			/// Initializes the scripting module.
			void init();

			/// Shut down the scripting module.
			void shutdown();

		private:

			/// The EcmaScript platform.
			EcmaScriptPlatformPtr ecma_script_platform;

			/// Execution of scripts.
			ScriptExecutorPtr script_executor;

			/// Manages the ecma script interpreters.
			EcmaScriptInterpreterManagerPtr ecma_script_interpreter_manager;

	};

}
}
