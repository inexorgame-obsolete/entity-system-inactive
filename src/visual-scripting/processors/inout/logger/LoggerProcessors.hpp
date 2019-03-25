#pragma once

#include "visual-scripting/processors/inout/logger/LoggerProcessor.hpp"

namespace inexor {
namespace visual_scripting {

	using LoggerProcessorPtr = std::shared_ptr<LoggerProcessor>;

	/// @class LoggerProcessors
    /// @brief Management of the logger processors.
	class LoggerProcessors
	{
		public:

			/// @brief Constructs the logger processors.
            /// @note The dependencies of this class will be injected automatically.
            /// @param logger_processor Processor for the entity type LOGGER.
			LoggerProcessors(
				LoggerProcessorPtr logger_processor
			);

            /// Destructor.
			~LoggerProcessors();

			/// Initialization of the logger processors.
			void init();

		private:

			/// Processor for the entity type LOGGER.
			LoggerProcessorPtr logger_processor;

	};

}
}
