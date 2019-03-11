#include "Processors.hpp"

namespace inexor {
namespace visual_scripting {

	Processors::Processors(
		ProcessorRegistryPtr processor_registry,
		ArithmeticProcessorsPtr arithmetic_processors,
		TrigonometricProcessorsPtr trigonometric_processors
	)
	{
		this->processor_registry = processor_registry;
		this->arithmetic_processors = arithmetic_processors;
		this->trigonometric_processors = trigonometric_processors;
	}

	Processors::~Processors()
	{
	}

	void Processors::init()
	{
		this->processor_registry->init();
		this->arithmetic_processors->init();
		this->trigonometric_processors->init();
	}

}
}
