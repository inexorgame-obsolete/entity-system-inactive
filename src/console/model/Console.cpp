#include "Console.hpp"

namespace inexor {
namespace console {

	Console::Console(std::string name)
	{
		this->name = name;
		this->command_prompt = "> ";
		this->command_line = "";
	}

	Console::Console(std::string name, std::string command_prompt)
	{
		this->name = name;
		this->command_prompt = command_prompt;
		this->command_line = "";
	}

	Console::~Console()
	{
	}

}
}
