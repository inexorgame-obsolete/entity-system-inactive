#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	/// Provides an entity type "STRING_STORE".
	class StringStoreEntityTypeProvider : public EntityTypeProvider
	{
		public:

			/// Constructs the specialized provider for the STRING_STORE entity type
			StringStoreEntityTypeProvider(
				std::shared_ptr<EntityTypeBuilderFactory> entity_type_builder_manager
			) : EntityTypeProvider(
				entity_type_builder_manager,
				TYPE_NAME,
				{
					{ STRING_STORE_NAME, { DataType::STRING, 1 << Feature::OUTPUT } },
					{ STRING_STORE_INPUT_VALUE, { DataType::STRING, 1 << Feature::INPUT } },
					{ STRING_STORE_DEFAULT_VALUE, { DataType::STRING, 1 << Feature::INPUT | 1 << Feature::OUTPUT } },
					{ STRING_STORE_OUTPUT_VALUE, { DataType::STRING, 1 << Feature::OUTPUT } }
				}
			) {};

			~StringStoreEntityTypeProvider() {};

			/// Defines the name of this entity type
			static constexpr char TYPE_NAME[] = "STRING_STORE";

			/// The name of the store
			static constexpr char STRING_STORE_NAME[] = "string_store_name";

			/// The name of the input attribute
			static constexpr char STRING_STORE_INPUT_VALUE[] = "string_store_input_value";

			/// The name of the default value attribute
			static constexpr char STRING_STORE_DEFAULT_VALUE[] = "string_store_default_value";

			/// The name of the output value attribute
			static constexpr char STRING_STORE_OUTPUT_VALUE[] = "string_store_output_value";

	};

}
}
}
