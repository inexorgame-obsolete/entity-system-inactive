#include "RelationManager.hpp"

#include <utility>

using namespace inexor::entity_system;

namespace inexor::entity_system {

RelationManager::RelationManager(std::shared_ptr<RelationTypeManager> relation_type_manager, std::shared_ptr<RelationInstanceManager> relation_instance_manager, std::shared_ptr<RelationAttributeTypeManager> relation_attribute_type_manager,
                                 std::shared_ptr<RelationAttributeInstanceManager> relation_attribute_instance_manager)
{
    // Use lock guard to ensure thread safety during write operations!
    std::lock_guard<std::mutex> lock(relation_manager_mutex);

    this->relation_type_manager = std::move(relation_type_manager);
    this->relation_instance_manager = std::move(relation_instance_manager);
    this->relation_attribute_type_manager = std::move(relation_attribute_type_manager);
    this->relation_attribute_instance_manager = std::move(relation_attribute_instance_manager);
}

RelationManager::~RelationManager() = default;

void RelationManager::reset_relations_and_relation_attributes()
{
    // TODO: Use lock_guard here as well?
    relation_attribute_instance_manager->delete_all_relation_attribute_instances();
    relation_attribute_type_manager->delete_all_relation_attribute_types();
    relation_instance_manager->delete_all_relation_instances();
    relation_type_manager->delete_all_relation_types();
}

} // namespace inexor::entity_system
