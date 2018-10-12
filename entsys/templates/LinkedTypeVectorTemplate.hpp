// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include <vector>

// When using template classes it is not possible
// to separate definitions of class methods from their declaration.
// This is the reason why there is no cpp file for this header file!


namespace inexor {
namespace entity_system {


	// A template class for a linked std::vector of types.
	template <typename T>
	class LinkedTypeVectorTemplate
	{
		protected:
			
			// Vector of stored objects which are linked to this.
			std::vector<std::shared_ptr<T>> linked_objects;

		protected:

			// 
			void add_linked_object(const std::shared_ptr<T>& new_object)
			{
				linked_objects.push_back(new_object);
			}

			
			// TODO: Remove linked object


			//
			std::size_t get_linked_objects_count() const
			{
				return linked_objects.size();
			}


			//
			std::vector<std::shared_ptr<T>> get_linked_objects() const
			{
				return linked_objects;
			}


			// 
			void delete_all_linked_objects()
			{
				linked_objects.clear();
			}

	};


};
};
