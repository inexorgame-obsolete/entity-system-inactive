#include <functional>

#include "RestServer.hpp"

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
            http_server->config.port = port;
            thread server_thread([this]()
            {
                this->log_manager->register_logger(LOGGER_ENTITY_REST);
                spdlog::get(LOGGER_ENTITY_REST)->info("Starting REST server on http://localhost:{}", this->port);
                this->http_server->start();
            });
            server_thread.join();
        }

        void RestServer::set_port(unsigned short port)
        {
            http_server->config.port = port;
        }

        void RestServer::create_resources()
        {
            http_server->resource["^/string$"]["GET"] = [this](shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request) {
                // Retrieve string:
                string content = "abc";

                *response << "HTTP/1.1 200 OK\r\nContent-Length: " << content.size() << "\r\n\r\n"
                          << content;
            };

        }
    };
};