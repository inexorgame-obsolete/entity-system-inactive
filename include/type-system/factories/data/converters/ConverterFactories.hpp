#pragma once

#include "base/LifeCycleComponent.hpp"
#include "type-system/factories/data/converters/IntToFloatFactory.hpp"
#include "type-system/factories/data/converters/IntToStringFactory.hpp"

#include <memory>
#include <utility>

namespace inexor::entity_system::type_system {

using IntToFloatFactoryPtr = std::shared_ptr<IntToFloatFactory>;
using IntToStringFactoryPtr = std::shared_ptr<IntToStringFactory>;

/// @class ConverterFactories
/// @brief The converter factories.
class ConverterFactories : public LifeCycleComponent
{
    public:
    /// @brief Constructs the converter factories.
    /// @param int_to_float_factory Factory for creating entity instances of type INT_TO_FLOAT.
    /// @param int_to_string_factory Factory for creating entity instances of type INT_TO_STRING.
    ConverterFactories(IntToFloatFactoryPtr int_to_float_factory, IntToStringFactoryPtr int_to_string_factory);

    /// Destructor.
    ~ConverterFactories();

    /// Returns the name of the component
    std::string get_component_name() override;

    private:
    /// Factory for creating entity instances of type INT_TO_FLOAT.
    IntToFloatFactoryPtr int_to_float_factory;

    /// Factory for creating entity instances of type INT_TO_STRING.
    IntToStringFactoryPtr int_to_string_factory;
};

} // namespace inexor::entity_system::type_system
