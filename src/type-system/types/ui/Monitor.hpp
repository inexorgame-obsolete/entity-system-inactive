#pragma once

namespace inexor::entity_system::type_system {

class Monitor
{
    public:
    /// Defines the name of this entity type.
    inline static const std::string TYPE_NAME = "MONITOR";

    /// The prefix of the attribute names.
    inline static const std::string PREFIX = "monitor_";

    /// The name of the input attribute monitor_title.
    /// @see glfwGetMonitorName
    inline static const std::string TITLE = PREFIX + "title";

    /// The name of the output attribute monitor_position_x.
    /// @see glfwGetMonitorWorkarea
    /// @see https://www.glfw.org/docs/3.3/intro_guide.html#coordinate_systems
    inline static const std::string POSITION_X = PREFIX + "position_x";

    /// The name of the output attribute monitor_position_y.
    /// @see glfwGetMonitorWorkarea
    /// @see https://www.glfw.org/docs/3.3/intro_guide.html#coordinate_systems
    inline static const std::string POSITION_Y = PREFIX + "position_y";

    /// The name of the output attribute monitor_width.
    /// @see glfwGetMonitorWorkarea
    inline static const std::string WIDTH = PREFIX + "width";

    /// The name of the output attribute monitor_height.
    /// @see glfwGetMonitorWorkarea
    inline static const std::string HEIGHT = PREFIX + "height";

    /// The name of the output attribute monitor_is_primary.
    /// @see glfwGetPrimaryMonitor
    inline static const std::string IS_PRIMARY = PREFIX + "is_primary";
};

} // namespace inexor::entity_system::type_system
