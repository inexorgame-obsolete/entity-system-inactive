#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

    /// @class SinEntityTypeProvider
	/// @brief Provides an entity type "SIN": sin_value = sin(sin_input).
	class SinEntityTypeProvider : public EntityTypeProvider
	{
		public:

			/// @brief Constructs the specialized provider for the entity type SIN.
            /// @note The dependencies of this class will be injected automatically.
            /// @param entity_type_builder_manager The entity type builder manager.
			SinEntityTypeProvider(
				std::shared_ptr<EntityTypeBuilderFactory> entity_type_builder_manager
			) : EntityTypeProvider(
				entity_type_builder_manager,
				TYPE_NAME,
				{
					{ SIN_INPUT, { DataType::FLOAT, 1 << Feature::INPUT } },
					{ SIN_VALUE, { DataType::FLOAT, 1 << Feature::OUTPUT } }
				}
			) {};

            /// Destructor.
			~SinEntityTypeProvider() {};

			/// Defines the name of this entity type.
			static constexpr char TYPE_NAME[] = "SIN";

			/// The name for the attribute sin_input.
			static constexpr char SIN_INPUT[] = "sin_input";

			/// The name for the attribute sin_value.
			static constexpr char SIN_VALUE[] = "sin_value";

	};

}
}
}
