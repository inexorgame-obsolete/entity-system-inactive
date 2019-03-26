#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

    /// @class InRangeIntEntityTypeProvider
	/// @brief Provides an entity type "IN_RANGE_INT".
	class InRangeIntEntityTypeProvider : public EntityTypeProvider
	{
		public:

			/// @brief Constructs the specialized provider for the entity type IN_RANGE_INT.
            /// @note The dependencies of this class will be injected automatically.
            /// @param entity_type_builder_manager The entity type builder manager.
			InRangeIntEntityTypeProvider(
				std::shared_ptr<EntityTypeBuilderFactory> entity_type_builder_manager
			) : EntityTypeProvider(
				entity_type_builder_manager,
				TYPE_NAME,
				{
					{ IN_RANGE_INT_INPUT, { DataType::INT, 1 << Feature::INPUT } },
					{ IN_RANGE_INT_MIN, { DataType::INT, 1 << Feature::INPUT } },
					{ IN_RANGE_INT_MAX, { DataType::INT, 1 << Feature::INPUT } },
					{ IN_RANGE_INT_RESULT, { DataType::BOOL, 1 << Feature::OUTPUT } }
				}
			) {};

            /// Destructor.
			~InRangeIntEntityTypeProvider() {};

			/// Defines the name of this entity type.
			static constexpr char TYPE_NAME[] = "IN_RANGE_INT";

			/// The name of the attribute in_range_int_input.
			static constexpr char IN_RANGE_INT_INPUT[] = "in_range_int_input";

			/// The name of the attribute in_range_int_min.
			static constexpr char IN_RANGE_INT_MIN[] = "in_range_int_min";

			/// The name of the attribute in_range_int_max.
			static constexpr char IN_RANGE_INT_MAX[] = "in_range_int_max";

			/// The name of the attribute in_range_int_result.
			static constexpr char IN_RANGE_INT_RESULT[] = "in_range_int_result";

	};

}
}
}
