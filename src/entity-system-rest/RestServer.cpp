#include "RestServer.hpp"

namespace inexor {
    namespace rest {

        RestServer::RestServer(
                shared_ptr<inexor::logging::LogManager> log_manager
        )
        {
            this->log_manager = log_manager;
            this->http_server = make_shared<HttpServer>();
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

        void RestServer::set_port(unsigned int port)
        {
            http_server->config.port = port;
        }


    };
};