#include "MonitorManager.hpp"

#include <GLFW/glfw3.h>

#include "spdlog/spdlog.h"

namespace inexor {
namespace renderer {

	MonitorManager::MonitorManager(
		MonitorFactoryPtr monitor_factory,
		LogManagerPtr log_manager
	) {
		this->monitor_factory = monitor_factory;
		this->log_manager = log_manager;
	}

	MonitorManager::~MonitorManager()
	{
	}

	void MonitorManager::init()
	{
		log_manager->register_logger(LOGGER_NAME);
		detect_monitors();
	}

	void MonitorManager::shutdown()
	{
	}

	void MonitorManager::detect_monitors()
	{
		int count_monitors;
		GLFWmonitor** monitors = glfwGetMonitors(&count_monitors);
		for (int i = 0; i < count_monitors; i++)
		{
			EntityInstancePtrOpt o_monitor = create_monitor(monitors[i]);
		}
	}

	/// Detects the monitors.
	EntityInstancePtrOpt MonitorManager::create_monitor(GLFWmonitor* glfw_monitor)
	{
		std::string monitor_name = glfwGetMonitorName(glfw_monitor);
		const GLFWvidmode* mode = glfwGetVideoMode(glfw_monitor);
		int x;
		int y;
		glfwGetMonitorPos(glfw_monitor, &x, &y);
		EntityInstancePtrOpt o_monitor = monitor_factory->create_instance(monitor_name, x, y, mode->width, mode->height, is_primary(glfw_monitor));
		if (o_monitor.has_value())
		{
			EntityInstancePtr monitor = o_monitor.value();
			monitors[monitor] = glfw_monitor;
			spdlog::get(MonitorManager::LOGGER_NAME)->info("Created monitor {} ({}, {}) ({} x {}) {}", monitor_name, x, y, mode->width, mode->height, is_primary(glfw_monitor) ? "[primary]" : "");
			detect_video_modes(monitor);
		}
		return o_monitor;
	}

	void MonitorManager::destroy_monitor(EntityInstancePtr monitor)
	{
		monitors.erase(monitor);
	}

	bool MonitorManager::is_primary(EntityInstancePtr monitor)
	{
		return is_primary(monitors[monitor]);
	}

	bool MonitorManager::is_primary(GLFWmonitor* glfw_monitor)
	{
		return glfw_monitor == glfwGetPrimaryMonitor();
	}

	void MonitorManager::detect_video_modes(EntityInstancePtr monitor)
	{
		int count_video_modes;
		const GLFWvidmode* video_modes = glfwGetVideoModes(monitors[monitor], &count_video_modes);
		for (int i = 0; i < count_video_modes; i++)
		{
			GLFWvidmode video_mode = video_modes[i];
			spdlog::get(MonitorManager::LOGGER_NAME)->info("  {} x {} @ {} Hz ({}x{}x{}) ", video_mode.width, video_mode.height, video_mode.refreshRate, video_mode.redBits, video_mode.greenBits, video_mode.blueBits);
		}
	}

}
}
