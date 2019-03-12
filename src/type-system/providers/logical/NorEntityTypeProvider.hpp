#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	/// Provides an entity type "NOR".
	class NorEntityTypeProvider : public EntityTypeProvider
	{
		public:

			/// Constructs the specialized provider for the entity type NOR
			NorEntityTypeProvider(
				std::shared_ptr<EntityTypeBuilderFactory> entity_type_builder_manager
			) : EntityTypeProvider(
				entity_type_builder_manager,
				TYPE_NAME,
				{
					{ NOR_INPUT_1, { DataType::BOOL, 1 << Feature::INPUT } },
					{ NOR_INPUT_2, { DataType::BOOL, 1 << Feature::INPUT } },
					{ NOR_RESULT, { DataType::BOOL, 1 << Feature::OUTPUT } }
				}
			) {};

			~NorEntityTypeProvider() {};

			/// Defines the name of this entity type
			static constexpr char TYPE_NAME[] = "NOR";

			/// The name of the attribute nor_input_1
			static constexpr char NOR_INPUT_1[] = "nor_input_1";

			/// The name of the attribute nor_input_1
			static constexpr char NOR_INPUT_2[] = "nor_input_2";

			/// The name of the attribute nor_result
			static constexpr char NOR_RESULT[] = "nor_result";

	};

}
}
}