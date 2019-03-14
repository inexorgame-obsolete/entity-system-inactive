#pragma once

#include "visual-scripting/processors/math/trigonometric/SinProcessor.hpp"
#include "visual-scripting/processors/math/trigonometric/CosProcessor.hpp"
#include "visual-scripting/processors/math/trigonometric/TanProcessor.hpp"

namespace inexor {
namespace visual_scripting {

	using SinProcessorPtr = std::shared_ptr<SinProcessor>;
	using CosProcessorPtr = std::shared_ptr<CosProcessor>;
	using TanProcessorPtr = std::shared_ptr<TanProcessor>;

	/// @class TrigonometricProcessors
    /// @brief Management of the trigonometric processors.
	class TrigonometricProcessors
	{
		public:

			/// Constructs the trigonometric processors.
			TrigonometricProcessors(
				SinProcessorPtr sin_processor,
				CosProcessorPtr cos_processor,
				TanProcessorPtr tan_processor
			);

			~TrigonometricProcessors();

			/// Initialization of the processors.
			void init();

		private:

			// The sin generator.
			SinProcessorPtr sin_processor;

			// The cos generator.
			CosProcessorPtr cos_processor;

			// The tan generator.
			TanProcessorPtr tan_processor;

	};

}
}
