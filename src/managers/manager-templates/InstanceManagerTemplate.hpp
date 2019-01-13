// Inexor entity system prototype
// (c)2018-2019 Inexor

#pragma once

#include <vector>
#include <memory>
#include <mutex>
#include <unordered_map>
#include <crossguid/guid.hpp>


// When using template classes it is not possible
// to separate definitions of class methods from their declaration.
// This is the reason why there is no cpp file for this header file!


namespace inexor {
namespace entity_system {


	/// @brief A template base class
	/// for instance manager classes.
	/// @param T The type for this type instance manager.
	template <typename T> class InstanceManagerTemplate
	{
		private:

            // 
            std::unordered_map<xg::Guid, std::shared_ptr<T>> stored_instances;

			// This error instance will be returned when a method fails.
			// It will be set when the constructor is called
			std::shared_ptr<T> error_instance;

			// 
			std::mutex type_instance_manager_mutex;

		protected:
			
			/// Constructor. 
			InstanceManagerTemplate(const std::shared_ptr<T>& param_error_inst)
			{
				// Use lock guard to ensure thread safety for this write operation!
				std::lock_guard<std::mutex> lock(type_instance_manager_mutex);
				error_instance = param_error_inst;
			}


            /// Destructor.
            ~InstanceManagerTemplate()
            {
                // TODO: Implement
            }


			/// Adds an instance to the instance buffer.
			/// @param type_instance The instance which will be added.
			void add_instance(const xg::Guid type_GUID, std::shared_ptr<T>& instance)
			{
				// Use lock guard to ensure thread safety for this write operation!
				std::lock_guard<std::mutex> lock(type_instance_manager_mutex);
				stored_instances[type_GUID] = instance;
			}


            /// Checks if an instance does already exist.
            /// @param instance_GUID The GUID of the instance.
            bool does_instance_exist(const xg::Guid instance_GUID)
            {
                // Read only, no mutex required.
				return !(stored_instances.end() == stored_instances.find(instance_GUID));
            }


			/// Returns the number of existing instances.
			/// @return The number of existing instances.
			const std::size_t get_instance_count() const
			{
				// Read only, no mutex required.
				return stored_instances.size();
			}

            
            // TODO: Get all instances of a certain type!


            /// Returns a specific instance.
            /// @param type_GUID The GUID of the instance.
			std::shared_ptr<T> get_instance(const xg::Guid& type_GUID)
			{
                // Check if an instance with this GUID exists.
                if(does_instance_exist(type_GUID))
                {
                    // An instance with this GUID exists!
                    return stored_instances[type_GUID];
                }
                // If it does not exist, return error instance!
                return error_instance;
			}


			/// Deletes a specific instance
            /// @param type_GUID The GUID of the instance which should be deleted!
			void delete_instance(const xg::Guid& type_GUID)
			{
				// Use lock guard to ensure thread safety for this write operation!
				std::lock_guard<std::mutex> lock(type_instance_manager_mutex);
				// Erase the instance.
				stored_instances.erase(type_GUID);
			}

            
            /// Deletes all instances.
			void delete_all_instances()
			{
				// Use lock guard to ensure thread safety for this write operation!
				std::lock_guard<std::mutex> lock(type_instance_manager_mutex);
				stored_instances.clear();
			}

			
	};


};
};
