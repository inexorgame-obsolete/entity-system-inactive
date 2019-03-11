#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	/// Provides an entity type "CONSOLE_STDIN".
	class StdInEntityTypeProvider : public EntityTypeProvider
	{
		public:

			/// Constructs the specialized provider for the LOGGER entity type
			StdInEntityTypeProvider(
				std::shared_ptr<EntityTypeBuilderFactory> entity_type_builder_manager
			) : EntityTypeProvider(
				entity_type_builder_manager,
				TYPE_NAME,
				{
					{ CONSOLE_STDIN, { DataType::STRING, 1 << Feature::OUTPUT } }
				}
			) {};

			~StdInEntityTypeProvider() {};

			/// Defines the name of this entity type
			static constexpr char TYPE_NAME[] = "CONSOLE_STDIN";

			/// The name of the attribute console_std_out
			static constexpr char CONSOLE_STDIN[] = "console_stdin";

	};

}
}
}
