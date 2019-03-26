#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

    /// @class GreaterThanIntEntityTypeProvider
	/// @brief Provides an entity type "GREATER_THAN_INT".
	class GreaterThanIntEntityTypeProvider : public EntityTypeProvider
	{
		public:

			/// @brief Constructs the specialized provider for the entity type GREATER_THAN_INT.
            /// @note The dependencies of this class will be injected automatically.
            /// @param entity_type_builder_manager The entity type builder manager.
			GreaterThanIntEntityTypeProvider(
				std::shared_ptr<EntityTypeBuilderFactory> entity_type_builder_manager
			) : EntityTypeProvider(
				entity_type_builder_manager,
				TYPE_NAME,
				{
					{ GREATER_THAN_INT_INPUT_1, { DataType::INT, 1 << Feature::INPUT } },
					{ GREATER_THAN_INT_INPUT_2, { DataType::INT, 1 << Feature::INPUT } },
					{ GREATER_THAN_INT_RESULT, { DataType::BOOL, 1 << Feature::OUTPUT } }
				}
			) {};

            /// Destructor.
			~GreaterThanIntEntityTypeProvider() {};

			/// Defines the name of this entity type.
			static constexpr char TYPE_NAME[] = "GREATER_THAN_INT";

			/// The name of the attribute greater_than_int_input_1.
			static constexpr char GREATER_THAN_INT_INPUT_1[] = "greater_than_int_input_1";

			/// The name of the attribute greater_than_int_input_1.
			static constexpr char GREATER_THAN_INT_INPUT_2[] = "greater_than_int_input_2";

			/// The name of the attribute greater_than_int_result.
			static constexpr char GREATER_THAN_INT_RESULT[] = "greater_than_int_result";

	};

}
}
}
