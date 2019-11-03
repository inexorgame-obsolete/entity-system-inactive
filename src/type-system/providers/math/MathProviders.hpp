#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"

#include "type-system/providers/math/arithmetic/ArithmeticProviders.hpp"

namespace inexor::entity_system::type_system {

using EntityTypeBuilderFactoryPtr = std::shared_ptr<EntityTypeBuilderFactory>;
using ArithmeticProvidersPtr = std::shared_ptr<ArithmeticProviders>;

/// @class MathProviders
/// @brief The providers for mathematical operations.
class MathProviders
{
    public:
    /// @brief Constructs the providers for mathematical operations.
    /// @note The dependencies of this class will be injected automatically.
    /// @param entity_type_builder_factory Factory for creating entity types.
    /// @param arithmetic_providers The providers for arithmetic operations.
    MathProviders(EntityTypeBuilderFactoryPtr entity_type_builder_factory, ArithmeticProvidersPtr arithmetic_providers);

    /// Destructor.
    ~MathProviders();

    /// Initializes the providers for mathematical operations.
    void init();

    private:
    /// Factory for creating entity types.
    EntityTypeBuilderFactoryPtr entity_type_builder_factory;

    /// The providers for arithmetic operations.
    ArithmeticProvidersPtr arithmetic_providers;
};

} // namespace inexor::entity_system::type_system
