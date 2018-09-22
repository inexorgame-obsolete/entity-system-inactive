// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityTypeInstance.hpp"
#include "../../../EntitySystem.hpp"


namespace inexor {
namespace entity_system {


	EntityTypeInstance::EntityTypeInstance(const std::shared_ptr<EntityType>& param_entity_type)
	{
		pointer_to_entity_type = param_entity_type;
		// TODO: Create instances of entity attribute types for this entity type instance!
		
		// Add pointer from EntityTypeInstanceManager's list.
		// TODO: Evaluate and debug this!
		entsys.register_entity_type_instance(std::shared_ptr<EntityTypeInstance>(this));
		
	}


	EntityTypeInstance::EntityTypeInstance()
	{
		// TODO: Remove pointer from EntityTypeInstanceManager's list!
	}


	EntityTypeInstance::~EntityTypeInstance()
	{
		// TODO: Remove pointer from EntityTypeInstanceManager's list!
	}


	ENTSYS_DATA_VALIDATION_RESULT EntityTypeInstance::validate()
	{
		return ENTSYS_DATA_INVALID;
	}


	// Set attribute data
	void EntityTypeInstance::set_attribute_data(const std::shared_ptr<EntityAttributeType>& param_entity_attribute_type,
		                                        const DataContainer& param_data)
	{
		// TODO: Implement and debug!
		//linked_entity_attribute_type_instances[param_entity_attribute_type]->data = param_data;
	}


};
};
