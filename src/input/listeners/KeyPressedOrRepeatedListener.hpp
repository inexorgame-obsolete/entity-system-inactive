#pragma once

#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"

namespace inexor::input {

using EntityInstancePtr = std::shared_ptr<entity_system::EntityInstance>;

/// @class KeyPressedOrRepeatedListener
/// @brief Listener for if a key has been pressed or repeated on any window.
class KeyPressedOrRepeatedListener
{
    public:
    /// Called if a key has been pressed or repeated on any window.
    virtual void on_key_pressed_or_repeated(EntityInstancePtr window, int key, int scancode, int mods) = 0;
};

} // namespace inexor::input
