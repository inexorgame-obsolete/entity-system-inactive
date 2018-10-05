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
	template <typename T1, typename T2> // T1 = entity types, T2 = entity type instances
	class TypeInstanceManagerTemplate
	{
		private:


			// In this vector we will store shared pointers of 
			// the instances of <T2>.
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
			std::shared_ptr<T2> create_type_instance(const std::shared_ptr<T1>& param_type_poiner)
			{
				std::shared_ptr<T2> new_type_instance = std::make_shared<T2>(param_type_poiner);
				type_instances.push_back(new_type_instance);
				return new_type_instance;
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

	};


};
};
