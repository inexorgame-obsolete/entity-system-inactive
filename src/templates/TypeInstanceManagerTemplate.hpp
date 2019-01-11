// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include <vector>
#include <memory>
#include <mutex>


// When using template classes it is not possible
// to separate definitions of class methods from their declaration.
// This is the reason why there is no cpp file for this header file!


namespace inexor {
namespace entity_system {


	/// @brief A template base class
	/// for instance manager classes.
	/// @param T The type for this type instance manager.
	template <typename T>
	class TypeInstanceManagerTemplate
	{
		private:

			// 
			std::unordered_map<xg::Guid, std::shared_ptr<T>> stored_type_instances;
			
			// This error instance will be returned when a method fails.
			// It will be set when the constructor is called
			std::shared_ptr<T> error_instance;

			// 
			std::mutex type_instance_manager_mutex;

		protected:
			
			/// 
			TypeInstanceManagerTemplate(const std::shared_ptr<T>& param_error_inst)
			{
				// Use lock guard to ensure thread safety for this write operation!
				std::lock_guard<std::mutex> lock(type_instance_manager_mutex);
				error_instance = param_error_inst;
			}


			/// Adds an instance to the instance buffer.
			/// @param type_instance The instance which will be added.
			void add_instance_to_buffer(const xg::Guid type_GUID, std::shared_ptr<T>& type_instance)
			{
				// Use lock guard to ensure thread safety for this write operation!
				std::lock_guard<std::mutex> lock(type_instance_manager_mutex);
				stored_type_instances[type_GUID] = type_instance;
			}


			/// Returns the number of existing instances.
			/// @return The number of existing instances.
			const std::size_t get_type_instance_count() const
			{
				// Read only, no mutex required.
				return stored_type_instances.size();
			}


			/// Deletes all instances.
			void delete_all_type_instances()
			{
				// Use lock guard to ensure thread safety for this write operation!
				std::lock_guard<std::mutex> lock(type_instance_manager_mutex);
				stored_type_instances.clear();
			}


			/// 
			void delete_instance(const xg::Guid& type_GUID)
			{
				// Use lock guard to ensure thread safety for this write operation!
				std::lock_guard<std::mutex> lock(type_instance_manager_mutex);
				// Erase the instance.
				stored_type_instances.erase(type_GUID);
			}


			// TODO: Get instance by UUID.
			std::shared_ptr<T> get_instance(const xg::Guid&)
			{
				// Read only, no mutex required.
				return error_instance;
			}
			
	};


};
};
