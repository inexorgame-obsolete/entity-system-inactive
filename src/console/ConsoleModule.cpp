#include "ConsoleModule.hpp"

namespace inexor {
namespace console {

	ConsoleModule::ConsoleModule(
		ConsoleManagerPtr console_manager
	)
	{
        this->console_manager = console_manager;
	}

	ConsoleModule::~ConsoleModule()
	{
	}

	void ConsoleModule::init()
	{
		console_manager->init();
	}

	void ConsoleModule::shutdown()
	{
		console_manager->shutdown();
	}

}
}
