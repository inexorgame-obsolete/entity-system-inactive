#pragma once

#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "renderer/factories/MonitorFactory.hpp"
#include "logging/managers/LogManager.hpp"

struct GLFWmonitor;

namespace inexor {
namespace renderer {

	using MonitorFactoryPtr = std::shared_ptr<MonitorFactory>;
	using LogManagerPtr = std::shared_ptr<inexor::logging::LogManager>;
	using EntityInstancePtr = std::shared_ptr<EntityInstance>;
	using EntityInstancePtrOpt = std::optional<EntityInstancePtr>;

	/// @class MonitorManager
	/// @brief Management of the monitors.
	class MonitorManager
	: public std::enable_shared_from_this<MonitorManager>
	{
		public:

			/// @brief Constructor.
			/// @note The dependencies of this class will be injected automatically.
			/// @param monitor_factory Factory for creating entity instances of type 'MONITOR'.
			/// @param log_manager The log manager.
			MonitorManager(
				MonitorFactoryPtr monitor_factory,
				LogManagerPtr log_manager
			);

			/// Destructor.
			~MonitorManager();

			/// Initialize the monitor manager.
			void init();

			/// Shut down the monitor manager.
			void shutdown();

			/// Detects the monitors.
			void detect_monitors();

			/// Detects the video modes.
			void detect_video_modes(EntityInstancePtr monitor);

			bool is_primary(EntityInstancePtr monitor);

			/// The logger name of this service.
			static constexpr char LOGGER_NAME[] = "inexor.renderer.monitor";

		private:

			/// Creates a monitor.
			EntityInstancePtrOpt create_monitor(GLFWmonitor* glfw_monitor);

			/// Destroys a monitor.
			void destroy_monitor(EntityInstancePtr monitor);

			bool is_primary(GLFWmonitor* glfw_monitor);

			/// The monitor factory.
			MonitorFactoryPtr monitor_factory;

			/// The log manager.
			LogManagerPtr log_manager;

			/// The mapping between the entity instance and the pointer to the
			/// corresponding monitor.
			std::unordered_map<EntityInstancePtr, GLFWmonitor*> monitors;

	};

}
}
