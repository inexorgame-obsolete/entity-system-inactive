// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include <string>
#include <unordered_map>
#include <memory>

// When using template classes it is not possible
// to separate definitions of class methods from their declaration.
// This is the reason why there is no cpp file for this header file!


namespace inexor {
namespace entity_system {


	/// A template base class
	/// for type manager classes.
	template <typename T>
	class TypeManagerTemplate
	{
		private:

			// TODO: Store by UUID, not by name!

			/// An unordered map which stores all available types.
			std::unordered_map<std::string, std::shared_ptr<T>> type_map;

		protected:

			// All of those methods must be protected since the
			// actual implementation of the type manager class
			// will contain a method which has an individual name
			// but calls back to those base class methods here.


			/// Constructor.
			TypeManagerTemplate()
			{
			}


			/// Destructor.
			~TypeManagerTemplate()
			{
			}


			/// Checks if a type already exists.
			/// @param type_name The name of the type.
			/// @return True if a type with this name
			/// does already exist, false otherwise.
			bool does_type_exist(const std::string& type_name)
			{
				// TODO: Add MUTEX here?
				return ! (type_map.end() == type_map.find(type_name));
			}


			// TODO: Does type exist by UUID?


			/// Checks if the name of a type is valid.
			/// @param type_name The name of the type.
			/// @return True if the name is valid, false otherwise.
			bool is_type_name_valid(const std::string& type_name)
			{
				if(0 == type_name.compare("")) return false;
				if(does_type_exist(type_name)) return false;
				return true;
			}


			/// Adds a new type.
			/// @param type_name The name of the new type.
			/// @param new_type A shared pointer reference to the new type.
			void add_type_to_map(const std::string& type_name, const std::shared_ptr<T>& new_type)
			{
				// TODO: Add MUTEX here!
				type_map[type_name] = new_type;
			}


			/// Searches for the desired type by name and returns it.
			/// @param type_name the name of the type to search for.
			/// @return A const shared pointer to the type.
			const std::shared_ptr<T> get_type(const std::string& type_name)
			{
				return type_map[type_name];
			}


			// TODO: Get by UUI!


			/// Returns the number of existing types.
			/// @return The number of existing types.
			const std::size_t get_type_count() const
			{
				return type_map.size();
			}


			/// Deletes a specific type.
			/// @param type_name The name of the type which will be deleted.
			void delete_type(const std::string& type_name)
			{
				// TODO: Add MUTEX here!
				// TODO: Delete all instances first!
				type_map.erase(type_name);
			}


			// TODO: Delete by UUID!


			/// Deletes all types.
			void delete_all_types()
			{
				// TODO: Add MUTEX here!
				// TODO: Delete all instances first!
				type_map.clear();
			}


	};


};
};
