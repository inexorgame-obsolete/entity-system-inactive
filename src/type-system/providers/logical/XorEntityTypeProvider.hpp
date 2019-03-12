#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	/// Provides an entity type "XOR".
	class XorEntityTypeProvider : public EntityTypeProvider
	{
		public:

			/// Constructs the specialized provider for the entity type XOR
			XorEntityTypeProvider(
				std::shared_ptr<EntityTypeBuilderFactory> entity_type_builder_manager
			) : EntityTypeProvider(
				entity_type_builder_manager,
				TYPE_NAME,
				{
					{ XOR_INPUT_1, { DataType::BOOL, 1 << Feature::INPUT } },
					{ XOR_INPUT_2, { DataType::BOOL, 1 << Feature::INPUT } },
					{ XOR_RESULT, { DataType::BOOL, 1 << Feature::OUTPUT } }
				}
			) {};

			~XorEntityTypeProvider() {};

			/// Defines the name of this entity type
			static constexpr char TYPE_NAME[] = "XOR";

			/// The name of the attribute xor_input_1
			static constexpr char XOR_INPUT_1[] = "xor_input_1";

			/// The name of the attribute xor_input_1
			static constexpr char XOR_INPUT_2[] = "xor_input_2";

			/// The name of the attribute xor_result
			static constexpr char XOR_RESULT[] = "xor_result";

	};

}
}
}
