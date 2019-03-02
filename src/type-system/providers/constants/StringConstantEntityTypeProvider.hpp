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

	/// @class StringConstantEntityTypeProvider
    /// @brief Provides the entity type STRING_CONSTANT.
	class StringConstantEntityTypeProvider : public EntityTypeProvider
	{
		public:

			/// Constructor.
			StringConstantEntityTypeProvider(
				shared_ptr<EntityTypeBuilderManager> entity_type_builder_manager
			) : EntityTypeProvider(
				entity_type_builder_manager,
				"STRING_CONSTANT",
				{
					{ "string_constant_name", DataType::STRING },
					{ "string_constant_value", DataType::STRING }
				},
				{
					{ "string_constant_name", 1 << Feature::OUTPUT },
					{ "string_constant_value", 1 << Feature::OUTPUT }
				}
			) {};

			/// Destructor.
			~StringConstantEntityTypeProvider() {};

	};

}
}
}
