// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include <iostream>

#include "entity-manager/EntityManager.hpp"


namespace inexor {
namespace entity_system {


	// TODO: Implement EntityEditor
	// TODO: Implement EntityEditorRenderer
	// TODO: Implement EntityGameSceneRenderer,
    // TODO: Implement EntitySync
	// TODO: Implement EntityErrorHandling
	// TODO: Implement EntityImporter
	// TODO: Implement EntityExporter


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
