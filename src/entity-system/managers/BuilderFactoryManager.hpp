#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "entity-system/factories/relations/relation-type-builder-factory/RelationTypeBuilderFactory.hpp"
#include "entity-system/factories/relations/relation-instance-builder-factory/RelationInstanceBuilderFactory.hpp"

namespace inexor {
namespace entity_system {

	/// @class BuilderFactoryManager
	/// @brief A manager class which bundles the following builder factory classes:
	/// <ol>
	///		<li> Entity type builder factory
	///		<li> Entity instance builder factory
	///		<li> Relation type builder factory
	///		<li> Relation instance builder factory
	/// </ol>
	class BuilderFactoryManager
	{
		public:

			/// These using instructions help to shorten the following code.
			using EntityTypeBuilderFactoryPtr = std::shared_ptr<EntityTypeBuilderFactory>;
			using EntityInstanceBuilderFactoryPtr = std::shared_ptr<EntityInstanceBuilderFactory>;
			using RelationTypeBuilderFactoryPtr = std::shared_ptr<RelationTypeBuilderFactory>;
			using RelationInstanceBuilderFactoryPtr = std::shared_ptr<RelationInstanceBuilderFactory>;

			/// @brief Constructor.
			/// @note The dependencies of this class will be injected automatically with the help of Boost DI.<br>
			/// For more information see https://boost-experimental.github.io/di/user_guide/index.html
			/// BOOST_DI_INJECT constructor parameters is limited to BOOST_DI_CFG_CTOR_LIMIT_SIZE,<br>
			/// which by default is set to 10. Not more than 10 arguments can be passed to the DI constructor!<br>
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

			/// @brief Destructor.
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

			/// The mutex of this class.
			std::mutex builder_factory_manager_mutex;

	};

}
}
