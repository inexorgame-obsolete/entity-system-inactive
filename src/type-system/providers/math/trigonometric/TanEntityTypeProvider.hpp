#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	/// Provides an entity type "TAN": tan_value = tan(tan_input)
	class TanEntityTypeProvider : public EntityTypeProvider
	{
		public:

			/// Constructs the specialized provider for the entity type TAN.
			TanEntityTypeProvider(
				std::shared_ptr<EntityTypeBuilderFactory> entity_type_builder_manager
			) : EntityTypeProvider(
				entity_type_builder_manager,
				TYPE_NAME,
				{
					{ TAN_INPUT, { DataType::FLOAT, 1 << Feature::INPUT } },
					{ TAN_VALUE, { DataType::FLOAT, 1 << Feature::OUTPUT } }
				}
			) {};

			~TanEntityTypeProvider() {};

			/// Defines the name of this entity type
			static constexpr char TYPE_NAME[] = "TAN";

			/// The name for the attribute tan_input.
			static constexpr char TAN_INPUT[] = "tan_input";

			/// The name for the attribute tan_value.
			static constexpr char TAN_VALUE[] = "tan_value";

	};

}
}
}
