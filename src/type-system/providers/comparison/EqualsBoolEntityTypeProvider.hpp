#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	/// Provides an entity type "EQUALS_BOOL".
	class EqualsBoolEntityTypeProvider : public EntityTypeProvider
	{
		public:

			/// Constructs the specialized provider for the entity type EQUALS_BOOL
			EqualsBoolEntityTypeProvider(
				std::shared_ptr<EntityTypeBuilderFactory> entity_type_builder_manager
			) : EntityTypeProvider(
				entity_type_builder_manager,
				TYPE_NAME,
				{
					{ EQUALS_BOOL_INPUT_1, { DataType::BOOL, 1 << Feature::INPUT } },
					{ EQUALS_BOOL_INPUT_2, { DataType::BOOL, 1 << Feature::INPUT } },
					{ EQUALS_BOOL_RESULT, { DataType::BOOL, 1 << Feature::OUTPUT } }
				}
			) {};

			~EqualsBoolEntityTypeProvider() {};

			/// Defines the name of this entity type
			static constexpr char TYPE_NAME[] = "EQUALS_BOOL";

			/// The name of the attribute equals_bool_input_1
			static constexpr char EQUALS_BOOL_INPUT_1[] = "equals_bool_input_1";

			/// The name of the attribute equals_bool_input_1
			static constexpr char EQUALS_BOOL_INPUT_2[] = "equals_bool_input_2";

			/// The name of the attribute equals_bool_result
			static constexpr char EQUALS_BOOL_RESULT[] = "equals_bool_result";

	};

}
}
}