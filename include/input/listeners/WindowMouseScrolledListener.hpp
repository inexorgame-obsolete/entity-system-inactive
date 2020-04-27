#pragma once

#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"

namespace inexor::input {

using EntityInstancePtr = std::shared_ptr<entity_system::EntityInstance>;

/// @class WindowMouseScrolledListener
/// @brief Listener for mouse scrolled on a specific window.
class WindowMouseScrolledListener
{
    public:
    /// Called if the mouse has been scrolled on a specific window.
    virtual void on_window_mouse_scrolled(EntityInstancePtr window, double xoffset, double yoffset) = 0;
};

} // namespace inexor::input
