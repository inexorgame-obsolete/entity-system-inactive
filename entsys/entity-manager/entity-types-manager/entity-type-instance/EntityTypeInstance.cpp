// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityTypeInstance.hpp"


namespace inexor {
namespace entity_system {


	EntityTypeInstance::EntityTypeInstance()
	{
		// TODO: Implement!
	}


	EntityTypeInstance::EntityTypeInstance(const std::shared_ptr<EntityType>& param_entity_type)
	{
		entity_type = param_entity_type;
		// TODO: Create instances of entity attribute types for this entity type instance!
		// Add pointer from EntityTypeInstanceManager's list.
		// TODO: Evaluate and debug this!
	}


	EntityTypeInstance::~EntityTypeInstance()
	{
		// TODO: Remove pointer from EntityTypeInstanceManager's list!
	}


	ENTSYS_DATA_VALIDATION_RESULT EntityTypeInstance::validate()
	{
		return ENTSYS_DATA_INVALID;
	}


	void EntityTypeInstance::set_attribute_data(const std::shared_ptr<EntityAttributeType>& param_entity_attribute_type,
		                                        const DataContainer& param_data)
	{
		//linked_entity_attribute_type_instances[param_entity_attribute_type] = TODO;
	}


};
};
