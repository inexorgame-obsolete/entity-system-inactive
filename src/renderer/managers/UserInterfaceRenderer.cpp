#include <renderer/managers/UserInterfaceRenderer.hpp>

#include <GLFW/glfw3.h>

#include <utility>

#include "spdlog/spdlog.h"

namespace inexor::renderer {

UserInterfaceRenderer::UserInterfaceRenderer(LogManagerPtr log_manager)
{
    this->log_manager = std::move(log_manager);
}

UserInterfaceRenderer::~UserInterfaceRenderer() = default;

void UserInterfaceRenderer::init()
{
    log_manager->register_logger(LOGGER_NAME);
}

void UserInterfaceRenderer::shutdown()
{
}

void UserInterfaceRenderer::render_user_interfaces(const EntityInstancePtr &window, GLFWwindow *glfw_window, Magnum::Timeline timeline)
{
}

} // namespace inexor::renderer
