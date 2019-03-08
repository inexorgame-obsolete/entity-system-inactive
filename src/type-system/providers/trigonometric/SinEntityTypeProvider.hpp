#pragma once

#include "entity-system/managers/entities/entity-type-builder-manager/EntityTypeBuilderManager.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	/// Provides an entity type "SIN" which is a sinus value generator.
	class SinEntityTypeProvider : public EntityTypeProvider
	{
		public:

			/// Constructs the specialized provider for the SIN entity type
			SinEntityTypeProvider(
				std::shared_ptr<EntityTypeBuilderManager> entity_type_builder_manager
			) : EntityTypeProvider(
				entity_type_builder_manager,
				TYPE_NAME,
				{
					{ SIN_VALUE, { DataType::FLOAT, 1 << Feature::OUTPUT } }
				}
			) {};

			/// Destructor.
			~SinEntityTypeProvider() {};

			/// Defines the name of this entity type
			static constexpr char TYPE_NAME[] = "SIN";

			/// The sinus value attribute
			static constexpr char SIN_VALUE[] = "sin_value";

	};

}
}
}
