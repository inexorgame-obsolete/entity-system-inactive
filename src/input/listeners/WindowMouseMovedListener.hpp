#pragma once

#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"

namespace inexor::input {

using EntityInstancePtr = std::shared_ptr<entity_system::EntityInstance>;

/// @class WindowMouseMovedListener
/// @brief Listener for mouse movement on a specific window.
class WindowMouseMovedListener
{
    public:
    /// Called if the mouse position has been changed on a specific window.
    virtual void on_window_mouse_moved(EntityInstancePtr window, double xpos, double ypos) = 0;
};

} // namespace inexor::input
