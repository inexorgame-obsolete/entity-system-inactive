#pragma once

#include <string>
#include <unordered_map>
#include <memory>
#include <mutex>
#include <crossguid/guid.hpp>


// When using template classes it is not possible
// to separate definitions of class methods from their declaration.
// This is the reason why there is no cpp file for this header file!


namespace inexor {
namespace entity_system {

	/// @class TypeManagerTemplate
	/// @brief A template base class for type manager classes.
	template <typename T>
	class TypeManagerTemplate
	{
		private:

			/// An unordered map which stores all available
			/// type names as key and their corresponding GUID as value.
			std::unordered_map<std::string, xg::Guid> stored_type_names;

			/// An unordered map which stored all available
			/// GUIDs as key and their corresponding type names as value.
			std::unordered_map<xg::Guid, std::string> stored_type_GUIDs;

			/// An unordered map which stores all available types.
			std::unordered_map<xg::Guid, std::shared_ptr<T>> stored_types;

			/// The mutex for this base class.
			std::mutex type_manager_mutex;

	protected:

		// All of those methods must be protected since the
		// actual implementation of the type manager class
		// will contain a method which has an individual name
		// but calls back to those base class methods here.

		/// @brief Constructor.
		TypeManagerTemplate()
		{
		}

		/// @brief Destructor.
		~TypeManagerTemplate()
		{
		}

		/// @brief Checks if a type already exists.
		/// @param type_name The name of the type.
		/// @return True if a type with this name already exists, false otherwise.
		bool does_type_exist(const std::string& type_name)
		{
			// Get the GUID of this type by name.
			xg::Guid type_GUID = get_GUID_by_type_name(type_name);

			// Read only, no mutex required.
			return ! (stored_types.end() == stored_types.find(type_GUID));
		}


		/// @brief Checks if a type already exists.
		/// @param type_GUID The name of the type.
		/// @return True if a type with this name already exists, false otherwise.
		bool does_type_exist(const xg::Guid& type_GUID)
		{
			// Read only, no mutex required.
			return !(stored_types.end() == stored_types.find(type_GUID));
		}


		/// Checks if the name of a type is valid.
		/// @param type_name The name of the type.
		/// @return True if the name is valid, false otherwise.
		bool is_type_name_valid(const std::string& type_name)
		{
			if(0 == type_name.compare("")) return false;
			if(does_type_exist(type_name)) return false;
			// TODO: Add further validation methods here.
			return true;
		}


		/// Adds a new type.
		/// @param type_name The name of the new type.
		/// @param new_type A shared pointer reference to the new type.
		void add_type(const std::string& type_name, const xg::Guid& type_GUID, const std::shared_ptr<T>& new_type)
		{
			// Use lock guard to ensure thread safety for this write operation!
			std::lock_guard<std::mutex> lock(type_manager_mutex);

			stored_type_names[type_name] = type_GUID;
			stored_type_GUIDs[type_GUID] = type_name;
			stored_types[type_GUID] = new_type;
		}


		/// Returns the GUID of a type by name.
		/// @param type_name The name of the type.
		xg::Guid get_GUID_by_type_name(const std::string& type_name)
		{
			// Read only, no mutex required.
			return stored_type_names[type_name];
		}


		/// Returns the name of a type by given GUID.
		/// @param type_GUID The GUID of the type.
		std::string get_type_name_by_GUID(const xg::Guid& type_GUID)
		{
			// Read only, no mutex required.
			return stored_type_GUIDs[type_GUID];
		}


		/// Searches for the desired type by name and returns it.
		/// @param type_name the name of the type to search for.
		/// @return A const shared pointer to the type.
		std::shared_ptr<T> get_type(const std::string& type_name)
		{
			// Get the GUID of this type by name.
			xg::Guid type_GUID = get_GUID_by_type_name(type_name);

			// Read only, no mutex required.
			return stored_types[type_name];
		}


		/// Searches for the desired type by name.
		std::shared_ptr<T> get_type(const xg::Guid& type_GUID)
		{
			// Read only, no mutex required.
			return stored_types[type_GUID];
		}


		/// @brief Returns the number of existing types.
		/// @return The number of existing types.
		std::size_t get_type_count() const
		{
			// Read only, no mutex required.
			return stored_types.size();
		}


		/// @brief Deletes a specific type.
		/// @param type_name The name of the type which will be deleted.
		std::size_t delete_type(const std::string& type_name)
		{
			// Use lock guard to ensure thread safety for this write operation!
			std::lock_guard<std::mutex> lock(type_manager_mutex);

			xg::Guid type_GUID_to_delete = get_GUID_by_type_name(type_name);

			// Erase type name
			stored_type_names.erase(type_name);
			// Erase GUID
			stored_type_GUIDs.erase(type_GUID_to_delete);
			// Erase type
			std::size_t deleted_types = stored_types.erase(type_name);
			return deleted_types;
		}


		/// @brief Deletes a type by GUID.
		/// @param type_GUID The GUID of the type.
		std::size_t delete_type(const xg::Guid& type_GUID)
		{
			// We do not need a mutex for these read operations here.
			std::string type_name_to_delete = get_type_name_by_GUID(type_GUID);

			xg::Guid type_GUID_to_delete = get_GUID_by_type_name(type_name_to_delete);

			// Use lock guard to ensure thread safety for this write operations!
			std::lock_guard<std::mutex> lock(type_manager_mutex);

			// Erase type name
			stored_type_names.erase(type_name_to_delete);
			// Erase GUID
			stored_type_GUIDs.erase(type_GUID_to_delete);
			// Erase type
			std::size_t deleted_types = stored_types.erase(type_GUID);
			return deleted_types;
		}


		/// Deletes all types.
		/// At this point it must be made sure
		/// that all the type instances have been
		/// deleted first.
		void delete_all_types()
		{
			// Use lock guard to ensure thread safety for this write operation!
			std::lock_guard<std::mutex> lock(type_manager_mutex);

			// Erase type names
			stored_type_names.clear();
			// Erase GUIDs
			stored_type_GUIDs.clear();
			// Erase types
			stored_types.clear();
		}

	};

};
};
