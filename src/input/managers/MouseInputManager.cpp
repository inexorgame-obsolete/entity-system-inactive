#include <input/managers/MouseInputManager.hpp>

#include <tuple>
#include <utility>

#include <GLFW/glfw3.h>

#include "spdlog/spdlog.h"

#include "entity-system/model/data/DataTypes.hpp"
#include "type-system/types/ui/Window.hpp"

namespace inexor::input {

using Window = entity_system::type_system::Window;

MouseInputManager::MouseInputManager(GlobalMouseButtonFactoryPtr global_mouse_button_factory, LogManagerPtr log_manager)
    : LifeCycleComponent()
{
    this->global_mouse_button_factory = std::move(global_mouse_button_factory);
    this->log_manager = std::move(log_manager);
}

MouseInputManager::~MouseInputManager() = default;

void MouseInputManager::init()
{
    log_manager->register_logger(LOGGER_NAME);
}

void MouseInputManager::destroy()
{
    signal_mouse_button_changed.disconnect_all_slots();
    signal_mouse_button_pressed.disconnect_all_slots();
    signal_mouse_button_released.disconnect_all_slots();
    for (const auto &kv : signal_window_mouse_button_changed)
    {
        kv.second->disconnect_all_slots();
    }
    signal_window_mouse_button_changed.clear();
    for (const auto &kv : signal_window_mouse_button_pressed)
    {
        kv.second->disconnect_all_slots();
    }
    signal_window_mouse_button_pressed.clear();
    for (const auto &kv : signal_window_mouse_button_released)
    {
        kv.second->disconnect_all_slots();
    }
    signal_window_mouse_button_released.clear();
    for (const auto &kv : signal_window_mouse_moved)
    {
        kv.second->disconnect_all_slots();
    }
    signal_window_mouse_moved.clear();
    for (const auto &kv : signal_window_mouse_scrolled)
    {
        kv.second->disconnect_all_slots();
    }
    signal_window_mouse_scrolled.clear();
}

std::string MouseInputManager::get_component_name()
{
    return "MouseInputManager";
}

EntityInstancePtrOpt MouseInputManager::create_mouse_button(const int &button)
{
    spdlog::get(LOGGER_NAME)->debug("Create entity instance of type GLOBAL_MOUSE_BUTTON {}", button);
    return global_mouse_button_factory->create_instance(button);
}

void MouseInputManager::mouse_position_changed(const EntityInstancePtr &window, double xpos, double ypos)
{
    spdlog::get(LOGGER_NAME)->debug("Window {} Mouse movement: {}, {}", get_window_name(window), xpos, ypos);
    if (signal_window_mouse_moved.end() != signal_window_mouse_moved.find(window))
    {
        signal_window_mouse_moved[window]->operator()(window, xpos, ypos);
    }
}

void MouseInputManager::mouse_button_changed(const EntityInstancePtr &window, int button, int action, int mods)
{
    spdlog::get(LOGGER_NAME)->debug("Window {} Mouse button: {} Action: {} Mods: {}", get_window_name(window), button, action, mods);
    signal_mouse_button_changed(window, button, action, mods);
    switch (action)
    {
    case GLFW_PRESS:
        signal_mouse_button_pressed(window, button, mods);
        break;
    case GLFW_RELEASE:
        signal_mouse_button_released(window, button, mods);
        break;
    default:
        break;
    }
    if (signal_window_mouse_button_changed.end() != signal_window_mouse_button_changed.find(window))
    {
        signal_window_mouse_button_changed[window]->operator()(window, button, action, mods);
    }
    if (GLFW_PRESS == action && signal_window_mouse_button_pressed.find(window) != signal_window_mouse_button_pressed.end())
    {
        signal_window_mouse_button_pressed[window]->operator()(window, button, mods);
    }
    if (GLFW_RELEASE == action && signal_window_mouse_button_released.find(window) != signal_window_mouse_button_released.end())
    {
        signal_window_mouse_button_released[window]->operator()(window, button, mods);
    }
}

void MouseInputManager::mouse_scroll_changed(const EntityInstancePtr &window, double xoffset, double yoffset)
{
    spdlog::get(LOGGER_NAME)->info("Window {} Mouse scroll: {}, {}", get_window_name(window), xoffset, yoffset);
    if (signal_window_mouse_scrolled.end() != signal_window_mouse_scrolled.find(window))
    {
        signal_window_mouse_scrolled[window]->operator()(window, xoffset, yoffset);
    }
}

void MouseInputManager::register_on_mouse_button_changed(const std::shared_ptr<MouseButtonChangedListener> &mouse_button_changed_listener)
{
    spdlog::info("register_on_mouse_button_changed");
    signal_mouse_button_changed.connect(std::bind(&MouseButtonChangedListener::on_mouse_button_changed, mouse_button_changed_listener.get(), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
}

void MouseInputManager::register_on_mouse_button_pressed(const std::shared_ptr<MouseButtonPressedListener> &mouse_button_pressed_listener)
{
    signal_mouse_button_pressed.connect(std::bind(&MouseButtonPressedListener::on_mouse_button_pressed, mouse_button_pressed_listener.get(), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
}

void MouseInputManager::register_on_mouse_button_released(const std::shared_ptr<MouseButtonReleasedListener> &mouse_button_released_listener)
{
    signal_mouse_button_released.connect(std::bind(&MouseButtonReleasedListener::on_mouse_button_released, mouse_button_released_listener.get(), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
}

void MouseInputManager::register_on_window_mouse_button_changed(const EntityInstancePtr &window, const std::shared_ptr<WindowMouseButtonChangedListener> &window_mouse_button_changed_listener)
{
    if (signal_window_mouse_button_changed.end() == signal_window_mouse_button_changed.find(window))
    {
        auto signal = std::make_shared<SignalMouseButtonChanged>();
        signal_window_mouse_button_changed.insert(std::make_pair(window, signal));
    }
    signal_window_mouse_button_changed[window]->connect(
        std::bind(&WindowMouseButtonChangedListener::on_window_mouse_button_changed, window_mouse_button_changed_listener.get(), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
}

void MouseInputManager::register_on_window_mouse_button_pressed(const EntityInstancePtr &window, const std::shared_ptr<WindowMouseButtonPressedListener> &window_mouse_button_pressed_listener)
{
    if (signal_window_mouse_button_pressed.end() == signal_window_mouse_button_pressed.find(window))
    {
        auto signal = std::make_shared<SignalMouseButtonPressed>();
        signal_window_mouse_button_pressed.insert(std::make_pair(window, signal));
    }
    signal_window_mouse_button_pressed[window]->connect(
        std::bind(&WindowMouseButtonPressedListener::on_window_mouse_button_pressed, window_mouse_button_pressed_listener.get(), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
}

void MouseInputManager::register_on_window_mouse_button_released(const EntityInstancePtr &window, const std::shared_ptr<WindowMouseButtonReleasedListener> &window_mouse_button_released_listener)
{
    if (signal_window_mouse_button_released.end() == signal_window_mouse_button_released.find(window))
    {
        auto signal = std::make_shared<SignalMouseButtonReleased>();
        signal_window_mouse_button_released.insert(std::make_pair(window, signal));
    }
    signal_window_mouse_button_released[window]->connect(
        std::bind(&WindowMouseButtonReleasedListener::on_window_mouse_button_released, window_mouse_button_released_listener.get(), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
}

void MouseInputManager::register_on_window_mouse_moved(const EntityInstancePtr &window, const std::shared_ptr<WindowMouseMovedListener> &window_mouse_moved_listener)
{
    if (signal_window_mouse_moved.end() == signal_window_mouse_moved.find(window))
    {
        auto signal = std::make_shared<SignalMouseMoved>();
        signal_window_mouse_moved.insert(std::make_pair(window, signal));
    }
    signal_window_mouse_moved[window]->connect(std::bind(&WindowMouseMovedListener::on_window_mouse_moved, window_mouse_moved_listener.get(), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
}

void MouseInputManager::register_on_window_mouse_scrolled(const EntityInstancePtr &window, const std::shared_ptr<WindowMouseScrolledListener> &window_mouse_scrolled_listener)
{
    if (signal_window_mouse_scrolled.end() == signal_window_mouse_scrolled.find(window))
    {
        auto signal = std::make_shared<SignalMouseScrolled>();
        signal_window_mouse_scrolled.insert(std::make_pair(window, signal));
    }
    signal_window_mouse_scrolled[window]->connect(std::bind(&WindowMouseScrolledListener::on_window_mouse_scrolled, window_mouse_scrolled_listener.get(), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
}

// TODO: if the window has been destroyed, remove the signals for this window

std::string MouseInputManager::get_window_name(const EntityInstancePtr &window)
{
    return window->get<entity_system::DataType::STRING>(Window::TITLE);
}

} // namespace inexor::input
