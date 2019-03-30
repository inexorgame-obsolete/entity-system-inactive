#include "RendererManager.hpp"

#include <Magnum/GL/Buffer.h>
#include <Magnum/GL/DefaultFramebuffer.h>
#include <Magnum/GL/Mesh.h>
#include <Magnum/GL/Renderer.h>
#include <Magnum/Platform/GLContext.h>
#include <Magnum/Math/Color.h>
#include <Magnum/Shaders/VertexColor.h>
#include <GLFW/glfw3.h>

#include "spdlog/spdlog.h"

#include <iomanip>

using namespace std::chrono_literals;
using namespace Magnum;
using namespace Math::Literals;

namespace inexor {
namespace renderer {

	using EntityInstancePtrOpt = std::optional<EntityInstancePtr>;
	using EntityAttributeInstanceOpt = std::optional<EntityAttributeInstancePtr>;

	RendererManager::RendererManager(
		EntityInstanceManagerPtr entity_instance_manager,
		ConnectorManagerPtr connector_manager,
		CounterFloatFactoryPtr counter_float_factory,
		SinFactoryPtr sin_factory,
		CosFactoryPtr cos_factory,
		RendererFactoryPtr render_factory,
		LogManagerPtr log_manager,
		KeyboardInputManagerPtr keyboard_input_manager,
		MouseInputManagerPtr mouse_input_manager
	) {
		this->entity_instance_manager = entity_instance_manager;
		this->connector_manager = connector_manager;
		this->counter_float_factory = counter_float_factory;
		this->sin_factory = sin_factory;
		this->cos_factory = cos_factory;
		this->renderer_factory = render_factory;
		this->log_manager = log_manager;
		this->keyboard_input_manager = keyboard_input_manager;
		this->mouse_input_manager = mouse_input_manager;
	}

	RendererManager::~RendererManager()
	{
	}

	GLFWwindow *create_window()
	{
		// Initialize the library.
		if(!glfwInit())
		{
			spdlog::get(RendererManager::LOGGER_NAME)->error("Failed to initialize glfw!");
			std::exit(1);
		}

		// Create a windowed mode window and its OpenGL context.
		GLFWwindow* const window = glfwCreateWindow(
			800,
			600,
			"Inexor Renderer 1",
			nullptr,
			nullptr
		);

		if(!window)
		{
			glfwTerminate();
			spdlog::get(RendererManager::LOGGER_NAME)->error("Failed to create window!");
			std::exit(1);
		}
		return window;
	}

	void RendererManager::init()
	{
		log_manager->register_logger(LOGGER_NAME);

		EntityInstancePtrOpt o_counter = counter_float_factory->create_instance(50, 0.1f);
		EntityInstancePtrOpt o_sin = sin_factory->create_instance();
		EntityInstancePtrOpt o_cos = cos_factory->create_instance();
		EntityInstancePtrOpt o_renderer = renderer_factory->create_instance(0.5f, -0.5f);

		if(o_counter.has_value() && o_sin.has_value() && o_cos.has_value() && o_renderer.has_value())
		{
			counter = o_counter.value();
			sin = o_sin.value();
			cos = o_cos.value();
			renderer = o_renderer.value();

			EntityAttributeInstanceOpt o_counter_attr_count = counter->get_attribute_instance(entity_system::type_system::CounterFloatEntityTypeProvider::COUNTER_FLOAT_COUNT);
			EntityAttributeInstanceOpt o_sin_attr_input = sin->get_attribute_instance(entity_system::type_system::SinEntityTypeProvider::SIN_INPUT);
			EntityAttributeInstanceOpt o_sin_attr_value = sin->get_attribute_instance(entity_system::type_system::SinEntityTypeProvider::SIN_VALUE);
			EntityAttributeInstanceOpt o_cos_attr_input = cos->get_attribute_instance(entity_system::type_system::CosEntityTypeProvider::COS_INPUT);
			EntityAttributeInstanceOpt o_cos_attr_value = cos->get_attribute_instance(entity_system::type_system::CosEntityTypeProvider::COS_VALUE);
			EntityAttributeInstanceOpt o_renderer_attr_x = renderer->get_attribute_instance(RendererEntityTypeProvider::RENDERER_X);
			EntityAttributeInstanceOpt o_renderer_attr_y = renderer->get_attribute_instance(RendererEntityTypeProvider::RENDERER_Y);

			if(o_counter_attr_count.has_value() && o_sin_attr_value.has_value() && o_cos_attr_value.has_value() && o_renderer_attr_x.has_value() && o_renderer_attr_y.has_value())
			{
				counter_attr_count = o_counter_attr_count.value();
				sin_attr_input = o_sin_attr_input.value();
				sin_attr_value = o_sin_attr_value.value();
				cos_attr_input = o_cos_attr_input.value();
				cos_attr_value = o_cos_attr_value.value();
				renderer_attr_x = o_renderer_attr_x.value();
				renderer_attr_y = o_renderer_attr_y.value();
			}
			else
			{
				spdlog::get(LOGGER_NAME)->error("Failed to get attributes");
			}
		}
		else
		{
			spdlog::get(LOGGER_NAME)->error("Failed to create entity instances: SIN, COS, RENDERER");
		}

		GLFWwindow *window = create_window();
		std::thread start_thread(&renderer::RendererManager::start_window_thread, this, window);
		start_thread.detach();
	}

	void RendererManager::start_window_thread(GLFWwindow *window)
	{
		std::optional<std::shared_ptr<visual_scripting::Connector>> connector_c_sin = connector_manager->create_connector(counter_attr_count, sin_attr_input);
		if(!connector_c_sin.has_value())
		{
			//spdlog::get(LOGGER_NAME)->error("Failed to create connector_c_sin");
		}
		else
		{
			//spdlog::get(LOGGER_NAME)->info("Created connector_c_sin");
			connector_c_sin.value()->enable_debug();
		}

		std::optional<std::shared_ptr<visual_scripting::Connector>> connector_c_cos = connector_manager->create_connector(counter_attr_count, cos_attr_input);
		if(!connector_c_cos.has_value())
		{
			//spdlog::get(LOGGER_NAME)->error("Failed to create connector_c_cos");
		}
		else
		{
			//spdlog::get(LOGGER_NAME)->info("Created connector_c_cos");
			connector_c_cos.value()->enable_debug();
		}

		std::optional<std::shared_ptr<visual_scripting::Connector>> connector_x = connector_manager->create_connector(sin_attr_value, renderer_attr_x);
		if(!connector_x.has_value())
		{
			//spdlog::get(LOGGER_NAME)->error("Failed to create connector_x");
		}
		else
		{
			//spdlog::get(LOGGER_NAME)->info("Created connector_x");
			connector_x.value()->enable_debug();
		}

		std::optional<std::shared_ptr<visual_scripting::Connector>> connector_y = connector_manager->create_connector(cos_attr_value, renderer_attr_y);
		if(!connector_y.has_value())
		{
			//spdlog::get(LOGGER_NAME)->error("Failed to create connector_y");
		}
		else
		{
			//spdlog::get(LOGGER_NAME)->info("Created connector_y");
			connector_y.value()->enable_debug();
		}

		// Make the window's context current.
		glfwMakeContextCurrent(window);

		// Create Magnum context in an isolated scope.
		Platform::GLContext ctx{};

		// Setup the colored triangle.
		using namespace Math::Literals;

		struct TriangleVertex {
			Vector2 position;
			Color3 color;
		};

		const TriangleVertex data[] {
			{{-0.5f, -0.5f}, 0xff0000_rgbf}, // Left vertex, red color
			{{ 0.5f, -0.5f}, 0x00ff00_rgbf}, // Right vertex, green color
			{{ 0.0f,  0.5f}, 0x0000ff_rgbf}  // Top vertex, blue color
		};

		GL::Buffer buffer;
		buffer.setData(data);

		GL::Mesh mesh;
		mesh.setPrimitive(GL::MeshPrimitive::Triangles)
			.setCount(3)
			.addVertexBuffer(
			buffer,
			0,
			Shaders::VertexColor2D::Position{},
			Shaders::VertexColor2D::Color3{}
		);

		// The shader.
		Shaders::VertexColor2D shader;

		// Register keyboard input handler.
		keyboard_input_manager->set_keyboard_callback(window);

		// Register mouse input handler.
		// This takes care of both mouse buttons and mouse movement.
		mouse_input_manager->set_mouse_callback(window);

		// Loop until the user closes the window.
		while(!glfwWindowShouldClose(window))
		{
			float x = std::get<DataType::FLOAT>(renderer_attr_x->value.Value());
			float y = 0.0f - std::get<DataType::FLOAT>(renderer_attr_x->value.Value());
			//spdlog::get(LOGGER_NAME)->info("TranslationXY({}, {})", x, y);

			Matrix3 transformation_matrix_x = Matrix3::translation(Vector2::xAxis(x));
			Matrix3 transformation_matrix_y = Matrix3::translation(Vector2::yAxis(y));

			shader.setTransformationProjectionMatrix(transformation_matrix_x * transformation_matrix_y);

			// Render here.
			GL::defaultFramebuffer.clear(GL::FramebufferClear::Color);
			mesh.draw(shader);

			// Swap front and back buffers.
			glfwSwapBuffers(window);

			std::this_thread::sleep_for(50ms);
		}

		spdlog::get(LOGGER_NAME)->info("Window closed!");
		glfwTerminate();
		std::exit(1);
	}

}
}
