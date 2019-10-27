#pragma once

#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"

namespace inexor::input {

using EntityInstancePtr = std::shared_ptr<entity_system::EntityInstance>;

/// @class WindowCharInputListener
/// @brief Listener for char input on a specific window.
class WindowCharInputListener
{
    public:
    /// Called on character input.
    virtual void on_window_char_input(EntityInstancePtr window, std::string character, unsigned int codepoint) = 0;
};

} // namespace inexor::input
