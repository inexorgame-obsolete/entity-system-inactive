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
		// Use lock guard to ensure thread safety during write operations!
		std::lock_guard<std::mutex> lock(entity_system_module);

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
		// Use lock guard to ensure thread safety during write operations!
		std::lock_guard<std::mutex> lock(entity_system_module);

		spdlog::get(LOGGER_NAME)->debug("Resetting entity system.");

		// Reset relation attribute instances, relation attribute types, relation instances and relation types.
		relation_manager->reset_relations_and_relation_attributes();

		// Reset attribute instances, attribute types, entity instances and entity types.
		entity_manager->reset_attributes_and_types();
	}

}
}
