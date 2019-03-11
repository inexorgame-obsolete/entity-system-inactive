#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "entity-system/factories/relations/relation-type-builder-factory/RelationTypeBuilderFactory.hpp"
#include "entity-system/factories/relations/relation-instance-builder-factory/RelationInstanceBuilderFactory.hpp"

namespace inexor {
namespace entity_system {

    /// @class BuilderFactoryManager
    /// @brief The builder factory manager manages the builder factories.
    class BuilderFactoryManager
    {

		public:

    		using EntityTypeBuilderFactoryPtr = std::shared_ptr<EntityTypeBuilderFactory>;
    		using EntityInstanceBuilderFactoryPtr = std::shared_ptr<EntityInstanceBuilderFactory>;
    		using RelationTypeBuilderFactoryPtr = std::shared_ptr<RelationTypeBuilderFactory>;
    		using RelationInstanceBuilderFactoryPtr = std::shared_ptr<RelationInstanceBuilderFactory>;

			/// Constructor.
		    BuilderFactoryManager(
				EntityTypeBuilderFactoryPtr entity_type_builder_factory,
				EntityInstanceBuilderFactoryPtr entity_instance_builder_factory,
				RelationTypeBuilderFactoryPtr relation_type_builder_factory,
				RelationInstanceBuilderFactoryPtr relation_instance_builder_factory
		    );

			/// Destructor.
			~BuilderFactoryManager();

		private:

			/// The entity type builder factory.
			EntityTypeBuilderFactoryPtr entity_type_builder_factory;

			/// The entity instance builder factory.
			EntityInstanceBuilderFactoryPtr entity_instance_builder_factory;

			/// The entity relation type builder factory.
			RelationTypeBuilderFactoryPtr relation_type_builder_factory;

			/// The entity relation instance builder factory.
			RelationInstanceBuilderFactoryPtr relation_instance_builder_factory;

    };

}
}
