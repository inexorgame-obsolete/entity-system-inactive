#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	/// Provides an entity type "CONSOLE_STDOUT".
	class StdOutEntityTypeProvider : public EntityTypeProvider
	{
		public:

			/// Constructs the specialized provider for the entity type CONSOLE_STDOUT
			StdOutEntityTypeProvider(
				std::shared_ptr<EntityTypeBuilderFactory> entity_type_builder_manager
			) : EntityTypeProvider(
				entity_type_builder_manager,
				TYPE_NAME,
				{
					{ CONSOLE_STDOUT, { DataType::STRING, 1 << Feature::INPUT } }
				}
			) {};

			~StdOutEntityTypeProvider() {};

			/// Defines the name of this entity type
			static constexpr char TYPE_NAME[] = "CONSOLE_STDOUT";

			/// The name of the attribute console_stdout
			static constexpr char CONSOLE_STDOUT[] = "console_stdout";

	};

}
}
}
