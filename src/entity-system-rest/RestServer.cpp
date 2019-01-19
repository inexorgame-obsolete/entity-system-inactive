// Inexor entity system
// (c)2018 Inexor

#include "RestServer.hpp"

using namespace std;
using namespace restbed;
using namespace inexor::entity_system::rest::api;

namespace inexor {
namespace entity_system {


	RestServer::RestServer(std::shared_ptr<inexor::entity_system::EntitySystem> entity_system) : entity_system(entity_system)
	{
		settings = make_shared<Settings>();
		settings->set_port(8080);
		settings->set_root("api/v1");
		settings->set_worker_limit(8);
		settings->set_default_header("Connection", "close");
	}

	RestServer::~RestServer()
	{
	}

	std::shared_ptr<Service> RestServer::get_service()
	{
		return this->service;
	}

	void RestServer::set_service(std::shared_ptr<Service> service)
	{
		this->service = service;
	}

	void RestServer::create_resources()
	{
//		EntitySystemApi::createResources(this->entity_system, this->service);
		EntityTypeApi::createResources(this->entity_system, this->service);
//		RelationshipTypeApi::createResources(this->entity_system, this->service);
//		EntityInstanceApi::createResources(this->entity_system, this->service);
//		RelationshipInstanceApi::createResources(this->entity_system, this->service);
//		AttributeApi::createResources(this->entity_system, this->service);
	}

	shared_ptr<EntitySystem> RestServer::get_entity_system()
	{
		return this->entity_system;
	}

	shared_ptr<Settings> RestServer::get_settings()
	{
		return this->settings;
	}

	void RestServer::startService(int const& _port) {
		// port is ignored (already set in the settings!
	    spdlog::get(LOGGER_ENTITY_REST)->info("Starting REST server on http://localhost:{}/{}", this->settings->get_port(), this->settings->get_root());
		this->service->start(settings);
	}

	void RestServer::stopService() {
	    spdlog::get(LOGGER_ENTITY_REST)->info("Stopping REST server");
	    // spdlog::get(LOGGER_ENTITY_REST)->info("Stopping REST server on http://localhost:{}/{}", this->settings->get_port(), this->settings->get_root());
		this->service->stop();
	}

	void RestServer::status() {
		spdlog::get(LOGGER_ENTITY_REST)->info("REST server is running");
//		auto http_uri = this->service->get_http_uri();
//		spdlog::get(LOGGER_ENTITY_REST)->info("REST server is running on {}", http_uri->to_string());
	    // spdlog::get(LOGGER_ENTITY_REST)->info("REST server is running on http://localhost:{}/{}", this->settings->get_port(), this->settings->get_root());
	}

};
};
