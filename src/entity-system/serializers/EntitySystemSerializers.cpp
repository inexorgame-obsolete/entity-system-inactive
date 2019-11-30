#include "EntitySystemSerializers.hpp"

#include <utility>

namespace inexor::entity_system::serializers {

EntitySystemSerializers::EntitySystemSerializers(EntityTypeJsonSerializerPtr entity_type_json_serializer)
    : LifeCycleComponent()
{
    this->entity_type_json_serializer = std::move(entity_type_json_serializer);
}

EntitySystemSerializers::~EntitySystemSerializers() = default;

std::string EntitySystemSerializers::get_component_name()
{
    return "TypeSystemSerializers";
}

} // namespace inexor::entity_system::serializers
