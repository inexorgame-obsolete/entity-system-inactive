#pragma once

#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"

#include "server_http.hpp"
using HttpServer = SimpleWeb::Server<SimpleWeb::HTTP>;

namespace inexor {
    namespace rest {
        namespace api {
            class EntityInstances {
            public:
                EntityInstances(
                    shared_ptr<EntityInstanceManager> entity_instance_manger
                );

                ~EntityInstances();


                void get_entity_instance_by_uuid(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request);
            private:
                shared_ptr<EntityInstanceManager> entity_instance_manager;
            };
        };
    };
};
