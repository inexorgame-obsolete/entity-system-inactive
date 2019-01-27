// Inexor entity system
// (c)2018-2019 Inexor

#pragma once

#include <vector>
#include <memory>
#include <mutex>
#include <optional>
#include <unordered_map>
#include <crossguid/guid.hpp>


// When using template classes it is not possible
// to separate definitions of class methods from their declaration.
// This is the reason why there is no cpp file for this header file!


namespace inexor {
namespace entity_system {


    /// @class InstanceManagerTemplate
	/// @brief A template base class for instance manager classes.
	/// @param T The type for this type instance manager.
	template <typename T> class InstanceManagerTemplate
	{
		private:

            // A map of stored instances.
            std::unordered_map<xg::Guid, std::shared_ptr<T>> stored_instances;

			// Mutex for this base class.
			std::mutex type_instance_manager_mutex;

		protected:
			
			/// @brief Constructor. 
			InstanceManagerTemplate()
			{
                // TODO: Implement!
			}


            /// @brief Destructor.
            ~InstanceManagerTemplate()
            {
                // TODO: Implement!
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
            /// @return True of the instance exists, false otherwise.
            bool does_instance_exist(const xg::Guid instance_GUID)
            {
                // TODO: Refactor this when C++20 comes out!
                // Read only, no mutex required.
				return !(stored_instances.end() == stored_instances.find(instance_GUID));
            }


			/// Returns the number of existing instances.
			/// @return The number of existing instances.
			std::size_t get_instance_count() const
			{
				// Read only, no mutex required.
				return stored_instances.size();
			}

            
            // TODO: Get all instances of a certain type!


            /// @brief Returns a specific instance.
            /// @param type_GUID The GUID of the instance.
            /// @return If the instance exists it will be returned, std::nullopt otherwise.
			std::optional<std::shared_ptr<T>> get_instance(const xg::Guid& instance_GUID)
			{
                // Check if an instance with this GUID exists.
                auto lookup = stored_instances.find(instance_GUID);

                // We've found a key value pair!
                if(!(stored_instances.end() == lookup))
                {
                    return std::optional<std::shared_ptr<T>>{ lookup->second };
                }
                // We've found nothing!
                return std::nullopt;
            }


            /// @brief Looks up the GUID of an instance.
            /// @param type_inst The instance of which we need the GUID.
            /// @return The GUID of the instance.
            std::optional<xg::Guid> get_GUID_from_instance(const std::shared_ptr<T>& type_inst)
            {
                if(does_instance_exist(type_inst))
                {
                    // Iterate through the unordered map and find the GUID of this type.
                    // TODO: Maybe implement ->get_GUID() method for T ?

                }
                return std::nullopt;
            }


			/// @brief Deletes a specific instance
            /// @param type_GUID The GUID of the instance which should be deleted!
			std::size_t delete_instance(const xg::Guid& type_GUID)
			{
				// Use lock guard to ensure thread safety for this write operation!
				std::lock_guard<std::mutex> lock(type_instance_manager_mutex);
				
                // Erase the instance.
				return stored_instances.erase(type_GUID);
			}

            
            /// @brief 
            std::size_t delete_instance(const std::shared_ptr<T>& type_ptr)
            {
				// Use lock guard to ensure thread safety for this write operation!
				std::lock_guard<std::mutex> lock(type_instance_manager_mutex);

                // Look up the GUID of the 
                xg::Guid instance_to_delete = get_instance(type_ptr);
                return delete_instance(instance_to_delete);
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
