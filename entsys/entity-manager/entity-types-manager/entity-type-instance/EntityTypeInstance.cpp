// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityTypeInstance.hpp"
#include "../../../EntitySystem.hpp"


namespace inexor {
namespace entity_system {


	extern std::shared_ptr<EntitySystem> entsys;


	EntityTypeInstance::EntityTypeInstance(const std::shared_ptr<EntityType>& ent_type)
	{
		// 
		set_type_pointer(ent_type);
		// 
		set_type_name(ent_type->get_type_name());

		// Create entity attribute type instances for this entiy type instance!
		std::vector<std::shared_ptr<EntityAttributeType>> ent_type_attributes = ent_type->get_linked_attribute_types();

		for(std::size_t i = 0; i< ent_type_attributes.size(); i++)
		{
			// Create an entity attribute type instance and store it in the map.
			linked_attributes[ent_type_attributes[i]] = entsys->create_entity_attribute_type_instance(ent_type_attributes[i]);
		}
	}


	EntityTypeInstance::~EntityTypeInstance()
	{
		// Destroy instances of associated entity attribute types.
		// Loop through std::map using range-based loop.
		// No need for std::const_iterator, C++11 rocks!
		for(const auto& map_pair : linked_attributes)
		{
			// TODO: Debug!
			map_pair.second->~EntityAttributeTypeInstance();
		}
	}


	void EntityTypeInstance::set_attribute_data(const std::shared_ptr<EntityAttributeType>& ent_attr_type, const int& int_data)
	{
		linked_attributes[ent_attr_type]->set(int_data);
	}


	void EntityTypeInstance::set_attribute_data(const std::shared_ptr<EntityAttributeType>& ent_attr_type, const bool& bool_data)
	{
		linked_attributes[ent_attr_type]->set(bool_data);
	}


	void EntityTypeInstance::set_attribute_data(const std::shared_ptr<EntityAttributeType>& ent_attr_type, const float& float_data)
	{
		linked_attributes[ent_attr_type]->set(float_data);
	}


	void EntityTypeInstance::set_attribute_data(const std::shared_ptr<EntityAttributeType>& ent_attr_type, const double& double_data)
	{
		linked_attributes[ent_attr_type]->set(double_data);
	}


	void EntityTypeInstance::set_attribute_data(const std::shared_ptr<EntityAttributeType>& ent_attr_type, const std::string& string_data)
	{
		linked_attributes[ent_attr_type]->set(string_data);
	}


	void EntityTypeInstance::set_attribute_data(const std::shared_ptr<EntityAttributeType>& ent_attr_type, const std::int64_t& int64t_data)
	{
		linked_attributes[ent_attr_type]->set(int64t_data);
	}


	void EntityTypeInstance::get_attribute_data(const std::shared_ptr<EntityAttributeType>& ent_attr_type, int& int_ref)
	{
		int_ref = linked_attributes[ent_attr_type]->get_int();
	}


	void EntityTypeInstance::get_attribute_data(const std::shared_ptr<EntityAttributeType>& ent_attr_type, bool& bool_ref)
	{
		bool_ref = linked_attributes[ent_attr_type]->get_bool();
	}
	
	
	void EntityTypeInstance::get_attribute_data(const std::shared_ptr<EntityAttributeType>& ent_attr_type, float& float_ref)
	{
		float_ref = linked_attributes[ent_attr_type]->get_float();
	}
	

	void EntityTypeInstance::get_attribute_data(const std::shared_ptr<EntityAttributeType>& ent_attr_type, double& double_ref)
	{
		double_ref = linked_attributes[ent_attr_type]->get_double();
	}
	
	
	void EntityTypeInstance::get_attribute_data(const std::shared_ptr<EntityAttributeType>& ent_attr_type, std::string& string_ref)
	{
		string_ref = linked_attributes[ent_attr_type]->get_string();
	}


	void EntityTypeInstance::get_attribute_data(const std::shared_ptr<EntityAttributeType>& ent_attr_type, std::int64_t& int64_ref)
	{
		int64_ref = linked_attributes[ent_attr_type]->get_int64();
	}


};
};
