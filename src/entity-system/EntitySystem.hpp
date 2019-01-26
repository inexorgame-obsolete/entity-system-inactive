// Inexor entity system
// (c)2018-2019 Inexor

#pragma once

#include <iostream>

#include "managers/EntityManager.hpp"
#include "managers/RelationManager.hpp"
#include "managers/BuilderManager.hpp"


using namespace inexor::entity_system;
using namespace std;


namespace inexor {
namespace entity_system {


	/// @class EntitySystem
    /// @brief Entity system main class.
	class EntitySystem
	{
		public:

			/// Constructor.
			EntitySystem(
				shared_ptr<EntityManager> entity_manager,
				shared_ptr<RelationManager> relation_manager,
				shared_ptr<BuilderManager> builder_manager
			);

			/// Destructor.
			~EntitySystem();

			/// Resets the entire entity system.
			void reset_entity_system();

		private:

			/// The entity managers
			shared_ptr<EntityManager> entity_manager;

			/// The entity managers
			shared_ptr<RelationManager> relation_manager;

			/// The builder managers
			shared_ptr<BuilderManager> builder_manager;

	};


};
};
