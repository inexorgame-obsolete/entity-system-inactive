#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

    /// @class CounterIntEntityTypeProvider
	/// @brief Provides an entity type "COUNTER_INT".
	class CounterIntEntityTypeProvider : public EntityTypeProvider
	{
		public:

			/// @brief Constructs the specialized provider for the entity type COUNTER_INT.
            /// @note The dependencies of this class will be injected automatically.
            /// @param entity_type_builder_manager The entity type builder manager.
			CounterIntEntityTypeProvider(
				std::shared_ptr<EntityTypeBuilderFactory> entity_type_builder_manager
			) : EntityTypeProvider(
				entity_type_builder_manager,
				TYPE_NAME,
				{
					{ COUNTER_INT_MILLIS, { DataType::INT, 1 << Feature::INPUT } },
					{ COUNTER_INT_STEP, { DataType::INT, 1 << Feature::INPUT } },
					{ COUNTER_INT_RESET, { DataType::BOOL, 1 << Feature::INPUT } },
					{ COUNTER_INT_COUNT, { DataType::INT, 1 << Feature::OUTPUT } }
				}
			) {};

            /// Destructor.
			~CounterIntEntityTypeProvider() {};

			/// Defines the name of this entity type.
			static constexpr char TYPE_NAME[] = "COUNTER_INT";

			/// The name of the attribute counter_int_millis.
			static constexpr char COUNTER_INT_MILLIS[] = "counter_int_millis";

			/// The name of the attribute counter_int_step.
			static constexpr char COUNTER_INT_STEP[] = "counter_int_step";

			/// The name of the attribute counter_int_reset.
			static constexpr char COUNTER_INT_RESET[] = "counter_int_reset";

			/// The name of the attribute counter_int_count.
			static constexpr char COUNTER_INT_COUNT[] = "counter_int_count";

	};

}
}
}
