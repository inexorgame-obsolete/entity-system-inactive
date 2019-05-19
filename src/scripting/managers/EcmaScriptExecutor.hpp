#pragma once

#include "EcmaScriptPlatform.hpp"

#include "v8.h"

#include <string>

namespace inexor {
namespace scripting {

	using EcmaScriptPlatformPtr = std::shared_ptr<EcmaScriptPlatform>;

	/// @class EcmaScriptExecutor
	/// @brief Service for executing ECMA scripts.
	class EcmaScriptExecutor
		: public std::enable_shared_from_this<EcmaScriptExecutor>
	{
		public:

			/// Constructor.
			EcmaScriptExecutor(
				EcmaScriptPlatformPtr ecma_script_platform
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

		private:

			/// Executes the given ECMA script.
			void execute(std::string path);

			/// Loads the file into a string.
			std::string load_file(std::string path);

			/// The EcmaScript Platform.
			EcmaScriptPlatformPtr ecma_script_platform;

	};

}
}
