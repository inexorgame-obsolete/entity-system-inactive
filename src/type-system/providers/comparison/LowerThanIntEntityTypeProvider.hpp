#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	/// Provides an entity type "LOWER_THAN_INT".
	class LowerThanIntEntityTypeProvider : public EntityTypeProvider
	{
		public:

			/// Constructs the specialized provider for the entity type LOWER_THAN_INT
			LowerThanIntEntityTypeProvider(
				std::shared_ptr<EntityTypeBuilderFactory> entity_type_builder_manager
			) : EntityTypeProvider(
				entity_type_builder_manager,
				TYPE_NAME,
				{
					{ LOWER_THAN_INT_INPUT_1, { DataType::INT, 1 << Feature::INPUT } },
					{ LOWER_THAN_INT_INPUT_2, { DataType::INT, 1 << Feature::INPUT } },
					{ LOWER_THAN_INT_RESULT, { DataType::BOOL, 1 << Feature::OUTPUT } }
				}
			) {};

			~LowerThanIntEntityTypeProvider() {};

			/// Defines the name of this entity type
			static constexpr char TYPE_NAME[] = "LOWER_THAN_INT";

			/// The name of the attribute lower_than_int_input_1
			static constexpr char LOWER_THAN_INT_INPUT_1[] = "lower_than_int_input_1";

			/// The name of the attribute lower_than_int_input_1
			static constexpr char LOWER_THAN_INT_INPUT_2[] = "lower_than_int_input_2";

			/// The name of the attribute lower_than_int_result
			static constexpr char LOWER_THAN_INT_RESULT[] = "lower_than_int_result";

	};

}
}
}
