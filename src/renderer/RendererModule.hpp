#pragma once

#include "renderer/managers/MonitorManager.hpp"
#include "renderer/managers/WindowManager.hpp"
#include "renderer/managers/FontManager.hpp"
#include "renderer/managers/LoadingScreen.hpp"
#ifdef INEXOR_WITH_INTEGRATION_TESTS
#include "renderer/managers/TriangleExample.hpp"
#endif

namespace inexor {
namespace renderer {

	/// @class RendererModule
	/// @brief This module is responsible for the management of the windows,
	/// the rendering of the world (octree) and the rendering of the user
	/// interface.
	class RendererModule
	{
		using MonitorManagerPtr = std::shared_ptr<MonitorManager>;
		using WindowManagerPtr = std::shared_ptr<WindowManager>;
		using FontManagerPtr = std::shared_ptr<FontManager>;
		using LoadingScreenPtr = std::shared_ptr<LoadingScreen>;
#ifdef INEXOR_WITH_INTEGRATION_TESTS
		using TriangleExamplePtr = std::shared_ptr<TriangleExample>;
#endif

		public:

			/// @brief Constructor.
			/// @note The dependencies of this class will be injected automatically.
			/// @note The TriangleExample is only an example right now.
			/// @param monitor_manager The monitor manager.
			/// @param window_manager The window manager.
			/// @param loading_screen The loading screen.
			/// @param triangle_example The triangle example.
			RendererModule(
				MonitorManagerPtr monitor_manager,
				WindowManagerPtr window_manager,
				FontManagerPtr font_manager,
				LoadingScreenPtr loading_screen
#ifdef INEXOR_WITH_INTEGRATION_TESTS
				, TriangleExamplePtr triangle_example
#endif
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

			/// The monitor manager.
			MonitorManagerPtr monitor_manager;

			/// The window manager.
			WindowManagerPtr window_manager;

			/// The font manager.
			FontManagerPtr font_manager;

			/// The loading screen.
			LoadingScreenPtr loading_screen;

			/// The triangle example.
#ifdef INEXOR_WITH_INTEGRATION_TESTS
			TriangleExamplePtr triangle_example;
#endif

	};

}
}
