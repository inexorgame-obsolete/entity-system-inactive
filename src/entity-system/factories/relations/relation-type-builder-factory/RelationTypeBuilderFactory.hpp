#pragma once

#include "entity-system/builders/relations/relation-type-builder/RelationTypeBuilder.hpp"
#include "entity-system/managers/relation-attributes/relation-attribute-instance-manager/RelationAttributeInstanceManager.hpp"
#include "entity-system/managers/relation-attributes/relation-attribute-type-manager/RelationAttributeTypeManager.hpp"
#include "entity-system/managers/relations/relation-type-manager/RelationTypeManager.hpp"

namespace inexor::entity_system {

/// @class RelationTypeBuilderFactory
/// @brief A builder class for relation types.
/// @note For more information on the builder software pattern see
/// https://en.wikipedia.org/wiki/Builder_pattern
class RelationTypeBuilderFactory
{
    public:
    /// These using instructions help to shorten the following code.
    using RelationTypeBuilderPtr = std::shared_ptr<RelationTypeBuilder>;
    using RelationTypeManagerPtr = std::shared_ptr<RelationTypeManager>;
    using RelationAttributeTypeManagerPtr = std::shared_ptr<RelationAttributeTypeManager>;
    using RelationAttributeInstanceManagerPtr = std::shared_ptr<RelationAttributeInstanceManager>;

    /// @brief Constructor.
    /// @param relation_type_manager A shared pointer to the relation type manager.
    /// @param relation_attribute_type_manager A shared pointer to the relation attribute type manager.
    /// @param relation_attribute_instance_manager A shared pointer to the relation attribute instance manager.
    RelationTypeBuilderFactory(RelationTypeManagerPtr relation_type_manager, RelationAttributeTypeManagerPtr relation_attribute_type_manager, RelationAttributeInstanceManagerPtr relation_attribute_instance_manager);

    /// @brief Destructor.
    ~RelationTypeBuilderFactory();

    /// @brief Initialization of the manager
    void init();

    /// @brief Returns a new instance of a builder.
    /// @return A std::shared pointer to the relation type builder.
    RelationTypeBuilderPtr get_builder();

    private:
    /// The relation type manager.
    RelationTypeManagerPtr relation_type_manager;

    /// The relation attribute instance manager.
    RelationAttributeTypeManagerPtr relation_attribute_type_manager;

    /// The relation attribute instance manager.
    RelationAttributeInstanceManagerPtr relation_attribute_instance_manager;

    /// The mutex of this class.
    std::mutex relation_type_builder_factory;
};

} // namespace inexor::entity_system
