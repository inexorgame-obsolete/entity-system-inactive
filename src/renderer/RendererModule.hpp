#pragma once

#include "renderer/managers/WindowManager.hpp"
#include "renderer/managers/TriangleExample.hpp"

namespace inexor {
namespace renderer {

	/// @class RendererModule
	/// @brief This module is responsible for the management of the windows,
	/// the rendering of the world (octree) and the rendering of the user
	/// interface.
	class RendererModule
	{
		using WindowManagerPtr = std::shared_ptr<WindowManager>;
		using TriangleExamplePtr = std::shared_ptr<TriangleExample>;

		public:

			/// @brief Constructor.
			/// @note The dependencies of this class will be injected automatically.
			/// @note The TriangleExample is only an example right now.
			/// @param window_manager The window manager.
		/// @param triangle_example The triangle example.
			RendererModule(
				WindowManagerPtr window_manager,
				TriangleExamplePtr triangle_example
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

			/// Returns the window manager.
			WindowManagerPtr get_window_manager();

		private:

			/// The window manager.
			WindowManagerPtr window_manager;

			/// The triangle example.
			TriangleExamplePtr triangle_example;

	};

}
}
