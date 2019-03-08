#pragma once

#include "entity-system/managers/entities/entity-type-builder-manager/EntityTypeBuilderManager.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	/// Provides an entity type "COS" which is a cosinus value generator.
	class CosEntityTypeProvider : public EntityTypeProvider
	{
		public:

			/// Constructs the specialized provider for the COS entity type
			CosEntityTypeProvider(
				std::shared_ptr<EntityTypeBuilderManager> entity_type_builder_manager
			) : EntityTypeProvider(
				entity_type_builder_manager,
				TYPE_NAME,
				{
					{ COS_VALUE, { DataType::FLOAT, 1 << Feature::OUTPUT } }
				}
			) {};

			/// Destructor.
			~CosEntityTypeProvider() {};

			/// Defines the name of this entity type
			static constexpr char TYPE_NAME[] = "COS";

			/// The cosinus value attribute
			static constexpr char COS_VALUE[] = "cos_value";

	};

}
}
}
