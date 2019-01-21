// Inexor entity system
// (c)2018-2019 Inexor

#include "RelationAttributeTypeManager.hpp"


namespace inexor {
namespace entity_system {

	
	RelationAttributeTypeManager::RelationAttributeTypeManager() : TypeManagerTemplate()
	{
		// TODO: Implement!
	}
	
	
	RelationAttributeTypeManager::~RelationAttributeTypeManager()
	{
		// TODO: Implement!
	}


	std::optional<REL_ATTR_TYPE> RelationAttributeTypeManager::create_relation_attribute_type(const std::string& rel_attr_type_name, const ENTSYS_DATA_TYPE& rel_attr_data_type)
	{
		// Check if an entity relation attribute type
		// with this name does already exist.
		if(! is_type_name_valid(rel_attr_type_name))
		{
			// This entity relation attribute type does already exist.
			// TODO: Throw error message.

            // Since we've not created a new entity relation attribute type
            // we can now return std::nullopt thanks to std::optional.
			return std::nullopt;
		}

		// Create new entity relation attribute type
		REL_ATTR_TYPE new_rel_attr_type = std::make_shared<RelationAttributeType>(rel_attr_type_name, rel_attr_data_type);

        // 
		add_type(rel_attr_type_name, new_rel_attr_type);

        return std::optional<REL_ATTR_TYPE> { new_rel_attr_type };
	}


	std::size_t RelationAttributeTypeManager::get_relation_attribute_type_count() const
	{
		// Call base class method.
		return get_type_count();
	}


	void RelationAttributeTypeManager::delete_all_relation_attribute_types()
	{
		// Call base class method.
		delete_all_types();
	}


};
};
