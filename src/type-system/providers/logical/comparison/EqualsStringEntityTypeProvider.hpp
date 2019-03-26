#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

    /// @class EqualsStringEntityTypeProvider
	/// @brief Provides an entity type "EQUALS_STRING".
	class EqualsStringEntityTypeProvider : public EntityTypeProvider
	{
		public:

			/// @brief Constructs the specialized provider for the entity type EQUALS_STRING.
            /// @note The dependencies of this class will be injected automatically.
            /// @param entity_type_builder_manager The entity type builder manager.
			EqualsStringEntityTypeProvider(
				std::shared_ptr<EntityTypeBuilderFactory> entity_type_builder_manager
			) : EntityTypeProvider(
				entity_type_builder_manager,
				TYPE_NAME,
				{
					{ EQUALS_STRING_INPUT_1, { DataType::STRING, 1 << Feature::INPUT } },
					{ EQUALS_STRING_INPUT_2, { DataType::STRING, 1 << Feature::INPUT } },
					{ EQUALS_STRING_RESULT, { DataType::BOOL, 1 << Feature::OUTPUT } }
				}
			) {};

            /// Destructor.
			~EqualsStringEntityTypeProvider() {};

			/// Defines the name of this entity type.
			static constexpr char TYPE_NAME[] = "EQUALS_STRING";

			/// The name of the attribute equals_string_input_1.
			static constexpr char EQUALS_STRING_INPUT_1[] = "equals_string_input_1";

			/// The name of the attribute equals_string_input_1.
			static constexpr char EQUALS_STRING_INPUT_2[] = "equals_string_input_2";

			/// The name of the attribute equals_string_result.
			static constexpr char EQUALS_STRING_RESULT[] = "equals_string_result";

	};

}
}
}
