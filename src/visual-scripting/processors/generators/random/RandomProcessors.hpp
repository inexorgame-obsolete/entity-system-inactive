#pragma once

#include "visual-scripting/processors/generators/random/RandomNextIntProcessor.hpp"
#include "visual-scripting/processors/generators/random/RandomNextFloatProcessor.hpp"

namespace inexor {
namespace visual_scripting {

	using RandomNextIntProcessorPtr = std::shared_ptr<RandomNextIntProcessor>;
	using RandomNextFloatProcessorPtr = std::shared_ptr<RandomNextFloatProcessor>;

	/// Provides processors for random number generators.
	class RandomProcessors
	{
		public:

			/// Constructs the processors for random number generators.
			RandomProcessors(
				RandomNextIntProcessorPtr random_next_int_processor,
				RandomNextFloatProcessorPtr random_next_float_processor
			);

			~RandomProcessors();

			/// Initialization of the processors for random number generators.
			void init();

		private:

			// Processor for the entity type RANDOM_NEXT_INT
			RandomNextIntProcessorPtr random_next_int_processor;

			// Processor for the entity type RANDOM_NEXT_FLOAT
			RandomNextFloatProcessorPtr random_next_float_processor;

	};

}
}
