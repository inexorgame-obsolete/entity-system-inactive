#pragma once

#include "visual-scripting/processors/generators/timers/TimerTickProcessor.hpp"

namespace inexor {
namespace visual_scripting {

	using TimerTickProcessorPtr = std::shared_ptr<TimerTickProcessor>;

	/// Provides processors for timers.
	class TimerProcessors
	{
		public:

			/// Constructs the processors for timers.
			TimerProcessors(
				TimerTickProcessorPtr timer_tick_processor
			);

			~TimerProcessors();

			/// Initialization of the processors for timers.
			void init();

		private:

			// Processor for the entity type TIMER_TICK.
			TimerTickProcessorPtr timer_tick_processor;

	};

}
}
