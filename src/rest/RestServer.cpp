// Inexor entity system prototype
// (c)2018 Inexor

#include "RestServer.hpp"

#include <pistache/endpoint.h>
#include <pistache/http.h>
#include <pistache/router.h>

#include "impl/AttributeApiImpl.h"
#include "impl/EntityInstanceApiImpl.h"
#include "impl/EntitySystemApiImpl.h"
#include "impl/EntityTypeApiImpl.h"
#include "impl/RelationshipInstanceApiImpl.h"
#include "impl/RelationshipTypeApiImpl.h"

using namespace inexor::entity_system::server::api;

namespace inexor {
namespace entity_system {


	RestServer::RestServer()
	{
	}


	RestServer::~RestServer()
	{
		// this->stop();
	}

	void RestServer::start()
	{
		std::cout << "Starting Inexor Entity System REST server on port 8080" << std::endl;
	    Pistache::Address addr(Pistache::Ipv4::any(), Pistache::Port(8080));

	    // httpEndpoint = new Pistache::Http::Endpoint((addr));
	    httpEndpoint = std::make_shared<Pistache::Http::Endpoint>(addr);
	    auto router = std::make_shared<Pistache::Rest::Router>();

	    auto opts = Pistache::Http::Endpoint::options().threads(PISTACHE_SERVER_THREADS);
	    httpEndpoint->init(opts);


	    AttributeApiImpl AttributeApiserver(router);
	    AttributeApiserver.init();
	    EntityInstanceApiImpl EntityInstanceApiserver(router);
	    EntityInstanceApiserver.init();
	    EntitySystemApiImpl EntitySystemApiserver(router);
	    EntitySystemApiserver.init();
	    EntityTypeApiImpl EntityTypeApiserver(router);
	    EntityTypeApiserver.init();
	    RelationshipInstanceApiImpl RelationshipInstanceApiserver(router);
	    RelationshipInstanceApiserver.init();
	    RelationshipTypeApiImpl RelationshipTypeApiserver(router);
	    RelationshipTypeApiserver.init();

	    httpEndpoint->setHandler(router->handler());
	    httpEndpoint->serve();

	    httpEndpoint->shutdown();

//		Pistache::Address addr(Pistache::Ipv4::any(), Pistache::Port(9080));
//		auto opts = Pistache::Http::Endpoint::options().threads(1);
//		server = std::make_shared<Pistache::Http::Endpoint>(addr);
//		server->init(opts);
//		// server->setHandler(std::make_shared<TestHandler>());
//		server->setHandler(Http::make_handler<TestHandler>());
//		server->serve();
//		std::cout << "Listening on port 9080" << std::endl;
	}

	void RestServer::stop()
	{
		httpEndpoint->shutdown();
	}

};
};
