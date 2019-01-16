// Inexor entity system
// (c)2018-2019 Inexor

#pragma once

#include <vector>

#include "attributes/attribute-instance-manager/EntityAttributeInstanceManager.hpp"
#include "attributes/attribute-type-manager/EntityAttributeTypeManager.hpp"
#include "relation-attributes/relation-attribute-instance-manager/EntityRelationAttributeInstanceManager.hpp"
#include "relation-attributes/relation-attribute-type-manager/EntityRelationAttributeTypeManager.hpp"
#include "relations/relation-instance-manager/EntityRelationInstanceManager.hpp"
#include "relations/relation-type-manager/EntityRelationTypeManager.hpp"
#include "types/instance-manager/EntityInstanceManager.hpp"
#include "types/type-manager/EntityTypeManager.hpp"


namespace inexor {
namespace entity_system {


    /// @class EntityManager
    /// @brief The entity manager class is responsible for adding,
    /// modifying and removing entity types, entity attributes,
    /// entity relations and instances of them.
    class EntityManager : public EntityTypeManager,
                          public EntityInstanceManager,
                          public EntityAttributeTypeManager,
                          public EntityAttributeInstanceManager,
                          public EntityRelationTypeManager,
                          public EntityRelationInstanceManager,
                          public EntityRelationAttributeTypeManager,
                          public EntityRelationAttributeInstanceManager
    {

		protected:

			/// Constructor.
		    EntityManager();

			/// Destructor.
			~EntityManager();

		public:

			/// Resets the entire entity system.
			void wire(std::shared_ptr<EntityManager> entity_manager);

			/// Resets the entire entity system.
			void reset_entity_system();


    };


};
};
