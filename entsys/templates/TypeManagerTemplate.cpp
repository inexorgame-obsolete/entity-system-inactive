// Inexor entity system prototype
// (c)2018 Inexor

#include "TypeManagerTemplate.hpp"

namespace inexor {
namespace entity_system {


	template <typename T>
	TypeManagerTemplate<T>::TypeManagerTemplate()
	{
		error_type = std::make_shared<T>(std::string("ERROR"));
	}


	template <typename T>
	TypeManagerTemplate<T>::~TypeManagerTemplate()
	{
	}


	template <typename T>
	bool TypeManagerTemplate<T>::does_type_exist(const std::string& type_name)
	{
		return !(type_map.end() == type_map.find(type_name));
	}

	
	/*
	template <typename T>
	std::shared_ptr<T> TypeManagerTemplate<T>::create_and_add_type(const std::string& new_name)
	{
		// Check if type with this name does already exist
		if (does_type_exist(new_name))
		{
			// This type does already exist
			return error_type;
		}

		if (0 == new_name.compare(std::string("")))
		{
			// This type does already exist
			return error_type;
		}

		// TODO: Add further validation here

		// Create new type by making a standard constructor call.
		std::shared_ptr<T> new_type = std::make_shared<T>(new_name);

		// Add new type to the type map.
		type_map[new_name] = new_type;

		// Return type
		return new_type;
	}
	*/


	template <typename T>
	const std::shared_ptr<T> TypeManagerTemplate<T>::get_type(const std::string& param_name)
	{
		return type_map[param_name];
	}


	template <typename T>
	void TypeManagerTemplate<T>::delete_type(const std::string& param_name)
	{
		// TODO: Delete all instances!!
		type_map.erase(param_name);
	}


	template <typename T>
	void TypeManagerTemplate<T>::delete_all_types()
	{
		type_map.clear();
	}
	

	template <typename T>
	const std::size_t TypeManagerTemplate<T>::get_type_count() const
	{
		return type_map.size();
	}


};
};
