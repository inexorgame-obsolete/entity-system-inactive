// Inexor entity system prototype
// (c)2018-2019 Inexor

#include "EntityInstance.hpp"
#include "../../../EntitySystem.hpp"


namespace inexor {
namespace entity_system {


	extern std::shared_ptr<EntitySystem> entsys;


	EntityInstance::EntityInstance(const ENT_TYPE& ent_type) : InstanceBase(ent_type)
	{
		// Create all entity attribute type instances for this entity type instance.
		std::vector<ENT_ATTR_TYPE> ent_type_attributes = ent_type->get_linked_attribute_types();

		for(std::size_t i=0; i<ent_type_attributes.size(); i++)
		{
			// Create an entity attribute type instance and store it in the map.
			// Use the entity system's EntityAttributeInstanceManager method!
			ENT_ATTR_INST new_ent_attr_type_instance = entsys->create_entity_attribute_type_instance(ent_type_attributes[i]);

			// Call template base class method.
			add_entity_attribute_instance(ent_type_attributes[i], new_ent_attr_type_instance);
		}
	}


	EntityInstance::~EntityInstance()
	{
		// TODO: Implement!
	}


    void EntityInstance::add_entity_attribute_instance(const std::shared_ptr<EntityAttributeType>& ent_attr_type, const std::shared_ptr<EntityAttributeInstance>& ent_attr_inst)
    {
        // Use lock guard to ensure thread safety for this write operation!
        std::lock_guard<std::mutex> lock(entity_type_mutex);
        instances[ent_attr_type] = ent_attr_inst;
    }


};
};
