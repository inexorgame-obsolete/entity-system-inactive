#include "RestServer.hpp"

namespace inexor {
    namespace rest {

        RestServer::RestServer(
            shared_ptr<inexor::logging::LogManager> log_manager,
            shared_ptr<inexor::entity_system::EntityTypeManager> entity_type_manager
        )
        {
            this->log_manager = log_manager;
            this->entity_type_manager = entity_type_manager;
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
            http_server->resource["^/entities/type/(" + uuid_regex + ")$"]["GET"] = [this](shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request) {
                // Retrieve string:
                string content;
                string type_uuid = request->path_match[1];

                if (this->entity_type_manager->does_entity_type_exist(type_uuid)) { 
                    O_ENT_TYPE type_instance = this->entity_type_manager->get_entity_type(type_uuid);
                    // Serialize type
                } else {

                }

                *response << "HTTP/1.1 200 OK\r\nContent-Length: " << content.size() << "\r\n\r\n"
                          << content;
            };

        }
    };
};