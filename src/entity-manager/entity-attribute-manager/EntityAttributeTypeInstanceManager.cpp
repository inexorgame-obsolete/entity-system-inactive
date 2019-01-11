// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityAttributeTypeInstanceManager.hpp"
#include "../../EntitySystem.hpp"


namespace inexor {
namespace entity_system {


	extern std::shared_ptr<EntitySystem> entsys;


    EntityAttributeTypeInstanceManager::EntityAttributeTypeInstanceManager()
		: TypeInstanceManagerTemplate(entity_attribute_type_instance_error)
    {
		// TODO: Implement!
    }


    EntityAttributeTypeInstanceManager::~EntityAttributeTypeInstanceManager()
    {
		// TODO: Implement!
    }


	ENT_ATTR_TYPE_INST EntityAttributeTypeInstanceManager
        ::create_entity_attribute_type_instance(const ENT_ATTR_TYPE& ent_attr_type)
	{
		// Create entity attribute type instance.
		ENT_ATTR_TYPE_INST new_ent_attr_type_instance = std::make_shared<EntityAttributeTypeInstance>(ent_attr_type);

		// Call template base class method.
		add_instance_to_buffer(new_ent_attr_type_instance->get_GUID(), new_ent_attr_type_instance);

		return new_ent_attr_type_instance;
	}


	const std::size_t EntityAttributeTypeInstanceManager::get_entity_attribute_type_instance_count() const
	{
		// Call template base class method.
		return get_type_instance_count();
	}

	
	void EntityAttributeTypeInstanceManager::delete_all_entity_attribute_type_instances()
	{
		// Call template base class method.
		delete_all_type_instances();
	}


};
};
