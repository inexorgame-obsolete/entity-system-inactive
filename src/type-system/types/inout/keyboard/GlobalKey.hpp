#pragma once

namespace inexor::entity_system::type_system {

class GlobalKey
{
    public:
    /// Defines the name of this entity type.
    inline static const std::string TYPE_NAME = "GLOBAL_KEY";

    /// The name of the output attribute global_key_keycode.
    inline static const std::string KEYCODE = "global_key_keycode";

    /// The name of the output attribute global_key_action.
    inline static const std::string ACTION = "global_key_action";

    /// The name of the output attribute global_key_mods.
    inline static const std::string MODS = "global_key_mods";
};

} // namespace inexor::entity_system::type_system
