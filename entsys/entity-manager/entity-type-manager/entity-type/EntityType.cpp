// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityType.hpp"


namespace inexor {
namespace entity_system {
    

    EntityType::EntityType(const std::string& ent_type_name)
    {
		// Call template base class method.
		set_type_name(ent_type_name);
	}


	EntityType::~EntityType()
	{
	}
	

	bool EntityType::has_attribute_type(const std::string& ent_attr_type_name)
	{
		bool entity_attribute_type_found = false;

		std::string name1 = ent_attr_type_name;
		std::string name2 = "";

		for(std::size_t i=0; i<linked_objects.size(); i++)
		{
			name2 = linked_objects[i]->get_type_name();

			// Check if we can find the entity attribute type by name.
			// This would mean that it is already linked to this entity type!
			if(0 == name1.compare(name2))
			{
				entity_attribute_type_found = true;
				break;
			}
		}

		return entity_attribute_type_found;
	}
	

	bool EntityType::has_attribute_type(const std::shared_ptr<EntityAttributeType>& ent_attr_type)
	{
		return has_attribute_type(ent_attr_type->get_type_name());
	}


	ENTSYS_RESULT EntityType::link_attribute_type(const std::shared_ptr<EntityAttributeType>& ent_attr_type)
	{
		if(! has_attribute_type(ent_attr_type->get_type_name()))
		{
			// The entity attribute type is not already linked to this entity type.
			// Link entity attribute type to this entity type.
			// Call template base class method.
			add_linked_object(ent_attr_type);
			return ENTSYS_SUCCESS;
		}
		return ENTSYS_ERROR;
	}


	std::size_t EntityType::get_linked_attributes_count() const
	{
		// Call template base class method.
		return get_linked_objects_count();
	}


	const std::vector<std::shared_ptr<EntityAttributeType>> EntityType::get_linked_attribute_types() const
	{
		// Call template base class method.
		return get_linked_objects();
	}


	void EntityType::reset_linked_attribute_types()
	{
		// Call template base class method.
		delete_all_linked_objects();
	}


	ENTSYS_DATA_VALIDATION_RESULT EntityType::validate()
	{
		// TODO: Implement!
		return ENTSYS_DATA_VALID;
	}


};
};
