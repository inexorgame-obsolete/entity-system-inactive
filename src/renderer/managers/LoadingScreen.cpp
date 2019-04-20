#include "LoadingScreen.hpp"

#include "entity-system/model/entity-attributes/entity-attribute-instances/EntityAttributeInstance.hpp"
#include "type-system/providers/inout/keyboard/GlobalKeyEntityTypeProvider.hpp"

#include <Magnum/DebugTools/Screenshot.h>
#include <Magnum/Primitives/Square.h>

#include <GLFW/glfw3.h>

// TODO: enable boost stacktrace again (2/3)
//#include <boost/stacktrace.hpp>

#include "spdlog/spdlog.h"
#include <spdlog/fmt/ostr.h>

#include <algorithm>

using namespace Magnum::Math::Literals;

namespace inexor {
namespace renderer {

	using EntityAttributeInstancePtr = std::shared_ptr<EntityAttributeInstance>;
	using EntityAttributeInstancePtrOpt = std::optional<EntityAttributeInstancePtr>;

	LoadingScreen::LoadingScreen(
		WindowManagerPtr window_manager,
		MonitorManagerPtr monitor_manager,
		KeyboardInputManagerPtr keyboard_input_manager,
		ConnectorManagerPtr connector_manager,
		ClientLifecyclePtr client_lifecycle,
		LogManagerPtr log_manager
	) {
		this->window_manager = window_manager;
		this->monitor_manager = monitor_manager;
		this->keyboard_input_manager = keyboard_input_manager;
		this->connector_manager = connector_manager;
		this->client_lifecycle = client_lifecycle;
		this->log_manager = log_manager;
		this->show_fps = false;
		this->create_screenshot = false;
	}

	LoadingScreen::~LoadingScreen()
	{
	}

	void LoadingScreen::init()
	{
		log_manager->register_logger(LOGGER_NAME);

		// Creates the window
		window = window_manager->create_window(
			"Loading Inexor...",
			800, 0, 800, 600,
			0.8f,
			true, false, false, false, true, true,
			60.0f,
			{ std::bind(&LoadingScreen::init_loading_screen, this, std::placeholders::_1, std::placeholders::_2) },
			{ std::bind(&LoadingScreen::shutdown_loading_screen, this, std::placeholders::_1, std::placeholders::_2) }
		);
		window_manager->center_window(window);
		window_manager->register_render_function(window, std::bind(&LoadingScreen::render_loading_screen, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));

		keyboard_input_manager->register_on_window_key_released(window, shared_from_this());
		keyboard_input_manager->register_on_window_key_pressed_or_repeated(window, shared_from_this());

		EntityInstancePtrOpt o_key_b = keyboard_input_manager->create_key(GLFW_KEY_B);
		if (o_key_b.has_value())
		{
			EntityInstancePtr key_b = o_key_b.value();
			EntityAttributeInstancePtrOpt o_key_b_key = key_b->get_attribute_instance(entity_system::type_system::GlobalKeyEntityTypeProvider::GLOBAL_KEY_KEYCODE);
			EntityAttributeInstancePtrOpt o_key_b_action = key_b->get_attribute_instance(entity_system::type_system::GlobalKeyEntityTypeProvider::GLOBAL_KEY_ACTION);
			if (o_key_b_key.has_value() && o_key_b_action.has_value())
			{
				EntityAttributeInstancePtr key_b_key = o_key_b_key.value();
				EntityAttributeInstancePtr key_b_action = o_key_b_action.value();
				spdlog::info("Creating observer for GLOBAL KEY {} {}", std::get<entity_system::DataType::INT>(key_b_key->value.Value()), std::get<entity_system::DataType::INT>(key_b_action->value.Value()));
				Observe(
					key_b_action->value,
					[] (DataValue action) {
						spdlog::info("GLOBAL KEY B {}", std::get<entity_system::DataType::INT>(action));
						if (std::get<entity_system::DataType::INT>(action) == GLFW_RELEASE)
						{
							// TODO: enable boost stacktrace again (3/3)
							/* spdlog::info("Stacktrace\n{}", boost::stacktrace::stacktrace()); */
						}
					}
				);
			}
		}

	}

	void LoadingScreen::shutdown()
	{
		window_manager->destroy_window(window);
	}

	void toggle_raw(GLFWwindow* glfw_window, int window_attribute)
	{
		glfwSetWindowAttrib(glfw_window, window_attribute, !glfwGetWindowAttrib(glfw_window, window_attribute));
	}


	void increase(EntityInstancePtr entity_instance, std::string name, float step, float max)
	{
		EntityAttributeInstancePtr attr =  entity_instance->get_attribute_instance(name).value();
		attr->own_value.Set(std::min(max, std::get<entity_system::DataType::FLOAT>(attr->value.Value()) + step));
	}

	void increase(EntityInstancePtr entity_instance, std::string name, int step, int max)
	{
		EntityAttributeInstancePtr attr =  entity_instance->get_attribute_instance(name).value();
		attr->own_value.Set(std::min(max, std::get<entity_system::DataType::INT>(attr->value.Value()) + step));
	}

	void decrease(EntityInstancePtr entity_instance, std::string name, float step, float min)
	{
		EntityAttributeInstancePtr attr =  entity_instance->get_attribute_instance(name).value();
		attr->own_value.Set(std::max(min, std::get<entity_system::DataType::FLOAT>(attr->value.Value()) - step));
	}

	void decrease(EntityInstancePtr entity_instance, std::string name, int step, int min)
	{
		EntityAttributeInstancePtr attr =  entity_instance->get_attribute_instance(name).value();
		attr->own_value.Set(std::max(min, std::get<entity_system::DataType::INT>(attr->value.Value()) - step));
	}

	void LoadingScreen::on_window_key_released(EntityInstancePtr window, int key, int scancode, int mods)
	{
		switch (key)
		{
			case GLFW_KEY_X:
				window_manager->destroy_window(window);
				break;
			case GLFW_KEY_Q:
				client_lifecycle->request_shutdown();
				break;
			case GLFW_KEY_R:
				client_lifecycle->request_restart();
				break;
			case GLFW_KEY_V:
				window_manager->set_window_position(window, 100, 100);
				break;
			case GLFW_KEY_G:
				window_manager->set_window_size(window, 800, 600);
				break;
			case GLFW_KEY_H:
				window_manager->set_window_size(window, 1024, 768);
				break;
			case GLFW_KEY_C:
				window_manager->center_window(window);
				break;
			case GLFW_KEY_T:
				window_manager->set_window_title(window, "*Still* loading Inexor...");
				break;
			case GLFW_KEY_I:
				window->toggle(WindowEntityTypeProvider::WINDOW_ICONIFIED);
				break;
			case GLFW_KEY_F:
				window->toggle(WindowEntityTypeProvider::WINDOW_FULLSCREEN);
				break;
			case GLFW_KEY_M:
				window->toggle(WindowEntityTypeProvider::WINDOW_MAXIMIZED);
				break;
			case GLFW_KEY_J:
				window->toggle(WindowEntityTypeProvider::WINDOW_VSYNC);
				break;
			case GLFW_KEY_U:
				toggle_raw(window_manager->get_window_handle(window), GLFW_DECORATED);
				break;
			case GLFW_KEY_MINUS:
				show_fps = !show_fps;
				break;
			case GLFW_KEY_PRINT_SCREEN:
				create_screenshot = true;
				break;
			default:
				break;
		}
	}

	void LoadingScreen::on_window_key_pressed_or_repeated(EntityInstancePtr window, int key, int scancode, int mods)
	{
		spdlog::get(LOGGER_NAME)->debug("Key pressed / repeated {} {} {}", key, scancode, mods);
		switch (key)
		{
			case GLFW_KEY_W:
				decrease(window, WindowEntityTypeProvider::WINDOW_POSITION_Y, 10, 0);
				break;
			case GLFW_KEY_A:
				decrease(window, WindowEntityTypeProvider::WINDOW_POSITION_X, 10, 0);
				break;
			case GLFW_KEY_S:
				increase(window, WindowEntityTypeProvider::WINDOW_POSITION_Y, 10, 3840);
				break;
			case GLFW_KEY_D:
				increase(window, WindowEntityTypeProvider::WINDOW_POSITION_X, 10, 2160);
				break;
			case GLFW_KEY_KP_ADD:
				increase(window, WindowEntityTypeProvider::WINDOW_OPACITY, 0.05f, 1.0f);
				break;
			case GLFW_KEY_KP_SUBTRACT:
				decrease(window, WindowEntityTypeProvider::WINDOW_OPACITY, 0.05f, 0.1f);
				break;
			case GLFW_KEY_PAGE_UP:
				increase(window, WindowEntityTypeProvider::WINDOW_FPS, 5.00f, 250.0f);
				break;
			case GLFW_KEY_PAGE_DOWN:
				decrease(window, WindowEntityTypeProvider::WINDOW_FPS, 5.00f, 10.0f);
				break;
			default:
				break;
		}
	}

	void LoadingScreen::init_loading_screen(EntityInstancePtr window, GLFWwindow* glfw_window)
	{
		spdlog::info("init loading screen");
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

		shader = std::make_shared<Magnum::Shaders::VertexColor2D>();
	}

	void LoadingScreen::render_loading_screen(EntityInstancePtr window, GLFWwindow* glfw_window, Magnum::Timeline timeline)
	{
		// Set viewport
		Magnum::Vector2i framebufferSize;
		glfwGetFramebufferSize(glfw_window, &framebufferSize.x(), &framebufferSize.y());
		Magnum::GL::defaultFramebuffer.setViewport({ {}, framebufferSize });

		// Reset
		Magnum::GL::defaultFramebuffer.clear(Magnum::GL::FramebufferClear::Color);

		// Render logo
		mesh->draw((*shader));

		if (show_fps)
		{
			spdlog::info("frame time: {} frame duration: {} FPS: {}", timeline.previousFrameTime(), timeline.previousFrameDuration(), 1.0f / timeline.previousFrameDuration());
		}
		if (create_screenshot)
		{
			// Test: saving screenshot in all formats (tga included in core magnum, png and jpg needs magnum-plugins)
			Magnum::DebugTools::screenshot(Magnum::GL::defaultFramebuffer, "loading-screen.tga");
			Magnum::DebugTools::screenshot(Magnum::GL::defaultFramebuffer, "loading-screen.png");
			Magnum::DebugTools::screenshot(Magnum::GL::defaultFramebuffer, "loading-screen.jpg");
			create_screenshot = false;
		}
	}

	void LoadingScreen::shutdown_loading_screen(EntityInstancePtr window, GLFWwindow* glfw_window)
	{
		shader = nullptr;
		mesh = nullptr;
		buffer = nullptr;
		spdlog::info("Loading screen destroyed");
	}

}
}
