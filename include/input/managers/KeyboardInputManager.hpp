#pragma once

#include "base/LifeCycleComponent.hpp"
#include "input/listeners/KeyChangedListener.hpp"
#include "input/listeners/KeyPressedListener.hpp"
#include "input/listeners/KeyPressedOrRepeatedListener.hpp"
#include "input/listeners/KeyReleasedListener.hpp"
#include "input/listeners/PathDroppedListener.hpp"
#include "input/listeners/WindowCharInputListener.hpp"
#include "input/listeners/WindowKeyChangedListener.hpp"
#include "input/listeners/WindowKeyPressedListener.hpp"
#include "input/listeners/WindowKeyPressedOrRepeatedListener.hpp"
#include "input/listeners/WindowKeyReleasedListener.hpp"
#include "input/listeners/WindowPathDroppedListener.hpp"

#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "logging/managers/LogManager.hpp"
#include "type-system/factories/inout/keyboard/GlobalKeyFactory.hpp"

#include <boost/signals2.hpp>

namespace inexor::input {

using LogManagerPtr = std::shared_ptr<logging::LogManager>;
using GlobalKeyFactoryPtr = std::shared_ptr<entity_system::type_system::GlobalKeyFactory>;

using EntityInstancePtr = std::shared_ptr<entity_system::EntityInstance>;
using EntityInstancePtrOpt = std::optional<EntityInstancePtr>;

using SignalCharInput = boost::signals2::signal<void(EntityInstancePtr window, std::string character, unsigned int codepoint)>;
using SignalCharInputPtr = std::shared_ptr<SignalCharInput>;
using SignalKeyChanged = boost::signals2::signal<void(EntityInstancePtr window, int key, int scancode, int action, int mods)>;
using SignalKeyChangedPtr = std::shared_ptr<SignalKeyChanged>;
using SignalKeyPressed = boost::signals2::signal<void(EntityInstancePtr window, int key, int scancode, int mods)>;
using SignalKeyPressedPtr = std::shared_ptr<SignalKeyPressed>;
using SignalKeyPressedOrRepeated = boost::signals2::signal<void(EntityInstancePtr window, int key, int scancode, int mods)>;
using SignalKeyPressedOrRepeatedPtr = std::shared_ptr<SignalKeyPressedOrRepeated>;
using SignalKeyReleased = boost::signals2::signal<void(EntityInstancePtr window, int key, int scancode, int mods)>;
using SignalKeyReleasedPtr = std::shared_ptr<SignalKeyReleased>;
using SignalPathDropped = boost::signals2::signal<void(EntityInstancePtr window, std::vector<std::string> paths)>;
using SignalPathDroppedPtr = std::shared_ptr<SignalPathDropped>;

/// @class KeyboardInputManager
/// @brief Management of the keyboard input data.
class KeyboardInputManager : public LifeCycleComponent, public std::enable_shared_from_this<KeyboardInputManager>
{
    public:
    /// @brief Constructor.
    /// @note The dependencies of this class will be injected automatically.
    /// @param global_key_factory The factory for creating instances of type 'GLOBAL_KEY'.
    /// @param log_manager The log manager.
    KeyboardInputManager(GlobalKeyFactoryPtr global_key_factory, LogManagerPtr log_manager);

    /// Destructor.
    ~KeyboardInputManager();

    /// Initialize the keyboard input module.
    void init() override;

    /// Shut down the keyboard input manager.
    void destroy() override;

    /// Returns the name of the component
    std::string get_component_name() override;

    /// @brief Creates a new entity instance of type 'GLOBAL_KEY'.
    /// @param key The key code.
    EntityInstancePtrOpt create_key(const int &key);

    /// @brief Called on character input.
    /// @param window The entity instance of type 'WINDOW'.
    /// @param codepoint The unicode codepoint.
    void char_input(const EntityInstancePtr& window, unsigned int codepoint);

    /// @brief Called if the state of a key has been changed.
    /// @param window The entity instance of type 'WINDOW'.
    /// @param key
    /// @param scancode
    /// @param action
    /// @param mods
    void key_changed(const EntityInstancePtr& window, int key, int scancode, int action, int mods);

    /// @brief Called if one or multiple files has been dropped.
    void path_dropped(const EntityInstancePtr& window, const std::vector<std::string>& paths);

    /// @brief Registers a listener for the state of a key has been changed on any window.
    void register_on_key_changed(const std::shared_ptr<KeyChangedListener>& key_changed_listener);

    /// @brief Registers a listener for a key has been pressed on any window.
    void register_on_key_pressed(const std::shared_ptr<KeyPressedListener>& key_pressed_listener);

    /// @brief Registers a listener for a key has been pressed or repeated on any window.
    void register_on_key_pressed_or_repeated(const std::shared_ptr<KeyPressedOrRepeatedListener>& key_pressed_or_repeated_listener);

    /// @brief Registers a listener for a key has been released on any window.
    void register_on_key_released(const std::shared_ptr<KeyReleasedListener>& key_released_listener);

    /// @brief Registers a listener for dropped paths on any window.
    void register_on_path_dropped(const std::shared_ptr<PathDroppedListener>& path_dropped_listener);

    /// @brief Registers a listener for character input on a specific window.
    void register_on_window_char_input(const EntityInstancePtr& window, const std::shared_ptr<WindowCharInputListener>& window_char_input_listener);

    /// @brief Registers a listener for the state of a key has been changed on a specific window.
    void register_on_window_key_changed(const EntityInstancePtr& window, const std::shared_ptr<WindowKeyChangedListener>& window_key_changed_listener);

    /// @brief Registers a listener for a key has been pressed on a specific window.
    void register_on_window_key_pressed(const EntityInstancePtr& window, const std::shared_ptr<WindowKeyPressedListener>& window_key_pressed_listener);

    /// @brief Registers a listener for a key has been pressed or repeated on a specific window.
    void register_on_window_key_pressed_or_repeated(const EntityInstancePtr& window, const std::shared_ptr<WindowKeyPressedOrRepeatedListener>& window_key_pressed_or_repeated_listener);

    /// @brief Registers a listener for a key has been released on a specific window.
    void register_on_window_key_released(const EntityInstancePtr& window, const std::shared_ptr<WindowKeyReleasedListener>& window_key_released_listener);

    /// @brief Registers a listener for dropped paths on a specific window.
    void register_on_window_path_dropped(const EntityInstancePtr& window, const std::shared_ptr<WindowPathDroppedListener>& window_path_dropped_listener);

    /// The logger name of this service.
    static constexpr char LOGGER_NAME[] = "inexor.input.keyboard";

    private:
    std::string codepoint2string(unsigned int codepoint);

    std::string get_window_name(const EntityInstancePtr& window);

    /// The factory for creating entity instance of type 'GLOBAL_KEY'.
    GlobalKeyFactoryPtr global_key_factory;

    /// The log manager.
    LogManagerPtr log_manager;

    /// Signal, that the state of a key has been changed on any window.
    SignalKeyChanged signal_key_changed;

    /// Signal, that the state of a key has been pressed on any window.
    SignalKeyPressed signal_key_pressed;

    /// Signal, that the state of a key has been pressed or repeated on any window.
    SignalKeyPressedOrRepeated signal_key_pressed_or_repeated;

    /// Signal, that the state of a key has been released on any window.
    SignalKeyReleased signal_key_released;

    /// Signal, that a path has been dropped on any window.
    SignalPathDropped signal_path_dropped;

    /// Signal character input on a specific window.
    std::unordered_map<EntityInstancePtr, SignalCharInputPtr> signal_window_char_input;

    /// Signal, that the state of a key has been changed on a specific window.
    std::unordered_map<EntityInstancePtr, SignalKeyChangedPtr> signal_window_key_changed;

    /// Signal, that the state of a key has been pressed on a specific window.
    std::unordered_map<EntityInstancePtr, SignalKeyPressedPtr> signal_window_key_pressed;

    /// Signal, that the state of a key has been pressed or repeated on a specific window.
    std::unordered_map<EntityInstancePtr, SignalKeyPressedOrRepeatedPtr> signal_window_key_pressed_or_repeated;

    /// Signal, that the state of a key has been released on a specific window.
    std::unordered_map<EntityInstancePtr, SignalKeyReleasedPtr> signal_window_key_released;

    /// Signal, that a path has been dropped on a specific window.
    std::unordered_map<EntityInstancePtr, SignalPathDroppedPtr> signal_window_path_dropped;
};

} // namespace inexor::input
