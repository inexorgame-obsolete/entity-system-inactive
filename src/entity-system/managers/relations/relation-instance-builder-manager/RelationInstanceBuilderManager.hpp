// Inexor entity system
// (c)2018 Inexor

#pragma once

#include "entity-system/managers/relations/relation-instance-manager/RelationInstanceManager.hpp"
#include "entity-system/managers/relations/relation-type-manager/RelationTypeManager.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/util/type-definitions/TypeDefinitions.hpp"

#include "entity-system/builders/relations/relation-instance-builder/RelationInstanceBuilder.hpp"

using namespace std;

namespace inexor {
namespace entity_system {

	/// @class RelationInstanceBuilder
    /// @brief Manages the relation instance builders.
	class RelationInstanceBuilderManager
	{
		public:

			/// Constructor.
			RelationInstanceBuilderManager(
				shared_ptr<RelationInstanceManager> relation_instance_manager,
				shared_ptr<RelationTypeManager> relation_type_manager
			);

			/// Destructor.
			~RelationInstanceBuilderManager();

			/// Initialization of the manager
			void init();

			/// Returns a new instance of a builder
			shared_ptr<RelationInstanceBuilder> get_builder();

		private:

			/// The relation instance manager
			shared_ptr<RelationInstanceManager> relation_instance_manager;

			/// The relation type manager
			shared_ptr<RelationTypeManager> relation_type_manager;

	};


};
};
