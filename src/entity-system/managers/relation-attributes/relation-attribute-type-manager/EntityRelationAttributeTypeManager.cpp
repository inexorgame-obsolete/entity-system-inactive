// Inexor entity system
// (c)2018-2019 Inexor

#include "EntityRelationAttributeTypeManager.hpp"


namespace inexor {
namespace entity_system {

	
	EntityRelationAttributeTypeManager::EntityRelationAttributeTypeManager() : TypeManagerTemplate()
	{
		// TODO: Implement!
	}
	
	
	EntityRelationAttributeTypeManager::~EntityRelationAttributeTypeManager()
	{
		// TODO: Implement!
	}


	std::optional<ENT_REL_ATTR_TYPE> EntityRelationAttributeTypeManager::create_entity_relation_attribute_type(const std::string& ent_rel_attr_type_name, const ENTSYS_DATA_TYPE& ent_rel_attr_data_type)
	{
		// Check if an entity relation attribute type
		// with this name does already exist.
		if(! is_type_name_valid(ent_rel_attr_type_name))
		{
			// This entity relation attribute type does already exist.
			// TODO: Throw error message.

            // Since we've not created a new entity relation attribute type
            // we can now return std::nullopt thanks to std::optional.
			return std::nullopt;
		}

		// Create new entity relation attribute type
		ENT_REL_ATTR_TYPE new_ent_rel_attr_type = std::make_shared<EntityRelationAttributeType>(ent_rel_attr_type_name, ent_rel_attr_data_type);

        // 
		add_type(ent_rel_attr_type_name, new_ent_rel_attr_type);

        return std::optional<ENT_REL_ATTR_TYPE> { new_ent_rel_attr_type };
	}


	std::size_t EntityRelationAttributeTypeManager::get_entity_relation_attribute_type_count() const
	{
		// Call base class method.
		return get_type_count();
	}


	void EntityRelationAttributeTypeManager::delete_all_entity_relation_attribute_types()
	{
		// Call base class method.
		delete_all_types();
	}


};
};
