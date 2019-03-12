#pragma once

#include "visual-scripting/processors/console/StdInProcessor.hpp"
#include "visual-scripting/processors/console/StdOutProcessor.hpp"
#include "visual-scripting/processors/console/StdErrProcessor.hpp"

namespace inexor {
namespace visual_scripting {

	using StdInProcessorPtr = std::shared_ptr<StdInProcessor>;
	using StdOutProcessorPtr = std::shared_ptr<StdOutProcessor>;
	using StdErrProcessorPtr = std::shared_ptr<StdErrProcessor>;

	/// @class ConsoleProcessors
    /// @brief Management of the logger processors.
	class ConsoleProcessors
	{
		public:

			/// Constructs the logger processors.
			ConsoleProcessors(
				StdInProcessorPtr stdin_processor,
				StdOutProcessorPtr stdout_processor,
				StdErrProcessorPtr stderr_processor
			);

			~ConsoleProcessors();

			/// Initialization of the logger processors.
			void init();

		private:

			// Processor for the entity type CONSOLE_STDIN
			StdInProcessorPtr stdin_processor;

			// Processor for the entity type CONSOLE_STDOUT
			StdOutProcessorPtr stdout_processor;

			// Processor for the entity type CONSOLE_STDERR
			StdErrProcessorPtr stderr_processor;

	};

}
}
