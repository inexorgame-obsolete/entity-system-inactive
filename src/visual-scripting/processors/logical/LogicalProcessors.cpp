#include "LogicalProcessors.hpp"

namespace inexor {
namespace visual_scripting {

	LogicalProcessors::LogicalProcessors(
		NotProcessorPtr not_processor
	)
	{
		this->not_processor = not_processor;
	}

	LogicalProcessors::~LogicalProcessors()
	{
	}

	void LogicalProcessors::init()
	{
		not_processor->init();
	}

}
}
