// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include <iostream>

#include "entity-manager/EntityManager.hpp"


namespace inexor {
namespace entity_system {


    // TODO: Implement
	// TODO: EntityEditor
	// TODO: EntityEditorRenderer
	// TODO: EntityGameSceneRenderer,
    // TODO: EntitySync
	// TODO: EntityErrorHandling
	// TODO: EntityImporter
	// TODO: EntityExporter


	/// @class EntitySystem
    /// @brief Entity system main class.
	class EntitySystem : public EntityManager
	{
		public:

			/// Constructor.
			EntitySystem();

			/// Destructor.
			~EntitySystem();

	};


};
};
