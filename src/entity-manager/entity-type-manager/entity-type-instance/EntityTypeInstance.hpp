// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include "../../entity-type-manager/entity-type/EntityType.hpp"
#include "../../entity-attribute-manager/entity-attribute-type-instances/EntityAttributeTypeInstance.hpp"
#include "../../../base-classes/TypeInstanceBase.hpp"
#include "../../../templates/TypeInstancesMap.hpp"


namespace inexor {
namespace entity_system {


	/// A base class for instances of entity types.
    class EntityTypeInstance : public TypeInstanceBase<EntityType,EntityTypeInstance>,
		                       public TypeInstancesMap<EntityAttributeType,EntityAttributeTypeInstance>
    {
		public:
			
			/// Constructor.
			/// @param ent_type A const reference of a shared pointer
			/// to the entity type of which an instance will be created.
			/// @return A shared pointer to the entity type instance which was created.
			/// TODO: entity_type_instance_error!
			EntityTypeInstance(const ENT_TYPE&);

			/// Destructor.
			~EntityTypeInstance();
			
    };


};
};
