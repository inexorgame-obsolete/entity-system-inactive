#include "EntityManager.hpp"

#include <utility>

namespace inexor::entity_system {

EntityManager::EntityManager(std::shared_ptr<inexor::entity_system::EntityTypeManager> entity_type_manager, std::shared_ptr<inexor::entity_system::EntityInstanceManager> entity_instance_manager,
                             std::shared_ptr<inexor::entity_system::EntityAttributeTypeManager> entity_attribute_type_manager, std::shared_ptr<inexor::entity_system::EntityAttributeInstanceManager> entity_attribute_instance_manager)
{
    // Use lock guard to ensure thread safety during write operations!
    std::lock_guard<std::mutex> lock(entity_manager_mutex);

    this->entity_type_manager = std::move(entity_type_manager);
    this->entity_instance_manager = std::move(entity_instance_manager);
    this->entity_attribute_type_manager = std::move(entity_attribute_type_manager);
    this->entity_attribute_instance_manager = std::move(entity_attribute_instance_manager);
}

EntityManager::~EntityManager() = default;

void EntityManager::reset_attributes_and_types()
{
    // Use lock guard to ensure thread safety during write operations!
    std::lock_guard<std::mutex> lock(entity_manager_mutex);

    entity_attribute_instance_manager->delete_all_entity_attribute_instances();
    entity_attribute_type_manager->delete_all_entity_attribute_types();
    entity_instance_manager->delete_all_entity_instances();
    entity_type_manager->delete_all_entity_types();
}

} // namespace inexor::entity_system
