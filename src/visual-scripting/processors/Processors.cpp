#include "Processors.hpp"

namespace inexor {
namespace visual_scripting {

	Processors::Processors(
		ProcessorRegistryPtr processor_registry,
		GeneratorProcessorsPtr generator_processors,
		InOutProcessorsPtr inout_processors,
		LogicalProcessorsPtr logical_processors,
		MathProcessorsPtr math_processors
	)
	{
		this->processor_registry = processor_registry;
		this->generator_processors = generator_processors;
		this->inout_processors = inout_processors;
		this->logical_processors = logical_processors;
		this->math_processors = math_processors;
	}

	Processors::~Processors()
	{
	}

	void Processors::init()
	{
		this->processor_registry->init();
		this->generator_processors->init();
		this->inout_processors->init();
		this->logical_processors->init();
		this->math_processors->init();
	}

	void Processors::shutdown()
	{
//		this->math_processors->shutdown();
//		this->logical_processors->shutdown();
//		this->inout_processors->shutdown();
		this->generator_processors->shutdown();
//		this->processor_registry->shutdown();
	}

}
}
