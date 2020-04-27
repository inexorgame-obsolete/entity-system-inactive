#pragma once

#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"

namespace inexor::input {

using EntityInstancePtr = std::shared_ptr<entity_system::EntityInstance>;

/// @class WindowPathDroppedListener
/// @brief Listener for path drops on a specific window.
class WindowPathDroppedListener
{
    public:
    /// Called if a path has been dropped on a specific window.
    virtual void on_window_path_dropped(EntityInstancePtr window, std::vector<std::string> paths) = 0;
};

} // namespace inexor::input
