#pragma once

#include "base/LifeCycleComponent.hpp"
#include "type-system/factories/math/arithmetic/ArithmeticFactories.hpp"
#include "type-system/factories/math/trigonometric/TrigonometricFactories.hpp"

namespace inexor::entity_system::type_system {

using ArithmeticFactoriesPtr = std::shared_ptr<ArithmeticFactories>;
using TrigonometricFactoriesPtr = std::shared_ptr<TrigonometricFactories>;

/// @class MathFactories
/// @brief The factories for mathematical operations.
class MathFactories : public LifeCycleComponent
{
    public:
    /// @brief Constructs the factories for mathematical operations.
    /// @note The dependencies of this class will be injected automatically.
    /// @param arithmetic_factories The factories for arithmetic operations.
    MathFactories(ArithmeticFactoriesPtr arithmetic_factories, TrigonometricFactoriesPtr trigonometric_factories);

    /// Destructor.
    ~MathFactories();

    /// Returns the name of the component
    std::string get_component_name() override;

    private:
    /// The factories for arithmetic operations.
    ArithmeticFactoriesPtr arithmetic_factories;

    /// The factories for trigonometric operations.
    TrigonometricFactoriesPtr trigonometric_factories;
};

} // namespace inexor::entity_system::type_system
