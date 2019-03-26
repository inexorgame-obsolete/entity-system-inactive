#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

    /// @class InRangeFloatEntityTypeProvider
	/// @brief Provides an entity type "IN_RANGE_FLOAT".
	class InRangeFloatEntityTypeProvider : public EntityTypeProvider
	{
		public:

			/// @brief Constructs the specialized provider for the entity type IN_RANGE_FLOAT.
            /// @note The dependencies of this class will be injected automatically.
            /// @param entity_type_builder_manager The entity type builder manager.
			InRangeFloatEntityTypeProvider(
				std::shared_ptr<EntityTypeBuilderFactory> entity_type_builder_manager
			) : EntityTypeProvider(
				entity_type_builder_manager,
				TYPE_NAME,
				{
					{ IN_RANGE_FLOAT_INPUT, { DataType::FLOAT, 1 << Feature::INPUT } },
					{ IN_RANGE_FLOAT_MIN, { DataType::FLOAT, 1 << Feature::INPUT } },
					{ IN_RANGE_FLOAT_MAX, { DataType::FLOAT, 1 << Feature::INPUT } },
					{ IN_RANGE_FLOAT_RESULT, { DataType::BOOL, 1 << Feature::OUTPUT } }
				}
			) {};

            /// Destructor.
			~InRangeFloatEntityTypeProvider() {};

			/// Defines the name of this entity type.
			static constexpr char TYPE_NAME[] = "IN_RANGE_FLOAT";

			/// The name of the attribute in_range_float_input.
			static constexpr char IN_RANGE_FLOAT_INPUT[] = "in_range_float_input";

			/// The name of the attribute in_range_float_min.
			static constexpr char IN_RANGE_FLOAT_MIN[] = "in_range_float_min";

			/// The name of the attribute in_range_float_max.
			static constexpr char IN_RANGE_FLOAT_MAX[] = "in_range_float_max";

			/// The name of the attribute in_range_float_result.
			static constexpr char IN_RANGE_FLOAT_RESULT[] = "in_range_float_result";

	};

}
}
}
