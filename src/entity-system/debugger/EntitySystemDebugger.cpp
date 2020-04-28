#include <entity-system/debugger/EntitySystemDebugger.hpp>

#include <utility>

namespace inexor::entity_system {

EntitySystemDebugger::EntitySystemDebugger(EntityTypeManagerPtr entity_type_manager, EntityInstanceManagerPtr entity_instance_manager, RelationTypeManagerPtr relation_type_manager, RelationInstanceManagerPtr relation_instance_manager,
                                           LogManagerPtr log_manager)
{
    // Use lock guard to ensure thread safety during write operations!
    std::lock_guard<std::mutex> lock(entity_system_debugger_mutex);

    this->logger = spdlog::default_logger();
    this->entity_type_manager = std::move(entity_type_manager);
    this->entity_instance_manager = std::move(entity_instance_manager);
    this->relation_type_manager = std::move(relation_type_manager);
    this->relation_instance_manager = std::move(relation_instance_manager);
    this->log_manager = std::move(log_manager);
}

EntitySystemDebugger::~EntitySystemDebugger() = default;

void EntitySystemDebugger::init()
{
    // Use lock guard to ensure thread safety during write operations!
    std::lock_guard<std::mutex> lock(entity_system_debugger_mutex);

    entity_type_manager->register_on_created(shared_from_this());
    entity_type_manager->register_on_deleted(shared_from_this());
    relation_type_manager->register_on_created(shared_from_this());
    relation_type_manager->register_on_deleted(shared_from_this());
}

void EntitySystemDebugger::init_logger()
{
    // Use lock guard to ensure thread safety during write operations!
    std::lock_guard<std::mutex> lock(entity_system_debugger_mutex);

    log_manager->register_logger(LOGGER_NAME);
    logger = spdlog::get(LOGGER_NAME);
}

void EntitySystemDebugger::on_entity_type_created(EntityTypePtr ent_type)
{
    // Use lock guard to ensure thread safety during write operations!
    std::lock_guard<std::mutex> lock(entity_system_debugger_mutex);

    logger->info("Created entity type {} (UUID: {})", ent_type->get_type_name(), ent_type->get_GUID().str());
    entity_instance_manager->register_on_created(ent_type->get_GUID(), shared_from_this());
    entity_instance_manager->register_on_deleted(ent_type->get_GUID(), shared_from_this());
}

void EntitySystemDebugger::on_entity_type_deleted(const xg::Guid &ent_type_GUID)
{
    logger->info("Deleted entity type (UUID: {})", ent_type_GUID.str());
    // TODO: unregister listeners?
}

void EntitySystemDebugger::on_entity_instance_created(EntityInstancePtr ent_inst)
{
    logger->info("Created entity instance of type {} (UUID: {})", ent_inst->get_entity_type()->get_type_name(), ent_inst->get_GUID().str());
}

void EntitySystemDebugger::on_entity_instance_deleted(const xg::Guid &type_GUID, const xg::Guid &inst_GUID)
{
    logger->info("Deleted entity instance {} of type {}", inst_GUID.str(), type_GUID.str());
}

void EntitySystemDebugger::on_relation_type_created(RelationTypePtr rel_type)
{
    // Use lock guard to ensure thread safety during write operations!
    std::lock_guard<std::mutex> lock(entity_system_debugger_mutex);

    logger->info("Created relation type {} (UUID: {})", rel_type->get_type_name(), rel_type->get_GUID().str());
    relation_instance_manager->register_on_created(rel_type->get_GUID(), shared_from_this());
    relation_instance_manager->register_on_deleted(rel_type->get_GUID(), shared_from_this());
}

void EntitySystemDebugger::on_relation_type_deleted(const xg::Guid &type_GUID)
{
    logger->info("Deleted relation type (UUID: {})", type_GUID.str());
}

void EntitySystemDebugger::on_relation_instance_created(RelationInstancePtr rel_inst)
{
    logger->info("Created relation instance of type {} (UUID: {})", rel_inst->get_relation_type()->get_type_name(), rel_inst->get_GUID().str());
}

void EntitySystemDebugger::on_relation_instance_deleted(const xg::Guid &rel_type_GUID, const xg::Guid &rel_inst_GUID)
{
    logger->info("Deleted relation instance {} of type {}", rel_inst_GUID.str(), rel_type_GUID.str());
}

} // namespace inexor::entity_system
