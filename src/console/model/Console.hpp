#pragma once

#include <string>
#include <vector>

namespace inexor {
namespace console {

    /// @class Console
	/// @brief A console consists of a command prompt, a command line and the output history.
    class Console
    {
		public:

    		/// @brief Constructs a new console with the given name.
            /// @param name The name of the console.
    		Console(std::string name);

    		/// @brief Constructs a new console with the given name and the given command prompt.
            /// @param name The name of the console.
            /// @param command_prompt The command prompt.
    		Console(std::string name, std::string command_prompt);

            /// Destructor.
			~Console();

			/// The name of the console.
			std::string name;

			/// The command prompt.
			std::string command_prompt;

			/// The command line.
			std::string command_line;

			/// The command history.
			std::vector<std::string> command_history;

			/// The output history.
			std::vector<std::string> output_history;

    };

}
}
