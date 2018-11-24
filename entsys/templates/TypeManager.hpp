// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include <unordered_map>
#include <memory>

// When using template classes it is not possible
// to separate definitions of class methods from their declaration.
// This is the reason why there is no cpp file for this header file!


namespace inexor {
namespace entity_system {


	// A template class for type manager classes.
	// This will be used for EntityTypeManager,
	// EntityAttributeTypeManager, EntityRelationTypeManager.
	template <typename T>
	class TypeManager
	{
		private:

			// This unordered map will store all available types in a key/value pair.
			std::unordered_map<std::string, std::shared_ptr<T>> type_map;

		protected:

			// All of those methods must be protected since the
			// actual implementation of the type manager class
			// will contain a method which has an individual name
			// but calls back to those methods here.
			

			// 
			TypeManager()
			{
			}


			// 
			~TypeManager()
			{
			}


			//
			bool does_type_exist(const std::string& type_name)
			{
				// TODO: Add MUTEX here?
				return ! (type_map.end() == type_map.find(type_name));
			}
			

			// TODO: Does type exist by UUID?


			// 
			bool is_new_type_name_valid(const std::string& type_name)
			{
				if(0 == type_name.compare("")) return false;
				if(does_type_exist(type_name)) return false;
				return true;
			}


			// Add a new type to the type map.
			void add_type_to_map(const std::string& type_name, const std::shared_ptr<T>& new_type)
			{
				// TODO: Add MUTEX here!
				type_map[type_name] = new_type;
			}


			// Return a certain type by name.
			const std::shared_ptr<T> get_type(const std::string& type_name)
			{
				return type_map[type_name];
			}


			// TODO: Get by UUI!


			// Get the number of existing types.
			const std::size_t get_type_count() const
			{
				return type_map.size();
			}


			// Delete a specific type.
			void delete_type(const std::string& type_name)
			{
				// TODO: Add MUTEX here!
				// TODO: Delete all instances first!
				type_map.erase(type_name);
			}
			

			// TODO: Delete by UUID!


			// Delete all types.
			void delete_all_types()
			{
				// TODO: Add MUTEX here!
				// TODO: Delete all instances first!
				type_map.clear();
			}


	};


};
};
