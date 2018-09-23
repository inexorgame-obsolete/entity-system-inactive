// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityTypeInstance.hpp"


namespace inexor {
namespace entity_system {


	EntityTypeInstance::EntityTypeInstance()
	{
		// TODO: Implement!
	}


	EntityTypeInstance::EntityTypeInstance(const std::shared_ptr<EntityType>& param_entity_type)
	{
		// Reserve a pointer to the entity type 
		// base type of this entity type instance.
		linked_entity_type = param_entity_type;

		// Create entity attribute type instances for this entiy type instance!
		/*
		std::vector<std::shared_ptr<EntityAttributeType>> linked_entity_attribute_types = param_entity_type->get_linked_attribute_types();
		for(std::size_t i = 0; i< linked_entity_attribute_types.size(); i++)
		{
			// Create an entity attribute type instance and store it in the map.
			linked_entity_attribute_type_instances[linked_entity_attribute_types[i]] = std::make_shared<EntityAttributeTypeInstance>();
		}
		*/
	}


	EntityTypeInstance::~EntityTypeInstance()
	{
		// Call constructors of associated
		// entity attribute type instances
		// when destroying entity type instance.
		// Loop through std::map using range-based loop.
		// No need for std::const_iterator, C++11 rocks!
		/*
		for(const auto& map_pair : linked_entity_attribute_type_instances)
		{
			// TODO: Debug!
			map_pair.second->~EntityAttributeTypeInstance();
		}
		*/
	}


	void EntityTypeInstance::set_attribute_data(const std::shared_ptr<EntityAttributeType>& param_entity_attribute_type,
		                                        const int& param_int_data)
	{
		linked_entity_attribute_type_instances[param_entity_attribute_type]->set(param_int_data);
	}

	void EntityTypeInstance::set_attribute_data(const std::shared_ptr<EntityAttributeType>& param_entity_attribute_type, const bool& param_bool_data)
	{
		linked_entity_attribute_type_instances[param_entity_attribute_type]->set(param_bool_data);
	}


	void EntityTypeInstance::set_attribute_data(const std::shared_ptr<EntityAttributeType>& param_entity_attribute_type, const float& param_float_data)
	{
		linked_entity_attribute_type_instances[param_entity_attribute_type]->set(param_float_data);
	}


	void EntityTypeInstance::set_attribute_data(const std::shared_ptr<EntityAttributeType>& param_entity_attribute_type, const double& param_double_data)
	{
		linked_entity_attribute_type_instances[param_entity_attribute_type]->set(param_double_data);
	}


	void EntityTypeInstance::set_attribute_data(const std::shared_ptr<EntityAttributeType>& param_entity_attribute_type, const std::string& param_string_data)
	{
		linked_entity_attribute_type_instances[param_entity_attribute_type]->set(param_string_data);
	}


	void EntityTypeInstance::set_attribute_data(const std::shared_ptr<EntityAttributeType>& param_entity_attribute_type, const std::int64_t& param_int64t_data)
	{
		linked_entity_attribute_type_instances[param_entity_attribute_type]->set(param_int64t_data);
	}


	// Get methods for attribute data.
	// TODO: Inherit them directly from DataContainer ?
	const int EntityTypeInstance::get_attribute_data_int(const std::shared_ptr<EntityAttributeType>& param_entity_attribute_type) const
	{
		// TODO: Why does the [] operator not work here ?
		return linked_entity_attribute_type_instances.at(param_entity_attribute_type)->get_int();
	}


	const bool EntityTypeInstance::get_attribute_data_bool(const std::shared_ptr<EntityAttributeType>& param_entity_attribute_type) const
	{
		return linked_entity_attribute_type_instances.at(param_entity_attribute_type)->get_bool();
	}


	const float EntityTypeInstance::get_attribute_data_float(const std::shared_ptr<EntityAttributeType>& param_entity_attribute_type) const
	{
		return linked_entity_attribute_type_instances.at(param_entity_attribute_type)->get_float();
	}


	const double EntityTypeInstance::get_attribute_data_double(const std::shared_ptr<EntityAttributeType>& param_entity_attribute_type) const
	{
		return linked_entity_attribute_type_instances.at(param_entity_attribute_type)->get_double();
	}


	const std::string EntityTypeInstance::get_attribute_data_string(const std::shared_ptr<EntityAttributeType>& param_entity_attribute_type) const
	{
		return linked_entity_attribute_type_instances.at(param_entity_attribute_type)->get_string();
	}


	const std::int64_t EntityTypeInstance::get_attribute_data_int64(const std::shared_ptr<EntityAttributeType>& param_entity_attribute_type) const
	{
		return linked_entity_attribute_type_instances.at(param_entity_attribute_type)->get_int64();
	}


	ENTSYS_DATA_VALIDATION_RESULT EntityTypeInstance::validate()
	{
		return ENTSYS_DATA_INVALID;
	}


};
};
