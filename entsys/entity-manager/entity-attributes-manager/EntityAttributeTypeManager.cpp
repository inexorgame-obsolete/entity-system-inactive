// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityAttributeTypeManager.hpp"


namespace inexor {
namespace entity_system {


    EntityAttributeTypeManager::EntityAttributeTypeManager()
    {
		// TODO: Implement!
    }


    EntityAttributeTypeManager::~EntityAttributeTypeManager()
    {
		// TODO: Implement!
    }


	bool EntityAttributeTypeManager::does_entity_attribute_type_exist(const std::string& param_entity_attribute_type_name)
	{
		// Returns false is entity attribute type does not already exist.
		return !(entity_attribute_type_buffer_map.end() == entity_attribute_type_buffer_map.find(param_entity_attribute_type_name));
	}


	std::shared_ptr<EntityAttributeType> EntityAttributeTypeManager::create_entity_attribute_type(
		const std::string& param_ent_attr_type_name, const ENTSYS_DATA_TYPE& param_ent_attr_data_type)
	{
		std::shared_ptr<EntityAttributeType> new_ent_attr_type = std::make_shared<EntityAttributeType>(param_ent_attr_type_name, param_ent_attr_data_type);
		entity_attribute_type_buffer_map[param_ent_attr_type_name] = new_ent_attr_type;
		return new_ent_attr_type;
	}


	const std::size_t EntityAttributeTypeManager::get_entity_attribute_type_count() const
	{
		return entity_attribute_type_buffer_map.size();
	}


	ENTSYS_RESULT EntityAttributeTypeManager::delete_entity_attribute_type(const std::string& param_entity_attribute_type)
	{
		// TODO: [CRITICAL] Remove all instances of
		// this entity attribute type before removing the entity attribute type itself!
		entity_attribute_type_buffer_map.erase(param_entity_attribute_type);
		return ENTSYS_SUCCESS;
	}


	ENTSYS_RESULT EntityAttributeTypeManager::delete_entity_attribute_type(const std::shared_ptr<EntityAttributeType>& param_entity_attribute_type)
	{
		// TODO: [CRITICAL] Remove all instances of
		// this entity attribute type before removing
		// the entity attribute type itself!
		delete_entity_attribute_type(param_entity_attribute_type->get_entity_attribute_type_name());
		return ENTSYS_SUCCESS;
	}


	ENTSYS_DATA_VALIDATION_RESULT EntityAttributeTypeManager::validate_attribute_types(const std::vector<std::shared_ptr<EntityAttributeType>>& param_entity_attribute_types)
	{
		ENTSYS_DATA_VALIDATION_RESULT temp_data_validation;

		// Loop through all linked entity attribut types and validate their data.
		for(std::size_t i=0; i<param_entity_attribute_types.size(); i++)
		{		
			temp_data_validation = param_entity_attribute_types[i]->validate();
			if(ENTSYS_DATA_VALID != temp_data_validation) return temp_data_validation;
		}
		return ENTSYS_DATA_VALID;
	}


};
};
