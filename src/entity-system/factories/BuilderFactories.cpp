#include <entity-system/factories/BuilderFactories.hpp>

#include <utility>

namespace inexor::entity_system {

BuilderFactories::BuilderFactories(EntityTypeBuilderFactoryPtr entity_type_builder_factory, EntityInstanceBuilderFactoryPtr entity_instance_builder_factory, RelationTypeBuilderFactoryPtr relation_type_builder_factory,
                                             RelationInstanceBuilderFactoryPtr relation_instance_builder_factory)
{
    // Use lock guard to ensure thread safety during write operations!
    std::lock_guard<std::mutex> lock(builder_factory_manager_mutex);

    this->entity_type_builder_factory = std::move(entity_type_builder_factory);
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
    this->relation_type_builder_factory = std::move(relation_type_builder_factory);
    this->relation_instance_builder_factory = std::move(relation_instance_builder_factory);
}

BuilderFactories::~BuilderFactories() = default;

} // namespace inexor::entity_system
