#pragma once

#include "renderer/managers/FontManager.hpp"
#include "renderer/managers/LoadingScreen.hpp"
#include "renderer/managers/TriangleExample.hpp"

namespace inexor::renderer {

/// @class RendererModule
/// @brief This module is responsible for the management of the windows,
/// the rendering of the world (octree) and the rendering of the user
/// interface.
class RendererModule
{
    using FontManagerPtr = std::shared_ptr<FontManager>;
    using LoadingScreenPtr = std::shared_ptr<LoadingScreen>;
    using TriangleExamplePtr = std::shared_ptr<TriangleExample>;

    public:
    /// @brief Constructor.
    /// @note The TriangleExample is only an example right now.
    /// @param font_manager The font manager.
    /// @param loading_screen The loading screen.
    /// @param triangle_example The triangle example.
    RendererModule(FontManagerPtr font_manager, LoadingScreenPtr loading_screen, TriangleExamplePtr triangle_example
                   // UserInterfaceRenderer
                   // WorldRenderer
                   // ...
    );

    /// Destructor.
    ~RendererModule();

    /// Initialization of the renderer module.
    void init();

    /// Shutdown of the renderer module.
    void shutdown();

    /// Updates the frame in main thread.
    void update();

    private:
    /// The font manager.
    FontManagerPtr font_manager;

    /// The loading screen.
    LoadingScreenPtr loading_screen;

    /// The triangle example.
    TriangleExamplePtr triangle_example;
};

} // namespace inexor::renderer
