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
		SinFactoryPtr sin_factory,
		CosFactoryPtr cos_factory,
		RendererFactoryPtr render_factory,
		LogManagerPtr log_manager
	) {
		this->entity_instance_manager = entity_instance_manager;
		this->connector_manager = connector_manager;
		this->sin_factory = sin_factory;
		this->cos_factory = cos_factory;
		this->renderer_factory = render_factory;
		this->log_manager = log_manager;
	}

	RendererManager::~RendererManager()
	{
	}

	GLFWwindow *create_window()
	{
		/* Initialize the library */
		if(!glfwInit())
		{
			spdlog::get(RendererManager::LOGGER_NAME)->error("Failed to initialize glfw!");
			std::exit(1);
		}

		/* Create a windowed mode window and its OpenGL context */
		GLFWwindow* const window = glfwCreateWindow(
			800,
			600,
			"Inexor Renderer 1",
			nullptr,
			nullptr
		);
		if(!window) {
			glfwTerminate();
			spdlog::get(RendererManager::LOGGER_NAME)->error("Failed to create window!");
			std::exit(1);
		}
		return window;
	}

	void RendererManager::init()
	{
		log_manager->register_logger(LOGGER_NAME);

		EntityInstancePtrOpt o_renderer = renderer_factory->create_instance(0.5f, -0.5f);
		EntityInstancePtrOpt o_sin_x = sin_factory->create_instance();
		EntityInstancePtrOpt o_cos_y = cos_factory->create_instance();

		if (o_renderer.has_value() && o_sin_x.has_value() && o_cos_y.has_value())
		{
			renderer = o_renderer.value();
			sin_x = o_sin_x.value();
			cos_y = o_cos_y.value();
			EntityAttributeInstanceOpt o_sin_x_attr_value = sin_x->get_attribute_instance(inexor::entity_system::type_system::SinEntityTypeProvider::SIN_VALUE);
			EntityAttributeInstanceOpt o_cos_y_attr_value = cos_y->get_attribute_instance(inexor::entity_system::type_system::CosEntityTypeProvider::COS_VALUE);
			EntityAttributeInstanceOpt o_renderer_x_attr_value = renderer->get_attribute_instance(RendererEntityTypeProvider::RENDERER_X);
			EntityAttributeInstanceOpt o_renderer_y_attr_value = renderer->get_attribute_instance(RendererEntityTypeProvider::RENDERER_Y);
			if (o_sin_x_attr_value.has_value() && o_cos_y_attr_value.has_value() && o_renderer_x_attr_value.has_value() && o_renderer_y_attr_value.has_value())
			{
				sin_x_attr_value = o_sin_x_attr_value.value();
				cos_y_attr_value = o_cos_y_attr_value.value();
				renderer_x_attr_value = o_renderer_x_attr_value.value();
				renderer_y_attr_value = o_renderer_y_attr_value.value();
			} else {

			}
		} else {
			spdlog::get(LOGGER_NAME)->error("Failed to create renderer instance");
		}

		GLFWwindow *window = create_window();
		std::thread start_thread(&inexor::renderer::RendererManager::start_window_thread, this, window);
		start_thread.detach();
	}

	void RendererManager::start_window_thread(GLFWwindow *window)
	{
		std::optional<std::shared_ptr<inexor::visual_scripting::Connector>> connector_x = connector_manager->create_connector(sin_x_attr_value, renderer_x_attr_value);
		if (!connector_x.has_value())
		{
			spdlog::get(LOGGER_NAME)->error("Failed to create connector_x");
		} else {
			connector_x.value()->enable_debug();
		}

		std::optional<std::shared_ptr<inexor::visual_scripting::Connector>> connector_y = connector_manager->create_connector(cos_y_attr_value, renderer_y_attr_value);
		if (!connector_y.has_value())
		{
			spdlog::get(LOGGER_NAME)->error("Failed to create connector_y");
		} else {
			connector_y.value()->enable_debug();
		}

		/* Make the window's context current */
		glfwMakeContextCurrent(window);

		/* Create Magnum context in an isolated scope */
		// argc, argv
		Platform::GLContext ctx{};

		/* Setup the colored triangle */
		using namespace Math::Literals;

		struct TriangleVertex {
			Vector2 position;
			Color3 color;
		};

		const TriangleVertex data[] {
			{{-0.5f, -0.5f}, 0xff0000_rgbf},    /* Left vertex, red color */
			{{ 0.5f, -0.5f}, 0x00ff00_rgbf},    /* Right vertex, green color */
			{{ 0.0f,  0.5f}, 0x0000ff_rgbf}     /* Top vertex, blue color */
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

		/// The shader
		Shaders::VertexColor2D shader;

		/* Loop until the user closes the window */
		while(!glfwWindowShouldClose(window))
		{
			float x = std::get<DataType::FLOAT>(renderer_x_attr_value->value.Value());
			float y = 0.0f - std::get<DataType::FLOAT>(renderer_y_attr_value->value.Value());
			spdlog::get(LOGGER_NAME)->info("TranslationXY({}, {})", x, y);

			Matrix3 transformation_matrix_x = Matrix3::translation(Vector2::xAxis(x));
			Matrix3 transformation_matrix_y = Matrix3::translation(Vector2::yAxis(y));

			shader.setTransformationProjectionMatrix(transformation_matrix_x * transformation_matrix_y);

			/* Render here */
			GL::defaultFramebuffer.clear(GL::FramebufferClear::Color);
			mesh.draw(shader);

			/* Swap front and back buffers */
			glfwSwapBuffers(window);

			std::this_thread::sleep_for(50ms);
		}

		spdlog::get(LOGGER_NAME)->info("Window closed!");
		glfwTerminate();
		std::exit(1);
	}

}
}
