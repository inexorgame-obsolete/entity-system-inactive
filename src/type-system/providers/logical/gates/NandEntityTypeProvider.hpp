#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

    /// @class NandEntityTypeProvider
	/// @brief Provides an entity type "NAND".
	class NandEntityTypeProvider : public EntityTypeProvider
	{
		public:

			/// @brief Constructs the specialized provider for the entity type NAND.
            /// @note The dependencies of this class will be injected automatically.
            /// @param entity_type_builder_manager The entity type builder manager.
			NandEntityTypeProvider(
				std::shared_ptr<EntityTypeBuilderFactory> entity_type_builder_manager
			) : EntityTypeProvider(
				entity_type_builder_manager,
				TYPE_NAME,
				{
					{ NAND_INPUT_1, { DataType::BOOL, 1 << Feature::INPUT } },
					{ NAND_INPUT_2, { DataType::BOOL, 1 << Feature::INPUT } },
					{ NAND_RESULT, { DataType::BOOL, 1 << Feature::OUTPUT } }
				}
			) {};

            /// Destructor.
			~NandEntityTypeProvider() {};

			/// Defines the name of this entity type.
			static constexpr char TYPE_NAME[] = "NAND";

			/// The name of the attribute nand_input_1.
			static constexpr char NAND_INPUT_1[] = "nand_input_1";

			/// The name of the attribute nand_input_1.
			static constexpr char NAND_INPUT_2[] = "nand_input_2";

			/// The name of the attribute nand_result.
			static constexpr char NAND_RESULT[] = "nand_result";

	};

}
}
}
