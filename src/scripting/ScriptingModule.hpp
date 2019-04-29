#pragma once

#include "scripting/managers/ScriptExecutor.hpp"

namespace inexor {
namespace scripting {

	using ScriptExecutorPtr = std::shared_ptr<ScriptExecutor>;

    /// @class ScriptingModule
    /// @brief This module provides the integration of the script engines.
	class ScriptingModule
	{
		public:

			/// @brief Constructs the scripting module.
            /// @note The dependencies of this class will be injected automatically.
            /// @param script_executor Service for executing scripts.
			ScriptingModule(
				ScriptExecutorPtr script_executor
			);

            /// Destructor.
			~ScriptingModule();

			/// Initializes the scripting module.
			void init();

			/// Shut down the scripting module.
			void shutdown();

		private:

			/// Execution of scripts.
			ScriptExecutorPtr script_executor;

	};

}
}
