#include "LogicalProcessors.hpp"

namespace inexor {
namespace visual_scripting {

	LogicalProcessors::LogicalProcessors(
		ComparisonProcessorsPtr comparison_processors,
		GateProcessorsPtr gate_processors
	)
	{
		this->comparison_processors = comparison_processors;
		this->gate_processors = gate_processors;
	}

	LogicalProcessors::~LogicalProcessors()
	{
	}

	void LogicalProcessors::init()
	{
		this->comparison_processors->init();
		this->gate_processors->init();
	}

}
}
