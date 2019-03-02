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
					{ "int_to_float_input", DataType::INT },
					{ "int_to_float_value", DataType::FLOAT }
				},
				{
					{ "int_to_float_input", 1 << Feature::INPUT },
					{ "int_to_float_value", 1 << Feature::OUTPUT }
				}
			) {};

			/// Destructor.
			~IntToFloatEntityTypeProvider() {};

	};

}
}
}
