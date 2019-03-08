#pragma once

#include "entity-system/managers/entities/entity-type-builder-manager/EntityTypeBuilderManager.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	/// Provides an entity type "BOOL_CONSTANT" which is a pure bool constant variable.
	class BoolConstantEntityTypeProvider : public EntityTypeProvider
	{
		public:

			/// Constructs the specialized provider for the BOOL_CONSTANT entity type
			BoolConstantEntityTypeProvider(
				std::shared_ptr<EntityTypeBuilderManager> entity_type_builder_manager
			) : EntityTypeProvider(
				entity_type_builder_manager,
				TYPE_NAME,
				{
					{ BOOL_CONSTANT_NAME, { DataType::STRING, 1 << Feature::OUTPUT } },
					{ BOOL_CONSTANT_VALUE, { DataType::BOOL, 1 << Feature::OUTPUT } }
				}
			) {};

			~BoolConstantEntityTypeProvider() {};

			/// Defines the name of this entity type
			static constexpr char TYPE_NAME[] = "BOOL_CONSTANT";

			/// The name of the output attribute bool_constant_name
			static constexpr char BOOL_CONSTANT_NAME[] = "bool_constant_name";

			/// The name of the output attribute bool_constant_value
			static constexpr char BOOL_CONSTANT_VALUE[] = "bool_constant_value";

	};

}
}
}
