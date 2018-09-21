// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityTypeInstance.hpp"
#include "../../../EntitySystem.hpp"


namespace inexor {
namespace entity_system {


	EntityTypeInstance::EntityTypeInstance(const std::shared_ptr<EntityType>& param_entity_type)
	{
		pointer_to_entity_type = param_entity_type;
		reset_memory();
	}


	EntityTypeInstance::~EntityTypeInstance()
	{
		// TODO: Implement!
	}


	void EntityTypeInstance::reset_memory()
	{
		vector_of_instances_of_linked_entity_attribute_types.clear();
	}


	ENTSYS_DATA_VALIDATION_RESULT EntityTypeInstance::validate()
	{
		return ENTSYS_DATA_INVALID;
	}


};
};
