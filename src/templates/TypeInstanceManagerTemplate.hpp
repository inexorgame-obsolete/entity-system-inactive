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


	/// A template base class
	/// for instance manager classes.
	template <typename T>
	class TypeInstanceManagerTemplate
	{
		private:

			/// A vector of stored instances of templatable type.
			std::vector<std::shared_ptr<T>> type_instances;
		
		protected:
			

			/// Adds an instance to the instance buffer.
			/// @param type_instance The instance which will be added.
			void add_instance_to_buffer(const std::shared_ptr<T>& type_instance)
			{
				// TODO: Add MUTEX here!
				type_instances.push_back(type_instance);
			}


			/// Returns the number of existing instances.
			/// @return The number of existing instances.
			const std::size_t get_type_instance_count() const
			{
				return type_instances.size();
			}


			/// Deletes all instances.
			void delete_all_type_instances()
			{
				// TODO: Add MUTEX here!
				type_instances.clear();
			}


			// TODO: Delete instance by UUID.
			// TODO: Get instance by UUID.
			
	};


};
};
