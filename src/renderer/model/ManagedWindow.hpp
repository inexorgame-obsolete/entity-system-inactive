#pragma once

#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"

#include "react/Signal.h"

#include <Magnum/Timeline.h>

#include <list>
#include <functional>

struct GLFWwindow;

namespace inexor {
namespace renderer {

	using EntityInstancePtr = std::shared_ptr<entity_system::EntityInstance>;

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
		react::Signal<entity_system::D, std::pair<int, int>> signal_position_changed;

		/// A signal that the size of the window has been changed.
		react::Signal<entity_system::D, std::pair<int, int>> signal_size_changed;

		// TODO: list of observers for shutting down the observers during destroy

		/// A list of functions to call during initialization of the window thread. The order of these functions is important.
		std::optional<std::function<void(EntityInstancePtr, GLFWwindow*)>> init_function;

		/// A list of functions to call during rendering. The order of these functions is important.
		std::list<std::function<void(EntityInstancePtr, GLFWwindow*, Magnum::Timeline)>> render_functions;

		/// A list of functions to call during shut down of the window thread. The order of these functions is important.
		std::optional<std::function<void(EntityInstancePtr, GLFWwindow*)>> shutdown_function;

	};

}
}
