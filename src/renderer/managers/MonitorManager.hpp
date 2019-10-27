#pragma once

#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "logging/managers/LogManager.hpp"
#include "renderer/factories/MonitorFactory.hpp"

#include <Magnum/Math/Range.h>

struct GLFWmonitor;

namespace inexor::renderer {

using MonitorFactoryPtr = std::shared_ptr<MonitorFactory>;
using LogManagerPtr = std::shared_ptr<inexor::logging::LogManager>;
using EntityInstancePtr = std::shared_ptr<EntityInstance>;
using EntityInstancePtrOpt = std::optional<EntityInstancePtr>;

using Range2Di = Magnum::Math::Range2D<std::int32_t>;
using MonitorRange = std::pair<GLFWmonitor *, Range2Di>;

/// @class MonitorManager
/// @brief Management of the monitors.
class MonitorManager : public std::enable_shared_from_this<MonitorManager>
{
    public:
    /// @brief Constructs the MonitorManager, a monitor management service.
    /// @note The dependencies of this class will be injected automatically.
    /// @param monitor_factory Factory for creating entity instances of type 'MONITOR'.
    /// @param log_manager The log manager.
    MonitorManager(MonitorFactoryPtr monitor_factory, LogManagerPtr log_manager);

    /// Destructor.
    ~MonitorManager();

    /// Initialize the monitor manager.
    void init();

    /// Shut down the monitor manager.
    void shutdown();

    /// Detects the monitors.
    void detect_monitors();

    /// Detects the video modes for the given monitor.
    /// @param monitor The entity instance of type 'MONITOR'.
    void detect_video_modes(const EntityInstancePtr &monitor);

    /// Returns the primary monitor.
    std::optional<EntityInstancePtr> get_primary();

    /// @brief Returns true, if the given monitor is the primary monitor.
    /// @param monitor The entity instance of type 'MONITOR'.
    /// @return True, the given monitor is the primary monitor.
    bool is_primary(const EntityInstancePtr &monitor);

    /// @brief Returns the dimensions of the given monitor.
    /// @param monitor The entity instance of type 'MONITOR'.
    /// @return An optional with the dimension of the given monitor.
    std::optional<Range2Di> get_monitor_dimensions(const EntityInstancePtr &monitor);

    /// @brief Returns the monitors and their dimensions. Monitors
    /// without video mode will not be returned.
    /// @return A vector containing pairs of monitors and their dimensions.
    std::vector<MonitorRange> get_all_monitors_and_dimensions();

    /// @brief Returns the monitor which contains the window center.
    /// @param window_dimensions The window dimensions.
    std::optional<MonitorRange> monitor_contains_window_center(Range2Di window_dimensions);

    /// @brief Returns the monitor which fully contains the window.
    /// @param window_dimensions The window dimensions.
    std::optional<MonitorRange> monitor_fully_contains_window(Range2Di window_dimensions);

    /// @brief Returns the current monitor which contains the window center.
    /// @param window_dimensions The window dimensions.
    std::optional<EntityInstancePtr> get_current_monitor_by_window_center(Range2Di window_dimensions);

    /// @brief Returns the monitor which is left of the given monitor.
    /// @param monitor The entity instance of type 'MONITOR'.
    std::optional<EntityInstancePtr> get_monitor_on_left(const EntityInstancePtr &monitor);

    /// @brief Returns the monitor which is right of the given monitor.
    /// @param monitor The entity instance of type 'MONITOR'.
    std::optional<EntityInstancePtr> get_monitor_on_right(const EntityInstancePtr &monitor);

    std::optional<MonitorRange> get_monitor_range(const EntityInstancePtr &monitor);

    GLFWmonitor *get_monitor_handle(const EntityInstancePtr &monitor);

    /// The logger name of this service.
    static constexpr char LOGGER_NAME[] = "inexor.renderer.monitor";

    private:
    /// @brief Returns true if the the given monitor is the primary monitor.
    /// @param glfw_monitor The glfw monitor.
    std::optional<EntityInstancePtr> get_by_monitor_handle(GLFWmonitor *glfw_monitor);

    /// Creates a monitor.
    EntityInstancePtrOpt create_monitor(GLFWmonitor *glfw_monitor);

    /// Destroys a monitor.
    void destroy_monitor(const EntityInstancePtr &monitor);

    /// @brief Returns true if the the given monitor is the primary monitor.
    /// @param glfw_monitor The glfw monitor.
    bool is_primary(GLFWmonitor *glfw_monitor);

    /// @brief Returns the dimensions of the given monitor.
    /// @param glfw_monitor The glfw monitor.
    std::optional<Range2Di> get_monitor_dimensions(GLFWmonitor *glfw_monitor);

    /// The monitor factory.
    MonitorFactoryPtr monitor_factory;

    /// The log manager.
    LogManagerPtr log_manager;

    /// The mapping between the entity instance and the pointer to the
    /// corresponding monitor.
    std::unordered_map<EntityInstancePtr, GLFWmonitor *> monitors;
};

} // namespace inexor::renderer
