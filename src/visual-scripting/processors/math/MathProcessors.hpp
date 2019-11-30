#pragma once

#include "visual-scripting/processors/math/arithmetic/ArithmeticProcessors.hpp"
#include "visual-scripting/processors/math/trigonometric/TrigonometricProcessors.hpp"

namespace inexor::visual_scripting {

using ArithmeticProcessorsPtr = std::shared_ptr<ArithmeticProcessors>;
using TrigonometricProcessorsPtr = std::shared_ptr<TrigonometricProcessors>;

/// @class MathProcessors
/// @brief Provides processors.
class MathProcessors : public LifeCycleComponent
{
    public:
    /// @brief Constructs the processors.
    /// @note The dependencies of this class will be injected automatically.
    /// @param arithmetic_processors The processors for arithmetic operations.
    /// @param trigonometric_processors The processors for processors trigonometric operations.
    MathProcessors(ArithmeticProcessorsPtr arithmetic_processors, TrigonometricProcessorsPtr trigonometric_processors);

    /// Destructor.
    ~MathProcessors();

    /// Returns the name of the component
    std::string get_component_name() override;

    private:
    /// The processors for arithmetic operations.
    ArithmeticProcessorsPtr arithmetic_processors;

    /// The processors for processors trigonometric operations.
    TrigonometricProcessorsPtr trigonometric_processors;
};

} // namespace inexor::visual_scripting
