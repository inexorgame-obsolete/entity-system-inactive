#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	/// Provides an entity type "TAN" which is a tangent value generator.
	class TanEntityTypeProvider : public EntityTypeProvider
	{
		public:

			/// Constructs the specialized provider for the TAN entity type
			TanEntityTypeProvider(
				std::shared_ptr<EntityTypeBuilderFactory> entity_type_builder_manager
			) : EntityTypeProvider(
				entity_type_builder_manager,
				TYPE_NAME,
				{
					{ TAN_VALUE, { DataType::FLOAT, 1 << Feature::OUTPUT } }
				}
			) {};

			/// Destructor.
			~TanEntityTypeProvider() {};

			/// Defines the name of this entity type
			static constexpr char TYPE_NAME[] = "TAN";

			/// The taninus value attribute
			static constexpr char TAN_VALUE[] = "tan_value";

	};

}
}
}
