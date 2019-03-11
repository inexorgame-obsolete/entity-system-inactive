#pragma once

#include "visual-scripting/processors/logical/NotProcessor.hpp"

namespace inexor {
namespace visual_scripting {

	using NotProcessorPtr = std::shared_ptr<NotProcessor>;

	/// @class LogicalProcessors
    /// @brief Management of the logger processors.
	class LogicalProcessors
	{
		public:

			/// Constructs the processors for logical operations.
			LogicalProcessors(
				NotProcessorPtr not_processor
			);

			~LogicalProcessors();

			/// Initialization of the processors for logical operations.
			void init();

		private:

			// Processor for the entity type NOT
			NotProcessorPtr not_processor;

	};

}
}
