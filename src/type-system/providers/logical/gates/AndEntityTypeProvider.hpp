#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

    /// @class AndEntityTypeProvider
	/// @brief Provides an entity type "AND".
	class AndEntityTypeProvider : public EntityTypeProvider
	{
		public:

			/// Constructs the specialized provider for the entity type AND.
            /// @note The dependencies of this class will be injected automatically.
            /// @param entity_type_builder_manager The entity type builder manager.
			AndEntityTypeProvider(
				std::shared_ptr<EntityTypeBuilderFactory> entity_type_builder_manager
			) : EntityTypeProvider(
				entity_type_builder_manager,
				TYPE_NAME,
				{
					{ AND_INPUT_1, { DataType::BOOL, 1 << Feature::INPUT } },
					{ AND_INPUT_2, { DataType::BOOL, 1 << Feature::INPUT } },
					{ AND_RESULT, { DataType::BOOL, 1 << Feature::OUTPUT } }
				}
			) {};

            /// Destructor.
			~AndEntityTypeProvider() {};

			/// Defines the name of this entity type.
			static constexpr char TYPE_NAME[] = "AND";

			/// The name of the attribute and_input_1.
			static constexpr char AND_INPUT_1[] = "and_input_1";

			/// The name of the attribute and_input_1.
			static constexpr char AND_INPUT_2[] = "and_input_2";

			/// The name of the attribute and_result.
			static constexpr char AND_RESULT[] = "and_result";

	};

}
}
}
