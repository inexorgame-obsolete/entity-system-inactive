#include "ProcessorRegistry.hpp"

namespace inexor {
namespace visual_scripting {

	ProcessorRegistry::ProcessorRegistry()
	{
	}

	ProcessorRegistry::~ProcessorRegistry()
	{
	}

	void ProcessorRegistry::init()
	{
	}

	void ProcessorRegistry::register_processor(const ProcessorPtr& processor)
	{
		processors[processor->get_entity_type()] = processor;
	}

	ProcessorPtrOpt ProcessorRegistry::get_processor(const EntityTypePtr& entity_type)
	{
		if (!(processors.end() == processors.find(entity_type)))
		{
			return ProcessorPtrOpt { processors[entity_type] };
		}
		return std::nullopt;
	}

	bool ProcessorRegistry::has_processor(const EntityTypePtr& entity_type)
	{
		return !(processors.end() == processors.find(entity_type));
	}

}
}
