#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	/// Provides an entity type "CONSOLE_STDERR".
	class StdErrEntityTypeProvider : public EntityTypeProvider
	{
		public:

			/// Constructs the specialized provider for the entity type CONSOLE_STDERR
			StdErrEntityTypeProvider(
				std::shared_ptr<EntityTypeBuilderFactory> entity_type_builder_manager
			) : EntityTypeProvider(
				entity_type_builder_manager,
				TYPE_NAME,
				{
					{ CONSOLE_STDERR, { DataType::STRING, 1 << Feature::INPUT } }
				}
			) {};

			~StdErrEntityTypeProvider() {};

			/// Defines the name of this entity type
			static constexpr char TYPE_NAME[] = "CONSOLE_STDERR";

			/// The name of the attribute console_stderr
			static constexpr char CONSOLE_STDERR[] = "console_stderr";

	};

}
}
}
