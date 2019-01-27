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

	/// @class IntStoreEntityTypeProvider
    /// @brief Provides the entity type INT_STORE.
	class IntStoreEntityTypeProvider : public EntityTypeProvider
	{
		public:

			/// Constructor.
			IntStoreEntityTypeProvider(
				shared_ptr<EntityTypeBuilderManager> entity_type_builder_manager
			) : EntityTypeProvider(
				entity_type_builder_manager,
				"INT_STORE",
				{
					{ "name", ENTSYS_DATA_TYPE_STRING },
					{ "input_value", ENTSYS_DATA_TYPE_INT },
					{ "default_value", ENTSYS_DATA_TYPE_INT },
					{ "output_value", ENTSYS_DATA_TYPE_INT }
				}
			) {};

			/// Destructor.
			~IntStoreEntityTypeProvider() {};

	};

}
}
}
