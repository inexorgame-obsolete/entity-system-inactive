#include <entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp>

#include <utility>

namespace inexor::entity_system {

EntityTypeBuilderFactory::EntityTypeBuilderFactory(EntityTypeManagerPtr entity_type_manager, EntityAttributeTypeManagerPtr entity_attribute_type_manager, EntityAttributeInstanceManagerPtr entity_attribute_instance_manager)
{
    // Use lock guard to ensure thread safety during write operations!
    std::lock_guard<std::mutex> lock(entity_type_builder_factory);

    this->entity_type_manager = std::move(entity_type_manager);
    this->entity_attribute_type_manager = std::move(entity_attribute_type_manager);
    this->entity_attribute_instance_manager = std::move(entity_attribute_instance_manager);
}

EntityTypeBuilderFactory::~EntityTypeBuilderFactory() = default;

void EntityTypeBuilderFactory::init()
{
}

EntityTypeBuilderPtr EntityTypeBuilderFactory::get_builder()
{
    // No mutex required as this is a read-only operation.
    return std::make_shared<EntityTypeBuilder>(entity_type_manager, entity_attribute_type_manager, entity_attribute_instance_manager);
}

} // namespace inexor::entity_system
