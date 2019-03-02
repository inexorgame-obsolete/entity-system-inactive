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

	/// @class AddIntEntityTypeProvider
    /// @brief Provides the entity type ADD_INT.
	class AddIntEntityTypeProvider : public EntityTypeProvider
	{
		public:

			/// Constructor.
			AddIntEntityTypeProvider(
				shared_ptr<EntityTypeBuilderManager> entity_type_builder_manager
			) : EntityTypeProvider(
				entity_type_builder_manager,
				"ADD_INT",
				{
					{ "add_int_augend", DataType::INT },
					{ "add_int_addend", DataType::INT },
					{ "add_int_sum", DataType::INT }
				},
				{
					{ "add_int_augend", 1 << Feature::INPUT },
					{ "add_int_addend", 1 << Feature::INPUT },
					{ "add_int_sum", 1 << Feature::OUTPUT }
				}
			) {};

			/// Destructor.
			~AddIntEntityTypeProvider() {};

	};

}
}
}
