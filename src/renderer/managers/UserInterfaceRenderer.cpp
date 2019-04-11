#include "UserInterfaceRenderer.hpp"

#include <GLFW/glfw3.h>

#include "spdlog/spdlog.h"

namespace inexor {
namespace renderer {

	UserInterfaceRenderer::UserInterfaceRenderer(
		LogManagerPtr log_manager
	) {
		this->log_manager = log_manager;
	}

	UserInterfaceRenderer::~UserInterfaceRenderer()
	{
	}

	void UserInterfaceRenderer::init()
	{
		log_manager->register_logger(LOGGER_NAME);
	}

	void UserInterfaceRenderer::shutdown()
	{
	}

	void UserInterfaceRenderer::render_user_interfaces(EntityInstancePtr window, GLFWwindow* glfw_window)
	{
	}

}
}
