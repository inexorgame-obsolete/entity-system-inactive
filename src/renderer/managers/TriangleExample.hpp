#pragma once

#include "client/ClientLifecycle.hpp"
#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "logging/managers/LogManager.hpp"
#include "renderer/factories/TriangleFactory.hpp"
#include "renderer/managers/WindowManager.hpp"
#include "type-system/factories/generators/counters/CounterFloatFactory.hpp"
#include "type-system/factories/math/trigonometric/CosFactory.hpp"
#include "type-system/factories/math/trigonometric/SinFactory.hpp"
#include "visual-scripting/managers/ConnectorManager.hpp"
#include "visual-scripting/model/Connector.hpp"

#include <Magnum/GL/Buffer.h>
#include <Magnum/GL/DefaultFramebuffer.h>
#include <Magnum/GL/Mesh.h>
#include <Magnum/GL/Renderer.h>
#include <Magnum/Math/Color.h>
#include <Magnum/Math/Matrix3.h>
#include <Magnum/Platform/GLContext.h>
#include <Magnum/Shaders/VertexColor.h>
#include <Magnum/Timeline.h>

struct GLFWwindow;

namespace inexor::renderer {

using EntityInstanceManagerPtr = std::shared_ptr<entity_system::EntityInstanceManager>;
using CounterFloatFactoryPtr = std::shared_ptr<entity_system::type_system::CounterFloatFactory>;
using SinFactoryPtr = std::shared_ptr<entity_system::type_system::SinFactory>;
using CosFactoryPtr = std::shared_ptr<entity_system::type_system::CosFactory>;
using ConnectorManagerPtr = std::shared_ptr<visual_scripting::ConnectorManager>;
using TriangleFactoryPtr = std::shared_ptr<TriangleFactory>;
using WindowManagerPtr = std::shared_ptr<WindowManager>;
using KeyboardInputManagerPtr = std::shared_ptr<input::KeyboardInputManager>;
using ClientLifecyclePtr = std::shared_ptr<client::ClientLifecycle>;
using LogManagerPtr = std::shared_ptr<inexor::logging::LogManager>;
using EntityInstancePtr = std::shared_ptr<EntityInstance>;
using EntityAttributeInstancePtr = std::shared_ptr<entity_system::EntityAttributeInstance>;

struct TriangleVertex
{
    Magnum::Vector2 position;
    Magnum::Color3 color;
};

/// @class TriangleExample
/// @brief Management of the rendering.
class TriangleExample : public input::WindowKeyReleasedListener, public input::WindowKeyPressedOrRepeatedListener, public std::enable_shared_from_this<TriangleExample>
{
    public:
    /// @brief Constructor.
    /// @note The dependencies of this class will be injected automatically.
    /// @param entity_instance_manager The entity instance manager.
    /// @param connector_manager The connector manager.
    /// @param counter_float_factory The factory for creating entities of type COUNTER_FLOAT.
    /// @param sin_factory The factory for creating entities of type SIN.
    /// @param cos_factory The factory for creating entities of type COS.
    /// @param render_factory The factory for creating entities of type TRIANGLE.
    /// @param log_manager The log manager.
    TriangleExample(EntityInstanceManagerPtr entity_instance_manager, ConnectorManagerPtr connector_manager, CounterFloatFactoryPtr counter_float_factory, SinFactoryPtr sin_factory, CosFactoryPtr cos_factory,
                    TriangleFactoryPtr render_factory, WindowManagerPtr window_manager, KeyboardInputManagerPtr keyboard_input_manager, ClientLifecyclePtr client_lifecycle, LogManagerPtr log_manager);

    /// Destructor.
    ~TriangleExample();

    /// Initialize triangle manager.
    void init();

    /// Shut down the triangle manager.
    void shutdown();

    /// Window key released
    void on_window_key_released(EntityInstancePtr window, int key, int scancode, int mods);

    /// Window key pressed or repeated
    void on_window_key_pressed_or_repeated(EntityInstancePtr window, int key, int scancode, int mods);

    /// The logger name of this service.
    static constexpr char LOGGER_NAME[] = "inexor.renderer.triangleexample";

    private:
    void create_entity_instances();
    void create_connectors();

    /// Initializes the triangle.
    void init_triangle(const EntityInstancePtr& window, GLFWwindow *glfw_window);

    /// Renders the triangle.
    void render_triangle(const EntityInstancePtr& window, GLFWwindow *glfw_window, Magnum::Timeline timeline);

    /// Shutdown the triangle.
    void shutdown_triangle(const EntityInstancePtr& window, GLFWwindow *glfw_window);

    /// Toggles the connector debugging
    void toggle_connector_debug();

    /// The entity instance manager.
    EntityInstanceManagerPtr entity_instance_manager;

    /// The connector manager.
    ConnectorManagerPtr connector_manager;

    /// The factory for creating entities of type COUNTER_FLOAT.
    CounterFloatFactoryPtr counter_float_factory;

    /// The factory for creating entities of type SIN.
    SinFactoryPtr sin_factory;

    /// The factory for creating entities of type COS.
    CosFactoryPtr cos_factory;

    /// The factory for creating entities of type TRIANGLE.
    TriangleFactoryPtr triangle_factory;

    /// The window manager
    WindowManagerPtr window_manager;

    /// The keyboard input manager
    KeyboardInputManagerPtr keyboard_input_manager;

    /// The client lifecycle.
    ClientLifecyclePtr client_lifecycle;

    /// The log manager.
    LogManagerPtr log_manager;

    /// The window entity instance.
    EntityInstancePtr window;

    /// The triangle entity instance.
    EntityInstancePtr triangle;

    /// The first counter.
    EntityInstancePtr counter_1;

    /// The second counter.
    EntityInstancePtr counter_2;

    /// The sin operator.
    EntityInstancePtr sin;

    /// The cos operator.
    EntityInstancePtr cos;

    /// The attribute count of the first counter.
    EntityAttributeInstancePtr counter_1_attr_count;

    /// The attribute step of the first counter.
    EntityAttributeInstancePtr counter_1_attr_step;

    /// The attribute count of the second counter.
    EntityAttributeInstancePtr counter_2_attr_count;

    /// The attribute step of the second counter.
    EntityAttributeInstancePtr counter_2_attr_step;

    /// The attribute sin_input.
    EntityAttributeInstancePtr sin_attr_input;

    /// The attribute sin_value.
    EntityAttributeInstancePtr sin_attr_value;

    /// The attribute cos_input.
    EntityAttributeInstancePtr cos_attr_input;

    /// The attribute cos_value.
    EntityAttributeInstancePtr cos_attr_value;

    /// The attribute triangle_x.
    EntityAttributeInstancePtr triangle_attr_x;

    /// The attribute triangle_x.
    EntityAttributeInstancePtr triangle_attr_y;

    std::optional<std::shared_ptr<visual_scripting::Connector>> connector_c_sin;
    std::optional<std::shared_ptr<visual_scripting::Connector>> connector_c_cos;
    std::optional<std::shared_ptr<visual_scripting::Connector>> connector_x;
    std::optional<std::shared_ptr<visual_scripting::Connector>> connector_y;

    std::shared_ptr<Magnum::GL::Buffer> buffer;
    std::shared_ptr<Magnum::GL::Mesh> mesh;
    std::shared_ptr<Magnum::Shaders::VertexColor2D> shader;

    TriangleVertex data[3];

    bool debug_enabled;
};

} // namespace inexor::renderer
