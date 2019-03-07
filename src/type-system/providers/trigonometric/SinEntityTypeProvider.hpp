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

	/// @class SinEntityTypeProvider
    /// @brief Provides the entity type SIN.
	class SinEntityTypeProvider : public EntityTypeProvider
	{
		public:

			/// Constructor.
			SinEntityTypeProvider(
				shared_ptr<EntityTypeBuilderManager> entity_type_builder_manager
			) : EntityTypeProvider(
				entity_type_builder_manager,
				"SIN",
				{
					{ "sin_value", DataType::FLOAT }
				},
				{
					{ "sin_value", 1 << Feature::OUTPUT }
				}
			) {};

			/// Destructor.
			~SinEntityTypeProvider() {};

	};

}
}
}
