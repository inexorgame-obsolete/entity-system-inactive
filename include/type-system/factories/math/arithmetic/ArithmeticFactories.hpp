#pragma once

#include "base/LifeCycleComponent.hpp"
#include "type-system/factories/math/arithmetic/AddFloatFactory.hpp"
#include "type-system/factories/math/arithmetic/AddIntFactory.hpp"

namespace inexor::entity_system::type_system {

using AddIntFactoryPtr = std::shared_ptr<AddIntFactory>;
using AddFloatFactoryPtr = std::shared_ptr<AddFloatFactory>;

/// @class ArithmeticFactories
/// @brief The arithmetic factories.
class ArithmeticFactories : public LifeCycleComponent
{
    public:
    /// @brief Constructs the arithmetic factories.
    /// @note The dependencies of this class will be injected automatically.
    /// @param add_int_factory Factory for creating entity instances of type ADD_INT.
    /// @param add_float_factory Factory for creating entity instances of type ADD_FLOAT.
    ArithmeticFactories(AddIntFactoryPtr add_int_factory, AddFloatFactoryPtr add_float_factory);

    /// Destructor.
    ~ArithmeticFactories();

    /// Returns the name of the component
    std::string get_component_name() override;

    private:
    /// Factory for creating entity instances of type ADD_INT.
    AddIntFactoryPtr add_int_factory;

    /// Factory for creating entity instances of type ADD_FLOAT.
    AddFloatFactoryPtr add_float_factory;
};

} // namespace inexor::entity_system::type_system
