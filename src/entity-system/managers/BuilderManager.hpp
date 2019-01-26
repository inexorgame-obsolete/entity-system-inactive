// Inexor entity system
// (c)2018-2019 Inexor

#pragma once

#include <vector>

#include "entities/entity-type-builder-manager/EntityTypeBuilderManager.hpp"
//#include "entities/entity-instance-builder-manager/EntityInstanceBuilderManager.hpp"
//#include "relations/relation-type-builder-manager/RelationTypeBuilderManager.hpp"
//#include "relations/relation-instance-builder-manager/RelationInstanceBuilderManager.hpp"


using namespace inexor::entity_system;
using namespace std;


namespace inexor {
namespace entity_system {


    /// @class BuilderManager
    /// @brief The builder manager manages the builder managers.
    class BuilderManager
    {

		public:

			/// Constructor.
		    BuilderManager(
		    	shared_ptr<EntityTypeBuilderManager> entity_type_builder_manager /*,
		    	shared_ptr<EntityInstanceBuilderManager> entity_instance_builder_manager,
				shared_ptr<RelationTypeBuilderManager> relation_type_builder_manager,
				shared_ptr<RelationInstanceBuilderManager> relation_instance_builder_manager */
		    );

			/// Destructor.
			~BuilderManager();

		private:

			/// The entity type builder manager.
			shared_ptr<EntityTypeBuilderManager> entity_type_builder_manager;

//			/// The entity instance builder manager.
//			shared_ptr<EntityInstanceBuilderManager> entity_instance_builder_manager;
//
//			/// The entity relation type builder manager.
//			shared_ptr<RelationTypeBuilderManager> relation_type_builder_manager;
//
//			/// The entity relation instance builder manager.
//			shared_ptr<RelationInstanceBuilderManager> relation_instance_builder_manager;

    };


};
};
