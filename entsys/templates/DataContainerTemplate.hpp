// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include <memory>
#include <mutex>


namespace inexor {
namespace entity_system {


	// A template class for multi purpose data containers.
	template <typename T>
	class DataContainerTemplate
	{
		private:

			// Data container.
			T container_data;

			// Only one mutex lock per data container class!
			// TODO: Use shared_mutex ? Use profiler !!
			//std::mutex mutex_reference;

		protected:

			// 
			DataContainerTemplate(const T default_value)
			{
				// Lock mutex for thread-safety!
				//std::lock_guard<std::mutex> entsys_guard(parent_mutex);
				//mutex_reference = parent_mutex;
				container_data = default_value;
				// std::mutex will be unlocked here by lock guard destructor call.
			}


			// 
			~DataContainerTemplate()
			{
			}

		
		public:


			// 
			std::shared_ptr<T> set_data(const T& container_value)
			{
				// Lock mutex for thread-safety!
				//std::lock_guard<std::mutex> entsys_guard(mutex_reference);
				container_data = container_value;
				return container_data;
				// std::mutex will be unlocked here by std::lock_guard destructor.
			}


			// 
			const T& operator=(const std::shared_ptr<T>& value)
			{
				return set_data(value);
			}
			
			
			// Call by reference get method for data.
			void get_data(std::shared_ptr<T>& data_target_reference)
			{
				// Read-only, no need for std::mutex here.
				data_target_reference = container_data;
			}


	};


};
};
