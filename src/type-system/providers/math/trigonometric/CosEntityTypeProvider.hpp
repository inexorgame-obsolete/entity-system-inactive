#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	/// Provides an entity type "COS": cos_value = cos(cos_input)
	class CosEntityTypeProvider : public EntityTypeProvider
	{
		public:

			/// Constructs the specialized provider for the entity type COS.
			CosEntityTypeProvider(
				std::shared_ptr<EntityTypeBuilderFactory> entity_type_builder_manager
			) : EntityTypeProvider(
				entity_type_builder_manager,
				TYPE_NAME,
				{
					{ COS_INPUT, { DataType::FLOAT, 1 << Feature::INPUT } },
					{ COS_VALUE, { DataType::FLOAT, 1 << Feature::OUTPUT } }
				}
			) {};

			~CosEntityTypeProvider() {};

			/// Defines the name of this entity type
			static constexpr char TYPE_NAME[] = "COS";

			/// The name for the attribute cos_input.
			static constexpr char COS_INPUT[] = "cos_input";

			/// The name for the attribute cos_value.
			static constexpr char COS_VALUE[] = "cos_value";

	};

}
}
}
