#pragma once

#include "visual-scripting/processors/math/trigonometric/CosProcessor.hpp"
#include "visual-scripting/processors/math/trigonometric/SinProcessor.hpp"
#include "visual-scripting/processors/math/trigonometric/TanProcessor.hpp"

namespace inexor::visual_scripting {

using SinProcessorPtr = std::shared_ptr<SinProcessor>;
using CosProcessorPtr = std::shared_ptr<CosProcessor>;
using TanProcessorPtr = std::shared_ptr<TanProcessor>;

/// @class TrigonometricProcessors
/// @brief Management of the trigonometric processors.
class TrigonometricProcessors
{
    public:
    /// @brief Constructs the trigonometric processors.
    /// @note The dependencies of this class will be injected automatically.
    /// @param sin_processor The sin generator.
    /// @param cos_processor The cos generator.
    /// @param tan_processor The tan generator.
    TrigonometricProcessors(SinProcessorPtr sin_processor, CosProcessorPtr cos_processor, TanProcessorPtr tan_processor);

    /// Destructor.
    ~TrigonometricProcessors();

    /// Initialization of the processors.
    void init();

    private:
    /// The sin generator.
    SinProcessorPtr sin_processor;

    /// The cos generator.
    CosProcessorPtr cos_processor;

    /// The tan generator.
    TanProcessorPtr tan_processor;
};

} // namespace inexor::visual_scripting
