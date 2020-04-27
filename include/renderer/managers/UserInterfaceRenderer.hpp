#pragma once

#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "logging/managers/LogManager.hpp"

#include <Magnum/Timeline.h>

struct GLFWwindow;

namespace inexor::renderer {

using LogManagerPtr = std::shared_ptr<logging::LogManager>;
using EntityInstancePtr = std::shared_ptr<entity_system::EntityInstance>;

/// @class UserInterfaceRenderer
/// @brief Renders the user interfaces.
class UserInterfaceRenderer : public std::enable_shared_from_this<UserInterfaceRenderer>
{
    public:
    /// @brief Constructor.
    /// @note The dependencies of this class will be injected automatically.
    /// @param log_manager The log manager.
    explicit UserInterfaceRenderer(LogManagerPtr log_manager);

    /// Destructor.
    ~UserInterfaceRenderer();

    /// Initialize the user interface renderer.
    void init();

    /// Shut down the user interface renderer.
    void shutdown();

    /// Renders the user interfaces.
    void render_user_interfaces(const EntityInstancePtr& window, GLFWwindow *glfw_window, Magnum::Timeline timeline);

    /// The logger name of this service.
    static constexpr char LOGGER_NAME[] = "inexor.renderer.ui";

    private:
    /// The log manager.
    LogManagerPtr log_manager;
};

} // namespace inexor::renderer
