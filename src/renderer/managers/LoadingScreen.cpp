#include "LoadingScreen.hpp"

#include <algorithm>
#include <utility>

#include <Corrade/Containers/Optional.h>
#include <Corrade/PluginManager/Manager.h>

#include <Magnum/DebugTools/Screenshot.h>
#include <Magnum/GL/TextureFormat.h>
#include <Magnum/Primitives/Square.h>
#include <Magnum/Trade/AbstractImporter.h>
#include <Magnum/Trade/ImageData.h>

#include <GLFW/glfw3.h>

#include "spdlog/spdlog.h"
#include <spdlog/fmt/ostr.h>

#include "entity-system/model/entity-attributes/entity-attribute-instances/EntityAttributeInstance.hpp"

#include "type-system/types/inout/keyboard/GlobalKey.hpp"
#include "type-system/types/inout/mouse/GlobalMouseButton.hpp"
#include "type-system/types/ui/Window.hpp"

using namespace Magnum::Math::Literals;

namespace inexor::renderer {

using DataType = entity_system::DataType;
using DataValue = entity_system::DataValue;
using GlobalKey = entity_system::type_system::GlobalKey;
using GlobalMouseButton = entity_system::type_system::GlobalMouseButton;
using Window = entity_system::type_system::Window;
using EntityInstancePtrOpt = std::optional<EntityInstancePtr>;
using EntityAttributeInstancePtr = std::shared_ptr<entity_system::EntityAttributeInstance>;
using EntityAttributeInstancePtrOpt = std::optional<EntityAttributeInstancePtr>;

LoadingScreen::LoadingScreen(WindowManagerPtr window_manager, MonitorManagerPtr monitor_manager, FontManagerPtr font_manager, KeyboardInputManagerPtr keyboard_input_manager, MouseInputManagerPtr mouse_input_manager,
                             ClipboardManagerPtr clipboard_manager, ConnectorManagerPtr connector_manager, ClientLifecyclePtr client_lifecycle, LogManagerPtr log_manager)
{
    this->window_manager = std::move(window_manager);
    this->monitor_manager = std::move(monitor_manager);
    this->font_manager = std::move(font_manager);
    this->keyboard_input_manager = std::move(keyboard_input_manager);
    this->mouse_input_manager = std::move(mouse_input_manager);
    this->clipboard_manager = std::move(clipboard_manager);
    this->connector_manager = std::move(connector_manager);
    this->client_lifecycle = std::move(client_lifecycle);
    this->log_manager = std::move(log_manager);
    this->show_fps = true;
    this->create_screenshot = false;
    this->mesh_size_x = 0.3f;
    this->mesh_size_y = 0.3f;
    this->mesh_factor = 0.6f;
    this->action = "";
    this->command_buffer = "";
}

LoadingScreen::~LoadingScreen() = default;

void LoadingScreen::init()
{
    log_manager->register_logger(LOGGER_NAME);

    // Creates the window
    window = window_manager->create_window("Loading Inexor...", 800, 0, 800, 600, 0.95f, true, false, false, false, true, true, 60.0f, {std::bind(&LoadingScreen::init_loading_screen, this, std::placeholders::_1, std::placeholders::_2)},
                                           {std::bind(&LoadingScreen::shutdown_loading_screen, this, std::placeholders::_1, std::placeholders::_2)});
    window_manager->center_window_on_current_monitor(window);
    window_manager->register_render_function(window, std::bind(&LoadingScreen::render_loading_screen, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));

    keyboard_input_manager->register_on_window_char_input(window, shared_from_this());
    keyboard_input_manager->register_on_window_key_released(window, shared_from_this());
    keyboard_input_manager->register_on_window_key_pressed_or_repeated(window, shared_from_this());
    keyboard_input_manager->register_on_window_path_dropped(window, shared_from_this());

    mouse_input_manager->register_on_window_mouse_button_changed(window, shared_from_this());
    mouse_input_manager->register_on_window_mouse_scrolled(window, shared_from_this());

    EntityInstancePtrOpt o_key_b = keyboard_input_manager->create_key(GLFW_KEY_B);
    if (o_key_b.has_value())
    {
        EntityInstancePtr key_b = o_key_b.value();
        EntityAttributeInstancePtrOpt o_key_b_key = key_b->get_attribute_instance(GlobalKey::KEYCODE);
        EntityAttributeInstancePtrOpt o_key_b_action = key_b->get_attribute_instance(GlobalKey::ACTION);
        if (o_key_b_key.has_value() && o_key_b_action.has_value())
        {
            EntityAttributeInstancePtr key_b_key = o_key_b_key.value();
            EntityAttributeInstancePtr key_b_action = o_key_b_action.value();
            spdlog::debug("Creating observer for GLOBAL KEY {} {}", std::get<DataType::INT>(key_b_key->value.Value()), std::get<DataType::INT>(key_b_action->value.Value()));
            Observe(key_b_action->value, [](DataValue action) {
                spdlog::info("GLOBAL KEY B {}", std::get<DataType::INT>(action));
                if (std::get<DataType::INT>(action) == GLFW_RELEASE)
                {
                    spdlog::info("GLOBAL_KEY_B released");
                    // TODO: enable boost stacktrace again (3/3)
                    /* spdlog::info("Stacktrace\n{}", boost::stacktrace::stacktrace()); */
                }
            });
        }
    }

    EntityInstancePtrOpt o_mouse_button_2 = mouse_input_manager->create_mouse_button(GLFW_MOUSE_BUTTON_MIDDLE);
    if (o_mouse_button_2.has_value())
    {
        EntityInstancePtr mouse_button_2 = o_mouse_button_2.value();
        EntityAttributeInstancePtrOpt o_mouse_button_2_number = mouse_button_2->get_attribute_instance(GlobalMouseButton::BUTTON_NUMBER);
        EntityAttributeInstancePtrOpt o_mouse_button_2_action = mouse_button_2->get_attribute_instance(GlobalMouseButton::ACTION);
        if (o_mouse_button_2_number.has_value() && o_mouse_button_2_action.has_value())
        {
            EntityAttributeInstancePtr mouse_button_2_number = o_mouse_button_2_number.value();
            EntityAttributeInstancePtr mouse_button_2_action = o_mouse_button_2_action.value();
            spdlog::debug("Creating observer for GLOBAL MOUSE_BUTTON {} {}", std::get<DataType::INT>(mouse_button_2_number->value.Value()), std::get<DataType::INT>(mouse_button_2_action->value.Value()));
            Observe(mouse_button_2_action->value, [](DataValue action) {
                spdlog::info("GLOBAL MOUSE BUTTON 2: {}", std::get<DataType::INT>(action));
                if (std::get<DataType::INT>(action) == GLFW_RELEASE)
                {
                    spdlog::info("GLOBAL_MOUSE_BUTTON_2 released");
                    // TODO: enable boost stacktrace again (3/3)
                    /* spdlog::info("Stacktrace\n{}", boost::stacktrace::stacktrace()); */
                }
            });
        }
    }
}

void LoadingScreen::destroy()
{
    window_manager->destroy_window(window);
}

std::string LoadingScreen::get_component_name()
{
    return "LoadingScreen";
}

void toggle_raw(GLFWwindow *glfw_window, int window_attribute)
{
    glfwSetWindowAttrib(glfw_window, window_attribute, !glfwGetWindowAttrib(glfw_window, window_attribute));
}

void increase(const EntityInstancePtr &entity_instance, std::string name, float step, float max)
{
    EntityAttributeInstancePtr attr = entity_instance->get_attribute_instance(name).value();
    attr->own_value.Set(std::min(max, std::get<DataType::FLOAT>(attr->value.Value()) + step));
}

void increase(const EntityInstancePtr &entity_instance, std::string name, int step, int max)
{
    EntityAttributeInstancePtr attr = entity_instance->get_attribute_instance(name).value();
    attr->own_value.Set(std::min(max, std::get<DataType::INT>(attr->value.Value()) + step));
}

void decrease(const EntityInstancePtr &entity_instance, std::string name, float step, float min)
{
    EntityAttributeInstancePtr attr = entity_instance->get_attribute_instance(name).value();
    attr->own_value.Set(std::max(min, std::get<DataType::FLOAT>(attr->value.Value()) - step));
}

void decrease(const EntityInstancePtr &entity_instance, std::string name, int step, int min)
{
    EntityAttributeInstancePtr attr = entity_instance->get_attribute_instance(name).value();
    attr->own_value.Set(std::max(min, std::get<DataType::INT>(attr->value.Value()) - step));
}

void LoadingScreen::on_window_char_input(EntityInstancePtr window, std::string character, unsigned int codepoint)
{
    spdlog::get(LOGGER_NAME)->debug("on_window_char_input({}, {})", character, codepoint);
    command_buffer += character;
}

void LoadingScreen::on_window_key_released(EntityInstancePtr window, int key, int scancode, int mods)
{
    spdlog::get(LOGGER_NAME)->debug("Key released {} {} {}", key, scancode, mods);
    switch (key)
    {
    case GLFW_KEY_ENTER:
    case GLFW_KEY_KP_ENTER:
        execute_command(window);
        break;

    case GLFW_KEY_X:
        if (mods & GLFW_MOD_CONTROL)
            window_manager->destroy_window(window);
        break;
    case GLFW_KEY_Q:
        if (mods & GLFW_MOD_CONTROL)
            client_lifecycle->request_shutdown();
        break;
    case GLFW_KEY_R:
        if (mods & GLFW_MOD_CONTROL)
            client_lifecycle->request_restart();
        break;
    case GLFW_KEY_1:
        if (mods & GLFW_MOD_CONTROL)
        {
            window_manager->set_window_position(window, 100, 100);
            action = "Window position 100,100";
        } else if (mods & GLFW_MOD_SHIFT)
        {
            window_manager->set_window_size(window, 800, 600);
            action = "Window size 800x600";
        }
        break;
    case GLFW_KEY_2:
        if (mods & GLFW_MOD_CONTROL)
        {
            window_manager->set_window_position(window, 200, 200);
            action = "Window position 200,200";
        } else if (mods & GLFW_MOD_SHIFT)
        {
            window_manager->set_window_size(window, 1024, 768);
            action = "Window size 1024x768";
        }
        break;
    case GLFW_KEY_I:
        if (mods & GLFW_MOD_CONTROL)
        {
            window->toggle(Window::ICONIFIED);
            action = window->get<DataType::BOOL>(Window::ICONIFIED) ? "Iconified" : "Restored";
        }
        break;
    case GLFW_KEY_F:
        if (mods & GLFW_MOD_CONTROL)
        {
            window->toggle(Window::FULLSCREEN);
            action = window->get<DataType::BOOL>(Window::FULLSCREEN) ? "Fullscreen" : "Restored";
        }
        break;
    case GLFW_KEY_M:
        if (mods & GLFW_MOD_CONTROL)
        {
            window->toggle(Window::MAXIMIZED);
            action = window->get<DataType::BOOL>(Window::MAXIMIZED) ? "Maximized" : "Restored";
        }
        break;
    case GLFW_KEY_U:
        if (mods & GLFW_MOD_CONTROL)
        {
            toggle_raw(window_manager->get_window_handle(window), GLFW_DECORATED);
            action = "Removed window decoration";
        }
        break;
    case GLFW_KEY_T:
        if (mods & GLFW_MOD_CONTROL)
        {
            window_manager->set_window_title(window, "*Still* loading Inexor...");
            action = "Changed window title";
        }
        break;
    case GLFW_KEY_SCROLL_LOCK:
        window->toggle(Window::VSYNC);
        action = "Toggle vsync";
        break;
    case GLFW_KEY_PRINT_SCREEN:
        create_screenshot = true;
        action = "Creating screenshot";
        break;

    case GLFW_KEY_UP:
        movement.forward = false;
        break;
    case GLFW_KEY_DOWN:
        movement.backward = false;
        break;
    case GLFW_KEY_LEFT:
        movement.left = false;
        break;
    case GLFW_KEY_RIGHT:
        movement.right = false;
        break;

    case GLFW_KEY_ESCAPE:
        movement.mode = 0;
        action = "";
        break;
    case GLFW_KEY_F1:
        movement.mode = 1;
        action = "Change window position";
        break;
    case GLFW_KEY_F2:
        movement.mode = 2;
        action = "Center window";
        break;
    case GLFW_KEY_F3:
        movement.mode = 3;
        action = "Change window fullscreen";
        break;
    case GLFW_KEY_F4:
        movement.mode = 4;
        action = "Change logo movement";
        break;
    case GLFW_KEY_F5:
        movement.mode = 5;
        action = "Change window opacity";
        break;
    case GLFW_KEY_F6:
        movement.mode = 6;
        action = "Change window fps";
        break;

    case GLFW_KEY_F11:
        show_fps = !show_fps;
        action = fmt::format("{} fps counter", show_fps ? "Show" : "Hide");
        break;

    default:
        break;
    }
}

void LoadingScreen::on_window_key_pressed_or_repeated(EntityInstancePtr window, int key, int scancode, int mods)
{
    spdlog::get(LOGGER_NAME)->debug("Key pressed / repeated {} {} {}", key, scancode, mods);
    switch (key)
    {
    case GLFW_KEY_UP:
        movement.forward = true;
        break;
    case GLFW_KEY_DOWN:
        movement.backward = true;
        break;
    case GLFW_KEY_LEFT:
        movement.left = true;
        break;
    case GLFW_KEY_RIGHT:
        movement.right = true;
        break;

    case GLFW_KEY_C:
        if (mods & GLFW_MOD_CONTROL)
            clipboard_manager->set(command_buffer);
        break;
    case GLFW_KEY_V:
        if (mods & GLFW_MOD_CONTROL)
            command_buffer += clipboard_manager->get_value();
        break;
    case GLFW_KEY_BACKSPACE:
        command_buffer = command_buffer.substr(0, command_buffer.size() - 1);
        break;

    default:
        break;
    }
    move(window);
}

void LoadingScreen::on_window_mouse_button_changed(EntityInstancePtr window, int button, int action, int mods)
{
    //		if (action != GLFW_RELEASE) return;
    //		switch (button)
    //		{
    //			case GLFW_MOUSE_BUTTON_LEFT:
    //				switch (mods)
    //				{
    //					case GLFW_MOD_SHIFT:
    //						mesh_size_y = std::max(0.05f, std::min(0.95f, mesh_size_y + 0.05f));
    //						break;
    //					default:
    //						mesh_size_x = std::max(0.05f, std::min(0.95f, mesh_size_x + 0.05f));
    //						break;
    //				}
    //				break;
    //			case GLFW_MOUSE_BUTTON_RIGHT:
    //				switch (mods)
    //				{
    //					case GLFW_MOD_SHIFT:
    //						mesh_size_y = std::max(0.05f, std::min(0.95f, mesh_size_y - 0.05f));
    //						break;
    //					default:
    //						mesh_size_x = std::max(0.05f, std::min(0.95f, mesh_size_x - 0.05f));
    //						break;
    //				}
    //				break;
    //			default:
    //				break;
    //		}
}

/// Window mouse scrolled
void LoadingScreen::on_window_mouse_scrolled(EntityInstancePtr window, double xpos, double ypos)
{
    mesh_factor += ((float)ypos * 0.1f);
    action = fmt::format("logo size {}x{} factor {}", mesh_size_x, mesh_size_y, mesh_factor);
}
void LoadingScreen::on_window_path_dropped(EntityInstancePtr window, std::vector<std::string> paths)
{
    std::string suffix = ".txt";
    for (std::string path : paths)
    {
        if (path.size() >= suffix.size() && 0 == path.compare(path.size() - suffix.size(), suffix.size(), suffix))
        {
            command_buffer += path;
        }
    }
}

void LoadingScreen::move(const EntityInstancePtr &window)
{
    switch (movement.mode)
    {
    case 1:
        // Change window position
        if (movement.forward)
            decrease(window, Window::POSITION_Y, 10, 0);
        if (movement.backward)
            increase(window, Window::POSITION_Y, 10, 3840);
        if (movement.left)
            decrease(window, Window::POSITION_X, 10, 0);
        if (movement.right)
            increase(window, Window::POSITION_X, 10, 2160);
        break;
    case 2:
        // Center window
        if (movement.forward)
        {
            window_manager->center_window_on_current_monitor(window);
            action = "Center window on current monitor";
        }
        if (movement.backward)
        {
            window_manager->center_window_on_primary_monitor(window);
            action = "Center window on primary monitor";
        }
        if (movement.left)
        {
            window_manager->center_window_on_next_left_monitor(window);
            action = "Center window on next left monitor";
        }
        if (movement.right)
        {
            window_manager->center_window_on_next_right_monitor(window);
            action = "Center window on next right monitor";
        }
        break;
    case 3:
        // Change window fullscreen
        if (movement.forward)
        {
            window_manager->fullscreen_window_on_current_monitor(window);
            action = "Fullscreen window on current monitor";
        }
        if (movement.backward)
        {
            window_manager->fullscreen_window_on_primary_monitor(window);
            action = "Fullscreen window on primary monitor";
        }
        if (movement.left)
        {
            window_manager->fullscreen_window_on_next_left_monitor(window);
            action = "Fullscreen window on next left monitor";
        }
        if (movement.right)
        {
            window_manager->fullscreen_window_on_next_right_monitor(window);
            action = "Fullscreen window on next right monitor";
        }
        break;
    case 4:
        // Change logo movement
        if (movement.forward)
        {
            mesh_size_y = std::max(0.05f, std::min(0.95f, mesh_size_y + 0.05f));
            action = fmt::format("logo size {}x{} factor {}", mesh_size_x, mesh_size_y, mesh_factor);
        }
        if (movement.backward)
        {
            mesh_size_y = std::max(0.05f, std::min(0.95f, mesh_size_y - 0.05f));
            action = fmt::format("logo size {}x{} factor {}", mesh_size_x, mesh_size_y, mesh_factor);
        }
        if (movement.left)
        {
            mesh_size_x = std::max(0.05f, std::min(0.95f, mesh_size_x - 0.05f));
            action = fmt::format("logo size {}x{} factor {}", mesh_size_x, mesh_size_y, mesh_factor);
        }
        if (movement.right)
        {
            mesh_size_x = std::max(0.05f, std::min(0.95f, mesh_size_x + 0.05f));
            action = fmt::format("logo size {}x{} factor {}", mesh_size_x, mesh_size_y, mesh_factor);
        }
        break;
    case 5:
        // Change window opacity
        if (movement.forward)
        {
            increase(window, Window::OPACITY, 0.05f, 1.0f);
            action = fmt::format("opacity = {}", window->get<DataType::FLOAT>(Window::OPACITY));
        }
        if (movement.backward)
        {
            decrease(window, Window::OPACITY, 0.05f, 0.1f);
            action = fmt::format("opacity = {}", window->get<DataType::FLOAT>(Window::OPACITY));
        }
        break;
    case 6:
        // Change window fps
        if (movement.forward)
        {
            increase(window, Window::FPS, 5.00f, 250.0f);
            action = fmt::format("max fps = {}", window->get<DataType::FLOAT>(Window::FPS));
        }
        if (movement.backward)
        {
            decrease(window, Window::FPS, 5.00f, 10.0f);
            action = fmt::format("max fps = {}", window->get<DataType::FLOAT>(Window::FPS));
        }
        break;
    default:
        break;
    }
}

void LoadingScreen::execute_command(const EntityInstancePtr &window)
{
    // TODO: call CommandManager; this is a demo only
    if (command_buffer == "/quit")
    {
        client_lifecycle->request_shutdown();
    } else if (command_buffer == "/screenshot")
    {
        action = "Creating screenshot";
        create_screenshot = true;
    } else if (command_buffer == "/vsync 0")
    {
        action = "vsync off";
        window->set_own_value(Window::VSYNC, false);
    } else if (command_buffer == "/vsync 1")
    {
        action = "vsync on";
        window->set_own_value(Window::VSYNC, true);
    } else if (command_buffer == "/fullscreen 0")
    {
        action = "Fullscreen off";
        window->set_own_value(Window::FULLSCREEN, false);
    } else if (command_buffer == "/fullscreen 1")
    {
        action = "Fullscreen on";
        window->set_own_value(Window::FULLSCREEN, true);
    } else if (command_buffer == "/maximize 0")
    {
        action = "Maximize off";
        window->set_own_value(Window::MAXIMIZED, false);
    } else if (command_buffer == "/maximize 1")
    {
        action = "Maximize on";
        window->set_own_value(Window::MAXIMIZED, true);
    } else if (command_buffer == "/license")
    {
        action = "License";
        Corrade::Utility::Resource rs{"inexor-base"};
        spdlog::info("License:\n{}", rs.get("license.txt"));
    }
    command_buffer = "";
}

// Thread local ("first frame")
// The initialization must happen within GL context.
void LoadingScreen::init_loading_screen(const EntityInstancePtr &window, GLFWwindow *glfw_window)
{
    buffer = std::make_shared<Magnum::GL::Buffer>();
    mesh = std::make_shared<Magnum::GL::Mesh>();
    shader = std::make_shared<Magnum::Shaders::Flat2D>(Magnum::Shaders::Flat2D::Flag::Textured);

    title_font = font_manager->load_internal(TITLE_FONT, 400.0f, "INEXOR", 6, 0.4f, Magnum::Text::Alignment::MiddleCenter).value();
    title_font->renderer->render("INEXOR");
    action_font = font_manager->load_internal(ACTION_FONT, 110.0f, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789?!:;,.+-*/=<>[](){}| ", 80, 0.05f, Magnum::Text::Alignment::MiddleCenter).value();
    command_font = font_manager->load_internal(COMMAND_FONT, 110.0f, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789?!:;,./><() ", 320, 0.05f, Magnum::Text::Alignment::LineLeft).value();
    fps_font = font_manager->load_internal(FPS_FONT, 110.0f, "fps0123456789 ", 16, 0.05f, Magnum::Text::Alignment::LineRight).value();

    // TODO: move to own service
    Corrade::PluginManager::Manager<Magnum::Trade::AbstractImporter> manager;
    Corrade::Containers::Pointer<Magnum::Trade::AbstractImporter> image_importer = manager.loadAndInstantiate("AnyImageImporter");
    if (image_importer)
    {
        const Corrade::Utility::Resource rs{"inexor-images"};
        if (image_importer->openData(rs.getRaw("logo.png")))
        {
            // TODO: move to own service
            Corrade::Containers::Optional<Magnum::Trade::ImageData2D> image = image_importer->image2D(0);
            texture = std::make_shared<Magnum::GL::Texture2D>();
            texture->setWrapping(Magnum::GL::SamplerWrapping::ClampToEdge)
                .setMagnificationFilter(Magnum::GL::SamplerFilter::Linear)
                .setMinificationFilter(Magnum::GL::SamplerFilter::Linear)
                .setImage(0, Magnum::GL::TextureFormat::RGBA8, (*image));
            spdlog::info("Successfully opened logo.png");
        } else
        {
            spdlog::error("Failed to open logo.png");
        }
    } else
    {
        spdlog::error("Failed to load and instantiate AnyImageImporter");
    }

    Magnum::GL::defaultFramebuffer.clearColor(Magnum::Color4{0.1f, 0.1f, 0.1f, 0.1f});
}

// Thread local
void LoadingScreen::render_inexor_logo(Magnum::Timeline timeline)
{
    float mx = mesh_size_x + std::sin(timeline.previousFrameTime()) * std::tan(mesh_size_y) * mesh_factor;
    float my = mesh_size_y + std::cos(timeline.previousFrameTime()) * std::tan(mesh_size_x) * mesh_factor;

    // TODO: make this more flexible
    const QuadVertex quad_vertex[]{{{mx, my * -1.0f}, {0.0f, 1.0f}}, {{mx * -1.0f, my * -1.0f}, {1.0f, 1.0f}}, {{mx, my}, {0.0f, 0.0f}}, {{mx * -1.0f, my}, {1.0f, 0.0f}}};
    shader->bindTexture((*texture));
    buffer->setData(quad_vertex);
    mesh->setPrimitive(Magnum::GL::MeshPrimitive::TriangleStrip).setCount(4).addVertexBuffer((*buffer), 0, Magnum::Shaders::Flat2D::Position{}, Magnum::Shaders::Flat2D::TextureCoordinates{});
    mesh->draw((*shader));
}

// Thread local
// TODO: move this to a service
void LoadingScreen::render_inexor_title(Magnum::Timeline timeline)
{
    Magnum::GL::Renderer::enable(Magnum::GL::Renderer::Feature::Blending);
    Magnum::GL::Renderer::setBlendFunction(Magnum::GL::Renderer::BlendFunction::SourceAlpha, Magnum::GL::Renderer::BlendFunction::OneMinusSourceAlpha);
    Magnum::GL::Renderer::setBlendEquation(Magnum::GL::Renderer::BlendEquation::Add, Magnum::GL::Renderer::BlendEquation::Add);

    float mx1 = (std::sin(timeline.previousFrameTime() * 1.995f) * 0.2f);
    float my1 = -0.8f + (mesh_size_y * (std::sin(timeline.previousFrameTime()) * 0.2f + 0.8f));
    auto translation_x1 = Magnum::Matrix3::translation(Magnum::Vector2::xAxis(mx1));
    auto translation_y1 = Magnum::Matrix3::translation(Magnum::Vector2::yAxis(my1));
    title_font->shader->setTransformationProjectionMatrix(translation_x1 * translation_y1)
        .setColor(Magnum::Color4{0.2f, 0.5f, 0.2f, 0.4f})
        .setOutlineColor(Magnum::Color4{1.0f, 1.0f, 1.0f, 0.8f})
        .setOutlineRange(0.5f, 1.0f)
        .setSmoothness(0.01f)
        .bindVectorTexture(title_font->glyph_cache->texture());
    title_font->renderer->mesh().draw((*title_font->shader));

    float mx2 = (std::sin(timeline.previousFrameTime() * 2.005f) * 0.2f);
    float my2 = -0.8f + (mesh_size_y * (std::sin(timeline.previousFrameTime() + 0.1f) * 0.2f + 0.8f));
    auto translation_x2 = Magnum::Matrix3::translation(Magnum::Vector2::xAxis(mx2));
    auto translation_y2 = Magnum::Matrix3::translation(Magnum::Vector2::yAxis(my2));
    title_font->shader->setTransformationProjectionMatrix(translation_x2 * translation_y2)
        .setColor(Magnum::Color4{0.2f, 0.2f, 0.5f, 0.8f})
        .setOutlineColor(Magnum::Color4{1.0f, 1.0f, 1.0f, 0.4f})
        .setOutlineRange(0.5f, 1.0f)
        .setSmoothness(0.01f)
        .bindVectorTexture(title_font->glyph_cache->texture());
    title_font->renderer->mesh().draw((*title_font->shader));

    float mx3 = (std::sin(timeline.previousFrameTime() * 2.0f) * 0.2f);
    float my3 = -0.8f + (mesh_size_y * (std::sin(timeline.previousFrameTime() + 0.2f) * 0.2f + 0.8f));
    auto translation_x3 = Magnum::Matrix3::translation(Magnum::Vector2::xAxis(mx3));
    auto translation_y3 = Magnum::Matrix3::translation(Magnum::Vector2::yAxis(my3));
    title_font->shader->setTransformationProjectionMatrix(translation_x3 * translation_y3)
        .setColor(Magnum::Color4{0.8f, 0.8f, 0.8f, 0.8f})
        .setOutlineColor(Magnum::Color4{1.0f, 1.0f, 1.0f, 0.4f})
        .setOutlineRange(0.5f, 1.0f)
        .setSmoothness(0.01f)
        .bindVectorTexture(title_font->glyph_cache->texture());
    title_font->renderer->mesh().draw((*title_font->shader));
}

// Thread local
void LoadingScreen::render_action(Magnum::Timeline timeline)
{
    Magnum::GL::Renderer::enable(Magnum::GL::Renderer::Feature::Blending);
    Magnum::GL::Renderer::setBlendFunction(Magnum::GL::Renderer::BlendFunction::SourceAlpha, Magnum::GL::Renderer::BlendFunction::OneMinusSourceAlpha);
    Magnum::GL::Renderer::setBlendEquation(Magnum::GL::Renderer::BlendEquation::Add, Magnum::GL::Renderer::BlendEquation::Add);

    action_font->renderer->render(fmt::format(" {} ", action));
    auto translation_y = Magnum::Matrix3::translation(Magnum::Vector2::yAxis(0.9f));
    action_font->shader->setTransformationProjectionMatrix(translation_y)
        .setColor(Magnum::Color4{1.0f, 1.0f, 1.0f, 0.8f})
        .setOutlineColor(Magnum::Color4{0.5f, 0.5f, 0.8f, 0.8f})
        .setOutlineRange(0.5f, 1.0f)
        .setSmoothness(0.075f)
        .bindVectorTexture(action_font->glyph_cache->texture());
    action_font->renderer->mesh().draw((*action_font->shader));
}

// Thread local
void LoadingScreen::render_command_buffer(Magnum::Timeline timeline)
{
    Magnum::GL::Renderer::enable(Magnum::GL::Renderer::Feature::Blending);
    Magnum::GL::Renderer::setBlendFunction(Magnum::GL::Renderer::BlendFunction::SourceAlpha, Magnum::GL::Renderer::BlendFunction::OneMinusSourceAlpha);
    Magnum::GL::Renderer::setBlendEquation(Magnum::GL::Renderer::BlendEquation::Add, Magnum::GL::Renderer::BlendEquation::Add);

    command_font->renderer->render(fmt::format("> {}", command_buffer));
    auto translation_x = Magnum::Matrix3::translation(Magnum::Vector2::xAxis(-0.9f));
    auto translation_y = Magnum::Matrix3::translation(Magnum::Vector2::yAxis(-0.9f));
    command_font->shader->setTransformationProjectionMatrix(translation_x * translation_y)
        .setColor(Magnum::Color4{1.0f, 1.0f, 1.0f, 0.8f})
        .setOutlineColor(Magnum::Color4{0.5f, 0.5f, 0.8f, 0.8f})
        .setOutlineRange(0.5f, 1.0f)
        .setSmoothness(0.075f)
        .bindVectorTexture(command_font->glyph_cache->texture());
    command_font->renderer->mesh().draw((*command_font->shader));
}

// Thread local
void LoadingScreen::render_fps_counter(Magnum::Timeline timeline)
{
    Magnum::GL::Renderer::enable(Magnum::GL::Renderer::Feature::Blending);
    Magnum::GL::Renderer::setBlendFunction(Magnum::GL::Renderer::BlendFunction::SourceAlpha, Magnum::GL::Renderer::BlendFunction::OneMinusSourceAlpha);
    Magnum::GL::Renderer::setBlendEquation(Magnum::GL::Renderer::BlendEquation::Add, Magnum::GL::Renderer::BlendEquation::Add);

    int fps = (int)std::ceil(1.0f / timeline.previousFrameDuration());
    fps_font->renderer->render(fmt::format("{} fps", fps));
    auto translation_x = Magnum::Matrix3::translation(Magnum::Vector2::xAxis(0.9f));
    auto translation_y = Magnum::Matrix3::translation(Magnum::Vector2::yAxis(-0.9f));
    fps_font->shader->setTransformationProjectionMatrix(translation_x * translation_y)
        .setColor(Magnum::Color4{1.0f, 1.0f, 1.0f, 0.8f})
        .setOutlineColor(Magnum::Color4{0.5f, 0.5f, 0.8f, 0.8f})
        .setOutlineRange(0.5f, 1.0f)
        .setSmoothness(0.075f)
        .bindVectorTexture(fps_font->glyph_cache->texture());
    fps_font->renderer->mesh().draw((*fps_font->shader));
}

// Thread local
void LoadingScreen::render_loading_screen(const EntityInstancePtr &window, GLFWwindow *glfw_window, Magnum::Timeline timeline)
{
    // Set viewport
    Magnum::Vector2i framebufferSize;
    glfwGetFramebufferSize(glfw_window, &framebufferSize.x(), &framebufferSize.y());
    Magnum::GL::defaultFramebuffer.setViewport({{}, framebufferSize});

    // Reset
    Magnum::GL::defaultFramebuffer.clear(Magnum::GL::FramebufferClear::Color);

    // Render logo and title
    render_inexor_logo(timeline);
    render_inexor_title(timeline);

    // Render action
    render_action(timeline);

    // Render text input
    render_command_buffer(timeline);

    if (show_fps)
    {
        // spdlog::debug("frame time: {} frame duration: {} FPS: {}", timeline.previousFrameTime(), timeline.previousFrameDuration(), 1.0f / timeline.previousFrameDuration());
        render_fps_counter(timeline);
    }
    if (create_screenshot)
    {
        // Test: saving screenshot in all formats (tga included in core magnum, png and jpg needs magnum-plugins)
        Magnum::DebugTools::screenshot(Magnum::GL::defaultFramebuffer, "loading-screen.tga");
        Magnum::DebugTools::screenshot(Magnum::GL::defaultFramebuffer, "loading-screen.png");
        Magnum::DebugTools::screenshot(Magnum::GL::defaultFramebuffer, "loading-screen.jpg");
        create_screenshot = false;
    }
}

// Thread local ("last frame")
// The destruction must happen within GL context.
void LoadingScreen::shutdown_loading_screen(const EntityInstancePtr &window, GLFWwindow *glfw_window)
{
    shader = nullptr;
    mesh = nullptr;
    buffer = nullptr;
    texture = nullptr;

    // TODO: free fonts!
    title_font = nullptr;
    action_font = nullptr;
    command_font = nullptr;
    fps_font = nullptr;

    spdlog::info("Loading screen destroyed");
}

} // namespace inexor::renderer
