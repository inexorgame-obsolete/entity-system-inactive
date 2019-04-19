#pragma once

#include "WorldRenderer.hpp"
#include "UserInterfaceRenderer.hpp"
#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "visual-scripting/managers/ConnectorManager.hpp"
#include "visual-scripting/model/Connector.hpp"
#include "renderer/factories/WindowFactory.hpp"
#include "input/managers/KeyboardInputManager.hpp"
#include "input/managers/MouseInputManager.hpp"
#include "logging/managers/LogManager.hpp"

#include <Magnum/Timeline.h>

#include <list>
#include <functional>

struct GLFWwindow;
struct GLFWmonitor;

namespace inexor {
namespace renderer {

	using WindowFactoryPtr = std::shared_ptr<WindowFactory>;
	using KeyboardInputManagerPtr = std::shared_ptr<input::KeyboardInputManager>;
	using MouseInputManagerPtr = std::shared_ptr<input::MouseInputManager>;
	using EntityInstanceManagerPtr = std::shared_ptr<entity_system::EntityInstanceManager>;
	using ConnectorManagerPtr = std::shared_ptr<visual_scripting::ConnectorManager>;
	using WorldRendererPtr = std::shared_ptr<WorldRenderer>;
	using UserInterfaceRendererPtr = std::shared_ptr<UserInterfaceRenderer>;
	using LogManagerPtr = std::shared_ptr<logging::LogManager>;

	using EntityInstancePtr = std::shared_ptr<EntityInstance>;
	using EntityAttributeInstancePtr = std::shared_ptr<entity_system::EntityAttributeInstance>;

	/// @class ManagedWindow
	/// @brief Represents a window, which is managed by the WindowManager.
	struct ManagedWindow
	{
		/// Creates a new ManagedWindow.
		ManagedWindow(
			int id,
			std::string title,
			EntityInstancePtr window,
			GLFWwindow* glfw_window,
			std::optional<std::function<void(EntityInstancePtr, GLFWwindow*)>> init_function,
			std::optional<std::function<void(EntityInstancePtr, GLFWwindow*)>> shutdown_function
		) : id(id),
			title(title),
			window(window),
			glfw_window(glfw_window),
			init_function(init_function),
			shutdown_function(shutdown_function),
			thread_running(false) {};

		/// The id of the window.
		int id;

		/// The initial title of the window.
		std::string title;

		/// The entity instance.
		EntityInstancePtr window;

		/// The GLFW window handle.
		GLFWwindow* glfw_window;

		/// The thread controls the window.
		std::thread thread;

		/// If true, the window thread is running
		bool thread_running;

		/// A signal that the position of the window has been changed.
		SignalT<std::pair<int, int>> signal_position_changed;

		/// A signal that the size of the window has been changed.
		SignalT<std::pair<int, int>> signal_size_changed;

		// TODO: list of observers for shutting down the observers during destroy

		/// A list of functions to call during initialization of the window thread. The order of these functions is important.
		std::optional<std::function<void(EntityInstancePtr, GLFWwindow*)>> init_function;

		/// A list of functions to call during rendering. The order of these functions is important.
		std::list<std::function<void(EntityInstancePtr, GLFWwindow*, Magnum::Timeline)>> render_functions;

		/// A list of functions to call during shut down of the window thread. The order of these functions is important.
		std::optional<std::function<void(EntityInstancePtr, GLFWwindow*)>> shutdown_function;

	};

	struct WindowOwner {
		WindowOwner(GLFWmonitor* monitor, int x, int y, int width, int height)
			: monitor(monitor), x(x), y(y), width(width), height(height) {};
		GLFWmonitor* monitor;
		int x;
		int y;
		int width;
		int height;
	};

	struct Dimensions {
		Dimensions()
			: x(0), y(0), width(0), height(0) {};
		Dimensions(int x, int y, int width, int height)
			: x(x), y(y), width(width), height(height) {};
		int x;
		int y;
		int width;
		int height;
	};

	/// @class WindowManager
	/// @brief The WindowManager manages the windows of the application.
	class WindowManager
	: public std::enable_shared_from_this<WindowManager>
	{
		public:

			/// @brief Constructor.
			/// @note The dependencies of this class will be injected automatically.
			/// @param window_factory Factory for creating instances of type 'WINDOW'.
			/// @param keyboard_input_manager The keyboard input manager.
			/// @param mouse_input_manager The mouse input manager.
			/// @param entity_instance_manager The entity instance manager.
			/// @param connector_manager The connector manager.
			/// @param world_renderer Service, which renders the world on a window.
			/// @param user_interface_renderer Service, which renders the user interface on a window.
			/// @param log_manager The log manager.
			WindowManager(
				WindowFactoryPtr window_factory,
				KeyboardInputManagerPtr keyboard_input_manager,
				MouseInputManagerPtr mouse_input_manager,
				EntityInstanceManagerPtr entity_instance_manager,
				ConnectorManagerPtr connector_manager,
				WorldRendererPtr world_renderer,
				UserInterfaceRendererPtr user_interface_renderer,
				LogManagerPtr log_manager
			);

			/// Destructor.
			~WindowManager();

			/// Initialize the window manager.
			void init();

			/// Shut down the window manager.
			void shutdown();

			/// @brief Creates a new window with the given title, position and dimensions.
			/// @param window The GLFWwindow instance.
			EntityInstancePtr create_window(std::string title, int x, int y, int width, int height);

			/// @brief Creates a new window with the given title, position and dimensions.
			/// @param window The GLFWwindow instance.
			EntityInstancePtr create_window(std::string title, int x, int y, int width, int height, float opacity, bool visible, bool fullscreen, bool iconified, bool maximized, bool focused, bool vsync, float fps);

			/// @brief Creates a new window with the given title, position and dimensions.
			/// @param window The GLFWwindow instance.
			EntityInstancePtr create_window(
				std::string title,
				int x,
				int y,
				int width,
				int height,
				float opacity,
				bool visible,
				bool fullscreen,
				bool iconified,
				bool maximized,
				bool focused,
				bool vsync,
				float fps,
				std::optional<std::function<void(EntityInstancePtr, GLFWwindow*)>> init_function,
				std::optional<std::function<void(EntityInstancePtr, GLFWwindow*)>> shutdown_function
			);

			/// @brief Destroys the given window.
			/// @param window The entity instance of type WINDOW.
			void destroy_window(EntityInstancePtr window);

			/// @brief Destroys the given window.
			/// @param window The entity instance of type WINDOW.
			void close_window(EntityInstancePtr window);

			/// @brief Sets the title of the given window.
			/// @param window The entity instance of type WINDOW.
			/// @param title The new title of the window.
			void set_window_title(EntityInstancePtr window, std::string title);

			/// @brief Sets the position of the given window.
			/// @param window The entity instance of type WINDOW.
			/// @param x The new x position of the window.
			/// @param y The new y position of the window.
			void set_window_position(EntityInstancePtr window, int x, int y);

			/// @brief Sets the size of the given window.
			/// @param window The entity instance of type WINDOW.
			/// @param width The new width of the window.
			/// @param height The new height of the window.
			void set_window_size(EntityInstancePtr window, int width, int height);

			/// @brief Sets the position of the given window.
			/// @param window The entity instance of type WINDOW.
			void center_window(EntityInstancePtr window);

			// TODO: document
			void make_current(EntityInstancePtr window);

			/// @brief Registers a function to be called at every frame.
			/// @param window The entity instance of type WINDOW.
			/// @param render_function The render function to register.
			void register_render_function(EntityInstancePtr window, std::function<void(EntityInstancePtr, GLFWwindow*, Magnum::Timeline)> render_function);

			/// @brief Returns the number of windows.
			int get_window_count();

			/// @brief Returns the window handle for the entity instance.
			/// @param window The entity instance of type 'WINDOW'.
			GLFWwindow* get_window_handle(EntityInstancePtr window);

			/// The logger name of this service.
			static constexpr char LOGGER_NAME[] = "inexor.renderer.window";

		private:

			// State management


			/// @brief Starts the window thread.
			/// @param window The entity instance of type WINDOW.
			void start_window_thread(EntityInstancePtr window);

			/// @brief Stops the window thread.
			/// @param window The entity instance of type 'WINDOW'.
			void stop_window_thread(EntityInstancePtr window);

			/// @brief Returns true, if the given entity instance of type WINDOW is managed.
			/// @param window The entity instance of type 'WINDOW'.
			bool is_window_managed(EntityInstancePtr window);

			/// @brief Returns true, if the given entity instance of type WINDOW is available.
			/// @param window The entity instance of type 'WINDOW'.
			bool is_window_available(EntityInstancePtr window);

			/// @brief Returns true, if the thread is managed for the given entity instance of type 'WINDOW'.
			/// @param window The entity instance of type 'WINDOW'.
			bool is_thread_managed(EntityInstancePtr window);

			/// @brief Returns true, if the thread is running for the given entity instance of type 'WINDOW'.
			/// @param window The entity instance of type 'WINDOW'.
			bool is_thread_running(EntityInstancePtr window);


			// Internal window API


			/// @brief Sets the position of the given window.
			/// @param glfw_window The glfw window.
			/// @param x The new x position of the window.
			/// @param y The new y position of the window.
			void set_window_position(GLFWwindow* glfw_window, int x, int y);

			/// @brief Sets the size of the given window.
			/// @param glfw_window The glfw window.
			/// @param width The new width of the window.
			/// @param height The new height of the window.
			void set_window_size(GLFWwindow* glfw_window, int width, int height);

			// TODO: document
			std::optional<WindowOwner> get_window_owner(Dimensions window);


			// Window initialization


			/// @brief Initializes the callbacks on window state changes.
			/// @param glfw_window The window handle.
			void initialize_window_callbacks(GLFWwindow* glfw_window);

			/// @brief Removes the callbacks on window state changes.
			/// @param glfw_window The window handle.
			void destroy_window_callbacks(GLFWwindow* glfw_window);

			/// @brief Initializes observers on the attributes of the entity instance of type WINDOW.
			/// @param window The entity instance of type 'WINDOW'.
			void initialize_window_observers(EntityInstancePtr window, GLFWwindow* glfw_window);


			// Event handling


			/// This callback is called if a window has been closed.
			/// @param glfw_window The window handle.
			void window_closed(GLFWwindow* glfw_window);

			/// This callback is called if a window has been focused / has lost the focus.
			/// @param glfw_window The window handle.
			void window_focused(GLFWwindow* glfw_window, bool has_focus);

			/// This callback is called if a window has been iconified / restored.
			/// @param glfw_window The window handle.
			void window_iconified(GLFWwindow* glfw_window, bool is_iconified);

			/// This callback is called if a window has been maximized / restored.
			/// @param glfw_window The window handle.
			void window_maximized(GLFWwindow* glfw_window, bool is_maximized);

			/// This callback is called if the position of a window has been changed.
			/// @param glfw_window The window handle.
			void window_position_changed(GLFWwindow* glfw_window, int x, int y);

			/// This callback is called if the size of a window has been changed.
			/// @param glfw_window The window handle.
			void window_size_changed(GLFWwindow* glfw_window, int width, int height);

			/// This callback is called if the state of a key has been changed.
			/// @param glfw_window The window handle.
			void window_key_changed(GLFWwindow* glfw_window, int key, int scancode, int action, int mods);

			/// This callback is called if the mouse position of a window has been changed.
			/// @param glfw_window The window handle.
			void window_mouse_position_changed(GLFWwindow* glfw_window, double xpos, double ypos);

			/// This callback is called if the state of a mouse button has been changed.
			/// @param glfw_window The window handle.
			void window_mouse_button_changed(GLFWwindow* glfw_window, int button, int action, int mods);

			/// This callback is called if the state of a mouse scroll wheel has been changed.
			/// @param glfw_window The window handle.
			void window_mouse_scroll_changed(GLFWwindow* glfw_window, double xoffset, double yoffset);


			// Services


			/// The factory for creating entities of type WINDOW.
			WindowFactoryPtr window_factory;

			/// The keyboard input manager.
			KeyboardInputManagerPtr keyboard_input_manager;

			/// The mouse input manager.
			MouseInputManagerPtr mouse_input_manager;

			/// The entity instance manager.
			EntityInstanceManagerPtr entity_instance_manager;

			/// The connector manager.
			ConnectorManagerPtr connector_manager;

			/// The world renderer.
			WorldRendererPtr world_renderer;

			/// The user interface renderer.
			UserInterfaceRendererPtr user_interface_renderer;

			/// The log manager.
			LogManagerPtr log_manager;


			// Managed windows and states


			/// The mapping between the entity instance and the pointer to the
			/// corresponding ManagedWindow.
			/// @see ManagedWindow
			std::unordered_map<EntityInstancePtr, std::shared_ptr<ManagedWindow>> windows;

			/// The mapping between the pointer to the window and the
			/// corresponding entity instance.
			std::unordered_map<GLFWwindow*, EntityInstancePtr> window_entities;

			/// The number of windows managed by the WindowManager.
			int window_count;

			/// The current window id.
			int current_window_id;

	};

}
}
