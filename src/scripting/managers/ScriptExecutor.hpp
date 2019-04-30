#pragma once

#include "scripting/managers/EcmaScriptExecutor.hpp"

#include <memory>

namespace inexor {
namespace scripting {

	using EcmaScriptExecutorPtr = std::shared_ptr<EcmaScriptExecutor>;

	/// @class ScriptExecutor
    /// @brief Service for executing scripts.
	class ScriptExecutor
	{
		public:

			/// Constructor.
			ScriptExecutor(
				EcmaScriptExecutorPtr ecma_script_executor
			);

			/// Destructor.
			~ScriptExecutor();

			/// Initialization of the active components.
			void init();

			/// Shuts down the script executor service.
			void shutdown();

			/// Executes the given script.
			// TODO: add script parameters
			// TODO: add return value (std::optional<entity_system::DataValue>)
			void execute_once(int script_type, std::string path);

			/// Executes the given script in it's own thread.
			// TODO: add script parameters
			// TODO: add return value (std::optional<entity_system::DataValue>)
			void execute_once(int script_type, std::string path, bool detached);

		private:

			/// The script executor for ECMA script.
			EcmaScriptExecutorPtr ecma_script_executor;

	};

}
}
