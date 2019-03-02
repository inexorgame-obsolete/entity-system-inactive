// Inexor entity system
// (c)2018-2019 Inexor

#include <boost/di.hpp>
#include "spdlog/spdlog.h"
#include "InexorApplication.hpp"

#include <Magnum/GL/DefaultFramebuffer.h>
#include <Magnum/GL/Renderer.h>
#include <Magnum/Math/Color.h>
#include <Magnum/GL/Mesh.h>
#include <Magnum/Platform/GlfwApplication.h>
#include <Magnum/Platform/GLContext.h>
#include <Magnum/Shaders/VertexColor.h>

using namespace Magnum;

namespace Magnum { namespace Examples {

    class TriangleExample: public Platform::Application {
    public:
        explicit TriangleExample(const Arguments& arguments);

    private:
        void drawEvent() override;

        GL::Mesh _mesh;
        Shaders::VertexColor2D _shader;
    };

    TriangleExample::TriangleExample(const Arguments& arguments):
            Platform::Application{arguments, Configuration{}.setTitle("Magnum Triangle Example")}
    {
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

        _mesh.setCount(3)
                .addVertexBuffer(std::move(buffer), 0,
                                 Shaders::VertexColor2D::Position{},
                                 Shaders::VertexColor2D::Color3{});

        // Entity system execution
        spdlog::info("Inexor (c) 2009-2019");
        auto injector = boost::di::make_injector();
        auto application = injector.create<inexor::InexorApplication>();
        application.init();
        //std::thread start_thread(&inexor::InexorApplication::start, &application);
        std::thread run_thread(&inexor::InexorApplication::run, &application);
        //start_thread.detach();
        run_thread.detach();
    }

    void TriangleExample::drawEvent() {
        GL::defaultFramebuffer.clear(GL::FramebufferClear::Color);

        _mesh.draw(_shader);

        swapBuffers();
    }

}}

/* main() function implementation */
MAGNUM_APPLICATION_MAIN(Magnum::Examples::TriangleExample)
