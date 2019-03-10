#pragma once

#include <memory>

#include "server_http.hpp"
#include "spdlog/spdlog.h"

#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "logging/managers/LogManager.hpp"
//#include "Serializer.hpp"

#define LOGGER_ENTITY_REST "inexor.entity.rest"

using HttpServer = SimpleWeb::Server<SimpleWeb::HTTP>;
using namespace std;

namespace inexor {
namespace rest {
    const string uuid_regex = "[a-f0-9]{8}-[a-f0-9]{4}-4[a-f0-9]{3}-[89aAbB][a-f0-9]{3}-[a-f0-9]{12}";

    class RestServer {
    public:
        RestServer(
            shared_ptr<inexor::logging::LogManager> log_manager,
            shared_ptr<inexor::entity_system::EntityTypeManager> entity_type_manager
        );

        ~RestServer();

        void start();
        void set_port(unsigned short port);
        void create_resources();

    private:
        shared_ptr<inexor::logging::LogManager> log_manager;
        shared_ptr<inexor::entity_system::EntityTypeManager> entity_type_manager;

        shared_ptr<HttpServer> http_server;
        unsigned short port;
    };
};
};