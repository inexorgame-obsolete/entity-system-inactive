#include "TrigonometricProcessors.hpp"

namespace inexor {
namespace visual_scripting {

	TrigonometricProcessors::TrigonometricProcessors(
		SinProcessorPtr sin_processor,
		CosProcessorPtr cos_processor
	)
	{
		this->sin_processor = sin_processor;
		this->cos_processor = cos_processor;
	}

	TrigonometricProcessors::~TrigonometricProcessors()
	{
	}

	void TrigonometricProcessors::init()
	{
		sin_processor->init();
		cos_processor->init();
	}

}
}
