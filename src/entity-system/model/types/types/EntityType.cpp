// Inexor entity system
// (c)2018-2019 Inexor

#include "EntityType.hpp"


namespace inexor {
namespace entity_system {
    

    EntityType::EntityType(const std::string& ent_type_name) : TypeBase(ent_type_name)
    {
		// TODO: Implement!
    }


	EntityType::~EntityType()
	{
		// TODO: Implement!
	}
	

	bool EntityType::has_attribute_type(const std::string& ent_attr_type_name)
	{
        // Look through all linked entity attribute types.
        for(int i=0; i<entity_attribute_instances.size(); i++)
        {
            if(0 == entity_attribute_instances[i]->get_type_name().compare(ent_attr_type_name))
            {
                // Yes, this entity attribute type is
                // already linked to this entity type.
                return true;
            }
        }
        return false;
	}
	

	bool EntityType::has_attribute_type(const ENT_ATTR_TYPE& ent_attr_type)
	{
        // Read only, no mutex require.
		return has_attribute_type(ent_attr_type->get_type_name());
	}


	ENTSYS_RESULT EntityType::link_attribute_type(const ENT_ATTR_TYPE& ent_attr_type)
	{
        // Is the entity attribute type already linked to this entity type?
        if(! has_attribute_type(ent_attr_type->get_type_name()))
		{
			// Link entity attribute type to this entity type.
            // Use lock guard to ensure thread safety for this write operation!
            std::lock_guard<std::mutex> lock(entity_type_mutex);
            entity_attribute_instances.push_back(ent_attr_type);

            return ENTSYS_SUCCESS;
		}
		return ENTSYS_ERROR;
	}


	std::size_t EntityType::get_linked_attributes_count() const
	{
        // Read only, no mutex required.
        return entity_attribute_instances.size();
	}


	std::optional<std::vector<ENT_ATTR_TYPE>> EntityType::get_linked_attribute_types() const
	{
        if(0 == entity_attribute_instances.size())
        {
            // There are no linked entity attribute instances.
            return std::nullopt;
        }
        
        // Read only, no mutex required.
        return std::optional<std::vector<ENT_ATTR_TYPE>> { entity_attribute_instances };
	}


	void EntityType::reset_linked_attribute_types()
	{
        // Use lock guard to ensure thread safety for this write operation!
        std::lock_guard<std::mutex> lock(entity_type_mutex);
        entity_attribute_instances.clear();
	}


	ENTSYS_DATA_VALIDATION_RESULT EntityType::validate()
	{
		// TODO: Implement!
		return ENTSYS_DATA_VALID;
	}


};
};
