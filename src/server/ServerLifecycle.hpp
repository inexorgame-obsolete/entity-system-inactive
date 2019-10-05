#pragma once

#include "logging/managers/LogManager.hpp"

#include <boost/signals2.hpp>

namespace inexor {
namespace server {

	using LogManagerPtr = std::shared_ptr<logging::LogManager>;

	/// @class ServerLifecycle
	/// @brief The life cycle of the client application.
	class ServerLifecycle
	{
		public:

			/// @brief Constructor.
			/// @note The dependencies of this class will be injected automatically.
			/// @param log_manager The log manager.
			ServerLifecycle(
				LogManagerPtr log_manager
			);

			/// Destructor.
			~ServerLifecycle();

			/// Initialize the server life cycle.
			void init();

			/// Shut down the server life cycle.
			void shutdown();

			/// Request a shutdown.
			void request_shutdown();

			/// Request a restart.
			void request_restart();

			/// Returns true, if a shutdown has been requested.
			bool is_shutdown_requested();

			/// Returns true, if a shutdown has been requested.
			bool is_restart_requested();

			/// The logger name of this service.
			static constexpr char LOGGER_NAME[] = "inexor.server.lifecycle";

		private:

			/// The log manager.
			LogManagerPtr log_manager;

			/// If true, a shutdown has been requested.
			bool shutdown_requested;

			/// If true, a shutdown has been requested.
			bool restart_requested;

	};

}
}
