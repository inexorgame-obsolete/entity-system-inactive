// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include <vector>
#include <memory>


namespace inexor {
namespace entity_system {

	
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
			TypeInstanceManagerTemplate();

			// 
			~TypeInstanceManagerTemplate();

			// 
			std::shared_ptr<T2> create_type_instance(const std::shared_ptr<T1>&);

			// 
			const std::size_t get_type_instance_count() const;

			// 
			void delete_all_type_instances();

	};


};
};
