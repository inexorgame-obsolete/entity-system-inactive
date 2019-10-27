#pragma once

#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "logging/managers/LogManager.hpp"

#include <Magnum/Timeline.h>

struct GLFWwindow;

namespace inexor::renderer {

using LogManagerPtr = std::shared_ptr<logging::LogManager>;
using EntityInstancePtr = std::shared_ptr<entity_system::EntityInstance>;

/// @class WorldRenderer
/// @brief Renders the world (octree, models).
class WorldRenderer : public std::enable_shared_from_this<WorldRenderer>
{
    public:
    /// @brief Constructor.
    /// @note The dependencies of this class will be injected automatically.
    /// @param log_manager The log manager.
    explicit WorldRenderer(LogManagerPtr log_manager);

    /// Destructor.
    ~WorldRenderer();

    /// Initialize the world renderer.
    void init();

    /// Shut down the world renderer.
    void shutdown();

    /// Renders the worlds (octree, models).
    void render_worlds(const EntityInstancePtr& window, GLFWwindow *glfw_window, Magnum::Timeline timeline);

    /// The logger name of this service.
    static constexpr char LOGGER_NAME[] = "inexor.renderer.world";

    private:
    /// The log manager.
    LogManagerPtr log_manager;
};

} // namespace inexor::renderer
