// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include <unordered_map>
#include <memory>

namespace inexor {
namespace entity_system {

	
	// A class template for type manager classes.
	// This will be used for EntityTypeManager,
	// EntityAttributeTypeManager, EntityRelationTypeManager.
	template <typename T>
	class TypeManagerTemplate
	{
		// All of those methods must be protected since the
		// actual implementation of the type manager class
		// will containt a method which has the right name
		// but calls back to those methods here.
		protected:

			// This unordered map will store all available types
			// in a key/value pair of name => type.
			std::unordered_map<std::string, std::shared_ptr<T>> type_map;

			// Error type.
			// This will be returned when a class method fails.
			// TODO: Discuss this. Is there no better way to do this?
			//       (Do not use exceptions either!)
			//std::shared_ptr<T> error_type;

			// 
			TypeManagerTemplate()
			{
			}


			// 
			~TypeManagerTemplate()
			{
			}


			//
			bool does_type_exist(const std::string& type_name)
			{
				return ! (type_map.end() == type_map.find(type_name));
			}

			/*
			// Because of the constructor call in std::make_shared this method
			// will might have to be overwritten when this class template gets inherited.
			// Unless we can call the standard constructor of <T> we are fine.
			virtual std::shared_ptr<T> create_and_add_type(const std::string& new_name)
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


			// TODO: Does this have to be of const type?
			const std::shared_ptr<T> get_type(const std::string& param_name)
			{
				return type_map[param_name];
			}

			// 
			void delete_type(const std::string& param_name)
			{
				// TODO: Delete all instances!!
				type_map.erase(param_name);
			}


			// 
			void delete_all_types()
			{
				type_map.clear();
			}


			// This implementation would require a T->get_name() method.
			//void delete_type(const std::shared_ptr<T>&);

			// 
			const std::size_t get_type_count() const
			{
				return type_map.size();
			}

	};


};
};
