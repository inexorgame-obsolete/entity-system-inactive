// Inexor entity system
// (c)2018-2019 Inexor

#include "EntityAttributeTypeManager.hpp"


namespace inexor {
namespace entity_system {


    EntityAttributeTypeManager::EntityAttributeTypeManager() : TypeManagerTemplate()
    {
		// TODO: Implement!
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


	O_ENT_ATTR_TYPE EntityAttributeTypeManager::create_entity_attribute_type(const std::string& ent_attr_type_name, const ENTSYS_DATA_TYPE& ent_attr_type_datatype)
	{
		// Check if entity attribute type's name is not empty.
		if(! is_type_name_valid(ent_attr_type_name))
		{
			// This entity attribute type does already exist.
			// TODO: Throw error message.
			
            // Since we've not created a new entity attribute type we can
            // now return std::nullopt thanks to std::optional.
            return std::nullopt;
		}

		// Create entity attribute type.
		ENT_ATTR_TYPE new_ent_attr_type = std::make_shared<EntityAttributeType>(ent_attr_type_name, ent_attr_type_datatype);
		
		// Call template base class method.
		add_type(ent_attr_type_name, new_ent_attr_type->get_GUID(), new_ent_attr_type);

        return O_ENT_ATTR_TYPE { new_ent_attr_type };
	}


	O_ENT_ATTR_TYPE EntityAttributeTypeManager::create_entity_attribute_type(const xg::Guid& ent_attr_type_GUID, const std::string& ent_attr_type_name, const ENTSYS_DATA_TYPE& ent_attr_type_datatype)
    {
        if(! is_type_name_valid(ent_attr_type_name))
        {
			// This entity attribute type does already exist.
			// TODO: Throw error message.

            // Since we've not created a new entity attribute type we can
            // now return std::nullopt thanks to std::optional.
            return std::nullopt;
        }

        ENT_ATTR_TYPE new_ent_attr_type = std::make_shared<EntityAttributeType>(ent_attr_type_name, ent_attr_type_datatype);

        return O_ENT_ATTR_TYPE {  };
    }


    /// Get an entity attribute type by name.
    /// @param ? ?
	O_ENT_ATTR_TYPE EntityAttributeTypeManager::get_entity_attribute_type(const std::string& type_name) const
    {
        /*
        if(does_type_exist(type_name))
        {
            //return std::optional<ENT_ATTR_TYPE> {  };
        }
        */
        return std::nullopt;
    }


    /// Get an entity attribute type by GUID.
    /// @param ? ? 
	O_ENT_ATTR_TYPE EntityAttributeTypeManager::get_entity_attribute_type(const xg::Guid& type_GUID) const
    {
        return std::nullopt;
    }


	std::size_t EntityAttributeTypeManager::get_entity_attribute_type_count() const
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

    
    void EntityAttributeTypeManager::delete_entity_attribute_type(const xg::Guid& type_GUID)
    {
        // Call template base class method.
        delete_type(type_GUID);
    }


	void EntityAttributeTypeManager::delete_all_entity_attribute_types()
	{
		// Call template base class method.
		delete_all_types();
	}


};
};
