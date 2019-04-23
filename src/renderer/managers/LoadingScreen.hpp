#pragma once

#include "renderer/managers/WindowManager.hpp"
#include "renderer/managers/MonitorManager.hpp"
#include "visual-scripting/managers/ConnectorManager.hpp"
#include "client/ClientLifecycle.hpp"
#include "logging/managers/LogManager.hpp"

#include <Magnum/GL/Mesh.h>
#include <Magnum/Math/Color.h>
#include <Magnum/Shaders/VertexColor.h>
#include <Magnum/GL/Buffer.h>
#include <Magnum/GL/DefaultFramebuffer.h>
#include <Magnum/GL/Renderer.h>
#include <Magnum/Platform/GLContext.h>
#include <Magnum/Math/Matrix3.h>
#include <Magnum/Timeline.h>

struct GLFWwindow;

namespace inexor {
namespace renderer {

	using WindowManagerPtr = std::shared_ptr<WindowManager>;
	using MonitorManagerPtr = std::shared_ptr<MonitorManager>;
	using KeyboardInputManagerPtr = std::shared_ptr<input::KeyboardInputManager>;
	using MouseInputManagerPtr = std::shared_ptr<input::MouseInputManager>;
	using ConnectorManagerPtr = std::shared_ptr<visual_scripting::ConnectorManager>;
	using ClientLifecyclePtr = std::shared_ptr<client::ClientLifecycle>;
	using LogManagerPtr = std::shared_ptr<logging::LogManager>;
	using EntityInstancePtr = std::shared_ptr<EntityInstance>;

	struct QuadVertex {
		Magnum::Vector2 position;
		Magnum::Color3 color;
	};

	/// @class LoadingScreen
	/// @brief Shows a loading screen during startup.
	class LoadingScreen
		: public input::WindowKeyReleasedListener,
		  public input::WindowKeyPressedOrRepeatedListener,
		  public input::WindowMouseButtonChangedListener,
		  public input::WindowMouseScrolledListener,
		  public std::enable_shared_from_this<LoadingScreen>
	{
		public:

			/// @brief Constructor.
			/// @note The dependencies of this class will be injected automatically.
			/// @param window_manager The window manager.
			/// @param monitor_manager The monitor manager.
			/// @param log_manager The log manager.
			LoadingScreen(
				WindowManagerPtr window_manager,
				MonitorManagerPtr monitor_manager,
				KeyboardInputManagerPtr keyboard_input_manager,
				MouseInputManagerPtr mouse_input_manager,
				ConnectorManagerPtr connector_manager,
				ClientLifecyclePtr client_lifecycle,
				LogManagerPtr log_manager
			);

			/// Destructor.
			~LoadingScreen();

			/// Initialize the loading screen.
			void init();

			/// Shut down the loading screen.
			void shutdown();

			/// Window key released
			void on_window_key_released(EntityInstancePtr window, int key, int scancode, int mods);

			/// Window key pressed or repeated
			void on_window_key_pressed_or_repeated(EntityInstancePtr window, int key, int scancode, int mods);

			/// Window mouse button changed
			void on_window_mouse_button_changed(EntityInstancePtr window, int button, int action, int mods);

			/// Window mouse scrolled
			void on_window_mouse_scrolled(EntityInstancePtr window, double xpos, double ypos);

			/// The logger name of this service.
			static constexpr char LOGGER_NAME[] = "inexor.renderer.loading";

		private:

			/// Initializes the loading screen.
			void init_loading_screen(EntityInstancePtr window, GLFWwindow* glfw_window);

			/// Renders the loading screen.
			void render_loading_screen(EntityInstancePtr window, GLFWwindow* glfw_window, Magnum::Timeline timeline);

			/// Initializes the loading screen.
			void shutdown_loading_screen(EntityInstancePtr window, GLFWwindow* glfw_window);

			/// Makes a screenshot.
			void screenshot();

			/// Updates the mesh.
			void update_mesh(Magnum::Timeline timeline);

			/// The window manager
			WindowManagerPtr window_manager;

			/// The monitor manager
			MonitorManagerPtr monitor_manager;

			/// The keyboard input manager
			KeyboardInputManagerPtr keyboard_input_manager;

			/// The mouse input manager
			MouseInputManagerPtr mouse_input_manager;

			/// The connector manager
			ConnectorManagerPtr connector_manager;

			/// The client lifecycle.
			ClientLifecyclePtr client_lifecycle;

			/// The log manager.
			LogManagerPtr log_manager;

			/// The window entity instance.
			EntityInstancePtr window;

			std::shared_ptr<Magnum::GL::Buffer> buffer;
			std::shared_ptr<Magnum::GL::Mesh> mesh;
			std::shared_ptr<Magnum::Shaders::VertexColor2D> shader;

			/// If true, the render thread shows the frames per second.
			bool show_fps;

			/// If true, the render thread creates a screenshot.
			bool create_screenshot;

			float mesh_size_x;
			float mesh_size_y;

			float mesh_factor;

	};

}
}
