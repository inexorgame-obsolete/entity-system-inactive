#pragma once

#include <vector>

#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "entity-system/managers/entities/entity-type-manager/EntityTypeManager.hpp"
#include "entity-system/managers/entity-attributes/entity-attribute-instance-manager/EntityAttributeInstanceManager.hpp"
#include "entity-system/managers/entity-attributes/entity-attribute-type-manager/EntityAttributeTypeManager.hpp"

using namespace inexor::entity_system;

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

			/// @brief Constructor.
			/// @note The dependencies of this class will be injected automatically.<br>
			/// BOOST_DI_INJECT constructor parameters is limited to BOOST_DI_CFG_CTOR_LIMIT_SIZE,<br>
			/// which by default is set to 10. Not more than 10 arguments can be passed to the DI constructor!<br>
			/// https://boost-experimental.github.io/di/user_guide/index.html
			/// @param entity_type_manager The entity type manager.
			/// @param entity_instance_manager The entity instance manager.
			/// @param entity_attribute_type_manager The entity attribute type manager.
			/// @param entity_attribute_instance_manager The entity attribute instance manager.
			EntityManager(
				std::shared_ptr<EntityTypeManager> entity_type_manager,
				std::shared_ptr<EntityInstanceManager> entity_instance_manager,
				std::shared_ptr<EntityAttributeTypeManager> entity_attribute_type_manager,
				std::shared_ptr<EntityAttributeInstanceManager> entity_attribute_instance_manager
			);

			/// Destructor.
			~EntityManager();

			/// Resets the entire entity system.
			void reset_entity_system();

		private:

			/// The entity type manager.
			std::shared_ptr<EntityTypeManager> entity_type_manager;

			/// The entity instance manager.
			std::shared_ptr<EntityInstanceManager> entity_instance_manager;

			/// The entity attribute type manager.
			std::shared_ptr<EntityAttributeTypeManager> entity_attribute_type_manager;

			/// The entity attribute instance manager.
			std::shared_ptr<EntityAttributeInstanceManager> entity_attribute_instance_manager;

	};

};
};
