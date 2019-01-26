// Inexor entity system
// (c)2018 Inexor

#pragma once

#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "entity-system/managers/entities/entity-type-manager/EntityTypeManager.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/util/type-definitions/TypeDefinitions.hpp"

#include "entity-system/builders/entities/entity-instance-builder/EntityInstanceBuilder.hpp"

using namespace std;

namespace inexor {
namespace entity_system {

	/// @class EntityTypeBuilder
    /// @brief Management of the loggers.
	class EntityInstanceBuilderManager
	{
		public:

			/// Constructor.
			EntityInstanceBuilderManager(
				shared_ptr<EntityInstanceManager> entity_instance_manager,
				shared_ptr<EntityTypeManager> entity_type_manager
			);

			/// Destructor.
			~EntityInstanceBuilderManager();

			/// Initialization of the manager
			void init();

			/// Returns a new instance of a builder
			shared_ptr<EntityInstanceBuilder> get_builder();

		private:

			/// The entity instance manager
			shared_ptr<EntityInstanceManager> entity_instance_manager;

			/// The entity type manager
			shared_ptr<EntityTypeManager> entity_type_manager;

	};


};
};
