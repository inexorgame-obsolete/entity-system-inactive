#include <functional>

#include "RestServer.hpp"
#include "entity-system-rest/controllers/EntityInstance.hpp"

namespace inexor {
    namespace rest {

        RestServer::RestServer(
            shared_ptr<inexor::logging::LogManager> log_manager,
            shared_ptr<inexor::entity_system::EntityInstanceManager> entity_instance_manager
        )
        {
            this->log_manager = log_manager;
            this->entity_instance_manager = entity_instance_manager;
            this->http_server = make_shared<HttpServer>();
            this->port = 8080; // Default port
            // Initialize API's by injecting the http server

        }

        RestServer::~RestServer() {
            // TODO: Dereference HttpServer
        }

        void RestServer::start()
        {
            thread server_thread([=]()
            {
                http_server->start();
            });
            server_thread.detach();
        }

        void RestServer::set_port(unsigned short port)
        {
            http_server->config.port = port;
        }

        void RestServer::create_resources()
        {
            this->http_server->resource["^/entities/instances/([0-9a-f]{12})$"]["GET"] = controllers::get_instance_by_uuid;
        }
    };
};