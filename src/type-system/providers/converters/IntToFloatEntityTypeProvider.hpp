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

	/// @class IntToFloatEntityTypeProvider
    /// @brief Provides the entity type INT_TO_FLOAT.
	class IntToFloatEntityTypeProvider : public EntityTypeProvider
	{
		public:

			/// Constructor.
			IntToFloatEntityTypeProvider(
				shared_ptr<EntityTypeBuilderManager> entity_type_builder_manager
			) : EntityTypeProvider(
				entity_type_builder_manager,
				"INT_TO_FLOAT",
				{
					{ "input", ENTSYS_DATA_TYPE_INT },
					{ "value", ENTSYS_DATA_TYPE_FLOAT }
				}
			) {};

			/// Destructor.
			~IntToFloatEntityTypeProvider() {};

	};

}
}
}
