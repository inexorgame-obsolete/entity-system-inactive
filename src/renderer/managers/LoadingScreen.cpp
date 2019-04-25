#include "LoadingScreen.hpp"

#include "entity-system/model/entity-attributes/entity-attribute-instances/EntityAttributeInstance.hpp"
#include "type-system/providers/inout/keyboard/GlobalKeyEntityTypeProvider.hpp"

#include <Corrade/PluginManager/Manager.h>

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
		FontManagerPtr font_manager,
		KeyboardInputManagerPtr keyboard_input_manager,
		MouseInputManagerPtr mouse_input_manager,
		ConnectorManagerPtr connector_manager,
		ClientLifecyclePtr client_lifecycle,
		LogManagerPtr log_manager
	) {
		this->window_manager = window_manager;
		this->monitor_manager = monitor_manager;
		this->font_manager = font_manager;
		this->keyboard_input_manager = keyboard_input_manager;
		this->mouse_input_manager = mouse_input_manager;
		this->connector_manager = connector_manager;
		this->client_lifecycle = client_lifecycle;
		this->log_manager = log_manager;
		this->show_fps = true;
		this->create_screenshot = false;
		this->mesh_size_x = 0.5f;
		this->mesh_size_y = 0.5f;
		this->mesh_factor = 0.1f;
		this->action = "";
		this->command_buffer = "";
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
		window_manager->center_window_on_current_monitor(window);
		window_manager->register_render_function(window, std::bind(&LoadingScreen::render_loading_screen, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));

		keyboard_input_manager->register_on_window_char_input(window, shared_from_this());
		keyboard_input_manager->register_on_window_key_released(window, shared_from_this());
		keyboard_input_manager->register_on_window_key_pressed_or_repeated(window, shared_from_this());
		mouse_input_manager->register_on_window_mouse_button_changed(window, shared_from_this());
		mouse_input_manager->register_on_window_mouse_scrolled(window, shared_from_this());

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
				spdlog::debug("Creating observer for GLOBAL KEY {} {}", std::get<entity_system::DataType::INT>(key_b_key->value.Value()), std::get<entity_system::DataType::INT>(key_b_action->value.Value()));
				Observe(
					key_b_action->value,
					[] (DataValue action) {
						spdlog::info("GLOBAL KEY B {}", std::get<entity_system::DataType::INT>(action));
						if (std::get<entity_system::DataType::INT>(action) == GLFW_RELEASE)
						{
							spdlog::info("GLOBAL_KEY_B released");
							// TODO: enable boost stacktrace again (3/3)
							/* spdlog::info("Stacktrace\n{}", boost::stacktrace::stacktrace()); */
						}
					}
				);
			}
		}

		EntityInstancePtrOpt o_mouse_button_2 = mouse_input_manager->create_mouse_button(GLFW_MOUSE_BUTTON_MIDDLE);
		if (o_mouse_button_2.has_value())
		{
			EntityInstancePtr mouse_button_2 = o_mouse_button_2.value();
			EntityAttributeInstancePtrOpt o_mouse_button_2_number = mouse_button_2->get_attribute_instance(entity_system::type_system::GlobalMouseButtonEntityTypeProvider::GLOBAL_MOUSE_BUTTON_NUMBER);
			EntityAttributeInstancePtrOpt o_mouse_button_2_action = mouse_button_2->get_attribute_instance(entity_system::type_system::GlobalMouseButtonEntityTypeProvider::GLOBAL_MOUSE_BUTTON_ACTION);
			if (o_mouse_button_2_number.has_value() && o_mouse_button_2_action.has_value())
			{
				EntityAttributeInstancePtr mouse_button_2_number = o_mouse_button_2_number.value();
				EntityAttributeInstancePtr mouse_button_2_action = o_mouse_button_2_action.value();
				spdlog::debug("Creating observer for GLOBAL MOUSE_BUTTON {} {}", std::get<entity_system::DataType::INT>(mouse_button_2_number->value.Value()), std::get<entity_system::DataType::INT>(mouse_button_2_action->value.Value()));
				Observe(
					mouse_button_2_action->value,
					[] (DataValue action) {
						spdlog::info("GLOBAL MOUSE BUTTON 2: {}", std::get<entity_system::DataType::INT>(action));
						if (std::get<entity_system::DataType::INT>(action) == GLFW_RELEASE)
						{
							spdlog::info("GLOBAL_MOUSE_BUTTON_2 released");
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

	void LoadingScreen::on_window_char_input(EntityInstancePtr window, std::string character, unsigned int codepoint)
	{
		spdlog::get(LOGGER_NAME)->debug("on_window_char_input({}, {})", character, codepoint);
		command_buffer += character;
	}

	void LoadingScreen::on_window_key_released(EntityInstancePtr window, int key, int scancode, int mods)
	{
		spdlog::get(LOGGER_NAME)->debug("Key released {} {} {}", key, scancode, mods);
		switch (key)
		{
			case GLFW_KEY_ENTER:
			case GLFW_KEY_KP_ENTER:
				execute_command(window);
				break;

			case GLFW_KEY_X:
				if (mods & GLFW_MOD_CONTROL) window_manager->destroy_window(window);
				break;
			case GLFW_KEY_Q:
				if (mods & GLFW_MOD_CONTROL) client_lifecycle->request_shutdown();
				break;
			case GLFW_KEY_R:
				if (mods & GLFW_MOD_CONTROL) client_lifecycle->request_restart();
				break;
			case GLFW_KEY_1:
				if (mods & GLFW_MOD_CONTROL)
				{
					window_manager->set_window_position(window, 100, 100);
					action = "Window position 100,100";
				} else if (mods & GLFW_MOD_SHIFT)
				{
					window_manager->set_window_size(window, 800, 600);
					action = "Window size 800x600";
				}
				break;
			case GLFW_KEY_2:
				if (mods & GLFW_MOD_CONTROL)
				{
					window_manager->set_window_position(window, 200, 200);
					action = "Window position 200,200";
				} else if (mods & GLFW_MOD_SHIFT)
				{
					window_manager->set_window_size(window, 1024, 768);
					action = "Window size 1024x768";
				}
				break;
			case GLFW_KEY_I:
				if (mods & GLFW_MOD_CONTROL) {
					window->toggle(WindowEntityTypeProvider::WINDOW_ICONIFIED);
					action = window->get<DataType::BOOL>(WindowEntityTypeProvider::WINDOW_ICONIFIED) ? "Iconified" : "Restored";
				}
				break;
			case GLFW_KEY_F:
				if (mods & GLFW_MOD_CONTROL) {
					window->toggle(WindowEntityTypeProvider::WINDOW_FULLSCREEN);
					action = window->get<DataType::BOOL>(WindowEntityTypeProvider::WINDOW_FULLSCREEN) ? "Fullscreen" : "Restored";
				}
				break;
			case GLFW_KEY_M:
				if (mods & GLFW_MOD_CONTROL) {
					window->toggle(WindowEntityTypeProvider::WINDOW_MAXIMIZED);
					action = window->get<DataType::BOOL>(WindowEntityTypeProvider::WINDOW_MAXIMIZED) ? "Maximized" : "Restored";
				}
				break;
			case GLFW_KEY_U:
				if (mods & GLFW_MOD_CONTROL) {
					toggle_raw(window_manager->get_window_handle(window), GLFW_DECORATED);
					action = "Removed window decoration";
				}
				break;
			case GLFW_KEY_T:
				if (mods & GLFW_MOD_CONTROL) {
					window_manager->set_window_title(window, "*Still* loading Inexor...");
					action = "Changed window title";
				}
				break;
			case GLFW_KEY_SCROLL_LOCK:
				window->toggle(WindowEntityTypeProvider::WINDOW_VSYNC);
				action = "Toggle vsync";
				break;
			case GLFW_KEY_PRINT_SCREEN:
				create_screenshot = true;
				action = "Creating screenshot";
				break;


			case GLFW_KEY_UP:
				movement.forward = false;
				break;
			case GLFW_KEY_DOWN:
				movement.backward = false;
				break;
			case GLFW_KEY_LEFT:
				movement.left = false;
				break;
			case GLFW_KEY_RIGHT:
				movement.right = false;
				break;

			case GLFW_KEY_ESCAPE:
				movement.mode = 0;
				action = "";
				break;
			case GLFW_KEY_F1:
				movement.mode = 1;
				action = "Change window position";
				break;
			case GLFW_KEY_F2:
				movement.mode = 2;
				action = "Center window";
				break;
			case GLFW_KEY_F3:
				movement.mode = 3;
				action = "Change window fullscreen";
				break;
			case GLFW_KEY_F4:
				movement.mode = 4;
				action = "Change logo movement";
				break;
			case GLFW_KEY_F5:
				movement.mode = 5;
				action = "Change window opacity";
				break;
			case GLFW_KEY_F6:
				movement.mode = 6;
				action = "Change window fps";
				break;

			case GLFW_KEY_F11:
				show_fps = !show_fps;
				action = fmt::format("{} fps counter", show_fps ? "Show" : "Hide");
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
			case GLFW_KEY_UP:
				movement.forward = true;
				break;
			case GLFW_KEY_DOWN:
				movement.backward = true;
				break;
			case GLFW_KEY_LEFT:
				movement.left = true;
				break;
			case GLFW_KEY_RIGHT:
				movement.right = true;
				break;

			case GLFW_KEY_BACKSPACE:
				command_buffer = command_buffer.substr(0, command_buffer.size() - 1);
				break;

			default:
				break;
		}
		move(window);
	}

	void LoadingScreen::on_window_mouse_button_changed(EntityInstancePtr window, int button, int action, int mods)
	{
//		if (action != GLFW_RELEASE) return;
//		switch (button)
//		{
//			case GLFW_MOUSE_BUTTON_LEFT:
//				switch (mods)
//				{
//					case GLFW_MOD_SHIFT:
//						mesh_size_y = std::max(0.05f, std::min(0.95f, mesh_size_y + 0.05f));
//						break;
//					default:
//						mesh_size_x = std::max(0.05f, std::min(0.95f, mesh_size_x + 0.05f));
//						break;
//				}
//				break;
//			case GLFW_MOUSE_BUTTON_RIGHT:
//				switch (mods)
//				{
//					case GLFW_MOD_SHIFT:
//						mesh_size_y = std::max(0.05f, std::min(0.95f, mesh_size_y - 0.05f));
//						break;
//					default:
//						mesh_size_x = std::max(0.05f, std::min(0.95f, mesh_size_x - 0.05f));
//						break;
//				}
//				break;
//			default:
//				break;
//		}
	}

	/// Window mouse scrolled
	void LoadingScreen::on_window_mouse_scrolled(EntityInstancePtr window, double xpos, double ypos)
	{
		mesh_factor += ((float) ypos * 0.1f);
		action = fmt::format("logo size {}x{} factor {}", mesh_size_x, mesh_size_y, mesh_factor);
	}

	void LoadingScreen::move(EntityInstancePtr window)
	{
		switch (movement.mode)
		{
			case 1:
				// Change window position
				if (movement.forward) decrease(window, WindowEntityTypeProvider::WINDOW_POSITION_Y, 10, 0);
				if (movement.backward) increase(window, WindowEntityTypeProvider::WINDOW_POSITION_Y, 10, 3840);
				if (movement.left) decrease(window, WindowEntityTypeProvider::WINDOW_POSITION_X, 10, 0);
				if (movement.right) increase(window, WindowEntityTypeProvider::WINDOW_POSITION_X, 10, 2160);
				break;
			case 2:
				// Center window
				if (movement.forward) {
					window_manager->center_window_on_current_monitor(window);
					action = "Center window on current monitor";
				}
				if (movement.backward) {
					window_manager->center_window_on_primary_monitor(window);
					action = "Center window on primary monitor";
				}
				if (movement.left) {
					window_manager->center_window_on_next_left_monitor(window);
					action = "Center window on next left monitor";
				}
				if (movement.right) {
					window_manager->center_window_on_next_right_monitor(window);
					action = "Center window on next right monitor";
				}
				break;
			case 3:
				// Change window fullscreen
				if (movement.forward) {
					window_manager->fullscreen_window_on_current_monitor(window);
					action = "Fullscreen window on current monitor";
				}
				if (movement.backward) {
					window_manager->fullscreen_window_on_primary_monitor(window);
					action = "Fullscreen window on primary monitor";
				}
				if (movement.left) {
					window_manager->fullscreen_window_on_next_left_monitor(window);
					action = "Fullscreen window on next left monitor";
				}
				if (movement.right) {
					window_manager->fullscreen_window_on_next_right_monitor(window);
					action = "Fullscreen window on next right monitor";
				}
				break;
			case 4:
				// Change logo movement
				if (movement.forward) {
					mesh_size_y = std::max(0.05f, std::min(0.95f, mesh_size_y + 0.05f));
					action = fmt::format("logo size {}x{} factor {}", mesh_size_x, mesh_size_y, mesh_factor);
				}
				if (movement.backward) {
					mesh_size_y = std::max(0.05f, std::min(0.95f, mesh_size_y - 0.05f));
					action = fmt::format("logo size {}x{} factor {}", mesh_size_x, mesh_size_y, mesh_factor);
				}
				if (movement.left) {
					mesh_size_x = std::max(0.05f, std::min(0.95f, mesh_size_x - 0.05f));
					action = fmt::format("logo size {}x{} factor {}", mesh_size_x, mesh_size_y, mesh_factor);
				}
				if (movement.right) {
					mesh_size_x = std::max(0.05f, std::min(0.95f, mesh_size_x + 0.05f));
					action = fmt::format("logo size {}x{} factor {}", mesh_size_x, mesh_size_y, mesh_factor);
				}
				break;
			case 5:
				// Change window opacity
				if (movement.forward) {
					increase(window, WindowEntityTypeProvider::WINDOW_OPACITY, 0.05f, 1.0f);
					action = fmt::format("opacity = {}", window->get<DataType::FLOAT>(WindowEntityTypeProvider::WINDOW_OPACITY));
				}
				if (movement.backward) {
					decrease(window, WindowEntityTypeProvider::WINDOW_OPACITY, 0.05f, 0.1f);
					action = fmt::format("opacity = {}", window->get<DataType::FLOAT>(WindowEntityTypeProvider::WINDOW_OPACITY));
				}
				break;
			case 6:
				// Change window fps
				if (movement.forward) {
					increase(window, WindowEntityTypeProvider::WINDOW_FPS, 5.00f, 250.0f);
					action = fmt::format("max fps = {}", window->get<DataType::FLOAT>(WindowEntityTypeProvider::WINDOW_FPS));
				}
				if (movement.backward) {
					decrease(window, WindowEntityTypeProvider::WINDOW_FPS, 5.00f, 10.0f);
					action = fmt::format("max fps = {}", window->get<DataType::FLOAT>(WindowEntityTypeProvider::WINDOW_FPS));
				}
				break;
			default:
				break;
		}
	}


	void LoadingScreen::execute_command(EntityInstancePtr window)
	{
		// TODO: call CommandManager; this is a demo only
		if (command_buffer == "/quit")
		{
			client_lifecycle->request_shutdown();
		} else if (command_buffer == "/screenshot") {
			action = "Creating screenshot";
			create_screenshot = true;
		} else if (command_buffer == "/vsync 0") {
			action = "vsync off";
			window->set_own_value(WindowEntityTypeProvider::WINDOW_VSYNC, false);
		} else if (command_buffer == "/vsync 1") {
			action = "vsync on";
			window->set_own_value(WindowEntityTypeProvider::WINDOW_VSYNC, true);
		}
		command_buffer = "";
	}

	// Thread local ("first frame")
	// The initialization must happen within GL context.
	void LoadingScreen::init_loading_screen(EntityInstancePtr window, GLFWwindow* glfw_window)
	{
		buffer = std::make_shared<Magnum::GL::Buffer>();
		mesh = std::make_shared<Magnum::GL::Mesh>();
		shader = std::make_shared<Magnum::Shaders::VertexColor2D>();

		// TODO: Use fontconfig for resolving the font os-independently: https://www.freedesktop.org/wiki/Software/fontconfig/ https://github.com/conan-community/conan-fontconfig
#ifdef __linux__
		std::string font_path = "/usr/share/fonts/truetype/msttcorefonts/Arial.ttf";
#elif _WIN32
		std::string font_path = "C:\\Windows\\Fonts\\arial.ttf";
#endif
		title_font = font_manager->get_font(
			font_path,
			200.0f,
			"INEXOR",
			6,
			0.3f,
			Magnum::Text::Alignment::MiddleCenter
		);
		title_font->renderer->render("INEXOR");
		action_font = font_manager->get_font(
			font_path,
			110.0f,
			"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789?!:;,.+-*/=<>[](){}| ",
			80,
			0.05f,
			Magnum::Text::Alignment::MiddleCenter
		);
		command_font = font_manager->get_font(
			font_path,
			110.0f,
			"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789?!:;,./><() ",
			80,
			0.05f,
			Magnum::Text::Alignment::LineLeft
		);
		fps_font = font_manager->get_font(
			font_path,
			110.0f,
			"fps0123456789 ",
			16,
			0.05f,
			Magnum::Text::Alignment::LineRight
		);
	}

	// Thread local
	void LoadingScreen::render_inexor_logo(Magnum::Timeline timeline)
	{
		float mx = mesh_size_x + std::sin(timeline.previousFrameTime()) * mesh_factor;
		float my = mesh_size_y + std::cos(timeline.previousFrameTime()) * mesh_factor;

		const QuadVertex quad_vertex[] {
			{{ mx, my * -1.0f}, 0xffff00_rgbf},
			{{ mx * -1.0f, my * -1.0f}, 0xffffff_rgbf},
			{{ mx, my}, 0x00ffff_rgbf},
			{{ mx * -1.0f, my}, 0xff00ff_rgbf}
		};
		buffer->setData(quad_vertex);
		mesh->setPrimitive(Magnum::GL::MeshPrimitive::TriangleStrip)
			.setCount(4)
			.addVertexBuffer(
				(*buffer),
				0,
				Magnum::Shaders::VertexColor2D::Position{},
				Magnum::Shaders::VertexColor2D::Color3{}
			);
		mesh->draw((*shader));
	}

	// Thread local
	void LoadingScreen::render_inexor_title(Magnum::Timeline timeline)
	{
		Magnum::GL::Renderer::enable(Magnum::GL::Renderer::Feature::Blending);
		Magnum::GL::Renderer::setBlendFunction(Magnum::GL::Renderer::BlendFunction::SourceAlpha, Magnum::GL::Renderer::BlendFunction::OneMinusSourceAlpha);
		Magnum::GL::Renderer::setBlendEquation(Magnum::GL::Renderer::BlendEquation::Difference, Magnum::GL::Renderer::BlendEquation::Difference);

		auto translation_y = Magnum::Matrix3::translation(Magnum::Vector2::yAxis(-0.2f));
		title_font->shader->setTransformationProjectionMatrix(translation_y)
			.setColor(Magnum::Color4 {0.0f, 0.0f, 0.0f, 0.8f})
			.setOutlineColor(Magnum::Color4 {1.0f, 1.0f, 1.0f, 0.8f})
			.setOutlineRange(0.95f, 1.0f)
			.setSmoothness(0.250f)
			.bindVectorTexture(title_font->glyph_cache->texture());
		title_font->renderer->mesh().draw((*title_font->shader));
	}

	// Thread local
	void LoadingScreen::render_action(Magnum::Timeline timeline)
	{
		Magnum::GL::Renderer::enable(Magnum::GL::Renderer::Feature::Blending);
		Magnum::GL::Renderer::setBlendFunction(Magnum::GL::Renderer::BlendFunction::SourceAlpha, Magnum::GL::Renderer::BlendFunction::OneMinusSourceAlpha);
		Magnum::GL::Renderer::setBlendEquation(Magnum::GL::Renderer::BlendEquation::Add, Magnum::GL::Renderer::BlendEquation::Add);

		action_font->renderer->render(fmt::format(" {} ", action));
		auto translation_y = Magnum::Matrix3::translation(Magnum::Vector2::yAxis(0.9f));
		action_font->shader->setTransformationProjectionMatrix(translation_y)
			.setColor(Magnum::Color4 {1.0f, 1.0f, 1.0f, 0.8f})
			.setOutlineColor(Magnum::Color4 {0.5f, 0.5f, 0.8f, 0.8f})
			.setOutlineRange(0.5f, 1.0f)
			.setSmoothness(0.075f)
			.bindVectorTexture(action_font->glyph_cache->texture());
		action_font->renderer->mesh().draw((*action_font->shader));
	}

	// Thread local
	void LoadingScreen::render_command_buffer(Magnum::Timeline timeline)
	{
		Magnum::GL::Renderer::enable(Magnum::GL::Renderer::Feature::Blending);
		Magnum::GL::Renderer::setBlendFunction(Magnum::GL::Renderer::BlendFunction::SourceAlpha, Magnum::GL::Renderer::BlendFunction::OneMinusSourceAlpha);
		Magnum::GL::Renderer::setBlendEquation(Magnum::GL::Renderer::BlendEquation::Add, Magnum::GL::Renderer::BlendEquation::Add);

		command_font->renderer->render(fmt::format("> {}", command_buffer));
		auto translation_x = Magnum::Matrix3::translation(Magnum::Vector2::xAxis(-0.9f));
		auto translation_y = Magnum::Matrix3::translation(Magnum::Vector2::yAxis(-0.9f));
		command_font->shader->setTransformationProjectionMatrix(translation_x * translation_y)
			.setColor(Magnum::Color4 {1.0f, 1.0f, 1.0f, 0.8f})
			.setOutlineColor(Magnum::Color4 {0.5f, 0.5f, 0.8f, 0.8f})
			.setOutlineRange(0.5f, 1.0f)
			.setSmoothness(0.075f)
			.bindVectorTexture(command_font->glyph_cache->texture());
		command_font->renderer->mesh().draw((*command_font->shader));
	}

	// Thread local
	void LoadingScreen::render_fps_counter(Magnum::Timeline timeline)
	{
		Magnum::GL::Renderer::enable(Magnum::GL::Renderer::Feature::Blending);
		Magnum::GL::Renderer::setBlendFunction(Magnum::GL::Renderer::BlendFunction::SourceAlpha, Magnum::GL::Renderer::BlendFunction::OneMinusSourceAlpha);
		Magnum::GL::Renderer::setBlendEquation(Magnum::GL::Renderer::BlendEquation::Add, Magnum::GL::Renderer::BlendEquation::Add);

		int fps = (int) std::ceil(1.0f / timeline.previousFrameDuration());
		fps_font->renderer->render(fmt::format("{} fps", fps));
		auto translation_x = Magnum::Matrix3::translation(Magnum::Vector2::xAxis(0.9f));
		auto translation_y = Magnum::Matrix3::translation(Magnum::Vector2::yAxis(-0.9f));
		fps_font->shader->setTransformationProjectionMatrix(translation_x * translation_y)
			.setColor(Magnum::Color4 {1.0f, 1.0f, 1.0f, 0.8f})
			.setOutlineColor(Magnum::Color4 {0.5f, 0.5f, 0.8f, 0.8f})
			.setOutlineRange(0.5f, 1.0f)
			.setSmoothness(0.075f)
			.bindVectorTexture(fps_font->glyph_cache->texture());
		fps_font->renderer->mesh().draw((*fps_font->shader));
	}

	// Thread local
	void LoadingScreen::render_loading_screen(EntityInstancePtr window, GLFWwindow* glfw_window, Magnum::Timeline timeline)
	{
		// Set viewport
		Magnum::Vector2i framebufferSize;
		glfwGetFramebufferSize(glfw_window, &framebufferSize.x(), &framebufferSize.y());
		Magnum::GL::defaultFramebuffer.setViewport({ {}, framebufferSize });

		// Reset
		Magnum::GL::defaultFramebuffer.clear(Magnum::GL::FramebufferClear::Color);

		// Render logo and title
		render_inexor_logo(timeline);
		render_inexor_title(timeline);

		// Render action
		render_action(timeline);

		// Render text input
		render_command_buffer(timeline);

		if (show_fps)
		{
			// spdlog::debug("frame time: {} frame duration: {} FPS: {}", timeline.previousFrameTime(), timeline.previousFrameDuration(), 1.0f / timeline.previousFrameDuration());
			render_fps_counter(timeline);
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

	// Thread local ("last frame")
	// The destruction must happen within GL context.
	void LoadingScreen::shutdown_loading_screen(EntityInstancePtr window, GLFWwindow* glfw_window)
	{
		shader = nullptr;
		mesh = nullptr;
		buffer = nullptr;

		// TODO: free fonts!
		title_font = nullptr;
		action_font = nullptr;
		command_font = nullptr;
		fps_font = nullptr;

		spdlog::info("Loading screen destroyed");
	}

}
}
