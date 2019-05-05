#pragma once

#include "scripting/managers/EcmaScriptPlatform.hpp"

#include "v8.h"

#include <string>
#include <vector>

namespace inexor {
namespace scripting {

	using EcmaScriptPlatformPtr = std::shared_ptr<EcmaScriptPlatform>;

    /// @class EcmaScriptInterpreter
	/// @brief Interpreter for ecma scripts.
    class EcmaScriptInterpreter
    {
		public:

    		/// @brief Constructs and initalizes a new interpreter instance.
            /// @param name The name of the interpreter instance.
    		EcmaScriptInterpreter(
    			std::string name,
				EcmaScriptPlatformPtr ecma_script_platform
			);

            /// Destructs the interpreter instance.
			~EcmaScriptInterpreter();

			/// Queues a command.
			void queue_command(std::string command);

			/// Exits the interpreter.
			void exit();

			/// Returns true, if the interpreter is initialized.
			bool is_initialized();

			/// Returns true, if the interpreter is running.
			bool is_running();

			/// Runs the interpreter in a message loop.
			/// Thread local.
			void run_context();

		private:

			/// Executes a command.
			void execute(v8::Isolate* isolate, std::string command);

			/// The name of the interpreter instance.
			std::string name;

			/// The EcmaScript Platform.
			EcmaScriptPlatformPtr ecma_script_platform;

			/// If true, the interpreter is initialized.
			bool initialized;

			/// If true, the interpreter is running.
			bool running;

			/// The command queue.
			std::deque<std::string> command_queue;
    };

}
}
