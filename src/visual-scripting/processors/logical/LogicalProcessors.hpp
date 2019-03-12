#pragma once

#include "visual-scripting/processors/logical/NotProcessor.hpp"
#include "visual-scripting/processors/logical/OrProcessor.hpp"
#include "visual-scripting/processors/logical/AndProcessor.hpp"
#include "visual-scripting/processors/logical/XorProcessor.hpp"
#include "visual-scripting/processors/logical/NorProcessor.hpp"
#include "visual-scripting/processors/logical/NandProcessor.hpp"

namespace inexor {
namespace visual_scripting {

	using NotProcessorPtr = std::shared_ptr<NotProcessor>;
	using OrProcessorPtr = std::shared_ptr<OrProcessor>;
	using AndProcessorPtr = std::shared_ptr<AndProcessor>;
	using XorProcessorPtr = std::shared_ptr<XorProcessor>;
	using NorProcessorPtr = std::shared_ptr<NorProcessor>;
	using NandProcessorPtr = std::shared_ptr<NandProcessor>;

	/// @class LogicalProcessors
    /// @brief Management of the logger processors.
	class LogicalProcessors
	{
		public:

			/// Constructs the processors for logical operations.
			LogicalProcessors(
				NotProcessorPtr not_processor,
				OrProcessorPtr or_processor,
				AndProcessorPtr and_processor,
				XorProcessorPtr xor_processor,
				NorProcessorPtr nor_processor,
				NandProcessorPtr nand_processor
			);

			~LogicalProcessors();

			/// Initialization of the processors for logical operations.
			void init();

		private:

			// Processor for the entity type NOT
			NotProcessorPtr not_processor;

			// Processor for the entity type OR
			OrProcessorPtr or_processor;

			// Processor for the entity type AND
			AndProcessorPtr and_processor;

			// Processor for the entity type XOR
			XorProcessorPtr xor_processor;

			// Processor for the entity type NOR
			NorProcessorPtr nor_processor;

			// Processor for the entity type NAND
			NandProcessorPtr nand_processor;

	};

}
}
