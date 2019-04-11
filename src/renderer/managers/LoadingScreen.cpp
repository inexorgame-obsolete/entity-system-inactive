#include "LoadingScreen.hpp"

#include <Magnum/Primitives/Square.h>

#include <GLFW/glfw3.h>

#include "spdlog/spdlog.h"

using namespace Magnum::Math::Literals;

namespace inexor {
namespace renderer {

	LoadingScreen::LoadingScreen(
		WindowManagerPtr window_manager,
		LogManagerPtr log_manager
	) {
		this->window_manager = window_manager;
		this->log_manager = log_manager;
		this->initialized = false;
	}

	LoadingScreen::~LoadingScreen()
	{
	}

	void LoadingScreen::init()
	{
		log_manager->register_logger(LOGGER_NAME);

		// Creates the window
		window = window_manager->create_window("Inexor", 0, 0, 800, 600);
		// The first render function is the initialization function which is executed only once
		window_manager->register_render_function(window, std::bind(&LoadingScreen::create_logo, this, std::placeholders::_1, std::placeholders::_2));
		// The second render function is for rendering the inexor logo
		window_manager->register_render_function(window, std::bind(&LoadingScreen::render_logo, this, std::placeholders::_1, std::placeholders::_2));
	}

	void LoadingScreen::shutdown()
	{
		window_manager->destroy_window(window);
	}


	void LoadingScreen::create_logo(EntityInstancePtr window, GLFWwindow* glfw_window)
	{
		if (!initialized)
		{
			spdlog::info("create logo");
			const QuadVertex quad_vertex[] {
				{{ 0.5f, -0.5f}, 0xffff00_rgbf},
				{{-0.5f, -0.5f}, 0xffffff_rgbf},
				{{ 0.5f,  0.5f}, 0x00ffff_rgbf},
				{{-0.5f,  0.5f}, 0xff00ff_rgbf}
			};

			buffer = std::make_shared<Magnum::GL::Buffer>();
			buffer->setData(quad_vertex);

			mesh = std::make_shared<Magnum::GL::Mesh>();

			// Magnum::Trade::MeshData2D square = Magnum::Primitives::squareSolid();

			mesh->setPrimitive(Magnum::GL::MeshPrimitive::TriangleStrip)
				.setCount(4)
				.addVertexBuffer(
					(*buffer),
					0,
					Magnum::Shaders::VertexColor2D::Position{},
					Magnum::Shaders::VertexColor2D::Color3{}
				);

			initialized = true;

			spdlog::info("logo mesh initialized");
		}
	}

	void LoadingScreen::render_logo(EntityInstancePtr window, GLFWwindow* glfw_window)
	{
		// spdlog::info("render_logo");

		shader = std::make_shared<Magnum::Shaders::VertexColor2D>();

		// Render here.
		Magnum::GL::defaultFramebuffer.clear(Magnum::GL::FramebufferClear::Color);
		mesh->draw((*shader));
	}

}
}
