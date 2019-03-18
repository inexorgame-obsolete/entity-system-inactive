#pragma once

#include "renderer/managers/RendererManager.hpp"

namespace inexor {
namespace renderer {

    /// Module Renderer
	class RendererModule
	{
		using RendererManagerPtr = std::shared_ptr<RendererManager>;

		public:

			RendererModule(
				// The RendererManager is only an example right now
				RendererManagerPtr renderer_manager
				// WindowManager
				// UserInterfaceRenderer
				// WorldRenderer
				// WindowInputHandler
				// ...
			);

			~RendererModule();

			/// Initialization of the renderer module
			void init();

		private:

			/// The renderer manager
			RendererManagerPtr renderer_manager;

	};

}
}
