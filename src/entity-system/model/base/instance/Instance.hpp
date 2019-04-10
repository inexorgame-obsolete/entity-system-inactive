#pragma once

#include <string>
#include <memory>
#include <mutex>

namespace inexor {
namespace entity_system {

	/// @brief A template base class for instances.
	/// @param T The type of the instance.
	template <typename T> class InstanceBase
	{
		private:

			/// A pointer to the type of this type instance.
			std::shared_ptr<T> type_pointer;

			/// Mutex for this instance base class.
			std::mutex instance_base_mutex;

		protected:

			///
			std::shared_ptr<T> get_type() const
			{
				// Read only, no mutex required.
				return type_pointer;
			}

		public:

			/// Constructor.
			InstanceBase(const std::shared_ptr<T>& type_ptr)
			{
				// Use lock guard to ensure thread safety for this write operation!
				std::lock_guard<std::mutex> lock(instance_base_mutex);
				type_pointer = type_ptr;
			}

			/// Destructor.
			~InstanceBase()
			{
			}

	};

};
};
