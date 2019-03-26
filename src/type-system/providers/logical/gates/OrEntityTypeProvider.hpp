#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

    /// @class OrEntityTypeProvider
	/// @brief Provides an entity type "OR".
	class OrEntityTypeProvider : public EntityTypeProvider
	{
		public:

			/// @brief Constructs the specialized provider for the entity type OR.
            /// @note The dependencies of this class will be injected automatically.
            /// @param entity_type_builder_manager The entity type builder manager.
			OrEntityTypeProvider(
				std::shared_ptr<EntityTypeBuilderFactory> entity_type_builder_manager
			) : EntityTypeProvider(
				entity_type_builder_manager,
				TYPE_NAME,
				{
					{ OR_INPUT_1, { DataType::BOOL, 1 << Feature::INPUT } },
					{ OR_INPUT_2, { DataType::BOOL, 1 << Feature::INPUT } },
					{ OR_RESULT, { DataType::BOOL, 1 << Feature::OUTPUT } }
				}
			) {};

            /// Destructor.
			~OrEntityTypeProvider() {};

			/// Defines the name of this entity type.
			static constexpr char TYPE_NAME[] = "OR";

			/// The name of the attribute or_input_1.
			static constexpr char OR_INPUT_1[] = "or_input_1";

			/// The name of the attribute or_input_1.
			static constexpr char OR_INPUT_2[] = "or_input_2";

			/// The name of the attribute or_result.
			static constexpr char OR_RESULT[] = "or_result";

	};

}
}
}
