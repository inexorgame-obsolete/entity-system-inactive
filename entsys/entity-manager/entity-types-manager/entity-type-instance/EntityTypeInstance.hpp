// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include "../../entity-types-manager/entity-type/EntityType.hpp"
#include "../../entity-attributes-manager/entity-attribute-type-instances/EntityAttributeTypeInstance.hpp"
#include "../../../base-classes/TypeInstanceBase.hpp"
#include "../../../templates/InstanceMapTemplate.hpp"


namespace inexor {
namespace entity_system {


	// A base class for instances of types of entities.
    class EntityTypeInstance : public TypeInstanceBase<EntityType,EntityTypeInstance>,
		public InstanceMapTemplate<EntityAttributeType,EntityAttributeTypeInstance>
    {
		public:
			
			EntityTypeInstance(const std::shared_ptr<EntityType>&);
			~EntityTypeInstance();
			
    };


};
};
