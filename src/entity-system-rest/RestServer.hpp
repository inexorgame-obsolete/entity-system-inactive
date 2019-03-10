#pragma once

#include <memory>

#include "server_http.hpp"
#include "spdlog/spdlog.h"

#include "logging/managers/LogManager.hpp"

#define LOGGER_ENTITY_REST "inexor.entity.rest"

using HttpServer = SimpleWeb::Server<SimpleWeb::HTTP>;
using namespace std;

namespace inexor {
namespace rest {

    class RestServer {
    public:
        RestServer(
            shared_ptr<inexor::logging::LogManager> log_manager,
            shared_ptr<inexor::entity_system::EntityInstanceManager> entity_instance_manager
        );

        ~RestServer();

        void start();
        void set_port(unsigned short port);
        void create_resources();

    private:
        shared_ptr<inexor::logging::LogManager> log_manager;
        shared_ptr<inexor::entity_system::EntityInstanceManager> entity_instance_manager;

        shared_ptr<HttpServer> http_server;
        unsigned short port;
    };
};
};