#pragma once

#include "renderer/managers/WindowManager.hpp"
#include "renderer/managers/MonitorManager.hpp"
#include "renderer/managers/FontManager.hpp"
#include "visual-scripting/managers/ConnectorManager.hpp"
#include "client/ClientLifecycle.hpp"
#include "input/managers/ClipboardManager.hpp"
#include "scripting/managers/ScriptExecutor.hpp"
#include "console/managers/ConsoleManager.hpp"
#include "logging/managers/LogManager.hpp"

#include <Magnum/GL/Mesh.h>
#include <Magnum/GL/Buffer.h>
#include <Magnum/GL/DefaultFramebuffer.h>
#include <Magnum/GL/Renderer.h>
#include <Magnum/Math/Color.h>
#include <Magnum/Math/Matrix3.h>
#include <Magnum/Platform/GLContext.h>
#include <Magnum/Shaders/Vector.h>
#include <Magnum/Shaders/Flat.h>
#include <Magnum/Timeline.h>

#include <boost/di.hpp>

struct GLFWwindow;

namespace inexor {
namespace renderer {

	using WindowManagerPtr = std::shared_ptr<WindowManager>;
	using MonitorManagerPtr = std::shared_ptr<MonitorManager>;
	using FontManagerPtr = std::shared_ptr<FontManager>;
	using KeyboardInputManagerPtr = std::shared_ptr<input::KeyboardInputManager>;
	using MouseInputManagerPtr = std::shared_ptr<input::MouseInputManager>;
	using ClipboardManagerPtr = std::shared_ptr<input::ClipboardManager>;
	using ConnectorManagerPtr = std::shared_ptr<visual_scripting::ConnectorManager>;
	using ClientLifecyclePtr = std::shared_ptr<client::ClientLifecycle>;
	using ScriptExecutorPtr = std::shared_ptr<scripting::ScriptExecutor>;
	using ConsoleManagerPtr = std::shared_ptr<console::ConsoleManager>;
	using LogManagerPtr = std::shared_ptr<logging::LogManager>;
	using EntityInstancePtr = std::shared_ptr<EntityInstance>;
	using ConsolePtr = std::shared_ptr<console::Console>;

	struct QuadVertex {
		Magnum::Vector2 position;
		Magnum::Vector2 texture_coordinated;
	};

	struct Movement {
		int mode = 0;
		bool forward = false;
		bool backward = false;
		bool left = false;
		bool right = false;
	};

	/// @class LoadingScreen
	/// @brief Shows a loading screen during startup.
	class LoadingScreen
		: public input::WindowKeyReleasedListener,
		  public input::WindowKeyPressedOrRepeatedListener,
		  public input::WindowCharInputListener,
		  public input::WindowMouseButtonChangedListener,
		  public input::WindowMouseScrolledListener,
		  public input::WindowPathDroppedListener,
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
				FontManagerPtr font_manager,
				KeyboardInputManagerPtr keyboard_input_manager,
				MouseInputManagerPtr mouse_input_manager,
				ClipboardManagerPtr clipboard_manager,
				ConnectorManagerPtr connector_manager,
				ClientLifecyclePtr client_lifecycle,
				ScriptExecutorPtr script_executor,
				ConsoleManagerPtr console_manager,
				LogManagerPtr log_manager
			);

			// This is neccessary for constructor length greater than 10
			using boost_di_inject__ = boost::di::inject<
				WindowManagerPtr,
				MonitorManagerPtr,
				FontManagerPtr,
				KeyboardInputManagerPtr,
				MouseInputManagerPtr,
				ClipboardManagerPtr,
				ConnectorManagerPtr,
				ClientLifecyclePtr,
				ScriptExecutorPtr,
				ConsoleManagerPtr,
				LogManagerPtr
			>;

			/// Destructor.
			~LoadingScreen();

			/// Initialize the loading screen.
			void init();

			/// Shut down the loading screen.
			void shutdown();

			/// Window char input
			void on_window_char_input(EntityInstancePtr window, std::string character, unsigned int codepoint);

			/// Window key released
			void on_window_key_released(EntityInstancePtr window, int key, int scancode, int mods);

			/// Window key pressed or repeated
			void on_window_key_pressed_or_repeated(EntityInstancePtr window, int key, int scancode, int mods);

			/// Window mouse button changed
			void on_window_mouse_button_changed(EntityInstancePtr window, int button, int action, int mods);

			/// Window mouse scrolled
			void on_window_mouse_scrolled(EntityInstancePtr window, double xpos, double ypos);

			/// Paths dropped
			void on_window_path_dropped(EntityInstancePtr window, std::vector<std::string> paths);

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

			/// Renders the Inexor logo.
			void render_inexor_logo(Magnum::Timeline timeline);

			/// Updates the Inexor title.
			void render_inexor_title(Magnum::Timeline timeline);

			/// Renders the action.
			void render_action(Magnum::Timeline timeline);

			/// Renders the command line of the console.
			void render_console_command_line(Magnum::Timeline timeline);

			/// Renders the fps counter.
			void render_fps_counter(Magnum::Timeline timeline);

			/// Moves whatever should be moved.
			void move(EntityInstancePtr window);

			/// Executes the command
			void execute_command(EntityInstancePtr window);

			/// The window manager
			WindowManagerPtr window_manager;

			/// The monitor manager
			MonitorManagerPtr monitor_manager;

			/// The font manager
			FontManagerPtr font_manager;

			/// The keyboard input manager
			KeyboardInputManagerPtr keyboard_input_manager;

			/// The mouse input manager
			MouseInputManagerPtr mouse_input_manager;

			/// The clipboard manager.
			ClipboardManagerPtr clipboard_manager;

			/// The connector manager
			ConnectorManagerPtr connector_manager;

			/// The client lifecycle.
			ClientLifecyclePtr client_lifecycle;

			/// The script executor.
			ScriptExecutorPtr script_executor;

			/// The console manager.
			ConsoleManagerPtr console_manager;

			/// The log manager.
			LogManagerPtr log_manager;

			/// The window entity instance.
			EntityInstancePtr window;

			/// The console.
			ConsolePtr console;

			/// The buffer for the logo.
			std::shared_ptr<Magnum::GL::Buffer> buffer;

			/// The mesh for the logo.
			std::shared_ptr<Magnum::GL::Mesh> mesh;

			/// The shader for the logo.
			std::shared_ptr<Magnum::Shaders::Flat2D> shader;

			std::shared_ptr<Magnum::GL::Texture2D> texture;

			/// If true, the render thread shows the frames per second.
			bool show_fps;

			/// If true, the render thread creates a screenshot.
			bool create_screenshot;

			float mesh_size_x;
			float mesh_size_y;

			float mesh_factor;

			FontPtr title_font;

			FontPtr action_font;

			FontPtr command_font;

			FontPtr fps_font;

			std::string action;

//			std::string command_buffer;

			Movement movement;

			/// The name of the title font.
			static constexpr char TITLE_FONT[] = "cabin_sketch_regular.ttf";

			/// The name of the command font.
			static constexpr char COMMAND_FONT[] = "cabin_regular.ttf";

			/// The name of the action font.
			static constexpr char ACTION_FONT[] = "cabin_italic.ttf";

			/// The name of the fps counter font.
			static constexpr char FPS_FONT[] = "cabin_regular.ttf";

	};

}
}
