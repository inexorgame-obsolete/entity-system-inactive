// Inexor entity system
// (C) 2018-2019 Inexor

#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/util/type-definitions/TypeDefinitions.hpp"
#include "renderer/providers/RendererEntityTypeProvider.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace renderer {


    /// @class RenderFactory
    /// @brief Factory of the renderers.
    class RendererFactory {
        public:
            /// Constructor.
            RendererFactory(
				shared_ptr<RendererEntityTypeProvider> renderer_entity_type_provider,
				shared_ptr<EntityInstanceBuilderFactory> entity_instance_builder_factory,
				shared_ptr<EntityInstanceManager> entity_instance_manager
            );

            /// Destructor.
            ~RendererFactory();

            /// Creates a new renderer with the given coordinates.
            O_ENT_INST create_instance(float x, float y);

        private:
            /// The entity type provider
            shared_ptr<RendererEntityTypeProvider> renderer_entity_type_provider;

            /// The entity instance builder factory
            shared_ptr<EntityInstanceBuilderFactory> entity_instance_builder_factory;

            /// The entity instance manager
            shared_ptr<EntityInstanceManager> entity_instance_manager;
    };
};
};
