#pragma once

#include <memory>
#include "server_http.hpp"

#include "entity-system-rest/RestServer.hpp"
#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"

using Request = HttpServer::Request;
using Response = HttpServer::Response;

namespace inexor {
    namespace rest {
        namespace controllers {
            void get_instance_by_uuid(shared_ptr<EntityInstanceManager> entity_instance_manager, shared_ptr<Response> response, shared_ptr<Request> request)
            {
                auto content = request->content.string();
                // request->content.string() is a convenience function for:
                // stringstream ss;
                // ss << request->content.rdbuf();
                // auto content=ss.str();

                *response << "HTTP/1.1 200 OK\r\nContent-Length: " << content.length() << "\r\n\r\n"
                          << content;
            }
        };
    };
};
