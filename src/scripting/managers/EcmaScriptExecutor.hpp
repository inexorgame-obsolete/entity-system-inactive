#pragma once

#include "v8/v8-platform.h"

#include <string>

namespace inexor {
namespace scripting {

	/// @class EcmaScriptExecutor
    /// @brief Service for executing ECMA scripts.
	class EcmaScriptExecutor
	{
		public:

			/// Constructor.
			EcmaScriptExecutor();

			/// Destructor.
			~EcmaScriptExecutor();

			/// Initialization of the EcmaScriptExecutor.
			void init();

			/// Shuts down the EcmaScriptExecutor.
			void shutdown();

			/// Executes the given ECMA script.
			void execute(std::string path);

			/// Loads the file into a string.
			std::string load_file(std::string path);

		private:

			/// The v8 platform.
			std::unique_ptr<v8::Platform> platform;

	};

}
}
