#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

    /// @class EqualsIntEntityTypeProvider
	/// @brief Provides an entity type "EQUALS_INT".
	class EqualsIntEntityTypeProvider : public EntityTypeProvider
	{
		public:

			/// @brief Constructs the specialized provider for the entity type EQUALS_INT.
            /// @note The dependencies of this class will be injected automatically.
            /// @param entity_type_builder_manager The entity type builder manager.
			EqualsIntEntityTypeProvider(
				std::shared_ptr<EntityTypeBuilderFactory> entity_type_builder_manager
			) : EntityTypeProvider(
				entity_type_builder_manager,
				TYPE_NAME,
				{
					{ EQUALS_INT_INPUT_1, { DataType::INT, 1 << Feature::INPUT } },
					{ EQUALS_INT_INPUT_2, { DataType::INT, 1 << Feature::INPUT } },
					{ EQUALS_INT_RESULT, { DataType::BOOL, 1 << Feature::OUTPUT } }
				}
			) {};

            /// Destructor.
			~EqualsIntEntityTypeProvider() {};

			/// Defines the name of this entity type.
			static constexpr char TYPE_NAME[] = "EQUALS_INT";

			/// The name of the attribute equals_int_input_1.
			static constexpr char EQUALS_INT_INPUT_1[] = "equals_int_input_1";

			/// The name of the attribute equals_int_input_1.
			static constexpr char EQUALS_INT_INPUT_2[] = "equals_int_input_2";

			/// The name of the attribute equals_int_result.
			static constexpr char EQUALS_INT_RESULT[] = "equals_int_result";

	};

}
}
}
