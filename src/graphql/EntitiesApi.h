#pragma once
/// This file implements the stub generated from the schema.entities.graphql into the EntitiesSchema.h|.cpp
/// (generated into the build folder) in order to implement response functions to various GraphQL queries from
/// some client.

#include "graphql/EntitiesSchema.h"
#include <stack>
#include <utility>

namespace inexor::entity_system {
    class EntityTypeManager;
    class EntityType;

}

namespace graphql::entities {

/// Implements the visitor getters of the individual fields for the GraphQL schema.
/// @see object::EntityType for the generated schema stub implemented here
class EntityTypeVisitor : public object::EntityType
{
    using EntityTypePtr = std::shared_ptr<inexor::entity_system::EntityType>;
    using IdFieldResult = service::FieldResult<std::optional<response::IdType>>;
    using StringFieldResult = service::FieldResult<std::optional<response::StringType>>;
    using EntityAttributeTypeFieldResult = service::FieldResult<std::optional<std::vector<std::shared_ptr<object::EntityAttributeType>>>>;


    public:
    /// Constructs the visitor with a link to the EntityType in the entity-system.
    /// @see inexor::entity_system::EntityType
    explicit EntityTypeVisitor(EntityTypePtr internal_ent_type);

    IdFieldResult getUuid(service::FieldParams&& params) const override;

    StringFieldResult getName(service::FieldParams&& params) const override;

    EntityAttributeTypeFieldResult getAttributes(service::FieldParams&& params) const override;

    private:
    /// The entity type within the entity system to be used in the getters of
    EntityTypePtr internal_ent_type;

};

class Query : public object::Query
{
    using EntityTypePtr = std::shared_ptr<inexor::entity_system::EntityType>;
    using EntityTypeManagerPtr = std::shared_ptr<inexor::entity_system::EntityTypeManager>;
    using SerializableEntityTypes = std::vector<std::shared_ptr<object::EntityType>>;

    template<typename T>
    using OptionalResult = service::FieldResult<std::optional<T>>;

    public:

    explicit Query(EntityTypeManagerPtr entity_type_manager) : entity_type_manager(std::move(entity_type_manager)) {
    }

    OptionalResult<SerializableEntityTypes> getEntity_types(service::FieldParams&& params) const override;

    // TODO: implement the other GraphQL queries:

//    service::FieldResult<std::optional<std::vector<std::shared_ptr<object::EntityInstance>>>> getEntity_instances(service::FieldParams&& params) const override;
//    service::FieldResult<std::optional<std::vector<std::shared_ptr<object::RelationType>>>> getRelation_types(service::FieldParams&& params) const override;
//    service::FieldResult<std::optional<std::vector<std::shared_ptr<object::RelationInstance>>>> getRelation_instances(service::FieldParams&& params) const override;

    private:

    EntityTypeManagerPtr entity_type_manager;
};

} /* namespace graphql::entities */
