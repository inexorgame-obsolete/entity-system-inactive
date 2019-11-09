#pragma once

namespace inexor::entity_system::type_system {

class Monitor
{
    public:
    /// Defines the name of this entity type.
    inline static const std::string TYPE_NAME = "MONITOR";

    /// The name of the input attribute monitor_title.
    /// @see glfwGetMonitorName
    inline static const std::string TITLE = "monitor_title";

    /// The name of the output attribute monitor_position_x.
    /// @see glfwGetMonitorWorkarea
    /// @see https://www.glfw.org/docs/3.3/intro_guide.html#coordinate_systems
    inline static const std::string POSITION_X = "monitor_position_x";

    /// The name of the output attribute monitor_position_y.
    /// @see glfwGetMonitorWorkarea
    /// @see https://www.glfw.org/docs/3.3/intro_guide.html#coordinate_systems
    inline static const std::string POSITION_Y = "monitor_position_y";

    /// The name of the output attribute monitor_width.
    /// @see glfwGetMonitorWorkarea
    inline static const std::string WIDTH = "monitor_width";

    /// The name of the output attribute monitor_height.
    /// @see glfwGetMonitorWorkarea
    inline static const std::string HEIGHT = "monitor_height";

    /// The name of the output attribute monitor_is_primary.
    /// @see glfwGetPrimaryMonitor
    inline static const std::string IS_PRIMARY = "monitor_is_primary";
};

} // namespace inexor::entity_system::type_system
