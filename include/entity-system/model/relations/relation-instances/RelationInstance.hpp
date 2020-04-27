#pragma once

#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "entity-system/model/relation-attributes/relation-attribute-instances/RelationAttributeInstance.hpp"
#include "entity-system/model/relation-attributes/relation-attribute-types/RelationAttributeType.hpp"
#include "entity-system/model/relations/relation-types/RelationType.hpp"

namespace inexor::entity_system {

/// These using instructions help to shorten the following code.
using RelationTypePtr = std::shared_ptr<RelationType>;
using EntityInstancePtr = std::shared_ptr<EntityInstance>;
using RelationAttributeTypePtr = std::shared_ptr<RelationAttributeType>;
using RelationAttributeInstancePtr = std::shared_ptr<RelationAttributeInstance>;

/// @class RelationInstance
/// @brief A base class for entity relation type instances.
class RelationInstance : public InstanceBase<RelationType>, public GUIDBase
{
    private:
    /// The source entity instance.
    EntityInstancePtr source_entity_instance;

    /// The target entity instance.
    EntityInstancePtr destination_entity_instance;

    /// An unordered map of entity relation attribute instances (value) and entity relation attribute types (key).
    std::unordered_map<RelationAttributeTypePtr, RelationAttributeInstancePtr> relation_attribute_instances;

    /// The mutex of this class.
    std::mutex relation_instance_mutex;

    public:
    /// @brief Constructs the relation instance.
    /// @note The GUID of the entity relation instance will be created automatically by inheriting from GUIDBase!
    /// @param rel_type A const reference to a shared pointer of an entity relation type of which an instance will be created.
    /// @param ent_inst_source A const reference to a shared pointer of an entity instance which will be used as source entity instance.
    /// @param ent_inst_target A const reference to a shared pointer of an entity instance which will be used as target entity instance.
    RelationInstance(const RelationTypePtr &rel_type, const EntityInstancePtr &ent_inst_source, const EntityInstancePtr &ent_inst_target);

    /// @brief Constructs the relation instance.
    /// @param inst_GUID The GUID of the relation instance which will be created.
    /// @param rel_type A const reference to a shared pointer of an relation type of which an instance will be created.
    /// @param ent_inst_source A const reference to a shared pointer of an entity instance which will be used as source entity instance.
    /// @param ent_inst_target A const reference to a shared pointer of an entity instance which will be used as target entity instance.
    RelationInstance(const xg::Guid &inst_GUID, const RelationTypePtr &rel_type, const EntityInstancePtr &ent_inst_source, const EntityInstancePtr &ent_inst_target);

    /// @brief Destructs the relation instance.
    ~RelationInstance();

    /// @brief Adds a relation attribute instance to a relation instance.
    /// @param rel_attr_type The relation attribute type.
    /// @param rel_attr_inst The relation attribute instance.
    void register_relation_attribute_instance(const RelationAttributeTypePtr &rel_attr_type, const RelationAttributeInstancePtr &rel_attr_inst);

    /// @brief Returns all entity relation attribute instances.
    /// @return A std::unordered_map of shared pointers of entity relation attribute types.
    std::unordered_map<RelationAttributeTypePtr, RelationAttributeInstancePtr> get_relation_attribute_instances() const;

    /// @brief Get the relation type.
    /// @return The relation type of the relation instance.
    RelationTypePtr get_relation_type() const;

    /// @brief Returns the entity instance on the source side.
    /// @return The source entity instance.
    EntityInstancePtr get_source_entity_instance() const;

    /// @brief Returns the entity instance on the target side.
    /// @return The target entity instance.
    EntityInstancePtr get_target_entity_instance() const;
};

} // namespace inexor::entity_system
