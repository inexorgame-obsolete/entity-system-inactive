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
	/// @param T The type for this instance manager.
	template <typename T> class InstanceManagerTemplate
	{
		private:

			// A map of stored instances.
			std::unordered_map<xg::Guid, std::shared_ptr<T>> stored_instances;

			// Mutex for this base class.
			std::mutex instance_manager_mutex;

		protected:

			/// Constructor.
			InstanceManagerTemplate()
			{
			}

			/// Destructor.
			~InstanceManagerTemplate()
			{
			}


			/// @brief Adds an instance to the instance buffer.
			/// @param instance_GUID The GUID of the instance.
			/// @param instance The instance which will be added.
			void add_instance(const xg::Guid instance_GUID, const std::shared_ptr<T>& instance)
			{
				// Use lock guard to ensure thread safety during write operations!
				std::lock_guard<std::mutex> lock(instance_manager_mutex);

				// TODO: But what if the instance does already exist?
				stored_instances[instance_GUID] = instance;
			}
			

			/// Checks if an instance does already exist.
			/// @param instance_GUID The GUID of the instance.
			/// @return True of the instance exists, false otherwise.
			bool does_instance_exist(const xg::Guid instance_GUID)
			{
				// No mutex required as this is a read-only operation.
				return !(stored_instances.end() == stored_instances.find(instance_GUID));
			}


			/// @brief Returns the number of existing instances.
			/// @return The number of existing instances.
			std::size_t get_instance_count() const
			{
				// No mutex required as this is a read-only operation.
				return stored_instances.size();
			}



			/// @brief Returns a specific instance.
			/// @param instance_GUID The GUID of the instance.
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


			/// @brief Deletes a specific instance
			/// @param instance_GUID The GUID of the instance which should be deleted!
			std::size_t delete_instance(const xg::Guid& instance_GUID)
			{
				// Use lock guard to ensure thread safety for this write operation!
				std::lock_guard<std::mutex> lock(instance_manager_mutex);

				// Erase the instance.
				return stored_instances.erase(instance_GUID);
			}


			/// @brief Deletes a specific instance.
			/// @param instance The instance which will be deleted.
			std::size_t delete_instance(const std::shared_ptr<T>& instance)
			{
				return delete_instance(get_GUID_from_instance(instance));
			}


			/// Deletes all instances.
			void delete_all_instances()
			{
				// Use lock guard to ensure thread safety for this write operation!
				std::lock_guard<std::mutex> lock(instance_manager_mutex);
				stored_instances.clear();
			}

			/// TODO: Get all instances of a certain type.

	};

}
}
