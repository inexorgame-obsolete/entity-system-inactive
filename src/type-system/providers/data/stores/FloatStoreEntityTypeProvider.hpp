#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

    /// @class FloatStoreEntityTypeProvider
	/// @brief Provides an entity type "FLOAT_STORE".
	class FloatStoreEntityTypeProvider : public EntityTypeProvider
	{
		public:

			/// @brief Constructs the specialized provider for the FLOAT_STORE entity type.
            /// @note The dependencies of this class will be injected automatically.
            /// @param entity_type_builder_manager The entity type builder manager.
			FloatStoreEntityTypeProvider(
				std::shared_ptr<EntityTypeBuilderFactory> entity_type_builder_manager
			) : EntityTypeProvider(
				entity_type_builder_manager,
				TYPE_NAME,
				{
					{ FLOAT_STORE_NAME, { DataType::STRING, 1 << Feature::OUTPUT } },
					{ FLOAT_STORE_INPUT_VALUE, { DataType::FLOAT, 1 << Feature::INPUT } },
					{ FLOAT_STORE_DEFAULT_VALUE, { DataType::FLOAT, 1 << Feature::INPUT | 1 << Feature::OUTPUT } },
					{ FLOAT_STORE_OUTPUT_VALUE, { DataType::FLOAT, 1 << Feature::OUTPUT } }
				}
			) {};

            /// Destructor.
			~FloatStoreEntityTypeProvider() {};

			/// Defines the name of this entity type.
			static constexpr char TYPE_NAME[] = "FLOAT_STORE";

			/// The name of the store.
			static constexpr char FLOAT_STORE_NAME[] = "float_store_name";

			/// The name of the input attribute.
			static constexpr char FLOAT_STORE_INPUT_VALUE[] = "float_store_input_value";

			/// The name of the default value attribute.
			static constexpr char FLOAT_STORE_DEFAULT_VALUE[] = "float_store_default_value";

			/// The name of the output value attribute.
			static constexpr char FLOAT_STORE_OUTPUT_VALUE[] = "float_store_output_value";

	};

}
}
}
