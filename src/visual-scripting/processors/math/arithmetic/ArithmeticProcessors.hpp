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

			/// @brief Constructs the arithmetic processors.
            /// @note The dependencies of this class will be injected automatically.
            /// @param add_int_processor Addition for integers.
            /// @param add_float_processor Addition for floating point numbers.
			ArithmeticProcessors(
				AddIntProcessorPtr add_int_processor,
				AddFloatProcessorPtr add_float_processor
			);

            /// Destructor.
			~ArithmeticProcessors();

			/// Initialization of the arithmetic processors.
			void init();

		private:

			/// Addition for integers.
			AddIntProcessorPtr add_int_processor;

			/// Addition for floating point numbers.
			AddFloatProcessorPtr add_float_processor;

	};

}
}
