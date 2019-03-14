#include "InOutProcessors.hpp"

namespace inexor {
namespace visual_scripting {

	InOutProcessors::InOutProcessors(
		ConsoleProcessorsPtr console_processors,
		LoggerProcessorsPtr logger_processors
	)
	{
		this->console_processors = console_processors;
		this->logger_processors = logger_processors;
	}

	InOutProcessors::~InOutProcessors()
	{
	}

	void InOutProcessors::init()
	{
		console_processors->init();
		logger_processors->init();
	}

}
}
