#include "WorldRenderer.hpp"

#include <GLFW/glfw3.h>

#include <utility>

#include "spdlog/spdlog.h"

namespace inexor::renderer {

	WorldRenderer::WorldRenderer(
		LogManagerPtr log_manager
	) {
		this->log_manager = std::move(log_manager);
	}

	WorldRenderer::~WorldRenderer()
	= default;

	void WorldRenderer::init()
	{
		log_manager->register_logger(LOGGER_NAME);
	}

	void WorldRenderer::shutdown()
	{
	}

	void WorldRenderer::render_worlds(const EntityInstancePtr& window, GLFWwindow*, Magnum::Timeline timeline)
	{
	}

}
