// Inexor entity system
// (c)2018 Inexor

#pragma once

#include "entity-system/managers/entities/entity-type-builder-manager/EntityTypeBuilderManager.hpp"
#include "entity-system/providers/entities/entity-type-provider/EntityTypeProvider.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace entity_system {
namespace type_system {

	/// @class StringStoreEntityTypeProvider
    /// @brief Provides the entity type STRING_STORE.
	class StringStoreEntityTypeProvider : public EntityTypeProvider
	{
		public:

			/// Constructor.
			StringStoreEntityTypeProvider(
				shared_ptr<EntityTypeBuilderManager> entity_type_builder_manager
			) : EntityTypeProvider(
				entity_type_builder_manager,
				"STRING_STORE",
				{
					{ "name", DataType::STRING },
					{ "input_value", DataType::STRING },
					{ "default_value", DataType::STRING },
					{ "output_value", DataType::STRING }
				}
			) {};

			/// Destructor.
			~StringStoreEntityTypeProvider() {};

	};

}
}
}
