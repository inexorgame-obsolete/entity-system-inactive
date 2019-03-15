#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	/// Provides an entity type "RANDOM_NEXT_FLOAT".
	class RandomNextFloatEntityTypeProvider : public EntityTypeProvider
	{
		public:

			/// Constructs the specialized provider for the entity type RANDOM_NEXT_FLOAT
			RandomNextFloatEntityTypeProvider(
				std::shared_ptr<EntityTypeBuilderFactory> entity_type_builder_manager
			) : EntityTypeProvider(
				entity_type_builder_manager,
				TYPE_NAME,
				{
					{ RANDOM_NEXT_FLOAT_ON_ACTIVATION, { DataType::BOOL, 1 << Feature::INPUT } },
					{ RANDOM_NEXT_FLOAT_MIN, { DataType::FLOAT, 1 << Feature::INPUT } },
					{ RANDOM_NEXT_FLOAT_MAX, { DataType::FLOAT, 1 << Feature::INPUT } },
					{ RANDOM_NEXT_FLOAT_VALUE, { DataType::FLOAT, 1 << Feature::OUTPUT } }
				}
			) {};

			~RandomNextFloatEntityTypeProvider() {};

			/// Defines the name of this entity type
			static constexpr char TYPE_NAME[] = "RANDOM_NEXT_FLOAT";

			/// The name of the attribute random_next_float_on_activation
			static constexpr char RANDOM_NEXT_FLOAT_ON_ACTIVATION[] = "random_next_float_on_activation";

			/// The name of the attribute random_next_float_min
			static constexpr char RANDOM_NEXT_FLOAT_MIN[] = "random_next_float_min";

			/// The name of the attribute random_next_float_max
			static constexpr char RANDOM_NEXT_FLOAT_MAX[] = "random_next_float_max";

			/// The name of the attribute random_next_float_value
			static constexpr char RANDOM_NEXT_FLOAT_VALUE[] = "random_next_float_value";

	};

}
}
}
