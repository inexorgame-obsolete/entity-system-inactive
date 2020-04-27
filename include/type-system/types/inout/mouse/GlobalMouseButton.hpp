#pragma once

namespace inexor::entity_system::type_system {

class GlobalMouseButton
{
    public:
    /// Defines the name of this entity type.
    inline static const std::string TYPE_NAME = "GLOBAL_MOUSE_BUTTON";

    /// The name of the output attribute global_mouse_button_number.
    inline static const std::string BUTTON_NUMBER = "global_mouse_button_number";

    /// The name of the output attribute global_mouse_button_action.
    inline static const std::string ACTION = "global_mouse_button_action";

    /// The name of the output attribute global_mouse_button_mods.
    inline static const std::string MODS = "global_mouse_button_mods";
};

} // namespace inexor::entity_system::type_system
