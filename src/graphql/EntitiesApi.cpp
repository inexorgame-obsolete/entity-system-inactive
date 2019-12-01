#include "EntitiesApi.h"

#include <algorithm>

#include <entity-system/managers/entities/entity-type-manager/EntityTypeManager.hpp>

namespace graphql::entities {

EntityTypeVisitor::EntityTypeVisitor(EntityTypeVisitor::EntityTypePtr internal_ent_type) : internal_ent_type(std::move(internal_ent_type))
{
}

EntityTypeVisitor::IdFieldResult EntityTypeVisitor::getUuid(service::FieldParams &&params) const
{
    const auto &uuid_str = internal_ent_type->get_GUID().str();
    std::vector<uint8_t> id(uuid_str.begin(), uuid_str.end());
    return response::IdType(id);
}

EntityTypeVisitor::StringFieldResult EntityTypeVisitor::getName(service::FieldParams &&params) const
{
    return internal_ent_type->get_type_name();
}

EntityTypeVisitor::EntityAttributeTypeFieldResult EntityTypeVisitor::getAttributes(service::FieldParams &&params) const
{
    auto internal_attr_types = internal_ent_type->get_linked_attribute_types();
    // TODO: make object::EntityAttributeType  i.e. implement a visitor
    //  for it (including the constructor with the link to the internal store)
    return std::nullopt;
}

Query::OptionalResult<Query::SerializableEntityTypes> Query::getEntity_types(service::FieldParams &&params) const
{
    std::vector<EntityTypePtr> internal_ent_types = entity_type_manager->get_all_entity_types();
    // TODO: make object::EntityType  i.e. implement a visitor
    //  for it (including the constructor with the link to the internal store)
    SerializableEntityTypes serializable_entity_types;
    for (const EntityTypePtr& ent_type : internal_ent_types) {
        serializable_entity_types.push_back(std::make_shared<EntityTypeVisitor>(ent_type));
    }
    return serializable_entity_types;

    // Q; do we need a future??? or is it just because they resolve everything async?
    // A: No. FieldResult is a wrapper for either the raw result or a future of the result

    // std::promise<SerializableEntityTypes> promise;
    // promise.set_value(std::move(serializable_entity_types));

    // return promise.get_future();
}
} /* namespace graphql::entities */
