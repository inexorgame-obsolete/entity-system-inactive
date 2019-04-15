#pragma once

#include "input/processors//GlobalKeyProcessor.hpp"

namespace inexor {
namespace input {

	using GlobalKeyProcessorPtr = std::shared_ptr<GlobalKeyProcessor>;

	/// @class InputProcessors
    /// @brief Management of the processors for input handling.
	class InputProcessors
	{
		public:

			/// @brief Constructs the processors for input handling.
            /// @note The dependencies of this class will be injected automatically.
            /// @param global_key_processor Processor for the entity type GLOBAL_KEY.
			InputProcessors(
				GlobalKeyProcessorPtr global_key_processor
			);

            /// Destructor.
			~InputProcessors();

			/// Initialization of the processors for input handling.
			void init();

		private:

			/// Processor for the entity type GLOBAL_KEY.
			GlobalKeyProcessorPtr global_key_processor;

	};

}
}
