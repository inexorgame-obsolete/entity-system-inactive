#pragma once

#include "base/LifeCycleComponent.hpp"
#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "entity-system/managers/entities/entity-type-manager/EntityTypeManager.hpp"

namespace inexor::entity_system::serializers {

using EntityInstanceBuilderFactoryPtr = std::shared_ptr<EntityInstanceBuilderFactory>;
using EntityTypeManagerPtr = std::shared_ptr<EntityTypeManager>;

class EntityInstanceJsonSerializer : public LifeCycleComponent
{
    public:
    /// @brief Constructs the serializers of entity types from and to JSON.
    /// @param entity_instance_builder_factory Factory for getting entity instance builders.
    EntityInstanceJsonSerializer(EntityInstanceBuilderFactoryPtr entity_instance_builder_factory, EntityTypeManagerPtr entity_type_manager);

    EntityInstancePtrOpt load(const std::string &instance_definition_str);

    EntityInstancePtrOpt load(const std::string &instance_definition_str, bool random_uuid);

    std::string save(const EntityInstancePtr &ent_inst);

    /// Returns the name of the component
    std::string get_component_name() override;

    private:
    /// Factory for creating entity types.
    EntityInstanceBuilderFactoryPtr entity_instance_builder_factory;

    /// Factory for creating entity types.
    EntityTypeManagerPtr entity_type_manager;
};

} // namespace inexor::entity_system::serializers
