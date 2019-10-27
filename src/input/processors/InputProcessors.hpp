#pragma once

#include "input/processors/GlobalKeyProcessor.hpp"
#include "input/processors/GlobalMouseButtonProcessor.hpp"

namespace inexor::input {

using GlobalKeyProcessorPtr = std::shared_ptr<GlobalKeyProcessor>;
using GlobalMouseButtonProcessorPtr = std::shared_ptr<GlobalMouseButtonProcessor>;

/// @class InputProcessors
/// @brief Management of the processors for input handling.
class InputProcessors
{
    public:
    /// @brief Constructs the processors for input handling.
    /// @note The dependencies of this class will be injected automatically.
    /// @param global_key_processor Processor for the entity type 'GLOBAL_KEY'.
    /// @param global_mouse_button_processor Processor for the entity type 'GLOBAL_MOUSE_BUTTON'.
    InputProcessors(GlobalKeyProcessorPtr global_key_processor, GlobalMouseButtonProcessorPtr global_mouse_button_processor);

    /// Destructor.
    ~InputProcessors();

    /// Initialization of the processors for input handling.
    void init();

    private:
    /// Processor for the entity type 'GLOBAL_KEY'.
    GlobalKeyProcessorPtr global_key_processor;

    /// Processor for the entity type 'GLOBAL_MOUSE_BUTTON'.
    GlobalMouseButtonProcessorPtr global_mouse_button_processor;
};

} // namespace inexor::input
