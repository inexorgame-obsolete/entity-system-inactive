#pragma once

#include "base/LifeCycleComponent.hpp"
#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"

namespace inexor::entity_system::serializers {

using EntityTypeBuilderFactoryPtr = std::shared_ptr<EntityTypeBuilderFactory>;

class EntityTypeJsonSerializer : public LifeCycleComponent
{
    public:
    /// @brief Constructs the serializers of entity types from and to JSON.
    /// @param entity_type_builder_factory The entity type builder factory.
    explicit EntityTypeJsonSerializer(EntityTypeBuilderFactoryPtr entity_type_builder_factory);

    EntityTypePtrOpt load(const std::string &type_definition_str);

    std::string save(const EntityTypePtr &ent_type);

    /// Returns the name of the component
    std::string get_component_name() override;

    private:
    /// Factory for creating entity types.
    EntityTypeBuilderFactoryPtr entity_type_builder_factory;
};

} // namespace inexor::entity_system::serializers
