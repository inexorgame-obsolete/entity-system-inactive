#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	/// Provides an entity type "RANDOM_NEXT_INT".
	class RandomNextIntEntityTypeProvider : public EntityTypeProvider
	{
		public:

			/// Constructs the specialized provider for the entity type RANDOM_NEXT_INT
			RandomNextIntEntityTypeProvider(
				std::shared_ptr<EntityTypeBuilderFactory> entity_type_builder_manager
			) : EntityTypeProvider(
				entity_type_builder_manager,
				TYPE_NAME,
				{
					{ RANDOM_NEXT_INT_ON_ACTIVATION, { DataType::BOOL, 1 << Feature::INPUT } },
					{ RANDOM_NEXT_INT_MIN, { DataType::INT, 1 << Feature::INPUT } },
					{ RANDOM_NEXT_INT_MAX, { DataType::INT, 1 << Feature::INPUT } },
					{ RANDOM_NEXT_INT_VALUE, { DataType::INT, 1 << Feature::OUTPUT } }
				}
			) {};

			~RandomNextIntEntityTypeProvider() {};

			/// Defines the name of this entity type
			static constexpr char TYPE_NAME[] = "RANDOM_NEXT_INT";

			/// The name of the attribute random_next_int_on_activation
			static constexpr char RANDOM_NEXT_INT_ON_ACTIVATION[] = "random_next_int_on_activation";

			/// The name of the attribute random_next_int_min
			static constexpr char RANDOM_NEXT_INT_MIN[] = "random_next_int_min";

			/// The name of the attribute random_next_int_max
			static constexpr char RANDOM_NEXT_INT_MAX[] = "random_next_int_max";

			/// The name of the attribute random_next_int_value
			static constexpr char RANDOM_NEXT_INT_VALUE[] = "random_next_int_value";

	};

}
}
}
