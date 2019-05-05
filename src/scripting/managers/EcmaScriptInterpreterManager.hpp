#pragma once

#include "scripting/model/EcmaScriptInterpreter.hpp"

#include "v8/v8.h"

#include <string>
#include <unordered_map>

namespace inexor {
namespace scripting {

	using EcmaScriptInterpreterPtr = std::shared_ptr<EcmaScriptInterpreter>;

	/// @class EcmaScriptInterpreterManager
    /// @brief Service for executing ECMA scripts.
	class EcmaScriptInterpreterManager
		: public std::enable_shared_from_this<EcmaScriptInterpreterManager>
	{
		public:

			/// Constructor.
			EcmaScriptInterpreterManager(
				EcmaScriptPlatformPtr ecma_script_platform
			);

			/// Destructor.
			~EcmaScriptInterpreterManager();

			/// Initialization of the EcmaScriptInterpreterManager.
			void init();

			/// Shuts down the EcmaScriptInterpreterManager.
			void shutdown();

			/// Creates a new interpreter.
			EcmaScriptInterpreterPtr create_interpreter(std::string name);

			/// Returns the interpreter with the given name.
			EcmaScriptInterpreterPtr get_interpreter(std::string name);

			/// Destroys the interpreter with the given name.
			void destroy_interpreter(std::string name);

		private:

			/// The EcmaScript platform.
			EcmaScriptPlatformPtr ecma_script_platform;

			/// The interpreters.
			std::unordered_map<std::string, EcmaScriptInterpreterPtr> interpreters;

	};

}
}
