#pragma once

#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/factories/relations/relation-instance-builder-factory/RelationInstanceBuilderFactory.hpp"
#include "entity-system/factories/relations/relation-type-builder-factory/RelationTypeBuilderFactory.hpp"

namespace inexor::entity_system {

/// @class BuilderFactoryManager
/// @brief A manager class which bundles the following builder factory classes:
/// <ol>
///		<li> Entity type builder factory
///		<li> Entity instance builder factory
///		<li> Relation type builder factory
///		<li> Relation instance builder factory
/// </ol>
class BuilderFactories
{
    public:
    /// These using instructions help to shorten the following code.
    using EntityTypeBuilderFactoryPtr = std::shared_ptr<EntityTypeBuilderFactory>;
    using EntityInstanceBuilderFactoryPtr = std::shared_ptr<EntityInstanceBuilderFactory>;
    using RelationTypeBuilderFactoryPtr = std::shared_ptr<RelationTypeBuilderFactory>;
    using RelationInstanceBuilderFactoryPtr = std::shared_ptr<RelationInstanceBuilderFactory>;

    /// @brief Constructor.
    /// @param entity_type_builder_factory The entity type builder factory.
    /// @param entity_instance_builder_factory The entity instance builder factory.
    /// @param relation_type_builder_factory The relation type builder factory.
    /// @param relation_instance_builder_factory The relation instance builder factory.
    BuilderFactories(EntityTypeBuilderFactoryPtr entity_type_builder_factory, EntityInstanceBuilderFactoryPtr entity_instance_builder_factory, RelationTypeBuilderFactoryPtr relation_type_builder_factory,
                          RelationInstanceBuilderFactoryPtr relation_instance_builder_factory);

    /// @brief Destructor.
    ~BuilderFactories();

    private:
    /// The entity type builder factory.
    EntityTypeBuilderFactoryPtr entity_type_builder_factory;

    /// The entity instance builder factory.
    EntityInstanceBuilderFactoryPtr entity_instance_builder_factory;

    /// The entity relation type builder factory.
    RelationTypeBuilderFactoryPtr relation_type_builder_factory;

    /// The entity relation instance builder factory.
    RelationInstanceBuilderFactoryPtr relation_instance_builder_factory;

    /// The mutex of this class.
    std::mutex builder_factory_manager_mutex;
};

} // namespace inexor::entity_system
