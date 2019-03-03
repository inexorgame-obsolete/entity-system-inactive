// Inexor entity system
// (C) 2018-2019 Inexor

#include "RendererManager.hpp"

using namespace Magnum;
using namespace Math::Literals;


namespace inexor {
    namespace renderer {
        RendererManager::RendererManager(
                shared_ptr<inexor::renderer::RendererFactory> render_factory,
                 shared_ptr<EntityInstanceManager> entity_instance_manager
         )
         {
            this->renderer_factory = render_factory;
            this->entity_instance_manager = entity_instance_manager;
         }

         RendererManager::~RendererManager()
         {

         }

         void RendererManager::init()
         {
        	 float x = 0;
        	 float y = 0;
        	 renderer_factory->create_instance(x, y);

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

			 /* Make the window's context current */
			 glfwMakeContextCurrent(window);

			 {
				 /* Create Magnum context in an isolated scope */
				 // argc, argv
				 Platform::GLContext ctx{};

				 /* Setup the colored triangle */
				 using namespace Math::Literals;

				 struct TriangleVertex {
					 Vector2 position;
					 Color3 color;
				 };
				 const TriangleVertex data[]{
					 {{-0.5f, -0.5f}, 0xff0000_rgbf},    /* Left vertex, red color */
					 {{ 0.5f, -0.5f}, 0x00ff00_rgbf},    /* Right vertex, green color */
					 {{ 0.0f,  0.5f}, 0x0000ff_rgbf}     /* Top vertex, blue color */
				 };

				 GL::Buffer buffer;
				 buffer.setData(data);

				 GL::Mesh mesh;
				 mesh.setPrimitive(GL::MeshPrimitive::Triangles)
					 .setCount(3)
					 .addVertexBuffer(buffer, 0,
						 Shaders::VertexColor2D::Position{},
						 Shaders::VertexColor2D::Color3{});

				 Shaders::VertexColor2D shader;

				 /* Loop until the user closes the window */
				 while(!glfwWindowShouldClose(window)) {

					 /* Render here */
					 GL::defaultFramebuffer.clear(GL::FramebufferClear::Color);
					 mesh.draw(shader);

					 /* Swap front and back buffers */
					 glfwSwapBuffers(window);

					 /* Poll for and process events */
					 glfwPollEvents();
				 }
			 }

         }

    };
};
