// Inexor entity system
// (c)2018 Inexor

#pragma once

#include "entity-system/managers/entities/entity-type-builder-manager/EntityTypeBuilderManager.hpp"
#include "entity-system/providers/entities/entity-type-provider/EntityTypeProvider.hpp"

using namespace inexor::entity_system;
using namespace std;


namespace inexor {
namespace renderer {

	/// @class RendererEntityTypeProvider
    /// @brief Provides the entity type LOGGER.
	class RendererEntityTypeProvider : public EntityTypeProvider
	{
		public:

			/// Constructor.
			RendererEntityTypeProvider(
				shared_ptr<EntityTypeBuilderManager> entity_type_builder_manager
			) : EntityTypeProvider(
				entity_type_builder_manager,
				"RENDERER",
				{
					{ "renderer_x", DataType::FLOAT },
					{ "renderer_y", DataType::FLOAT }
				},
				{
					{ "renderer_x", 1 << Feature::INPUT | 1 << Feature::OUTPUT },
					{ "renderer_y", 1 << Feature::INPUT | 1 << Feature::OUTPUT }
				}
			) {};

			/// Destructor.
			~RendererEntityTypeProvider() {};

	};


};
};
