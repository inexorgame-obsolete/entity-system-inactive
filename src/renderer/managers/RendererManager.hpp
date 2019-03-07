// Inexor entity system
// (C) 2018-2019 Inexor

#pragma once

#include <iomanip>

#include <Magnum/GL/Buffer.h>
#include <Magnum/GL/DefaultFramebuffer.h>
#include <Magnum/GL/Mesh.h>
#include <Magnum/GL/Renderer.h>
#include <Magnum/Platform/GLContext.h>
#include <Magnum/Math/Color.h>
#include <Magnum/Shaders/VertexColor.h>
#include <GLFW/glfw3.h>

#include "entity-system/managers/entities/entity-type-builder-manager/EntityTypeBuilderManager.hpp"
#include "entity-system/managers/entities/entity-instance-builder-manager/EntityInstanceBuilderManager.hpp"
#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "visual-scripting/model/Connector.hpp"
#include "entity-system/util/type-definitions/TypeDefinitions.hpp"
#include "entity-system/model/data/DataTypes.hpp"

#include "renderer/factories/RendererFactory.hpp"
#include "visual-scripting/managers/ConnectorManager.hpp"

#include "type-system/factories/arithmetic/SinFactory.hpp"

using namespace inexor::entity_system;
using namespace std;
using namespace Magnum;
using namespace Math::Literals;

namespace inexor {
namespace renderer {

    /// @class RendererManager
    /// @brief Management of the rendering.
    class RendererManager : public enable_shared_from_this<RendererManager> {
    public:
        /// Constructor.
        RendererManager(
                shared_ptr<RendererFactory> render_factory,
				shared_ptr<inexor::entity_system::type_system::SinFactory> sin_factory,
				std::shared_ptr<inexor::visual_scripting::ConnectorManager> connector_manager,
                shared_ptr<EntityInstanceManager> entity_instance_manager
        );

        /// Destructor.
        ~RendererManager();

        /// Initialize renderer.
        void init();

        /// Starts the window thread.
        void start_window_thread(GLFWwindow *windows);

    private:
        /// The entity type provider
        shared_ptr<RendererFactory> renderer_factory;

        /// The sin factory
        shared_ptr<inexor::entity_system::type_system::SinFactory> sin_factory;

        /// The connector manager
		std::shared_ptr<inexor::visual_scripting::ConnectorManager> connector_manager;

        /// The entity instance manager
        shared_ptr<EntityInstanceManager> entity_instance_manager;

        /// The renderer entity instance.
        shared_ptr<EntityInstance> renderer;

        /// The sinus generator.
        shared_ptr<EntityInstance> sin_x;

        /// The sinus generator.
        shared_ptr<EntityInstance> sin_y;

        /// The attribute sin_value
        std::shared_ptr<inexor::entity_system::EntityAttributeInstance> sin_x_attr_value;

        /// The attribute sin_value
        std::shared_ptr<inexor::entity_system::EntityAttributeInstance> sin_y_attr_value;

        /// The attribute renderer_x
        std::shared_ptr<inexor::entity_system::EntityAttributeInstance> renderer_x_attr_value;

        /// The attribute renderer_x
        std::shared_ptr<inexor::entity_system::EntityAttributeInstance> renderer_y_attr_value;

    };
};
};
