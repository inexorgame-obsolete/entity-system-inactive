// Inexor entity system
// (c)2018 Inexor

#include "ProcessorRegistry.hpp"

using namespace inexor::entity_system;

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

	void ProcessorRegistry::register_processor(const std::shared_ptr<Processor>& processor)
	{
		processors[processor->get_entity_type()] = processor;
	}

	std::optional<std::shared_ptr<Processor>> ProcessorRegistry::get_processor_by_entity_type(const ENT_TYPE& entity_type)
	{
		if (!(processors.end() == processors.find(entity_type)))
		{
			return std::optional<std::shared_ptr<Processor>> { processors[entity_type] };
		}
		return nullopt;
	}

	bool ProcessorRegistry::has_processor(const ENT_TYPE& entity_type)
	{
		return !(processors.end() == processors.find(entity_type));
	}


}
}
