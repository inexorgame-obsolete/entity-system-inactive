// Inexor entity system
// (C) 2018-2019 Inexor

#include "RendererManager.hpp"

using namespace Magnum;
using namespace Math::Literals;


namespace inexor {
namespace renderer {

	RendererManager::RendererManager(
		shared_ptr<inexor::renderer::RendererFactory> render_factory,
		shared_ptr<inexor::entity_system::type_system::SinFactory> sin_factory,
		std::shared_ptr<inexor::visual_scripting::ConnectorManager> connector_manager,
		shared_ptr<EntityInstanceManager> entity_instance_manager
	) {
		this->renderer_factory = render_factory;
		this->sin_factory = sin_factory;
		this->connector_manager = connector_manager;
		this->entity_instance_manager = entity_instance_manager;
	}

	RendererManager::~RendererManager()
	{
	}


	GLFWwindow *create_window()
	{
		/* Initialize the library */
		if(!glfwInit())
		{
			std::cout << "!glfwInit()" << std::endl;
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
			std::cout << "!window" << std::endl;
			std::exit(1);
		}
	}

	void RendererManager::init()
	{
		std::optional<std::shared_ptr<inexor::entity_system::EntityInstance>> o_renderer = renderer_factory->create_instance(0.5f, -0.5f);
		std::optional<std::shared_ptr<inexor::entity_system::EntityInstance>> o_sin_x = sin_factory->create_instance();
		std::optional<std::shared_ptr<inexor::entity_system::EntityInstance>> o_sin_y = sin_factory->create_instance();

		if (o_renderer.has_value() && o_sin_x.has_value() && o_sin_y.has_value())
		{
			renderer = o_renderer.value();
			sin_x = o_sin_x.value();
			sin_y = o_sin_y.value();
			std::optional<std::shared_ptr<inexor::entity_system::EntityAttributeInstance>> o_sin_x_attr_value = sin_x->get_attribute_instance("sin_value");
			std::optional<std::shared_ptr<inexor::entity_system::EntityAttributeInstance>> o_sin_y_attr_value = sin_y->get_attribute_instance("sin_value");
			std::optional<std::shared_ptr<inexor::entity_system::EntityAttributeInstance>> o_renderer_x_attr_value = renderer->get_attribute_instance("renderer_x");
			std::optional<std::shared_ptr<inexor::entity_system::EntityAttributeInstance>> o_renderer_y_attr_value = renderer->get_attribute_instance("renderer_y");
			if (o_sin_x_attr_value.has_value() && o_sin_y_attr_value.has_value() && o_renderer_x_attr_value.has_value() && o_renderer_y_attr_value.has_value())
			{
				sin_x_attr_value = o_sin_x_attr_value.value();
				sin_y_attr_value = o_sin_y_attr_value.value();
				renderer_x_attr_value = o_renderer_x_attr_value.value();
				renderer_y_attr_value = o_renderer_y_attr_value.value();
			}
		} else {
			std::cout << "Failed to create renderer instance!!!" << std::endl;
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
			std::cout << "Failed to create connector_x" << std::endl;
		} else {
			connector_x.value()->enable_debug();
		}

		std::optional<std::shared_ptr<inexor::visual_scripting::Connector>> connector_y = connector_manager->create_connector(sin_y_attr_value, renderer_y_attr_value);
		if (!connector_y.has_value())
		{
			std::cout << "Failed to create connector_y" << std::endl;
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
			std::cout << std::fixed << std::setprecision(3) << "(" << x << ", " << y << ")" << std::endl;

			Matrix3 transformation_matrix_x = Matrix3::translation(Vector2::xAxis(x));
			Matrix3 transformation_matrix_y = Matrix3::translation(Vector2::yAxis(y));

			shader.setTransformationProjectionMatrix(transformation_matrix_x * transformation_matrix_y);

			/* Render here */
			GL::defaultFramebuffer.clear(GL::FramebufferClear::Color);
			mesh.draw(shader);

			/* Swap front and back buffers */
			glfwSwapBuffers(window);

			/* Poll for and process events */
			glfwPollEvents();

			std::this_thread::sleep_for(50ms);
		}

		std::cout << "Window closed!" << std::endl;
		glfwTerminate();
		std::exit(1);
	}

};
};
