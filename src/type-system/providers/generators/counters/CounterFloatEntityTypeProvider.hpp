#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	/// Provides an entity type "COUNTER_FLOAT".
	class CounterFloatEntityTypeProvider : public EntityTypeProvider
	{
		public:

			/// Constructs the specialized provider for the entity type COUNTER_FLOAT
			CounterFloatEntityTypeProvider(
				std::shared_ptr<EntityTypeBuilderFactory> entity_type_builder_manager
			) : EntityTypeProvider(
				entity_type_builder_manager,
				TYPE_NAME,
				{
					{ COUNTER_FLOAT_MILLIS, { DataType::INT, 1 << Feature::INPUT } },
					{ COUNTER_FLOAT_STEP, { DataType::FLOAT, 1 << Feature::INPUT } },
					{ COUNTER_FLOAT_RESET, { DataType::BOOL, 1 << Feature::INPUT } },
					{ COUNTER_FLOAT_COUNT, { DataType::FLOAT, 1 << Feature::OUTPUT } }
				}
			) {};

			~CounterFloatEntityTypeProvider() {};

			/// Defines the name of this entity type
			static constexpr char TYPE_NAME[] = "COUNTER_FLOAT";

			/// The name of the attribute counter_float_millis
			static constexpr char COUNTER_FLOAT_MILLIS[] = "counter_float_millis";

			/// The name of the attribute counter_float_step
			static constexpr char COUNTER_FLOAT_STEP[] = "counter_float_step";

			/// The name of the attribute counter_float_reset
			static constexpr char COUNTER_FLOAT_RESET[] = "counter_float_reset";

			/// The name of the attribute counter_float_count
			static constexpr char COUNTER_FLOAT_COUNT[] = "counter_float_count";

	};

}
}
}
