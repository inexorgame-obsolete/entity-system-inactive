#include "LogicalProcessors.hpp"

namespace inexor {
namespace visual_scripting {

	LogicalProcessors::LogicalProcessors(
		NotProcessorPtr not_processor,
		OrProcessorPtr or_processor,
		AndProcessorPtr and_processor,
		XorProcessorPtr xor_processor,
		NorProcessorPtr nor_processor,
		NandProcessorPtr nand_processor
	)
	{
		this->not_processor = not_processor;
		this->or_processor = or_processor;
		this->and_processor = and_processor;
		this->xor_processor = xor_processor;
		this->nor_processor = nor_processor;
		this->nand_processor = nand_processor;
	}

	LogicalProcessors::~LogicalProcessors()
	{
	}

	void LogicalProcessors::init()
	{
		not_processor->init();
		or_processor->init();
		and_processor->init();
		xor_processor->init();
		nor_processor->init();
		nand_processor->init();
	}

}
}
