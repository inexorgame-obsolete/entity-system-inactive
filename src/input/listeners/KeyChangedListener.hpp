#pragma once

#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"

namespace inexor::input {

using EntityInstancePtr = std::shared_ptr<entity_system::EntityInstance>;

/// @class KeyChangedListener
/// @brief Listener for state changes of a key (either pressed or released) on any window.
class KeyChangedListener
{
    public:
    /// Called if the state of a key has been changed.
    virtual void on_key_changed(EntityInstancePtr window, int key, int scancode, int action, int mods) = 0;
};

} // namespace inexor::input
