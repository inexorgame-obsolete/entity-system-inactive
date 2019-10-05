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

			/// Inserts a string on the cursor position.
			void insert(std::string str);

			/// Removes the char before the cursor position.
			void backspace();

			/// Removes the char on the cursor position.
			void delete_char();

			/// Moves the cursor to the left.
			void cursor_left();

			/// Moves the cursor to the right.
			void cursor_right();

			/// Moves the cursor to the first position.
			void cursor_pos1();

			/// Moves the cursor to the end.
			void cursor_end();

			/// Resets the command line.
			void reset();

			/// Sets the command line. The former contents will be overwritten.
			void set(std::string command_line);

			/// The name of the console.
			std::string name;

			/// The command prompt.
			std::string command_prompt;

			/// The command line.
			std::string command_line;

			/// The cursor position.
			int cursor_position;

			/// The command history.
			std::vector<std::string> command_history;

			/// The output history.
			std::vector<std::string> output_history;

    };

}
}
