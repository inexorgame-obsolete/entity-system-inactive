#include "EntityType.hpp"

namespace inexor {
namespace entity_system {

	EntityType::EntityType(const std::string& ent_type_name)
		: GUIDBase(),
		TypeBase(ent_type_name)
	{
	}

	EntityType::EntityType(const xg::Guid& ent_type_GUID, const std::string& ent_type_name)
		: GUIDBase(ent_type_GUID),
		TypeBase(ent_type_name)
	{
	}

	EntityType::~EntityType()
	{
	}

	bool EntityType::has_attribute_type(const std::string& ent_attr_type_name)
	{
		// Look through all linked entity attribute types.
		for(int i = 0; i < entity_attribute_types.size(); i++)
		{
			if(0 == entity_attribute_types[i]->get_type_name().compare(ent_attr_type_name))
			{
				// Yes, this entity attribute type is
				// already linked to this entity type.
				return true;
			}
		}
		// No, this entity attribute type is
		// not already linked to this entity type.
		return false;
	}

	bool EntityType::has_attribute_type(const xg::Guid& ent_attr_type_GUID)
	{
		// Look through all linked entity attribute types.
		for(int i = 0; i < entity_attribute_types.size(); i++)
		{
			// TODO: Does this even work? DEBUG!
			if (ent_attr_type_GUID == entity_attribute_types[i]->get_GUID())
			{
				// Yes, this entity attribute type is
				// already linked to this entity type.
				return true;
			}
		}
		// No, this entity attribute type is
		// not already linked to this entity type.
		return false;
	}

	bool EntityType::has_attribute_type(const EntityAttributeTypePtr& ent_attr_type)
	{
		// No mutex required as this is a read-only operation.
		return has_attribute_type(ent_attr_type->get_type_name());
	}

	ENTSYS_RESULT EntityType::link_attribute_type(const EntityAttributeTypePtr& ent_attr_type)
	{
		// Is the entity attribute type already linked to this entity type?
		if(!has_attribute_type(ent_attr_type->get_type_name()))
		{
			// Link entity attribute type to this entity type.
			// Use lock guard to ensure thread safety for this write operation!
			std::lock_guard<std::mutex> lock(entity_type_mutex);
			entity_attribute_types.push_back(ent_attr_type);
			return ENTSYS_SUCCESS;
		}
		return ENTSYS_ERROR;
	}

	std::size_t EntityType::get_linked_attributes_count() const
	{
		// No mutex required as this is a read-only operation.
		return entity_attribute_types.size();
	}

	std::optional<EntityAttributeTypePtrList> EntityType::get_linked_attribute_types() const
	{
		if(0 == entity_attribute_types.size())
		{
			// There are no linked entity attribute instances.
			return std::nullopt;
		}

		// No mutex required as this is a read-only operation.
		return std::optional<EntityAttributeTypePtrList> { entity_attribute_types };
	}

	void EntityType::reset_linked_attribute_types()
	{
		// Use lock guard to ensure thread safety during write operations!
		std::lock_guard<std::mutex> lock(entity_type_mutex);
		entity_attribute_types.clear();
	}

}
}
