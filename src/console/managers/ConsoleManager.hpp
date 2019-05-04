#pragma once

#include "console/model/Console.hpp"

#include <memory>
#include <unordered_map>

namespace inexor {
namespace console {

	using ConsolePtr = std::shared_ptr<Console>;

	/// @class ConsoleManager
    /// @brief Service for executing scripts.
	class ConsoleManager
	{
		public:

			/// Constructor.
			ConsoleManager();

			/// Destructor.
			~ConsoleManager();

			/// Initialization of the console manager.
			void init();

			/// Shuts down the console manager.
			void shutdown();

			/// Creates a new console with the given name.
			/// @param name The name of the console.
			ConsolePtr create_console(std::string name);

			/// Creates a new console with the given name and command prompt.
			/// @param name The name of the console.
			/// @param command_prompt The initial command prompt.
			ConsolePtr create_console(std::string name, std::string command_prompt);

			/// Returns the console with the given name.
			// TODO: optional
			ConsolePtr get_console(std::string name);

			/// Destroys the console with the given name.
			void destroy_console(std::string name);

		private:

			/// The consoles.
			std::unordered_map<std::string, ConsolePtr> consoles;

	};

}
}
