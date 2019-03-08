#pragma once

#include "entity-system/managers/entities/entity-type-builder-manager/EntityTypeBuilderManager.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	/// Provides an entity type "INT_STORE".
	class IntStoreEntityTypeProvider : public EntityTypeProvider
	{
		public:

			/// Constructs the specialized provider for the INT_STORE entity type
			IntStoreEntityTypeProvider(
				std::shared_ptr<EntityTypeBuilderManager> entity_type_builder_manager
			) : EntityTypeProvider(
				entity_type_builder_manager,
				TYPE_NAME,
				{
					{ INT_STORE_NAME, { DataType::STRING, 1 << Feature::OUTPUT } },
					{ INT_STORE_INPUT_VALUE, { DataType::INT, 1 << Feature::INPUT } },
					{ INT_STORE_DEFAULT_VALUE, { DataType::INT, 1 << Feature::INPUT | 1 << Feature::OUTPUT } },
					{ INT_STORE_OUTPUT_VALUE, { DataType::INT, 1 << Feature::OUTPUT } }
				}
			) {};

			~IntStoreEntityTypeProvider() {};

			/// Defines the name of this entity type
			static constexpr char TYPE_NAME[] = "INT_STORE";

			/// The name of the store
			static constexpr char INT_STORE_NAME[] = "int_store_name";

			/// The name of the input attribute
			static constexpr char INT_STORE_INPUT_VALUE[] = "int_store_input_value";

			/// The name of the default value attribute
			static constexpr char INT_STORE_DEFAULT_VALUE[] = "int_store_default_value";

			/// The name of the output value attribute
			static constexpr char INT_STORE_OUTPUT_VALUE[] = "int_store_output_value";

	};

}
}
}
