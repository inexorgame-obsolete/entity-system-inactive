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

			/// Executes the given script
			void execute(int script_type, std::string path);

		private:

			/// The script executor for ECMA script.
			EcmaScriptExecutorPtr ecma_script_executor;

	};

}
}
