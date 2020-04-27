#pragma once

#include "entity-system/managers/manager-templates/InstanceManagerTemplate.hpp"
#include "entity-system/model/entity-attributes/entity-attribute-instances/EntityAttributeInstance.hpp"
#include "entity-system/model/relations/relation-instances/RelationInstance.hpp"
#include "entity-system/model/relations/relation-types/RelationType.hpp"

#include <optional>

namespace inexor::entity_system {

/// These using instructions help to shorten the following code.
using RelationAttributeTypePtr = std::shared_ptr<RelationAttributeType>;
using RelationAttributeInstancePtr = std::shared_ptr<RelationAttributeInstance>;
using RelationAttributeInstancePtrOpt = std::optional<RelationAttributeInstancePtr>;

/// @class RelationAttributeInstanceManager
/// A manager class for relation attribute instances.
class RelationAttributeInstanceManager : public InstanceManagerTemplate<RelationAttributeInstance>
{
    public:
    /// @brief Constructor.
    RelationAttributeInstanceManager();

    /// @brief Destructor.
    ~RelationAttributeInstanceManager();

    /// @brief Creates an relation attribute instance.
    /// @param rel_attr_type A const reference to a shared pointer of an relation attribute type of which an instance will be created.
    /// @return A shared pointer to the relation attribute instance which was created. <br>If the creation fails std::nullopt will be returned.
    RelationAttributeInstancePtr create_relation_attribute_instance(const RelationAttributeTypePtr &rel_attr_type);

    /// @brief Gets a relation attribute instance.
    /// @param rel_attr_inst_GUID The GUID of the relation attribute instance.
    /// @return A std::optional shared pointer to the relation attribute instance.
    std::optional<RelationAttributeInstancePtr> get_relation_attribute_instance(const xg::Guid &rel_attr_inst_GUID);

    /// @brief Returns the number of existing relation attribute type instances.
    /// @return The number of existing relation attribute type instances.
    std::size_t get_relation_attribute_instance_count() const;

    /// @brief Deletes all instances of relation attributes.
    void delete_all_relation_attribute_instances();
};

} // namespace inexor::entity_system
