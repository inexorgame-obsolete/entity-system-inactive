#include "ConsoleManager.hpp"

namespace inexor {
namespace console {

	ConsoleManager::ConsoleManager()
	{
	}

	ConsoleManager::~ConsoleManager()
	{
	}

	void ConsoleManager::init()
	{
	}

	void ConsoleManager::shutdown()
	{
	}

	ConsolePtr ConsoleManager::create_console(std::string name)
	{
		// TODO: check for existance, return existing one instead.
		ConsolePtr console = std::make_shared<Console>(name);
		consoles[name] = console;
		return console;
	}

	ConsolePtr ConsoleManager::create_console(std::string name, std::string command_prompt)
	{
		// TODO: check for existance, return existing one instead.
		ConsolePtr console = std::make_shared<Console>(name, command_prompt);
		consoles[name] = console;
		return console;
	}

	ConsolePtr ConsoleManager::get_console(std::string name)
	{
		// TODO: check for existance
		return consoles[name];
	}

	void ConsoleManager::destroy_console(std::string name)
	{
		consoles[name] = nullptr;
		// The console
	}

}
}
