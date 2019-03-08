#pragma once

#include <memory>
#include "server_http.hpp"

#include "logging/managers/LogManager.hpp"

using HttpServer = SimpleWeb::Server<SimpleWeb::HTTP>;
using namespace std;

namespace inexor {
namespace rest {

    class RestServer {
    public:
        RestServer(
            shared_ptr<inexor::logging::LogManager> log_manager
        );

        ~RestServer();

        void start();
        void set_port(unsigned int port);

    private:
        shared_ptr<inexor::logging::LogManager> log_manager;

        shared_ptr<HttpServer> http_server;

        unsigned int port;
    };
};
};