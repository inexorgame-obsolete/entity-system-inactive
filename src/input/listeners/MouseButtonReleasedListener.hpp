#pragma once

#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"

namespace inexor::input {

using EntityInstancePtr = std::shared_ptr<entity_system::EntityInstance>;

/// @class MouseButtonReleasedListener
/// @brief Listener for if a mouse button has been released on any window.
class MouseButtonReleasedListener
{
    public:
    /// Called if a mouse button has been released on any window.
    virtual void on_mouse_button_released(EntityInstancePtr window, int button, int mods) = 0;
};

} // namespace inexor::input
