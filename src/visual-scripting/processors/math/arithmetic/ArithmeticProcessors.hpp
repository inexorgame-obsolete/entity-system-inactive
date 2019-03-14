#pragma once

#include "visual-scripting/processors/math/arithmetic/AddIntProcessor.hpp"
#include "visual-scripting/processors/math/arithmetic/AddFloatProcessor.hpp"

namespace inexor {
namespace visual_scripting {

	using AddIntProcessorPtr = std::shared_ptr<AddIntProcessor>;
	using AddFloatProcessorPtr = std::shared_ptr<AddFloatProcessor>;

	/// @class ArithmeticProcessors
    /// @brief Management of the arithmetic processors.
	class ArithmeticProcessors
	{
		public:

			/// Constructs the arithmetic processors.
			ArithmeticProcessors(
				AddIntProcessorPtr add_int_processor,
				AddFloatProcessorPtr add_float_processor
			);

			~ArithmeticProcessors();

			/// Initialization of the arithmetic processors.
			void init();

		private:

			// Addition for integers.
			AddIntProcessorPtr add_int_processor;

			// Addition for floating point numbers.
			AddFloatProcessorPtr add_float_processor;

	};

}
}
