#pragma once

#include "entity-system/managers/relations/relation-instance-manager/RelationInstanceManager.hpp"
#include "entity-system/managers/relations/relation-type-manager/RelationTypeManager.hpp"
#include "entity-system/builders/relations/relation-instance-builder/RelationInstanceBuilder.hpp"

namespace inexor {
namespace entity_system {


	/// @class RelationInstanceBuilder
	/// @brief Manages the relation instance builders.
	class RelationInstanceBuilderFactory
	{
		public:

			/// These using instructions help to shorten the following code.
			using RelationInstanceBuilderPtr = std::shared_ptr<RelationInstanceBuilder>;
			using RelationInstanceManagerPtr = std::shared_ptr<RelationInstanceManager>;
			using RelationTypeManagerPtr = std::shared_ptr<RelationTypeManager>;

			/// Constructor.
			RelationInstanceBuilderFactory(
				RelationInstanceManagerPtr relation_instance_manager,
				RelationTypeManagerPtr relation_type_manager
			);

			/// Destructor.
			~RelationInstanceBuilderFactory();

			/// Initialization of the manager
			void init();

			/// Returns a new instance of a builder
			RelationInstanceBuilderPtr get_builder();

		private:

			/// The relation instance manager
			RelationInstanceManagerPtr relation_instance_manager;

			/// The relation type manager
			RelationTypeManagerPtr relation_type_manager;

			/// The mutex of this class
			std::mutex relation_instance_builder_factory_mutex;

	};

}
}
