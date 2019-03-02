// Inexor entity system
// (C) 2018-2019 Inexor

#pragma once

#include "entity-system/managers/entities/entity-type-builder-manager/EntityTypeBuilderManager.hpp"
#include "entity-system/managers/entities/entity-instance-builder-manager/EntityInstanceBuilderManager.hpp"
#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/util/type-definitions/TypeDefinitions.hpp"

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
                    shared_ptr<EntityInstanceBuilderManager> entity_instance_builder_manager,
                    shared_ptr<EntityInstanceManager> entity_instance_manager
            );

            /// Destructor.
            ~RendererFactory();

            /// Initialization of the loggers
            O_ENT_INST create_instance();

        private:
            /// The entity instance manager
            shared_ptr<EntityInstanceBuilderManager> entity_instance_builder_manager;

            /// The entity instance manager
            shared_ptr<EntityInstanceManager> entity_instance_manager;
    };
};
};
