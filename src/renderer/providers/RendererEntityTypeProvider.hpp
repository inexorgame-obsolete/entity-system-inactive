#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

namespace inexor {
namespace renderer {

	using namespace inexor::entity_system;

    /// @class RendererEntityTypeProvider
	/// @brief Provides an entity type "RENDERER".
	class RendererEntityTypeProvider : public EntityTypeProvider
	{
		public:

        	/// @brief Constructs the specialized provider for the RENERER entity type.
            /// @note The dependencies of this class will be injected automatically.
			RendererEntityTypeProvider(
				std::shared_ptr<EntityTypeBuilderFactory> entity_type_builder_factory
			) : EntityTypeProvider(
				entity_type_builder_factory,
				TYPE_NAME,
				{
					{ RENDERER_X, { DataType::FLOAT, 1 << Feature::INPUT } },
					{ RENDERER_Y, { DataType::FLOAT, 1 << Feature::INPUT } }
				}
			) {};

            /// Destructor.
			~RendererEntityTypeProvider() {};

			/// Defines the name of this entity type
			static constexpr char TYPE_NAME[] = "RENDERER";

			/// The name of the renderer x attribute value.
			static constexpr char RENDERER_X[] = "renderer_x";

			/// The name of the renderer y attribute value.
			static constexpr char RENDERER_Y[] = "renderer_y";

	};

}
}
