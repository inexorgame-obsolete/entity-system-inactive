#pragma once

#include "entity-system/managers/entities/entity-type-builder-manager/EntityTypeBuilderManager.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	/// Provides an entity type "INT_CONSTANT" which is a pure int constant variable.
	class IntConstantEntityTypeProvider : public EntityTypeProvider
	{
		public:

			/// Constructs the specialized provider for the INT_CONSTANT entity type
			IntConstantEntityTypeProvider(
				std::shared_ptr<EntityTypeBuilderManager> entity_type_builder_manager
			) : EntityTypeProvider(
				entity_type_builder_manager,
				TYPE_NAME,
				{
					{ INT_CONSTANT_NAME, { DataType::STRING, 1 << Feature::OUTPUT } },
					{ INT_CONSTANT_VALUE, { DataType::INT, 1 << Feature::OUTPUT } }
				}
			) {};

			~IntConstantEntityTypeProvider() {};

			/// Defines the name of this entity type
			static constexpr char TYPE_NAME[] = "INT_CONSTANT";

			/// The name of the output attribute int_constant_name
			static constexpr char INT_CONSTANT_NAME[] = "int_constant_name";

			/// The name of the output attribute int_constant_value
			static constexpr char INT_CONSTANT_VALUE[] = "int_constant_value";

	};

}
}
}
