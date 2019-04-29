#include "EntitySystemModule.hpp"

namespace inexor {
namespace entity_system {

	EntitySystemModule::EntitySystemModule(
		EntityManagerPtr entity_manager,
		RelationManagerPtr relation_manager,
		BuilderFactoryManagerPtr builder_factory_manager,
		EntitySystemDebuggerPtr entity_system_debugger,
		LogManagerPtr log_manager
	)
	{
		this->entity_manager = entity_manager;
		this->relation_manager = relation_manager;
		this->builder_factory_manager = builder_factory_manager;
		this->entity_system_debugger = entity_system_debugger;
		this->log_manager = log_manager;
	}

	EntitySystemModule::~EntitySystemModule()
	{
	}

	void EntitySystemModule::pre_init()
	{
		entity_system_debugger->pre_init();
	}

	void EntitySystemModule::init()
	{
		entity_system_debugger->init();
	}

	void EntitySystemModule::reset_entity_system()
	{
		spdlog::get(LOGGER_NAME)->debug("Resetting entity system.");

		// Reset relation attribute instances, relation attribute types, relation instances and relation types.
		relation_manager->reset_relations_and_relation_attributes();

		// Reset attribute instances, attribute types, entity instances and entity types.
		entity_manager->reset_attributes_and_types();
	}

}
}
