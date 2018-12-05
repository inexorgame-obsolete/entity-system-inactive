// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include "../../entity-type-manager/entity-type/EntityType.hpp"
#include "../../entity-attribute-manager/entity-attribute-type-instances/EntityAttributeTypeInstance.hpp"
#include "../../../base-classes/TypeInstanceBase.hpp"
#include "../../../templates/TypeInstancesContainerTemplate.hpp"


namespace inexor {
namespace entity_system {


	/// A base class for entity type instances.
    class EntityTypeInstance : public TypeInstanceBase<EntityType,EntityTypeInstance>,
		                       public TypeInstancesContainerTemplate<EntityAttributeType,EntityAttributeTypeInstance>
    {
		public:
			
			/// Constructor.
			/// @param ent_type A const reference of a shared pointer
			/// to the entity type of which an instance will be created.
			EntityTypeInstance(const ENT_TYPE&);

			/// Destructor.
			~EntityTypeInstance();
			
    };


};
};
