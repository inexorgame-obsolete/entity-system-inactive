#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	/// Provides an entity type "TIMER_TICK".
	class TimerTickEntityTypeProvider : public EntityTypeProvider
	{
		public:

			/// Constructs the specialized provider for the entity type TIMER_TICK
			TimerTickEntityTypeProvider(
				std::shared_ptr<EntityTypeBuilderFactory> entity_type_builder_manager
			) : EntityTypeProvider(
				entity_type_builder_manager,
				TYPE_NAME,
				{
					{ TIMER_TICK_MILLIS, { DataType::INT, 1 << Feature::INPUT } },
					{ TIMER_TICK_VALUE, { DataType::BOOL, 1 << Feature::OUTPUT } }
				}
			) {};

			~TimerTickEntityTypeProvider() {};

			/// Defines the name of this entity type
			static constexpr char TYPE_NAME[] = "TIMER_TICK";

			/// The name of the attribute timer_tick_millis
			static constexpr char TIMER_TICK_MILLIS[] = "timer_tick_millis";

			/// The name of the attribute timer_tick_value
			static constexpr char TIMER_TICK_VALUE[] = "timer_tick_value";

	};

}
}
}
