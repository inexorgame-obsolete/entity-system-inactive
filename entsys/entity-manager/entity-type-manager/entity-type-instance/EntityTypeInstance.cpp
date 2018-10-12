// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityTypeInstance.hpp"
#include "../../../EntitySystem.hpp"


namespace inexor {
namespace entity_system {


	extern std::shared_ptr<EntitySystem> entsys;


	EntityTypeInstance::EntityTypeInstance(const std::shared_ptr<EntityType>& ent_type)
	{
		// Call template base class method.
		set_type_pointer(ent_type);
		// Call template base class method.
		set_type_name(ent_type->get_type_name());

		// Create all entity attribute type instances for this entity type instance.
		std::vector<std::shared_ptr<EntityAttributeType>> ent_type_attributes = ent_type->get_linked_attribute_types();

		for(std::size_t i=0; i<ent_type_attributes.size(); i++)
		{
			// Create an entity attribute type instance and store it in the map.
			// Use the entity system's EntityAttributeTypeInstanceManager method!
			std::shared_ptr<EntityAttributeTypeInstance> new_ent_attr_type_instance
				= entsys->create_entity_attribute_type_instance(ent_type_attributes[i]);

			// Call template base class method.
			add_linked_instance(ent_type_attributes[i], new_ent_attr_type_instance);
		}
	}


	EntityTypeInstance::~EntityTypeInstance()
	{
	}


};
};
