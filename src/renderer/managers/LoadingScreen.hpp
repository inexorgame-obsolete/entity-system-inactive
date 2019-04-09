#pragma once

#include "renderer/managers/WindowManager.hpp"
#include "logging/managers/LogManager.hpp"

#include <Magnum/GL/Mesh.h>
#include <Magnum/Math/Color.h>
#include <Magnum/Shaders/VertexColor.h>
#include <Magnum/GL/Buffer.h>
#include <Magnum/GL/DefaultFramebuffer.h>
#include <Magnum/GL/Renderer.h>
#include <Magnum/Platform/GLContext.h>
#include <Magnum/Math/Matrix3.h>

struct GLFWwindow;

namespace inexor {
namespace renderer {

	using WindowManagerPtr = std::shared_ptr<WindowManager>;
	using LogManagerPtr = std::shared_ptr<inexor::logging::LogManager>;
	using EntityInstancePtr = std::shared_ptr<EntityInstance>;

	struct QuadVertex {
		Magnum::Vector2 position;
		Magnum::Color3 color;
	};

	/// @class LoadingScreen
	/// @brief Shows a loading screen during startup.
	class LoadingScreen
	: public std::enable_shared_from_this<LoadingScreen>
	{
		public:

			/// @brief Constructor.
			/// @note The dependencies of this class will be injected automatically.
			/// @param window_manager The window manager.
			/// @param log_manager The log manager.
			LoadingScreen(
				WindowManagerPtr window_manager,
				LogManagerPtr log_manager
			);

			/// Destructor.
			~LoadingScreen();

			/// Initialize the loading screen.
			void init();

			/// Shut down the loading screen.
			void shutdown();

			/// The logger name of this service.
			static constexpr char LOGGER_NAME[] = "inexor.renderer.loading";

		private:

			/// Creates the inexor logo.
			void create_logo(EntityInstancePtr, GLFWwindow*);

			/// Renders the inexor logo.
			void render_logo(EntityInstancePtr, GLFWwindow*);

			/// The window manager
			WindowManagerPtr window_manager;

			/// The log manager.
			LogManagerPtr log_manager;

			/// The window entity instance.
			EntityInstancePtr window;

			std::shared_ptr<Magnum::GL::Buffer> buffer;
			std::shared_ptr<Magnum::GL::Mesh> mesh;
			std::shared_ptr<Magnum::Shaders::VertexColor2D> shader;

			bool initialized;

	};

}
}
