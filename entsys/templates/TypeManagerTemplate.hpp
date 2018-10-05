// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include <unordered_map>
#include <memory>

namespace inexor {
namespace entity_system {

	// When using template classes it is not possible
	// to separate definitions of class methods from their declaration.

	// A class template for type manager classes.
	// This will be used for EntityTypeManager,
	// EntityAttributeTypeManager, EntityRelationTypeManager.
	template <typename T>
	class TypeManagerTemplate
	{
		public:

			// 
			TypeManagerTemplate()
			{
				error_type = std::make_shared<T>(std::string("ERROR"));
			}


			// 
			~TypeManagerTemplate()
			{
			}


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
			// TODO: Discuss this. Is there no better way to do this? Do not use exceptions!
			std::shared_ptr<T> error_type;


			//
			bool does_type_exist(const std::string& type_name)
			{
				return !(type_map.end() == type_map.find(type_name));
			}
			

			// 
			bool is_new_type_name_valid(const std::string& param_new_type_name)
			{
				if (0 == param_new_type_name.compare("")) return false;
				if (does_type_exist(param_new_type_name)) return false;
				return true;
			}


			//
			void add_type_to_map(const std::string& new_type_name, const std::shared_ptr<T>& new_type)
			{
				type_map[new_type_name] = new_type;
			}


			// 
			const std::shared_ptr<T> get_type(const std::string& param_type_name)
			{
				return type_map[param_type_name];
			}


			// 
			const std::size_t get_type_count() const
			{
				return type_map.size();
			}


			// 
			void delete_type(const std::string& param_name)
			{
				type_map.erase(param_name);
			}
			

			// 
			void delete_all_types()
			{
				type_map.clear();
			}


	};


};
};
