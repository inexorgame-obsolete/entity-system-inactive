// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include <vector>

// Variadic functions (variable parameter lists for initialisation)
#include <cstdarg>

// Entity system debugging.
#include "../../entsys/tests/EntitySystemDebugging.hpp"

// Entity types and instances of those.
#include "entity-types-manager\EntityTypeManager.hpp"
#include "entity-types-manager\EntityTypeInstanceManager.hpp"

// Entity attribute types and instances of those.
#include "entity-attributes-manager\EntityAttributeTypeManager.hpp"
#include "entity-attributes-manager\EntityAttributeTypeInstanceManager.hpp"

// Entity relation types and instances of those.
#include "entity-relations-manager\EntityRelationTypeManager.hpp"
#include "entity-relations-manager\EntityRelationTypeInstanceManager.hpp"


namespace inexor {
namespace entity_system {


    // The entity manager class is responsible for adding, modifying and removing entity types,
    // entity attributes, entity relations and instances of these.
    class EntityManager : public EntityTypeManager,
                          public EntityTypeInstanceManager,
                          public EntityAttributeTypeManager,
                          public EntityAttributeTypeInstanceManager,
                          public EntityRelationTypeManager,
                          public EntityRelationTypeInstanceManager
    {

		protected:
        
            EntityManager();

            ~EntityManager();

	public:

			// Validates the new entity type and all linked entity attribute
			// types and adds them to the entity system if their data is valid.
			ENTSYS_RESULT create_entity_type_with_attributes(const std::shared_ptr<EntityType>&,
				                                             const std::vector<std::shared_ptr<EntityAttributeType>>&);



    };

};
};
