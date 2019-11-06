#pragma once

#include <Corrade/Utility/Resource.h>

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"

namespace inexor::entity_system::type_system {

using EntityTypeBuilderFactoryPtr = std::shared_ptr<EntityTypeBuilderFactory>;

/// @class TypeSystemInitializer
/// @brief Initializes the type system using static resources.
class TypeSystemInitializer
{
    public:
    /// @brief Constructs the initializer of the type system.
    /// @param entity_type_builder_factory The entity type builder factory.
    explicit TypeSystemInitializer(EntityTypeBuilderFactoryPtr entity_type_builder_factory);

    /// Destructor.
    ~TypeSystemInitializer();

    /// Pre-Initialization of the type system module.
    void pre_init();

    /// Initializes the type system using static resources.
    void init();

    /// Loads a type definition
    void load_type_definition(Corrade::Utility::Resource rs, const std::string &file);

    private:
    /// Factory for creating entity types.
    EntityTypeBuilderFactoryPtr entity_type_builder_factory;

    /// The resource group for statically included types.
    static constexpr char RESOURCE_GROUP[] = "inexor-type-system";
};

} // namespace inexor::entity_system::type_system
