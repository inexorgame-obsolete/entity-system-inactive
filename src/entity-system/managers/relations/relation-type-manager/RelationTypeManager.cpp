// Inexor entity system
// (c)2018-2019 Inexor

#include "RelationTypeManager.hpp"


namespace inexor {
namespace entity_system {


    RelationTypeManager::RelationTypeManager() : TypeManagerTemplate()
    {
		// TODO: Implement!
    }


    RelationTypeManager::~RelationTypeManager()
    {
		// TODO: Implement!
    }


	bool RelationTypeManager::does_relation_type_exist(const std::string& ent_rel_type_name)
	{
        // 
		return does_type_exist(ent_rel_type_name);
	}


	bool RelationTypeManager::does_relation_type_exist(const REL_TYPE& ent_rel_type)
	{
        // 
		return does_relation_type_exist(ent_rel_type->get_type_name());
	}


	std::optional<REL_TYPE> RelationTypeManager::create_relation_type(const std::string& rel_type_name, const ENT_TYPE& ent_type_source, const ENT_TYPE& ent_type_target)
	{
		// Validate new entity relation type name.
		if(!is_type_name_valid(rel_type_name))
		{
			// This entity relation type does already exist.
			// TODO: Throw error message.

            // Since we've not created a new entity relation type we can
            // now return std::nullopt thanks to std::optional.
            return std::nullopt;
		}

		// Create new entity relation type.
		REL_TYPE new_relation_type = std::make_shared<RelationType>(rel_type_name, ent_type_source, ent_type_target);

		// Add new entity relation type to type map.
		add_type(rel_type_name, new_relation_type);

        return std::optional<REL_TYPE> { new_relation_type };
	}


	std::size_t RelationTypeManager::get_relation_types_count() const
	{
        // 
		return get_type_count();
	}


	void RelationTypeManager::delete_relation_type(const std::string& rel_type_name)
	{
        // 
		delete_type(rel_type_name);
	}

	
	void RelationTypeManager::delete_relation_type(const REL_TYPE& rel_type)
	{
        // 
		return delete_relation_type(rel_type->get_type_name());
	}


	void RelationTypeManager::delete_all_relation_types()
	{
        // 
		delete_all_types();
	}


};
};
