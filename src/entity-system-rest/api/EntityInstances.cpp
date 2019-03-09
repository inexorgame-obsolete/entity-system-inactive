#include "EntityInstances.hpp"

namespace inexor {
    namespace rest {
        namespace api {
            EntityInstances::EntityInstances(
                shared_ptr<EntityInstanceManager> entity_instance_manger
            )
            {
                this->entity_instance_manager = entity_instance_manger;
            }

            EntityInstances::~EntityInstances()
            {

            }

            void EntityInstances::get_entity_instance_by_uuid(shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request)
            {
                // Retrieve string:
                auto content = request->content.string();
                // request->content.string() is a convenience function for:
                // stringstream ss;
                // ss << request->content.rdbuf();
                // auto content=ss.str();

                *response << "HTTP/1.1 200 OK\r\nContent-Length: " << content.length() << "\r\n\r\n" << content;
            }
        };
    };
};