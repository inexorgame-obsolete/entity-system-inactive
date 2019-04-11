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

#include <list>
#include <functional>

struct GLFWwindow;

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

	/// @class WindowManager
	/// @brief The WindowManager manages the windows of the application.
	class WindowManager
	: public std::enable_shared_from_this<WindowManager>
	{
		public:

			/// @brief Constructor.
			/// @note The dependencies of this class will be injected automatically.
			/// @param entity_instance_manager The entity instance manager.
			/// @param connector_manager The connector manager.
			/// @param counter_float_factory The factory for creating entities of type COUNTER_FLOAT.
			/// @param sin_factory The factory for creating entities of type SIN.
			/// @param cos_factory The factory for creating entities of type COS.
			/// @param render_factory The factory for creating entities of type RENDERER.
			/// @param log_manager The log manager.
			/// @param keyboard_input_manager The keyboard input manager.
			/// @param mouse_input_manager The mouse input manager.
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

			/// @brief Destroys the given window.
			/// @param window The entity instance of type WINDOW.
			void destroy_window(EntityInstancePtr window);

			/// @brief Destroys the given window.
			/// @param window The entity instance of type WINDOW.
			void close_window(EntityInstancePtr window);

			/// @brief Sets the size of the given window.
			/// @param window The entity instance of type WINDOW.
			/// @param width The new width of the window.
			/// @param height The new height of the window.
			void set_window_size(EntityInstancePtr window, int width, int height);

			/// @brief Sets the size of the given window.
			/// @param glfw_window The glfw window.
			/// @param width The new width of the window.
			/// @param height The new height of the window.
			void set_window_size(GLFWwindow* glfw_window, int width, int height);

			void make_current(EntityInstancePtr window);

			/// @brief Sets the size of the given window.
			/// @param window The entity instance of type WINDOW.
			/// @param window The entity instance of type WINDOW.
			void register_render_function(EntityInstancePtr window, std::function<void(EntityInstancePtr, GLFWwindow*)> render_function);

			/// @brief Returns the number of windows.
			int get_window_count();

			/// @brief Returns the window handle for the entity instance.
			/// @param window The entity instance of type WINDOW.
			GLFWwindow* get_window_handle(EntityInstancePtr window);

			/// The logger name of this service.
			static constexpr char LOGGER_NAME[] = "inexor.renderer.window";

		private:

			/// @brief Starts the window thread.
			/// @param window The entity instance of type WINDOW.
			void start_window_thread(EntityInstancePtr window);

			/// @brief Stops the window thread.
			/// @param window The entity instance of type WINDOW.
			void stop_window_thread(EntityInstancePtr window);

			/// @brief Initializes observers on the attributes of the entity instance of type WINDOW.
			/// @param window The entity instance of type WINDOW.
			void initialize_window_observers(EntityInstancePtr window);

			/// This callback is called if a window has been closed.
			void window_closed(GLFWwindow* glfw_window);

			/// This callback is called if a window has been focused / has lost the focus.
			void window_focused(GLFWwindow* glfw_window, bool has_focus);

			/// This callback is called if a window has been iconified / restored.
			void window_iconified(GLFWwindow* glfw_window, bool is_iconified);

			/// This callback is called if a window has been maximized / restored.
			void window_maximized(GLFWwindow* glfw_window, bool is_maximized);

			/// This callback is called if a window position has been changed.
			void window_position_changed(GLFWwindow* glfw_window, int x, int y);

			/// This callback is called if a window size has been changed.
			void window_size_changed(GLFWwindow* glfw_window, int width, int height);

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

			/// The mapping between the entity instance and the pointer to the
			/// corresponding window and the window thread.
			std::unordered_map<EntityInstancePtr, std::pair<GLFWwindow*, std::thread>> windows;

			/// The mapping between the pointer to the window and the
			/// corresponding entity instance.
			std::unordered_map<GLFWwindow*, EntityInstancePtr> window_entities;

			std::unordered_map<EntityInstancePtr, bool> window_thread_state;

			std::unordered_map<EntityInstancePtr, std::list<std::function<void(EntityInstancePtr, GLFWwindow*)>>> window_render_functions;

			int window_count;
	};

}
}
