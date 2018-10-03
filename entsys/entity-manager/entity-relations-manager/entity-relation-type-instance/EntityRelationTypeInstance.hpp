// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include "../entity-relation-type/EntityRelationType.hpp"
#include "../../entity-types-manager/entity-type-instance/EntityTypeInstance.hpp"


namespace inexor {
namespace entity_system {


	// A base class for instances of types of relations between entity types.
	class EntityRelationTypeInstance : public DataValidation
	{
		private:
		
			// 
			std::shared_ptr<EntityTypeInstance> source_entity_type_instance;

			// 
			std::shared_ptr<EntityTypeInstance> destination_entity_type_instance;

			// 
			std::shared_ptr<EntityRelationType> pointer_to_base_type;

		public:

			// TODO: Remove default constructor!
			EntityRelationTypeInstance(); // = delete;
			
			// TODO: Make this the default constructor!
			EntityRelationTypeInstance(const std::shared_ptr<EntityRelationType>&,
				                       const std::shared_ptr<EntityTypeInstance>&,
				                       const std::shared_ptr<EntityTypeInstance>&);

			//
			~EntityRelationTypeInstance();

			// TODO: Set data !

	};


};
};
