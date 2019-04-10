#include "EntityAttributeTypeManager.hpp"

namespace inexor {
namespace entity_system {

	EntityAttributeTypeManager::EntityAttributeTypeManager() : TypeManagerTemplate()
	{
	}

	EntityAttributeTypeManager::~EntityAttributeTypeManager()
	{
	}

	bool EntityAttributeTypeManager::does_entity_attribute_type_exist(const std::string& ent_attr_type_name)
	{
		// Call template base class method.
		return does_type_exist(ent_attr_type_name);
	}

	bool EntityAttributeTypeManager::does_entity_attribute_type_exist(const EntityAttributeTypePtr& ent_attr_type)
	{
		return does_entity_attribute_type_exist(ent_attr_type->get_type_name());
	}

	EntityAttributeTypePtrOpt EntityAttributeTypeManager::create_entity_attribute_type(const std::string& ent_attr_type_name, const DataType& ent_attr_type_datatype, const EnumSet<Feature>& ent_attr_type_features)
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
		EntityAttributeTypePtr new_ent_attr_type = std::make_shared<EntityAttributeType>(ent_attr_type_name, ent_attr_type_datatype, ent_attr_type_features);

		// Call template base class method.
		add_type(ent_attr_type_name, new_ent_attr_type->get_GUID(), new_ent_attr_type);

		return EntityAttributeTypePtrOpt { new_ent_attr_type };
	}

	EntityAttributeTypePtrOpt EntityAttributeTypeManager::create_entity_attribute_type(const xg::Guid& ent_attr_type_GUID, const std::string& ent_attr_type_name, const DataType& ent_attr_type_datatype, const EnumSet<Feature>& ent_attr_type_features)
	{
		if(! is_type_name_valid(ent_attr_type_name))
		{
			// This entity attribute type does already exist.
			// TODO: Throw error message.

			// Since we've not created a new entity attribute type we can
			// now return std::nullopt thanks to std::optional.
			return std::nullopt;
		}

		EntityAttributeTypePtr new_ent_attr_type = std::make_shared<EntityAttributeType>(ent_attr_type_name, ent_attr_type_datatype, ent_attr_type_features);

		return EntityAttributeTypePtrOpt {  };
	}

	/// Get an entity attribute type by name.
	/// @param ? ?
	EntityAttributeTypePtrOpt EntityAttributeTypeManager::get_entity_attribute_type(const std::string& type_name) const
	{
		/*
		if(does_type_exist(type_name))
		{
		//return std::optional<EntityAttributeTypePtr> {  };
		}
		*/
		return std::nullopt;
	}

	/// Get an entity attribute type by GUID.
	/// @param ? ?
	EntityAttributeTypePtrOpt EntityAttributeTypeManager::get_entity_attribute_type(const xg::Guid& type_GUID) const
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

	void EntityAttributeTypeManager::delete_entity_attribute_type(const EntityAttributeTypePtr& ent_attr_type)
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

}
}
