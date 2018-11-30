// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include <vector>

// Entity types and instances of them.
#include "entity-type-manager\EntityTypeManager.hpp"
#include "entity-type-manager\EntityTypeInstanceManager.hpp"

// Entity attribute types and instances of them.
#include "entity-attribute-manager\EntityAttributeTypeManager.hpp"
#include "entity-attribute-manager\EntityAttributeTypeInstanceManager.hpp"

// Entity relation types and instances of them.
#include "entity-relation-manager\EntityRelationTypeManager.hpp"
#include "entity-relation-manager\EntityRelationTypeInstanceManager.hpp"

// Entity relation attribute types and instances of them.
#include "entity-relation-attribute-manager/EntityRelationAttributeTypeManager.hpp"
#include "entity-relation-attribute-manager/EntityRelationAttributeTypeInstanceManager.hpp"


namespace inexor {
namespace entity_system {


    // The entity manager class is responsible for adding, modifying and removing entity types,
    // entity attributes, entity relations and instances of these.
    class EntityManager : public EntityTypeManager,
                          public EntityTypeInstanceManager,
                          public EntityAttributeTypeManager,
                          public EntityAttributeTypeInstanceManager,
                          public EntityRelationTypeManager,
                          public EntityRelationTypeInstanceManager,
                          public EntityRelationAttributeTypeManager,
                          public EntityRelationAttributeTypeInstanceManager
    {

		protected:
			
			// 
		    EntityManager();

			// 
			~EntityManager();

		public:

			// Delete all entity types, entity attribute types,
			// entity relation types and instances of them.
			void reset_entity_system();

    };


};
};
