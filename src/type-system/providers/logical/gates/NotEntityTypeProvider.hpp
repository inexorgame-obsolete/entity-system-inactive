#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

    /// @class NotEntityTypeProvider
	/// @brief Provides an entity type "NOT".
	class NotEntityTypeProvider : public EntityTypeProvider
	{
		public:

			/// @brief Constructs the specialized provider for the entity type NOT.
            /// @note The dependencies of this class will be injected automatically.
            /// @param entity_type_builder_manager The entity type builder manager.
			NotEntityTypeProvider(
				std::shared_ptr<EntityTypeBuilderFactory> entity_type_builder_manager
			) : EntityTypeProvider(
				entity_type_builder_manager,
				TYPE_NAME,
				{
					{ NOT_INPUT, { DataType::BOOL, 1 << Feature::INPUT } },
					{ NOT_RESULT, { DataType::BOOL, 1 << Feature::OUTPUT } }
				}
			) {};

            /// Destructor.
			~NotEntityTypeProvider() {};

			/// Defines the name of this entity type.
			static constexpr char TYPE_NAME[] = "NOT";

			/// The name of the attribute not_input.
			static constexpr char NOT_INPUT[] = "not_input";

			/// The name of the attribute not_input.
			static constexpr char NOT_RESULT[] = "not_result";

	};

}
}
}
