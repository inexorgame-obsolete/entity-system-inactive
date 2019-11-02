#pragma once

#include "entity-system/managers/relation-attributes/relation-attribute-instance-manager/RelationAttributeInstanceManager.hpp"
#include "entity-system/managers/relation-attributes/relation-attribute-type-manager/RelationAttributeTypeManager.hpp"
#include "entity-system/managers/relations/relation-type-manager/RelationTypeManager.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/model/entities/entity-types/EntityType.hpp"
#include "entity-system/model/relations/relation-types/RelationType.hpp"

namespace inexor::entity_system {

/// These using instructions help to shorten the following code.
class RelationTypeBuilder;
using AttributeList = std::unordered_map<std::string, std::pair<DataType, Features>>;
using RelationTypeBuilderPtr = std::shared_ptr<RelationTypeBuilder>;
using RelationTypePtrOpt = std::optional<std::shared_ptr<RelationType>>;

/// @class RelationTypeBuilder
/// @brief Builder class for relation types.
/// @note For more information on the builder software pattern see
/// https://en.wikipedia.org/wiki/Builder_pattern
class RelationTypeBuilder : public std::enable_shared_from_this<RelationTypeBuilder>
{
    public:
    /// These using instructions help to shorten the following code.
    using RelationTypeManagerPtr = std::shared_ptr<RelationTypeManager>;
    using RelationAttributeTypeManagerPtr = std::shared_ptr<RelationAttributeTypeManager>;
    using RelationAttributeInstanceManagerPtr = std::shared_ptr<RelationAttributeInstanceManager>;
    using EntityTypePtr = std::shared_ptr<EntityType>;

    /// @brief Constructor.
    /// @param relation_type_manager A shared pointer to the relation type manager.
    /// @param relation_attribute_type_manager A shared pointer to the relation attribute type manager.
    /// @param relation_attribute_instance_manager A shared pointer to the relation attribute instance manager.
    RelationTypeBuilder(RelationTypeManagerPtr relation_type_manager, RelationAttributeTypeManagerPtr relation_attribute_type_manager, RelationAttributeInstanceManagerPtr relation_attribute_instance_manager);

    /// @brief Destructor.
    ~RelationTypeBuilder();

    /// @brief Sets the name of the relation type.
    /// @param relation_type_name The name of the relation which will be build.
    /// @return A shared pointer to the relation type builder.
    RelationTypeBuilderPtr name(std::string relation_type_name);

    /// @brief Sets the uuid of the relation type.
    /// @param relation_type_uuid The GUID of the relation which will be build.
    /// @return A shared pointer to the relation type builder.
    /// @TODO: Why is this not xg::guid?
    RelationTypeBuilderPtr uuid(std::string relation_type_uuid);

    /// @brief Sets the source entity type.
    /// @param ent_type_source The source entity type of the relation which will be build.
    /// @return A shared pointer to the relation type builder.
    RelationTypeBuilderPtr source(EntityTypePtr ent_type_source);

    /// @brief Sets the target entity type.
    /// @param ent_type_target The target entity type of the relation which will be build.
    /// @return A shared pointer to the relation type builder.
    RelationTypeBuilderPtr target(EntityTypePtr ent_type_target);

    /// @brief Sets the uuid of the relation type.
    /// @param attribute_name The name of the relation which will be build.
    /// @param attribute_datatype The data types of the relation attribute.
    /// @param attribute_features The features of the relation attribute.
    /// @return A shared pointer to the relation type builder.
    RelationTypeBuilderPtr attribute(const std::string &attribute_name, DataType attribute_datatype, const Features &attribute_features);

    /// @brief Builds the relation type.
    /// @return A std::optional shared pointer to the relation type which has been built.
    RelationTypePtrOpt build();

    private:
    /// The relation type manager.
    RelationTypeManagerPtr relation_type_manager;

    /// The relation attribute instance manager.
    RelationAttributeTypeManagerPtr relation_attribute_type_manager;

    /// The relation attribute instance manager.
    RelationAttributeInstanceManagerPtr relation_attribute_instance_manager;

    /// The name of the new relation type.
    std::string relation_type_name;

    /// TODO: Why is this not xg::guid?
    /// The UUID of the new relation type.
    std::string relation_type_uuid;

    /// The source entity type.
    EntityTypePtr ent_type_source;

    /// The target entity type.
    EntityTypePtr ent_type_target;

    /// The attribute definitions.
    AttributeList relation_type_attributes;

    /// The mutex of this class.
    std::mutex relation_type_builder_mutex;
};

} // namespace inexor::entity_system
