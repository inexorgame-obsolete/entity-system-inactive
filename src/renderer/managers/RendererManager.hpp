// Inexor entity system
// (C) 2018-2019 Inexor

#pragma once

#include "entity-system/managers/entities/entity-type-builder-manager/EntityTypeBuilderManager.hpp"
#include "entity-system/managers/entities/entity-instance-builder-manager/EntityInstanceBuilderManager.hpp"
#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/util/type-definitions/TypeDefinitions.hpp"

#include "renderer/factories/RendererFactory.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace renderer {

    /// @class RendererManager
    /// @brief Management of the rendering.
    class RendererManager {
    public:
        /// Constructor.
        RendererManager(
                shared_ptr<RendererFactory> render_factory,
                shared_ptr<EntityInstanceManager> entity_instance_manager
        );

        /// Destructor.
        ~RendererManager();

    private:
        /// The entity type provider
        shared_ptr<RendererFactory> renderer_factory;

        /// The entity instance manager
        shared_ptr<EntityInstanceManager> entity_instance_manager;
    };
};
};
