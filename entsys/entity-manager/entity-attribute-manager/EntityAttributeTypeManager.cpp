// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityAttributeTypeManager.hpp"
#include "../../EntitySystem.hpp"


namespace inexor {
namespace entity_system {


	extern std::shared_ptr<EntitySystem> entsys;


    EntityAttributeTypeManager::EntityAttributeTypeManager()
    {
		entity_attribute_type_error = std::make_shared<EntityAttributeType>("ERROR", ENTSYS_DATA_TYPE_UNDEFINED);
    }


    EntityAttributeTypeManager::~EntityAttributeTypeManager()
    {
		// TODO: Implement!
    }


	bool EntityAttributeTypeManager::does_entity_attribute_type_exist(const std::string& ent_attr_type_name)
	{
		// Call template base class method.
		return does_type_exist(ent_attr_type_name);
	}


	bool EntityAttributeTypeManager::does_entity_attribute_type_exist(const ENT_ATTR_TYPE& ent_attr_type)
	{
		return does_entity_attribute_type_exist(ent_attr_type->get_type_name());
	}


	ENT_ATTR_TYPE EntityAttributeTypeManager::create_entity_attribute_type(const std::string& ent_attr_type_name,
                                                                           const ENTSYS_DATA_TYPE& ent_attr_data_type)
	{
		// Check if entity attribute type's name is not empty.
		if(! is_new_type_name_valid(ent_attr_type_name)) return entity_attribute_type_error;

		// Create entity attribute type.
		ENT_ATTR_TYPE new_ent_attr_type = entsys->create_entity_attribute_type(ent_attr_type_name, ent_attr_data_type);
		
		// Call template base class method.
		add_type_to_map(ent_attr_type_name, new_ent_attr_type);

		return new_ent_attr_type;
	}


	const std::size_t EntityAttributeTypeManager::get_entity_attribute_type_count() const
	{
		// Call template base class method.
		return get_type_count();
	}


	void EntityAttributeTypeManager::delete_entity_attribute_type(const std::string& ent_attr_type)
	{
		// Call template base class method.
		delete_type(ent_attr_type);
	}


	void EntityAttributeTypeManager::delete_entity_attribute_type(const ENT_ATTR_TYPE& ent_attr_type)
	{
		// Call template base class method.
		delete_type(ent_attr_type->get_type_name());
	}


	void EntityAttributeTypeManager::delete_all_entity_attribute_types()
	{
		// Call template base class method.
		delete_all_types();
	}


};
};
