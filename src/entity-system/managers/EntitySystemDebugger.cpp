// Inexor entity system
// (c)2018 Inexor

#include "EntitySystemDebugger.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace entity_system {

	EntitySystemDebugger::EntitySystemDebugger(
		shared_ptr<EntityTypeManager> entity_type_manager,
		shared_ptr<EntityInstanceManager> entity_instance_manager,
		shared_ptr<RelationTypeManager> relation_type_manager,
		shared_ptr<RelationInstanceManager> relation_instance_manager
	)
	{
		this->entity_type_manager = entity_type_manager;
		this->entity_instance_manager = entity_instance_manager;
		this->relation_type_manager = relation_type_manager;
		this->relation_instance_manager = relation_instance_manager;
	}

	EntitySystemDebugger::~EntitySystemDebugger()
	{
	}

	void EntitySystemDebugger::init()
	{
		entity_type_manager->register_on_created(shared_from_this());
		entity_type_manager->register_on_deleted(shared_from_this());
		relation_type_manager->register_on_created(shared_from_this());
		relation_type_manager->register_on_deleted(shared_from_this());
	}

	void EntitySystemDebugger::on_entity_type_created(ENT_TYPE entity_type)
	{
		spdlog::info("[DBG] Created entity type {} (UUID: {})", entity_type->get_type_name(), entity_type->get_GUID().str());
		entity_instance_manager->register_on_created(entity_type->get_GUID(), shared_from_this());
		entity_instance_manager->register_on_deleted(entity_type->get_GUID(), shared_from_this());
	}

	void EntitySystemDebugger::on_entity_type_deleted(const xg::Guid& type_GUID)
	{
		spdlog::info("[DBG] Deleted entity type (UUID: {})", type_GUID.str());
		// TODO: unregister listeners?
	}

	void EntitySystemDebugger::on_entity_instance_created(ENT_INST entity_instance)
	{
		spdlog::info("[DBG] Created entity instance of type {} (UUID: {})", entity_instance->get_entity_type()->get_type_name(), entity_instance->get_GUID().str());
	}

	void EntitySystemDebugger::on_entity_instance_deleted(const xg::Guid& type_GUID, const xg::Guid& inst_GUID)
	{
		spdlog::info("[DBG] Deleted entity instance {} of type {}", inst_GUID.str(), type_GUID.str());
	}

	void EntitySystemDebugger::on_relation_type_created(REL_TYPE rel_type)
	{
		spdlog::info("[DBG] Created relation type {} (UUID: {})", rel_type->get_type_name(), rel_type->get_GUID().str());
		relation_instance_manager->register_on_created(rel_type->get_GUID(), shared_from_this());
		relation_instance_manager->register_on_deleted(rel_type->get_GUID(), shared_from_this());
	}

	void EntitySystemDebugger::on_relation_type_deleted(const xg::Guid& type_GUID)
	{
		spdlog::info("[DBG] Deleted relation type (UUID: {})", type_GUID.str());
	}

	void EntitySystemDebugger::on_relation_instance_created(REL_INST relation_instance)
	{
		spdlog::info("[DBG] Created relation instance of type {} (UUID: {})", relation_instance->get_relation_type()->get_type_name(), relation_instance->get_GUID().str());
	}

	void EntitySystemDebugger::on_relation_instance_deleted(const xg::Guid& type_GUID, const xg::Guid& inst_GUID)
	{
		spdlog::info("[DBG] Deleted relation instance {} of type {}", inst_GUID.str(), type_GUID.str());
	}

}
}
