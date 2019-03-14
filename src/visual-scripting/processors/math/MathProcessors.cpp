#include "MathProcessors.hpp"

namespace inexor {
namespace visual_scripting {

	MathProcessors::MathProcessors(
		ArithmeticProcessorsPtr arithmetic_processors,
		TrigonometricProcessorsPtr trigonometric_processors
	)
	{
		this->arithmetic_processors = arithmetic_processors;
		this->trigonometric_processors = trigonometric_processors;
	}

	MathProcessors::~MathProcessors()
	{
	}

	void MathProcessors::init()
	{
		this->arithmetic_processors->init();
		this->trigonometric_processors->init();
	}

}
}
