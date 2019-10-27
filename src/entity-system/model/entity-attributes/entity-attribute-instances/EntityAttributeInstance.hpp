#pragma once

#include "entity-system/model/base/instance/InstanceBase.hpp"
#include "entity-system/model/entity-attributes/entity-attribute-types/EntityAttributeType.hpp"

namespace inexor::entity_system {

/// These using instructions help to shorten the following code.
using EntityAttributeTypePtr = std::shared_ptr<EntityAttributeType>;

/// @class EntityAttributeInstance
/// @brief A base class for entity attribute type instances.
class EntityAttributeInstance : public InstanceBase<EntityAttributeType>, public DataContainer, public GUIDBase
{
    private:
    /// The mutex of this class.
    std::mutex entity_attribute_instance_mutex;

    public:
    /// @brief Constructor.
    /// @note the GUID of the new entity attribute instance will be created automatically by the inheritance of GUIDBase!
    /// @param ent_attr_type A reference to a shared pointer of an entity attribute type of which an instance will be created.
    explicit EntityAttributeInstance(const EntityAttributeTypePtr &ent_attr_type);

    /// @brief Destructor.
    ~EntityAttributeInstance();

    /// @brief Get the entity attribute type.
    /// @return The type of the attribute.
    [[nodiscard]] EntityAttributeTypePtr get_entity_attribute_type() const;

    /// @brief Returns the value of the attribute instance.
    /// @tparam I The data type.
    /// @return The value of the attribute instance.
    template <std::size_t I> auto get()
    {
        // No mutex required as this is a read-only operation.
        return std::get<I>(value.Value());
    }

    /// @brief Sets the own value of the attribute instance.
    /// @warning The given value must be of the correct data type. No checks are done.
    /// @param value The data value.
    void set_own_value(const DataValue& value);

    /// @brief Toggles the own value of the attribute instance.
    /// @warning The attribute have to be of data type BOOL. No checks are done.
    void toggle();
};

} // namespace inexor::entity_system
