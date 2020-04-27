#pragma once

#include "entity-system/model/base/instance/InstanceBase.hpp"
#include "entity-system/model/relation-attributes/relation-attribute-types/RelationAttributeType.hpp"

namespace inexor::entity_system {

/// This using instruction helps to shorten the following code.
using RelationAttributeTypePtr = std::shared_ptr<RelationAttributeType>;

/// @class RelationAttributeInstance
/// @brief A base class for relation attribute instances.
class RelationAttributeInstance : public InstanceBase<RelationAttributeType>, public DataContainer, public GUIDBase
{
    private:
    /// The mutex of this class
    std::mutex relation_attribute_instance_mutex;

    public:
    /// @brief Constructs the relation attribute instance.
    /// @note The GUID of this relation attribute instance will be created automatically by inheriting from GUIDBase!
    /// @param rel_attr_type A const reference to a shared pointer of a relation attribute type of which an instance will be created.
    /// @todo Add a mutex to ensure thread-safety!
    explicit RelationAttributeInstance(const RelationAttributeTypePtr &rel_attr_type);

    /// @brief Destructs the relation attribute instance.
    ~RelationAttributeInstance();

    /// @brief Returns the relation attribute type.
    /// @return The attribte type.
    [[nodiscard]] RelationAttributeTypePtr get_relation_attribute_type() const;
};

} // namespace inexor::entity_system
