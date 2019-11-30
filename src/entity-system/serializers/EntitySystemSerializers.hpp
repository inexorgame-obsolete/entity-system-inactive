#pragma once

#include "EntityTypeJsonSerializer.hpp"
#include "EntityInstanceJsonSerializer.hpp"
#include "base/LifeCycleComponent.hpp"

namespace inexor::entity_system::serializers {

using EntityTypeJsonSerializerPtr = std::shared_ptr<EntityTypeJsonSerializer>;
using EntityInstanceJsonSerializerPtr = std::shared_ptr<EntityInstanceJsonSerializer>;

/// @class TypeSystemPersistence
/// @brief The factories of the type system.
class EntitySystemSerializers : public LifeCycleComponent
{
    public:
    /// @brief Constructs the factories of the type system.
    /// @param entity_type_json_serializer The serializer for entity types.
    /// @param entity_instance_json_serializer The serializer for entity instances.
    EntitySystemSerializers(EntityTypeJsonSerializerPtr entity_type_json_serializer, EntityInstanceJsonSerializerPtr entity_instance_json_serializer);

    /// Destructor.
    ~EntitySystemSerializers();

    /// Returns the name of the component
    std::string get_component_name() override;

    private:
    /// The serializer for entity types.
    EntityTypeJsonSerializerPtr entity_type_json_serializer;

    /// The serializer for entity instances.
    EntityInstanceJsonSerializerPtr entity_instance_json_serializer;
};

} // namespace inexor::entity_system::serializers
