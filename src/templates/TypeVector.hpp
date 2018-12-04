// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include <vector>
#include <memory>


// When using template classes it is not possible
// to separate definitions of class methods from their declaration.
// This is the reason why there is no cpp file for this header file!


namespace inexor {
namespace entity_system {


	/// A template base class for a std::vector of a templatable type.
	template <typename T>
	class TypeVector
	{
		protected:
			
			/// Vector of objects of a templatable type.
			std::vector<std::shared_ptr<T>> linked_objects;

		protected:

			/// Adds an object of templatable type to the vector.
			/// @param new_object A const reference of a shared pointer to the new object.
			void add_linked_object(const std::shared_ptr<T>& new_object)
			{
				linked_objects.push_back(new_object);
			}

			
			// TODO: Method for removing linked objects.


			/// Returns the number of objects of templatable type which are stored in this class.
			/// @return Number of objects of templatable type which are stored.
			std::size_t get_linked_objects_count() const
			{
				return linked_objects.size();
			}


			/// Returns all objects.
			/// @return A std::vector of shared pointers to
			/// the objects of templatable type which are stored.
			std::vector<std::shared_ptr<T>> get_linked_objects() const
			{
				return linked_objects;
			}


			/// Deletes all objects.
			void delete_all_linked_objects()
			{
				linked_objects.clear();
			}

	};


};
};
