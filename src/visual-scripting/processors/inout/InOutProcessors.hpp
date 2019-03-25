#pragma once

#include "visual-scripting/processors/inout/console/ConsoleProcessors.hpp"
#include "visual-scripting/processors/inout/logger/LoggerProcessors.hpp"

namespace inexor {
namespace visual_scripting {

	using ConsoleProcessorsPtr = std::shared_ptr<ConsoleProcessors>;
	using LoggerProcessorsPtr = std::shared_ptr<LoggerProcessors>;

    /// @class InOutProcessors
    /// @brief Provides processors for input and output.
	class InOutProcessors
	{
		public:

			/// @brief Constructs the processors for input and output.
            /// @note The dependencies of this class will be injected automatically.
            /// @param console_processors The processors for console handling.
            /// @param logger_processors The processors for logging.
			InOutProcessors(
				ConsoleProcessorsPtr console_processors,
				LoggerProcessorsPtr logger_processors
			);

            /// Destructor.
			~InOutProcessors();

			/// Initialization of the processors for input and output.
			void init();

		private:

			/// The processors for console handling.
			ConsoleProcessorsPtr console_processors;

			/// The processors for logging.
			LoggerProcessorsPtr logger_processors;

	};

}
}
