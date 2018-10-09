// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include <vector>
#include <memory>

#include "../data-validation/DataValidation.hpp"


namespace inexor {
namespace entity_system {


	// When using template classes it is not possible
	// to separate definitions of class methods from their declaration.

	// A class template for instance manager classes.
	// This will be used by EntityTypeInstanceManager,
	// EntityAttributeTypeInstanceManager, EntityRelationTypeInstanceManager.
	// T1 = entity type, T2 = entity type instance.
	template <typename T>
	class TypeInstanceManagerTemplate
	{
		protected:

			// In this vector we will store shared pointers of <T2> instances.
			std::vector<std::shared_ptr<T>> type_instances;
			

			// 
			TypeInstanceManagerTemplate()
			{
			}

			
			// 
			~TypeInstanceManagerTemplate()
			{
			}


			// 
			void add_instance_to_buffer(const std::shared_ptr<T>& type_instance)
			{
				// TODO: Add MUTEX here!
				type_instances.push_back(type_instance);
			}


			// 
			const std::size_t get_type_instance_count() const
			{
				return type_instances.size();
			}


			// 
			void delete_all_type_instances()
			{
				// TODO: Add MUTEX here!
				type_instances.clear();
			}

			// TODO: Delete instance.
			// TODO: Get instance.
			
	};


};
};
