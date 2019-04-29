#include "EntitySystemDebugger.hpp"

namespace inexor {
namespace entity_system {

	EntitySystemDebugger::EntitySystemDebugger(
		EntityTypeManagerPtr entity_type_manager,
		EntityInstanceManagerPtr entity_instance_manager,
		RelationTypeManagerPtr relation_type_manager,
		RelationInstanceManagerPtr relation_instance_manager,
		LogManagerPtr log_manager
	)
	{
		this->logger = spdlog::default_logger();
		this->entity_type_manager = entity_type_manager;
		this->entity_instance_manager = entity_instance_manager;
		this->relation_type_manager = relation_type_manager;
		this->relation_instance_manager = relation_instance_manager;
		this->log_manager = log_manager;
	}

	EntitySystemDebugger::~EntitySystemDebugger()
	{
	}

	void EntitySystemDebugger::pre_init()
	{
		entity_type_manager->register_on_created(shared_from_this());
		entity_type_manager->register_on_deleted(shared_from_this());
		relation_type_manager->register_on_created(shared_from_this());
		relation_type_manager->register_on_deleted(shared_from_this());
	}

	void EntitySystemDebugger::init()
	{
		log_manager->register_logger(LOGGER_NAME);
		logger = spdlog::get(LOGGER_NAME);
	}

	void EntitySystemDebugger::on_entity_type_created(EntityTypePtr entity_type)
	{
		logger->info("Created entity type {} (UUID: {})", entity_type->get_type_name(), entity_type->get_GUID().str());
		entity_instance_manager->register_on_created(entity_type->get_GUID(), shared_from_this());
		entity_instance_manager->register_on_deleted(entity_type->get_GUID(), shared_from_this());
	}

	void EntitySystemDebugger::on_entity_type_deleted(const xg::Guid& type_GUID)
	{
		logger->info("Deleted entity type (UUID: {})", type_GUID.str());
		// TODO: unregister listeners?
	}

	void EntitySystemDebugger::on_entity_instance_created(EntityInstancePtr entity_instance)
	{
		logger->info("Created entity instance of type {} (UUID: {})", entity_instance->get_entity_type()->get_type_name(), entity_instance->get_GUID().str());
	}

	void EntitySystemDebugger::on_entity_instance_deleted(const xg::Guid& type_GUID, const xg::Guid& inst_GUID)
	{
		logger->info("Deleted entity instance {} of type {}", inst_GUID.str(), type_GUID.str());
	}

	void EntitySystemDebugger::on_relation_type_created(RelationTypePtr rel_type)
	{
		logger->info("Created relation type {} (UUID: {})", rel_type->get_type_name(), rel_type->get_GUID().str());
		relation_instance_manager->register_on_created(rel_type->get_GUID(), shared_from_this());
		relation_instance_manager->register_on_deleted(rel_type->get_GUID(), shared_from_this());
	}

	void EntitySystemDebugger::on_relation_type_deleted(const xg::Guid& type_GUID)
	{
		logger->info("Deleted relation type (UUID: {})", type_GUID.str());
	}

	void EntitySystemDebugger::on_relation_instance_created(RelationInstancePtr relation_instance)
	{
		logger->info("Created relation instance of type {} (UUID: {})", relation_instance->get_relation_type()->get_type_name(), relation_instance->get_GUID().str());
	}

	void EntitySystemDebugger::on_relation_instance_deleted(const xg::Guid& type_GUID, const xg::Guid& inst_GUID)
	{
		logger->info("Deleted relation instance {} of type {}", inst_GUID.str(), type_GUID.str());
	}

}
}
