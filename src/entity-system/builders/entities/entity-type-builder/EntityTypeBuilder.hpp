#pragma once

#include "entity-system/managers/entities/entity-type-manager/EntityTypeManager.hpp"
#include "entity-system/managers/entity-attributes/entity-attribute-instance-manager/EntityAttributeInstanceManager.hpp"
#include "entity-system/managers/entity-attributes/entity-attribute-type-manager/EntityAttributeTypeManager.hpp"
#include "entity-system/model/entities/entity-types/EntityType.hpp"

namespace inexor::entity_system {

class EntityTypeBuilder;

/// These using instructions help to shorten the following code.
using AttributeList = std::unordered_map<std::string, std::pair<DataType, Features>>;
using EntityTypeBuilderPtr = std::shared_ptr<EntityTypeBuilder>;
using EntityTypePtr = std::shared_ptr<EntityType>;
using EntityTypePtrOpt = std::optional<EntityTypePtr>;

/// @class EntityTypeBuilder
/// @brief A builder pattern class for entity types.
/// @note This template base class is part of a software design pattern called the <b>builder pattern</b>.<br>
/// https://en.wikipedia.org/wiki/Builder_pattern
/// @todo Should we lock the mutex as soon as a method gets called and unlock it
/// when the build() method is called ? Because otherwise multiple threads could
/// intercept this builder pattern and create "mixed" products.
class EntityTypeBuilder : public std::enable_shared_from_this<EntityTypeBuilder>
{
    public:
    /// These using instructions help to shorten the following code.
    using EntityTypeManagerPtr = std::shared_ptr<EntityTypeManager>;
    using EntityAttributeTypeManagerPtr = std::shared_ptr<EntityAttributeTypeManager>;
    using EntityAttributeInstanceManagerPtr = std::shared_ptr<EntityAttributeInstanceManager>;

    /// @brief Constructs the entity type builder.
    /// @note The dependencies of this class will be injected automatically.<br>
    /// BOOST_DI_INJECT constructor parameters is limited to BOOST_DI_CFG_CTOR_LIMIT_SIZE,<br>
    /// which by default is set to 10. Not more than 10 arguments can be passed to the DI constructor!<br>
    /// https://boost-experimental.github.io/di/user_guide/index.html
    /// @param entity_type_manager The entity type manager.
    /// @param entity_attribute_type_manager The entity attribute type manager.
    /// @param entity_attribute_instance_manager The entity attribute instance manager.
    EntityTypeBuilder(EntityTypeManagerPtr entity_type_manager, EntityAttributeTypeManagerPtr entity_attribute_type_manager, EntityAttributeInstanceManagerPtr entity_attribute_instance_manager);

    /// @brief Destructs the entity type builder.
    ~EntityTypeBuilder();

    /// @brief Sets the name of the entity type which is being built.
    /// @note Because this method will be used in a builder pattern it does not make sense to rename it so "set_name".
    /// @param entity_type_name The name of the new entity type.
    EntityTypeBuilderPtr name(const std::string &entity_type_name);

    /// @brief Sets the uuid of the entity type which is being built.
    /// @note Because this method will be used in a builder pattern it does not make sense to rename it so "set_uuid".
    /// @param entity_type_uuid The UUID of the new entity type.
    EntityTypeBuilderPtr uuid(const std::string &entity_type_uuid);

    /// @brief Adds an attribute to the entity type which is being built.
    /// @note Because this method will be used in a builder pattern it does not make sense to rename it so "set_attribute".
    /// @param attribute_name The name of the new attribute.
    /// @param attribute_datatype The data type of the new attribute.
    /// @param attribute_features The features of the new attribute.
    EntityTypeBuilderPtr attribute(const std::string &attribute_name, const DataType &attribute_datatype, const Features &attribute_features);

    /// @brief Adds an input attribute to the entity type which is being built.
    /// @note Because this method will be used in a builder pattern it does not make sense to rename it so "set_input".
    /// @param attribute_name The name of the new attribute.
    /// @param attribute_datatype The data type of the new attribute.
    EntityTypeBuilderPtr input(const std::string &attribute_name, const DataType &attribute_datatype);

    /// @brief Adds an output attribute to the entity type which is being built.
    /// @note Because this method will be used in a builder pattern it does not make sense to rename it so "set_output".
    /// @param attribute_name The name of the new attribute.
    /// @param attribute_datatype The data type of the attribute.
    EntityTypeBuilderPtr output(const std::string &attribute_name, const DataType &attribute_datatype);

    /// @brief Adds an attribute which is an input and output at the same time to the entity type which is being built.
    /// @note Because this method will be used in a builder pattern it does not make sense to rename it so "set_inout".
    /// @param attribute_name The name of the new attribute.
    /// @param attribute_datatype The data type of the attribute.
    EntityTypeBuilderPtr inout(const std::string &attribute_name, const DataType &attribute_datatype);

    /// @brief Builds and returns the created entity type.
    EntityTypePtrOpt build();

    private:
    /// The entity type manager.
    EntityTypeManagerPtr entity_type_manager;

    /// The entity attribute instance manager.
    EntityAttributeTypeManagerPtr entity_attribute_type_manager;

    /// The entity attribute instance manager.
    EntityAttributeInstanceManagerPtr entity_attribute_instance_manager;

    /// The name of the new entity type.
    std::string entity_type_name;

    /// The UUID of the new entity type.
    std::string entity_type_uuid;

    /// The attribute definitions.
    AttributeList entity_type_attributes;

    /// The mutex of this class
    std::mutex entity_type_builder_mutex;
};

} // namespace inexor::entity_system
