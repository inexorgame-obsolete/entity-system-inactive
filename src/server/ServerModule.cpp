#include "ServerModule.hpp"

namespace inexor {
namespace server {

	ServerModule::ServerModule(
		ServerLifecyclePtr server_lifecycle
	)
	{
		this->server_lifecycle = server_lifecycle;
	}

	ServerModule::~ServerModule()
	{
	}

	void ServerModule::init()
	{
		server_lifecycle->init();
	}

	void ServerModule::shutdown()
	{
		server_lifecycle->shutdown();
	}

	void ServerModule::update()
	{
	}

	bool ServerModule::is_shutdown_requested()
	{
		return server_lifecycle->is_shutdown_requested();
	}

	bool ServerModule::is_restart_requested()
	{
		return server_lifecycle->is_restart_requested();
	}

}
}
