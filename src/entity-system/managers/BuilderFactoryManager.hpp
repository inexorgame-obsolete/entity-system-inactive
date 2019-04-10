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

			/// @brief Constructor.
			/// @note The dependencies of this class will be injected automatically.<br>
			/// BOOST_DI_INJECT constructor parameters is limited to BOOST_DI_CFG_CTOR_LIMIT_SIZE,<br>
			/// which by default is set to 10. Not more than 10 arguments can be passed to the DI constructor!<br>
			/// https://boost-experimental.github.io/di/user_guide/index.html
			/// @param entity_type_builder_factory The entity type builder factory.
			/// @param entity_instance_builder_factory The entity instance builder factory.
			/// @param relation_type_builder_factory The relation type builder factory.
			/// @param relation_instance_builder_factory The relation instance builder factory.
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
