#pragma once

#include "visual-scripting/processors/logger/LoggerProcessor.hpp"

namespace inexor {
namespace visual_scripting {

	using LoggerProcessorPtr = std::shared_ptr<LoggerProcessor>;

	/// @class LoggerProcessors
    /// @brief Management of the logger processors.
	class LoggerProcessors
	{
		public:

			/// Constructs the logger processors.
			LoggerProcessors(
				LoggerProcessorPtr logger_processor
			);

			~LoggerProcessors();

			/// Initialization of the logger processors.
			void init();

		private:

			// Processor for the entity type LOGGER
			LoggerProcessorPtr logger_processor;

	};

}
}
