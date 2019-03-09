#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	/// Provides an entity type "INT_TO_FLOAT" which converts int values to float values.
	class IntToFloatEntityTypeProvider : public EntityTypeProvider
	{
		public:

			/// Constructs the specialized provider for the INT_TO_FLOAT entity type
			IntToFloatEntityTypeProvider(
				std::shared_ptr<EntityTypeBuilderFactory> entity_type_builder_manager
			) : EntityTypeProvider(
				entity_type_builder_manager,
				TYPE_NAME,
				{
					{ INT_TO_FLOAT_INPUT, { DataType::INT, 1 << Feature::INPUT } },
					{ INT_TO_FLOAT_VALUE, { DataType::FLOAT, 1 << Feature::OUTPUT } }
				}
			) {};

			~IntToFloatEntityTypeProvider() {};

			/// Defines the name of this entity type
			static constexpr char TYPE_NAME[] = "INT_TO_FLOAT";

			/// The name of the input attribute int_to_float_input
			static constexpr char INT_TO_FLOAT_INPUT[] = "int_to_float_input";

			/// The name of the output attribute int_to_float_value
			static constexpr char INT_TO_FLOAT_VALUE[] = "int_to_float_value";

	};

}
}
}
