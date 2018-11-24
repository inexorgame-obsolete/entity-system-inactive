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

		protected:

			// 
			explicit DataContainerTemplate(const T default_value)
			{
				container_data = default_value;
			}


			// 
			~DataContainerTemplate()
			{
			}
		
		public:


			// Set method can't be of type void because 
			// we need a return value for overloading = operator!
			std::shared_ptr<T> set_data(const T& container_value)
			{
				// TODO: Add mutex!
				container_data = container_value;
				return container_data;
			}


	};


};
};
