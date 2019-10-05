#include "Console.hpp"

namespace inexor {
namespace console {

	Console::Console(std::string name)
	{
		this->name = name;
		this->command_prompt = "> ";
		this->command_line = "";
		this->cursor_position = 0;
	}

	Console::Console(std::string name, std::string command_prompt)
	{
		this->name = name;
		this->command_prompt = command_prompt;
		this->command_line = "";
		this->cursor_position = 0;
	}

	Console::~Console()
	{
	}

	void Console::insert(std::string str)
	{
		size_t len = str.length();
		command_line.insert(cursor_position, str);
		cursor_position += len;
	}

	void Console::backspace()
	{
		if (cursor_position <= 0)
			return;
		command_line.erase(cursor_position - 1, 1);
		cursor_position -= 1;
	}

	void Console::delete_char()
	{
		if (cursor_position >= command_line.length())
			return;
		command_line.erase(cursor_position, 1);
	}

	void Console::cursor_left()
	{
		if (cursor_position <= 0)
			return;
		cursor_position -= 1;
	}

	void Console::cursor_right()
	{
		if (cursor_position >= command_line.length())
			return;
		cursor_position += 1;
	}

	void Console::cursor_pos1()
	{
		cursor_position = 0;
	}

	void Console::cursor_end()
	{
		cursor_position = command_line.length();
	}

	void Console::reset()
	{
		cursor_position = 0;
		command_line = "";
	}

	void Console::set(std::string command_line)
	{
		this->command_line = command_line;
		cursor_position = this->command_line.length();
	}

}
}
