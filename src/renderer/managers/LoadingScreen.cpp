#include "LoadingScreen.hpp"

#include "entity-system/model/entity-attributes/entity-attribute-instances/EntityAttributeInstance.hpp"
#include "type-system/providers/inout/keyboard/GlobalKeyEntityTypeProvider.hpp"

#include <Magnum/Primitives/Square.h>

#include <GLFW/glfw3.h>

#include <boost/stacktrace.hpp>

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
		KeyboardInputManagerPtr keyboard_input_manager,
		ConnectorManagerPtr connector_manager,
		LogManagerPtr log_manager
	) {
		this->window_manager = window_manager;
		this->keyboard_input_manager = keyboard_input_manager;
		this->connector_manager = connector_manager;
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
		window = window_manager->create_window("Inexor Logo", 0, 0, 800, 600, 0.8f, true, false, false, false, true);
		// The first render function is the initialization function which is executed only once
		window_manager->register_render_function(window, std::bind(&LoadingScreen::create_logo, this, std::placeholders::_1, std::placeholders::_2));
		// The second render function is for rendering the inexor logo
		window_manager->register_render_function(window, std::bind(&LoadingScreen::render_logo, this, std::placeholders::_1, std::placeholders::_2));

		keyboard_input_manager->register_on_window_key_released(window, shared_from_this());

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
						spdlog::info("Stacktrace {}", boost::stacktrace::stacktrace());
					}
				);
			}
		}
	}

	void LoadingScreen::shutdown()
	{
		window_manager->destroy_window(window);
	}

	void toggle(EntityInstancePtr entity_instance, std::string name)
	{
		EntityAttributeInstancePtr attr =  entity_instance->get_attribute_instance(name).value();
		attr->own_value.Set(!std::get<entity_system::DataType::BOOL>(attr->value.Value()));
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

		spdlog::get(LOGGER_NAME)->info("Loading Screen {} {} {}", key, scancode, mods);
		switch (key)
		{
			case GLFW_KEY_X:
				window_manager->destroy_window(window);
				break;
			case GLFW_KEY_Q:
				window_manager->shutdown();
				break;
			case GLFW_KEY_HOME:
				window_manager->set_window_position(window, 100, 100);
				break;
			case GLFW_KEY_END:
				window_manager->set_window_size(window, 800, 600);
				break;
			case GLFW_KEY_I:
				toggle(window, WindowEntityTypeProvider::WINDOW_ICONIFIED);
				break;
			case GLFW_KEY_F:
				toggle(window, WindowEntityTypeProvider::WINDOW_FULLSCREEN);
				break;
			case GLFW_KEY_M:
				toggle(window, WindowEntityTypeProvider::WINDOW_MAXIMIZED);
				break;
			case GLFW_KEY_W:
				decrease(window, WindowEntityTypeProvider::WINDOW_POSITION_Y, 5, 0);
				break;
			case GLFW_KEY_A:
				decrease(window, WindowEntityTypeProvider::WINDOW_POSITION_X, 5, 0);
				break;
			case GLFW_KEY_S:
				increase(window, WindowEntityTypeProvider::WINDOW_POSITION_Y, 5, 800);
				break;
			case GLFW_KEY_D:
				increase(window, WindowEntityTypeProvider::WINDOW_POSITION_X, 5, 600);
				break;
			case GLFW_KEY_KP_ADD:
				increase(window, WindowEntityTypeProvider::WINDOW_OPACITY, 0.05f, 1.0f);
				break;
			case GLFW_KEY_KP_SUBTRACT:
				decrease(window, WindowEntityTypeProvider::WINDOW_OPACITY, 0.05f, 0.1f);
				break;
			default:
				break;
		}
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

			shader = std::make_shared<Magnum::Shaders::VertexColor2D>();

			initialized = true;

			spdlog::info("logo mesh initialized");
		}
	}

	void LoadingScreen::render_logo(EntityInstancePtr window, GLFWwindow* glfw_window)
	{
		// Set viewport
		Magnum::Vector2i framebufferSize;
		glfwGetFramebufferSize(glfw_window, &framebufferSize.x(), &framebufferSize.y());
		Magnum::GL::defaultFramebuffer.setViewport({ {}, framebufferSize });

		// Reset
		Magnum::GL::defaultFramebuffer.clear(Magnum::GL::FramebufferClear::Color);

		// Render logo
		mesh->draw((*shader));
	}

}
}
