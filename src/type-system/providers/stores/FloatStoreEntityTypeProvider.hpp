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

	/// @class FloatStoreEntityTypeProvider
    /// @brief Provides the entity type FLOAT_STORE.
	class FloatStoreEntityTypeProvider : public EntityTypeProvider
	{
		public:

			/// Constructor.
			FloatStoreEntityTypeProvider(
				shared_ptr<EntityTypeBuilderManager> entity_type_builder_manager
			) : EntityTypeProvider(
				entity_type_builder_manager,
				"FLOAT_STORE",
				{
					{ "name", DataType::STRING },
					{ "input_value", DataType::FLOAT },
					{ "default_value", DataType::FLOAT },
					{ "output_value", DataType::FLOAT }
				},
				{
					{ "name", 0 },
					{ "input_value", 1 << Feature::INPUT },
					{ "default_value", 1 << Feature::INPUT | 1 << Feature::OUTPUT },
					{ "output_value", 1 << Feature::OUTPUT }
				}
			) {};

			/// Destructor.
			~FloatStoreEntityTypeProvider() {};

	};

}
}
}
