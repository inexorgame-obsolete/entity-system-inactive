#pragma once

#include "visual-scripting/processors/math/arithmetic/ArithmeticProcessors.hpp"
#include "visual-scripting/processors/math/trigonometric/TrigonometricProcessors.hpp"

namespace inexor {
namespace visual_scripting {

	using ArithmeticProcessorsPtr = std::shared_ptr<ArithmeticProcessors>;
	using TrigonometricProcessorsPtr = std::shared_ptr<TrigonometricProcessors>;

    /// Provides processors.
	class MathProcessors
	{
		public:

			/// Constructs the processors.
			MathProcessors(
				ArithmeticProcessorsPtr arithmetic_processors,
				TrigonometricProcessorsPtr trigonometric_processors
			);

			~MathProcessors();

			/// Initialization of the Processors.
			void init();

		private:

			/// The processors for arithmetic operations.
			ArithmeticProcessorsPtr arithmetic_processors;

			/// The processors for processors trigonometric operations.
			TrigonometricProcessorsPtr trigonometric_processors;

	};

}
}
