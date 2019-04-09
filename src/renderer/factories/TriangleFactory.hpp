#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "renderer/providers/TriangleEntityTypeProvider.hpp"

namespace inexor {
namespace renderer {

	using TriangleEntityTypeProviderPtr = std::shared_ptr<TriangleEntityTypeProvider>;
	using EntityInstanceBuilderFactoryPtr = std::shared_ptr<EntityInstanceBuilderFactory>;
	using EntityInstanceManagerPtr = std::shared_ptr<EntityInstanceManager>;
	using EntityInstancePtr = std::shared_ptr<EntityInstance>;
	using EntityInstancePtrOpt = std::optional<EntityInstancePtr>;

	/// @class RenderFactory
	/// @brief Factory of the triangles.
	class TriangleFactory
	{
		public:

			/// @brief Constructor.
			/// @note The dependencies of this class will be injected automatically.
			/// @param triangle_entity_type_provider The entity type provider.
			/// @param entity_instance_builder_factory The entity instance builder factory.
			/// @param entity_instance_manager The entity instance manager.
			TriangleFactory(
				TriangleEntityTypeProviderPtr triangle_entity_type_provider,
				EntityInstanceBuilderFactoryPtr entity_instance_builder_factory,
				EntityInstanceManagerPtr entity_instance_manager
			);

			/// Destructor.
			~TriangleFactory();

			/// Creates a new triangle with the given coordinates.
			/// @param x ?
			/// @param y ?
			EntityInstancePtrOpt create_instance(float x, float y);

		private:

			/// The entity type provider.
			TriangleEntityTypeProviderPtr triangle_entity_type_provider;

			/// The entity instance builder factory.
			EntityInstanceBuilderFactoryPtr entity_instance_builder_factory;

			/// The entity instance manager.
			EntityInstanceManagerPtr entity_instance_manager;

	};

}
}
