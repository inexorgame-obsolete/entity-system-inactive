
#include <spdlog/spdlog.h>
// #include <fmt/format.h>
#include <entt/entt.hpp>


#include <Magnum/GL/Mesh.h>
#include <Magnum/Math/Color.h>
#include <Magnum/Shaders/VertexColor.h>
#include <Magnum/GL/Buffer.h>
#include <Magnum/GL/DefaultFramebuffer.h>
#include <Magnum/GL/Renderer.h>
#include <Magnum/Platform/GLContext.h>
#include <Magnum/Math/Matrix3.h>

#include <GLFW/glfw3.h>

#include <cstdint>

using fmt::format;
using namespace Magnum::Math::Literals;


/// Creates a new window with the given title, position and dimensions.
GLFWwindow *create_window(std::string title, int x, int y, int width, int height) {
    spdlog::info("Creating window: '{}' ({}, {}) ({}x{})", title, x, y, width, height);

    // lets be notified about error information.
    glfwSetErrorCallback([](int error_code, const char *description) {
        throw std::runtime_error(fmt::format("GLFW error {0}: {1}.", error_code, description));
    });

    // Create a windowed mode window and its OpenGL context.
    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
    GLFWwindow *glfw_window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

    if (!glfw_window) {
        throw std::runtime_error("window was not created correctly");
    }

    glfwSetWindowPos(glfw_window, x, y);

    glfwSetWindowCloseCallback(glfw_window, [](GLFWwindow *_glfw_window) {
        exit(EXIT_SUCCESS);
        glfwSetWindowShouldClose(_glfw_window, GLFW_TRUE);
    });

    glfwShowWindow(glfw_window);

    glfwMakeContextCurrent(glfw_window);
    // TODO: set x and y, as they might not be the same as we requested
    return glfw_window;
}


struct ColoredVertex {
    Magnum::Vector2 position;
    Magnum::Color3 color;
};

struct Triangle {
    std::shared_ptr<Magnum::GL::Buffer> buffer;
    std::shared_ptr<Magnum::GL::Mesh> mesh;
    std::shared_ptr<Magnum::Shaders::VertexColor2D> shader;

    Triangle()
    {
        const ColoredVertex data[]{
                {{-0.5f, -0.5f}, 0xff0000_rgbf}, // Left vertex, red color
                {{0.5f,  -0.5f}, 0x00ff00_rgbf}, // Right vertex, green color
                {{0.0f,  0.5f},  0x0000ff_rgbf}  // Top vertex, blue color
        };
        buffer = std::make_shared<Magnum::GL::Buffer>();
        buffer->setData(data);
        mesh = std::make_shared<Magnum::GL::Mesh>();
        mesh->setPrimitive(Magnum::GL::MeshPrimitive::Triangles)
                .setCount(3)
                .addVertexBuffer(*buffer, 0,
                                 Magnum::Shaders::VertexColor2D::Position{},
                                 Magnum::Shaders::VertexColor2D::Color3{}
                );
        spdlog::info("created mesh");

        // actually not "mesh", but more generic
        shader = std::make_shared<Magnum::Shaders::VertexColor2D>();
    }

    void render(float x, float y)
    {
        // update position
        Magnum::Matrix3 transformation_matrix_x = Magnum::Matrix3::translation(Magnum::Vector2::xAxis(x));
        Magnum::Matrix3 transformation_matrix_y = Magnum::Matrix3::translation(Magnum::Vector2::yAxis(y));
        shader->setTransformationProjectionMatrix(transformation_matrix_x * transformation_matrix_y);

        // render
        // if (x > 4)
        // Magnum::GL::defaultFramebuffer.clear(Magnum::GL::FramebufferClear::Color);
        // else
        mesh->draw(*shader);
    }
};

///// Different Components (formerly known as "attributes")

struct Position {
    float x;
    float y;
};

struct Velocity {
    float dx;
    float dy;
};

void render_entities(entt::registry<> &registry, Triangle &triangle) {

    Magnum::GL::defaultFramebuffer.clear(Magnum::GL::FramebufferClear::Color);
    auto const_view = std::as_const(registry).view<const Position, const Velocity>();

    const_view.each([&triangle](const auto, const Position &pos, const auto) {
        triangle.render(pos.x, pos.y);
    });
}

void update_positions(std::uint64_t dt, entt::registry<> &registry) {
    auto view = registry.view<Position, Velocity>();

    view.each([dt](auto, Position &pos, Velocity &vel) {
        // gets all the components of the view at once ...

        pos.x += vel.dx * dt;
        pos.y += vel.dy * dt;
    });
}

int main(int argc, char *argv[]) {
    entt::registry registry;

    // delta time. hardcoded, but exemplary for how to get timings right here.
    std::uint64_t dt = 1;

    {
        auto entity = registry.create();
        registry.assign<Position>(entity, 0.0f, 0.0f);
        registry.assign<Velocity>(entity, 0.005f, 0.005f);
    }

    // Start up window and opengl context
    if (!glfwInit())
    {
        spdlog::error("Failed to init GLFW");
        exit(EXIT_FAILURE);
    }
    GLFWwindow *glfw_window = create_window("Entity System ECS version", 0, 0, 300, 300);

    // Create Magnum context in an isolated scope.
    Magnum::Platform::GLContext ctx{};

    Triangle triangle;
    // Loop until the user closes the window.
    while(!glfwWindowShouldClose(glfw_window))
    {
        // Double buffering: one frontbuffer (shown to user), one backbuffer (rendered into).
        // swap them -> show next frame
        glfwSwapBuffers(glfw_window);

        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        update_positions(dt, registry);
        render_entities(registry, triangle);
    }
    return EXIT_SUCCESS;

}
