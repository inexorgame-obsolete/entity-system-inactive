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

	/// @class FloatConstantEntityTypeProvider
    /// @brief Provides the entity type FLOAT_CONSTANT.
	class FloatConstantEntityTypeProvider : public EntityTypeProvider
	{
		public:

			/// Constructor.
			FloatConstantEntityTypeProvider(
				shared_ptr<EntityTypeBuilderManager> entity_type_builder_manager
			) : EntityTypeProvider(
				entity_type_builder_manager,
				"FLOAT_CONSTANT",
				{
					{ "name", ENTSYS_DATA_TYPE_STRING },
					{ "value", ENTSYS_DATA_TYPE_FLOAT }
				}
			) {};

			/// Destructor.
			~FloatConstantEntityTypeProvider() {};

	};

}
}
}
