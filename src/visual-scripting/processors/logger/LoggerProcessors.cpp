#include "LoggerProcessors.hpp"

namespace inexor {
namespace visual_scripting {

	LoggerProcessors::LoggerProcessors(
		LoggerProcessorPtr logger_processor
	)
	{
		this->logger_processor = logger_processor;
	}

	LoggerProcessors::~LoggerProcessors()
	{
	}

	void LoggerProcessors::init()
	{
		logger_processor->init();
	}

}
}
