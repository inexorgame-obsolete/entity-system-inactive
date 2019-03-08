#pragma once

#include "entity-system/managers/entities/entity-type-builder-manager/EntityTypeBuilderManager.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	/// Provides an entity type "FLOAT_CONSTANT" which is a pure float constant variable.
	class FloatConstantEntityTypeProvider : public EntityTypeProvider
	{
		public:

			/// Constructs the specialized provider for the FLOAT_CONSTANT entity type
			FloatConstantEntityTypeProvider(
				std::shared_ptr<EntityTypeBuilderManager> entity_type_builder_manager
			) : EntityTypeProvider(
				entity_type_builder_manager,
				TYPE_NAME,
				{
					{ FLOAT_CONSTANT_NAME, { DataType::STRING, 1 << Feature::OUTPUT } },
					{ FLOAT_CONSTANT_VALUE, { DataType::FLOAT, 1 << Feature::OUTPUT } }
				}
			) {};

			~FloatConstantEntityTypeProvider() {};

			/// Defines the name of this entity type
			static constexpr char TYPE_NAME[] = "FLOAT_CONSTANT";

			/// The name of the output attribute float_constant_name
			static constexpr char FLOAT_CONSTANT_NAME[] = "float_constant_name";

			/// The name of the output attribute float_constant_value
			static constexpr char FLOAT_CONSTANT_VALUE[] = "float_constant_value";

	};

}
}
}
