// Inexor entity system
// (c)2018-2019 Inexor

#pragma once

#include <vector>

#include "entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "entities/entity-type-manager/EntityTypeManager.hpp"
#include "entity-attributes/entity-attribute-instance-manager/EntityAttributeInstanceManager.hpp"
#include "entity-attributes/entity-attribute-type-manager/EntityAttributeTypeManager.hpp"


using namespace inexor::entity_system;
using namespace std;


namespace inexor {
namespace entity_system {


	// TODO: Implement EntityEditor
	// TODO: Implement EntityEditorRenderer
	// TODO: Implement EntityGameSceneRenderer
	// TODO: Implement EntitySync
	// TODO: Implement EntityImporter
	// TODO: Implement EntityExporter


	/// @class EntityManager
    /// @brief The entity manager manages the entity managers.
    class EntityManager
    {

		public:

			/// Constructor.
		    EntityManager(
		    	shared_ptr<EntityTypeManager> entity_type_manager,
		    	shared_ptr<EntityInstanceManager> entity_instance_manager,
				shared_ptr<EntityAttributeTypeManager> entity_attribute_type_manager,
				shared_ptr<EntityAttributeInstanceManager> entity_attribute_instance_manager
		    );

			/// Destructor.
			~EntityManager();

			/// Resets the entire entity system.
			void reset_entity_system();

		private:

			/// The entity type manager.
			shared_ptr<EntityTypeManager> entity_type_manager;

			/// The entity instance manager.
			shared_ptr<EntityInstanceManager> entity_instance_manager;

			/// The entity attribute type manager.
			shared_ptr<EntityAttributeTypeManager> entity_attribute_type_manager;

			/// The entity attribute instance manager.
			shared_ptr<EntityAttributeInstanceManager> entity_attribute_instance_manager;

    };


};
};
