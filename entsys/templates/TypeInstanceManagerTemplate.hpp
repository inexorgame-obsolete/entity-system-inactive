// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include <vector>
#include <memory>


namespace inexor {
namespace entity_system {


	// When using template classes it is not possible
	// to separate definitions of class methods from their declaration.

	// A class template for instance manager classes.
	// This will be used by EntityTypeInstanceManager,
	// EntityAttributeTypeInstanceManager, EntityRelationTypeInstanceManager.
	// T1 = entity type, T2 = entity type instance.
	template <typename T1, typename T2>
	class TypeInstanceManagerTemplate
	{
		private:

			// In this vector we will store shared pointers of <T2> instances.
			std::vector<std::shared_ptr<T2>> type_instances;


		protected:

			// 
			TypeInstanceManagerTemplate()
			{
			}

			
			// 
			~TypeInstanceManagerTemplate()
			{
			}


			// 
			void add_instance_to_buffer(const std::shared_ptr<T2>& param_instance_pointer)
			{
				type_instances.push_back(param_instance_pointer);
			}


			// 
			const std::size_t get_type_instance_count() const
			{
				return type_instances.size();
			}


			// 
			void delete_all_type_instances()
			{
				type_instances.clear();
			}

			// TODO: Delete instance.
			// TODO: Get instance.

	};


};
};
