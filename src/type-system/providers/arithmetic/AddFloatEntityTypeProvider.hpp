#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

    /// Provides an entity type "ADD_FLOAT" which is the floating point addition.
	class AddFloatEntityTypeProvider : public EntityTypeProvider
	{
		public:

			/// Constructs the specialized provider for the ADD_FLOAT entity type
			AddFloatEntityTypeProvider(
				std::shared_ptr<EntityTypeBuilderFactory> entity_type_builder_manager
			) : EntityTypeProvider(
				entity_type_builder_manager,
				TYPE_NAME,
				{
					{ ADD_FLOAT_AUGEND, { DataType::FLOAT, 1 << Feature::INPUT } },
					{ ADD_FLOAT_ADDEND, { DataType::FLOAT, 1 << Feature::INPUT } },
					{ ADD_FLOAT_SUM, { DataType::FLOAT, 1 << Feature::OUTPUT } }
				}
			) {};

			~AddFloatEntityTypeProvider() {};

			/// Defines the name of this entity type
			static constexpr char TYPE_NAME[] = "ADD_FLOAT";

			/// The name of the input attribute augend
			static constexpr char ADD_FLOAT_AUGEND[] = "add_float_augend";

			/// The name of the input attribute addend
			static constexpr char ADD_FLOAT_ADDEND[] = "add_float_addend";

			/// The name of the output attribute sum
			static constexpr char ADD_FLOAT_SUM[] = "add_float_sum";

	};

}
}
}
