#include "ConsoleProcessors.hpp"

namespace inexor {
namespace visual_scripting {

	ConsoleProcessors::ConsoleProcessors(
		StdInProcessorPtr stdin_processor,
		StdOutProcessorPtr stdout_processor,
		StdErrProcessorPtr stderr_processor
	)
	{
		this->stdin_processor = stdin_processor;
		this->stdout_processor = stdout_processor;
		this->stderr_processor = stderr_processor;
	}

	ConsoleProcessors::~ConsoleProcessors()
	{
	}

	void ConsoleProcessors::init()
	{
		stdin_processor->init();
		stdout_processor->init();
		stderr_processor->init();
	}

}
}
