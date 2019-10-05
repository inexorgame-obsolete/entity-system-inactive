#include "ServerLifecycle.hpp"

namespace inexor {
namespace server {

	ServerLifecycle::ServerLifecycle(
		LogManagerPtr log_manager
	) {
		this->log_manager = log_manager;
		this->shutdown_requested = false;
		this->restart_requested = false;
	}

	ServerLifecycle::~ServerLifecycle()
	{
	}

	void ServerLifecycle::init()
	{
		log_manager->register_logger(LOGGER_NAME);
		this->shutdown_requested = false;
		this->restart_requested = false;
	}

	void ServerLifecycle::shutdown()
	{
	}

	void ServerLifecycle::request_shutdown()
	{
		shutdown_requested = true;
	}

	void ServerLifecycle::request_restart()
	{
		restart_requested = true;
	}

	bool ServerLifecycle::is_shutdown_requested()
	{
		return shutdown_requested;
	}

	bool ServerLifecycle::is_restart_requested()
	{
		return restart_requested;
	}

}
}
