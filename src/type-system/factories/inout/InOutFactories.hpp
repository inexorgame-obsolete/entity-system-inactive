#pragma once

#include "type-system/factories/inout/keyboard/KeyboardFactories.hpp"
#include "type-system/factories/inout/logger/LoggerFactories.hpp"
#include "type-system/factories/inout/mouse/MouseFactories.hpp"

namespace inexor::entity_system::type_system {

using KeyboardFactoriesPtr = std::shared_ptr<KeyboardFactories>;
using MouseFactoriesPtr = std::shared_ptr<MouseFactories>;
using LoggerFactoriesPtr = std::shared_ptr<LoggerFactories>;

/// @class InOutFactories
/// @brief The factories for input and output.
class InOutFactories
{
    public:
    /// @brief Constructs the factories for input and output.
    /// @note The dependencies of this class will be injected automatically.
    /// @param keyboard_factories The factories for keyboard input.
    /// @param mouse_factories The factories for mouse input.
    /// @param logger_factories The factories for loggers.
    InOutFactories(KeyboardFactoriesPtr keyboard_factories, MouseFactoriesPtr mouse_factories, LoggerFactoriesPtr logger_factories);

    /// Destructor.
    ~InOutFactories();

    /// Initializes the factories for input and output.
    void init();

    /// Returns the factories for keyboard input.
    KeyboardFactoriesPtr get_keyboard_factories();

    /// Returns the factories for mouse input.
    MouseFactoriesPtr get_mouse_factories();

    private:
    /// The factories for keyboard input.
    KeyboardFactoriesPtr keyboard_factories;

    /// The factories for mouse input.
    MouseFactoriesPtr mouse_factories;

    /// The factories for loggers.
    LoggerFactoriesPtr logger_factories;
};

} // namespace inexor::entity_system::type_system
