// Inexor entity system
// (c)2018-2019 Inexor

#pragma once

#include <iostream>

#include "managers/EntityManager.hpp"


namespace inexor {
namespace entity_system {


	// TODO: Implement EntityEditor
	// TODO: Implement EntityEditorRenderer
	// TODO: Implement EntityGameSceneRenderer
    // TODO: Implement EntitySync
	// TODO: Implement EntityImporter
	// TODO: Implement EntityExporter


	/// @class EntitySystem
    /// @brief Entity system main class.
	class EntitySystem : public EntityManager
	{
		public:

			/// Constructor.
			EntitySystem(
				std::shared_ptr<inexor::entity_system::EntityTypeManager> entity_type_manager,
				std::shared_ptr<inexor::entity_system::EntityInstanceManager> entity_instance_manager,
				std::shared_ptr<inexor::entity_system::EntityAttributeTypeManager> entity_attribute_type_manager,
				std::shared_ptr<inexor::entity_system::EntityAttributeInstanceManager> entity_attribute_instance_manager,
				std::shared_ptr<inexor::entity_system::RelationTypeManager> relation_type_manager,
				std::shared_ptr<inexor::entity_system::RelationInstanceManager> relation_instance_manager,
				std::shared_ptr<inexor::entity_system::RelationAttributeTypeManager> relation_attribute_type_manager,
				std::shared_ptr<inexor::entity_system::RelationAttributeInstanceManager> relation_attribute_instance_manager
			);

			/// Destructor.
			~EntitySystem();

	};


};
};
