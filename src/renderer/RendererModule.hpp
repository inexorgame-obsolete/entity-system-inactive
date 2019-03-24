#pragma once

#include "renderer/managers/RendererManager.hpp"

namespace inexor {
namespace renderer {

    /// @class RendererModule
    /// @brief Rendering module.
	class RendererModule
	{
		using RendererManagerPtr = std::shared_ptr<RendererManager>;

		public:

            /// @brief Constructor.
            /// @note The dependencies of this class will be injected automatically.
			/// @note The RendererManager is only an example right now.
            /// @param renderer_manager The renderer manager.
			RendererModule(
				RendererManagerPtr renderer_manager
				// WindowManager
				// UserInterfaceRenderer
				// WorldRenderer
				// WindowInputHandler
				// ...
			);

            /// Destructor.
			~RendererModule();

			/// Initialization of the renderer module.
			void init();

		private:

			/// The renderer manager.
			RendererManagerPtr renderer_manager;

	};

}
}
