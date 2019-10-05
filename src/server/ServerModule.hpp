#pragma once

#include "ServerLifecycle.hpp"

namespace inexor {
namespace server {

	/// @class ServerModule
	/// @brief This module contains all modules for the Inexor Server.
	class ServerModule
	{
		using ServerLifecyclePtr = std::shared_ptr<ServerLifecycle>;

		public:

			/// @brief Constructor.
			/// @note The dependencies of this class will be injected automatically.
			ServerModule(
				ServerLifecyclePtr server_lifecycle
			);

			/// Destructor.
			~ServerModule();

			/// Initialization of the server module.
			void init();

			/// Shut down the server module.
			void shutdown();

			/// Update the server module.
			void update();

			/// Returns true, if the application should be shut down.
			bool is_shutdown_requested();

			/// Returns true, if the application should be restarted.
			bool is_restart_requested();

		private:

			/// The server lifecycle.
			ServerLifecyclePtr server_lifecycle;

	};

}
}
