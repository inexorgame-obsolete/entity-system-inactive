#include <entity-system/factories/relations/relation-type-builder-factory/RelationTypeBuilderFactory.hpp>

#include <utility>

namespace inexor::entity_system {

RelationTypeBuilderFactory::RelationTypeBuilderFactory(RelationTypeManagerPtr relation_type_manager, RelationAttributeTypeManagerPtr relation_attribute_type_manager, RelationAttributeInstanceManagerPtr relation_attribute_instance_manager)
{
    // Use lock guard to ensure thread safety during write operations!
    std::lock_guard<std::mutex> lock(relation_type_builder_factory);

    this->relation_type_manager = std::move(relation_type_manager);
    this->relation_attribute_type_manager = std::move(relation_attribute_type_manager);
    this->relation_attribute_instance_manager = std::move(relation_attribute_instance_manager);
}

RelationTypeBuilderFactory::~RelationTypeBuilderFactory() = default;

void RelationTypeBuilderFactory::init()
{
}

RelationTypeBuilderPtr RelationTypeBuilderFactory::get_builder()
{
    // No mutex required as this is a read-only operation.
    return std::make_shared<RelationTypeBuilder>(relation_type_manager, relation_attribute_type_manager, relation_attribute_instance_manager);
}

} // namespace inexor::entity_system
