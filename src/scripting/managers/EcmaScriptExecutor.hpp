#pragma once

#include "EcmaScriptLoggingModuleInitializer.hpp"

#include "v8/v8.h"

#include <string>

namespace inexor {
namespace scripting {

	using EcmaScriptLoggingModuleInitializerPtr = std::shared_ptr<EcmaScriptLoggingModuleInitializer>;

	/// @class EcmaScriptExecutor
    /// @brief Service for executing ECMA scripts.
	class EcmaScriptExecutor
		: public std::enable_shared_from_this<EcmaScriptExecutor>
	{
		public:

			/// Constructor.
			EcmaScriptExecutor(
				EcmaScriptLoggingModuleInitializerPtr logging_module_initializer
			);

			/// Destructor.
			~EcmaScriptExecutor();

			/// Initialization of the EcmaScriptExecutor.
			void init();

			/// Shuts down the EcmaScriptExecutor.
			void shutdown();

			/// Executes the given ECMA script.
			void execute(std::string path);

			EcmaScriptLoggingModuleInitializerPtr logging_module_initializer;

		private:

//			/// Require module.
//			void require_module(const v8::FunctionCallbackInfo<v8::Value>& args);

			/// Loads the file into a string.
			std::string load_file(std::string path);

			/// The v8 platform.
			std::unique_ptr<v8::Platform> platform;

	};

}
}
