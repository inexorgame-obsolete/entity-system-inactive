#pragma once

#include "type-system/providers/inout/console/ConsoleProviders.hpp"
#include "type-system/providers/inout/keyboard/KeyboardProviders.hpp"
#include "type-system/providers/inout/logger/LoggerProviders.hpp"
#include "type-system/providers/inout/mouse/MouseProviders.hpp"

namespace inexor::entity_system::type_system {

using ConsoleProvidersPtr = std::shared_ptr<ConsoleProviders>;
using KeyboardProvidersPtr = std::shared_ptr<KeyboardProviders>;
using MouseProvidersPtr = std::shared_ptr<MouseProviders>;
using LoggerProvidersPtr = std::shared_ptr<LoggerProviders>;

/// @class InOutProviders
/// @brief The providers for input and output.
class InOutProviders
{
    public:
    /// @brief Constructs the providers for input and output.
    /// @note The dependencies of this class will be injected automatically.
    /// @param console_providers The providers for the console.
    /// @param keyboard_providers The providers for the keyboard input.
    /// @param mouse_providers The providers for the mouse input.
    /// @param logger_providers The providers for loggers.
    InOutProviders(ConsoleProvidersPtr console_providers, KeyboardProvidersPtr keyboard_providers, MouseProvidersPtr mouse_providers, LoggerProvidersPtr logger_providers);

    /// Destructor.
    ~InOutProviders();

    /// Initializes the providers for input and output.
    void init();

    private:
    /// The providers for the console.
    ConsoleProvidersPtr console_providers;

    /// The providers for the keyboard input.
    KeyboardProvidersPtr keyboard_providers;

    /// The providers for the mouse.
    MouseProvidersPtr mouse_providers;

    /// The providers for loggers.
    LoggerProvidersPtr logger_providers;
};

} // namespace inexor::entity_system::type_system
