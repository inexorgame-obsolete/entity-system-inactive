#pragma once

namespace inexor::entity_system::type_system {

class Window
{
    public:
    /// Defines the name of this entity type.
    inline static const std::string TYPE_NAME = "WINDOW";

    /// The name of the output attribute window_id.
    inline static const std::string ID = "window_id";

    /// The name of the inout attribute window_title.
    inline static const std::string TITLE = "window_title";

    /// The name of the inout attribute window_position_x.
    inline static const std::string POSITION_X = "window_position_x";

    /// The name of the inout attribute window_position_y.
    inline static const std::string POSITION_Y = "window_position_y";

    /// The name of the inout attribute window_width.
    inline static const std::string WIDTH = "window_width";

    /// The name of the inout attribute window_height.
    inline static const std::string HEIGHT = "window_height";

    /// The name of the inout attribute window_opacity.
    inline static const std::string OPACITY = "window_opacity";

    /// The name of the inout attribute window_fullscreen.
    inline static const std::string FULLSCREEN = "window_fullscreen";

    /// The name of the output attribute window_restore_width.
    inline static const std::string RESTORE_WIDTH = "window_restore_width";

    /// The name of the output attribute window_restore_height.
    inline static const std::string RESTORE_HEIGHT = "window_restore_height";

    /// The name of the inout attribute window_visible.
    inline static const std::string VISIBLE = "window_visible";

    /// The name of the inout attribute window_iconified.
    inline static const std::string ICONIFIED = "window_iconified";

    /// The name of the inout attribute window_maximized.
    inline static const std::string MAXIMIZED = "window_maximized";

    /// The name of the output attribute window_focused.
    inline static const std::string FOCUSED = "window_focused";

    /// The name of the inout attribute window_vsync.
    inline static const std::string VSYNC = "window_vsync";

    /// The name of the inout attribute window_fps.
    inline static const std::string FPS = "window_fps";
};

} // namespace inexor::entity_system::type_system
