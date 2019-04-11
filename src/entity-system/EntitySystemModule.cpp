#include "EntitySystemModule.hpp"

namespace inexor {
namespace entity_system {

	EntitySystemModule::EntitySystemModule(
		EntityManagerPtr entity_manager,
		RelationManagerPtr relation_manager,
		BuilderFactoryManagerPtr builder_factory_manager,
		LogManagerPtr log_manager
	)
	{
		this->entity_manager = entity_manager;
		this->relation_manager = relation_manager;
		this->builder_factory_manager = builder_factory_manager;
		this->log_manager = log_manager;
	}

	EntitySystemModule::~EntitySystemModule()
	{
	}

	void EntitySystemModule::reset_entity_system()
	{
		spdlog::get(LOGGER_NAME)->debug("Resetting entity system.");
		relation_manager->reset_entity_system();
		entity_manager->reset_entity_system();
	}

}
}
