#pragma once

#include "type-system/factories/data/converters/IntToFloatFactory.hpp"
#include "type-system/factories/data/converters/IntToStringFactory.hpp"

#include <memory>

namespace inexor::entity_system::type_system {

using IntToFloatFactoryPtr = std::shared_ptr<IntToFloatFactory>;
using IntToStringFactoryPtr = std::shared_ptr<IntToStringFactory>;

/// @class ConverterFactories
/// @brief The converter factories.
class ConverterFactories
{
    public:
    /// @brief Constructs the converter factories.
    /// @param int_to_float_factory Factory for creating entity instances of type INT_TO_FLOAT.
    /// @param int_to_string_factory Factory for creating entity instances of type INT_TO_STRING.
    explicit ConverterFactories(IntToFloatFactoryPtr int_to_float_factory, IntToStringFactoryPtr int_to_string_factory);

    /// Destructor.
    ~ConverterFactories();

    /// Initializes the converter factories.
    void init();

    private:
    /// Factory for creating entity instances of type INT_TO_FLOAT.
    IntToFloatFactoryPtr int_to_float_factory;

    /// Factory for creating entity instances of type INT_TO_STRING.
    IntToStringFactoryPtr int_to_string_factory;
};

} // namespace inexor::entity_system::type_system
