#include "WorldRenderer.hpp"

#include <GLFW/glfw3.h>

#include "spdlog/spdlog.h"

namespace inexor {
namespace renderer {

	WorldRenderer::WorldRenderer(
		LogManagerPtr log_manager
	) {
		this->log_manager = log_manager;
	}

	WorldRenderer::~WorldRenderer()
	{
	}

	void WorldRenderer::init()
	{
		log_manager->register_logger(LOGGER_NAME);
	}

	void WorldRenderer::shutdown()
	{
	}

	void WorldRenderer::render_worlds(EntityInstancePtr window, GLFWwindow*)
	{
	}

}
}
