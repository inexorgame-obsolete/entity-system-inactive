// Inexor entity system
// (C) 2018-2019 Inexor

#pragma once

#include <iomanip>

#include "entity-system/managers/entities/entity-type-builder-manager/EntityTypeBuilderManager.hpp"
#include "entity-system/managers/entities/entity-instance-builder-manager/EntityInstanceBuilderManager.hpp"
#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "visual-scripting/model/Connector.hpp"
#include "entity-system/util/type-definitions/TypeDefinitions.hpp"
#include "entity-system/model/data/DataTypes.hpp"

#include "renderer/factories/RendererFactory.hpp"
#include "visual-scripting/managers/ConnectorManager.hpp"

#include "type-system/factories/trigonometric/SinFactory.hpp"
#include "type-system/factories/trigonometric/CosFactory.hpp"


struct GLFWwindow;

namespace inexor {
namespace renderer {
    /// @class RendererManager
    /// @brief Management of the rendering.
    class RendererManager : public enable_shared_from_this<RendererManager> {
    public:
        /// Constructor.
        RendererManager(
                std::shared_ptr<RendererFactory> render_factory,
				std::shared_ptr<entity_system::type_system::SinFactory> sin_factory,
				std::shared_ptr<entity_system::type_system::CosFactory> cos_factory,
				std::shared_ptr<visual_scripting::ConnectorManager> connector_manager,
                std::shared_ptr<EntityInstanceManager> entity_instance_manager
        );

        /// Destructor.
        ~RendererManager();

        /// Initialize renderer.
        void init();

        /// Starts the window thread.
        void start_window_thread(GLFWwindow *windows);

    private:
        /// The entity type provider
        std::shared_ptr<RendererFactory> renderer_factory;

        /// The sin factory
        std::shared_ptr<entity_system::type_system::SinFactory> sin_factory;

        /// The sin factory
        std::shared_ptr<entity_system::type_system::CosFactory> cos_factory;

        /// The connector manager
		std::shared_ptr<visual_scripting::ConnectorManager> connector_manager;

        /// The entity instance manager
        shared_ptr<EntityInstanceManager> entity_instance_manager;

        /// The renderer entity instance.
        shared_ptr<EntityInstance> renderer;

        /// The sinus generator.
        shared_ptr<EntityInstance> sin_x;

        /// The sinus generator.
        shared_ptr<EntityInstance> cos_y;

        /// The attribute sin_value
        std::shared_ptr<entity_system::EntityAttributeInstance> sin_x_attr_value;

        /// The attribute cos_value
        std::shared_ptr<entity_system::EntityAttributeInstance> cos_y_attr_value;

        /// The attribute renderer_x
        std::shared_ptr<entity_system::EntityAttributeInstance> renderer_x_attr_value;

        /// The attribute renderer_x
        std::shared_ptr<entity_system::EntityAttributeInstance> renderer_y_attr_value;

    };
};
};
