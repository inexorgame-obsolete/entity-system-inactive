#pragma once

#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"

namespace inexor::input {

using EntityInstancePtr = std::shared_ptr<entity_system::EntityInstance>;

/// @class KeyReleasedListener
/// @brief Listener for if a key has been released on any window.
class KeyReleasedListener
{
    public:
    /// Called if a key has been released on any window.
    virtual void on_key_released(EntityInstancePtr window, int key, int scancode, int mods) = 0;
};

} // namespace inexor::input
