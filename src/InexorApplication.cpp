#include "InexorApplication.hpp"

#include <graphqlservice/JSONResponse.h>
#include <utility>

#include "spdlog/spdlog.h"

#include "restinio/all.hpp"
#include <nlohmann/json.hpp>

namespace inexor {

// Static instances of the Inexor application(s)
std::vector<InexorApplication *> InexorApplication::instances;

InexorApplication::InexorApplication(EntitySystemModulePtr entity_system_module, TypeSystemModulePtr type_system_module, ConfigurationModulePtr configuration_module, EntitySystemDebuggerPtr entity_system_debugger,
                                     VisualScriptingSystemModulePtr visual_scripting_system_module, CommandModulePtr command_module, ClientModulePtr client_module, QueryPtr query, LogManagerPtr log_manager)
{
    this->entity_system_module = std::move(entity_system_module);
    this->type_system_module = std::move(type_system_module);
    this->configuration_module = std::move(configuration_module);
    this->entity_system_debugger = std::move(entity_system_debugger);
    this->visual_scripting_system_module = std::move(visual_scripting_system_module);
    this->command_module = std::move(command_module);
    this->client_module = std::move(client_module);
    this->log_manager = std::move(log_manager);
    this->query = std::move(query);
    this->running = false;
}

InexorApplication::~InexorApplication() = default;

void InexorApplication::pre_init(int argc, char *argv[])
{
    // Register application instance in static vector
    // You can't do this in the constructor
    InexorApplication::instances.push_back(this);

    // Type system initialization.
    type_system_module->pre_init_components();

    // Debugger
    // TODO: enable with macro
    entity_system_debugger->init();

    // Logging initialization
    log_manager->init();
    log_manager->register_logger(LOGGER_NAME);
    entity_system_debugger->init_logger();

    spdlog::get(LOGGER_NAME)->info("init()");

#ifdef _WIN32
    spdlog::get(LOGGER_NAME)->info("PID: {}", _getpid());
#else
    spdlog::get(LOGGER_NAME)->info("PID: {}", getpid());
#endif

    // Type system initialization.
    type_system_module->init_components();

    // Configuration manager initialization.
    configuration_module->init(argc, argv);

    // Initialize the command module
    command_module->pre_init_components();

    // Initialize the rendering.
    client_module->pre_init_components();

}

void replaceAll(std::string& str, const std::string& from, const std::string& to) {
    if(from.empty())
        return;
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
    }
}

void InexorApplication::init()
{
    spdlog::get(LOGGER_NAME)->info("Starting Inexor...");

    // Initialize the visual scripting.
    visual_scripting_system_module->init_components();

    // Initialize the command module
    command_module->init_components();

    // Initialize the rendering.
    client_module->init_components();



//    restinio::run(
//        restinio::on_this_thread()
//            .port(8080)
//            .address("localhost")
//            .request_handler([](auto req) {
//              return req->create_response().set_body("Hello, World!").done();
//            }));
    // TODO: Move the GraphQL to it's own component

    std::thread restinio_thread([this]() {
        auto service = std::make_shared<graphql::entities::Operations>(query);
        restinio::run(restinio::on_this_thread()
            .port(31415)
            .address("192.168.255.206")
            .request_handler([service] (auto req) {
                if (restinio::http_method_post() == req->header().method()) {
                    spdlog::get(LOGGER_NAME)->info("POST");
                    try
                    {
                        std::string req_body = req->body();
                        spdlog::get(LOGGER_NAME)->info(req_body);
                        using json = nlohmann::json;
//                        spdlog::get(LOGGER_NAME)->info("1");
//                        auto test = json::parse("{\n"
//                                                "\"operationName\": null,\n"
//                                                "\"variables\": {},\n"
//                                                "\"query\": \"{ entity_types { name attributes { uuid } } }\"\n"
//                                                "}");
                        spdlog::get(LOGGER_NAME)->info("1");
                        req_body.erase(std::remove(req_body.begin(), req_body.end(), '\n'), req_body.end());
                        spdlog::get(LOGGER_NAME)->info("2");
                        auto req_body_json = json::parse(req_body);
                        spdlog::get(LOGGER_NAME)->info(req_body_json);
                        auto req_query_json = req_body_json["query"];
                        std::string query_string = req_query_json.dump();
                        query_string = query_string.substr(1, query_string.size() - 2);
                        // TODO: unescape all "invalid" characters
                        replaceAll(query_string, "\\n", "");
                        spdlog::get(LOGGER_NAME)->info(query_string);

                        // std::string query_string = "{"operationName":null,"variables":{},"query":"{ entity_types { name attributes { uuid } } }";
                        spdlog::get(LOGGER_NAME)->info("GraphQL query string: {}", query_string);
                        graphql::peg::ast graphql_query = graphql::peg::parseString(std::move(query_string));
                        if (!graphql_query.root)
                        {
                            throw std::runtime_error("Unknown error: No query root");
                        }
                        spdlog::get(LOGGER_NAME)->info("Executing GraphQL query...");

                        auto result = graphql::response::toJSON(service->resolve(nullptr, *graphql_query.root, "", graphql::response::Value(graphql::response::Type::Map)).get());
                        spdlog::get(LOGGER_NAME)->info("GraphQL response: {}", result);

                        return req->create_response().append_header("Access-Control-Allow-Origin", "*").set_body(result).done();
                    } catch (const std::runtime_error &ex)
                    {
                        spdlog::get(LOGGER_NAME)->error("GraphQL query failed: {}", ex.what());
                        return req->create_response(restinio::status_internal_server_error())
                            .append_header(restinio::http_field::server, "Inexor GraphQL")
                            .append_header(restinio::http_field::access_control_allow_origin, "*")
                            .append_header(restinio::http_field::access_control_allow_headers, "*")
                            .set_body("error")
                            .done();
                    }
                } else if (restinio::http_method_options() == req->header().method()) {
                    spdlog::get(LOGGER_NAME)->info("HTTP OPTIONS");
                    return req->create_response()
                        .append_header(restinio::http_field::server, "Inexor GraphQL")
                        .append_header(restinio::http_field::access_control_allow_origin, "*")
                        .append_header(restinio::http_field::access_control_allow_headers, "*")
                        .append_header_date_field()
                        // .append_header(restinio::http_field::content_type, "text/plain; charset=utf-8")
                        .set_body("")
                        .done();
                } else {
                    spdlog::get(LOGGER_NAME)->error("Unknown http method {}", req->header().method());
                    return req->create_response(restinio::status_internal_server_error())
                        .append_header(restinio::http_field::server, "Inexor GraphQL")
                        .append_header(restinio::http_field::access_control_allow_origin, "*")
                        .append_header(restinio::http_field::access_control_allow_headers, "*")
                        .set_body("Unknown http method")
                        .done();

                }
            })
        );
    });
    restinio_thread.detach();



}

void InexorApplication::run()
{
    using namespace std::literals::chrono_literals;

    running = true;

    spdlog::get(LOGGER_NAME)->info("Inexor is running");
    while (running && !client_module->is_restart_requested())
    {
        // everything else happens in the execution graph or in threads for the ES instances.

        // main thread = poll events
        std::this_thread::sleep_for(10ms);

        // Main thread update
        client_module->update();

        // Shutdown requested?
        if (client_module->is_shutdown_requested())
        {
            destroy();
        }
    }

    // Restart requested?
    if (client_module->is_restart_requested())
    {
        restart();
    }

    post_destroy();
}

void InexorApplication::destroy()
{
    if (!running)
    {
        spdlog::get(LOGGER_NAME)->info("Not running");
        return;
    }

    spdlog::get(LOGGER_NAME)->info("Shutting down Inexor...");

    // Shut down the client module.
    client_module->destroy_components();

    // Shut down the command module
    command_module->destroy_components();

    // Shut down the visual scripting module.
    visual_scripting_system_module->destroy_components();

    // Shut down the type system.
    type_system_module->destroy_components();

    running = false;
    spdlog::get(LOGGER_NAME)->info("Shutdown completed");
}


void InexorApplication::post_destroy()
{
    // Shut down the client module
    client_module->post_destroy_components();

    // Shut down the command module
    command_module->post_destroy_components();

    // Shut down the visual scripting module.
    // visual_scripting_system_module->post_destroy_components();

    // Shut down the type system.
    type_system_module->post_destroy_components();
}

void InexorApplication::restart()
{
    spdlog::get(LOGGER_NAME)->info("Restarting Inexor...");
    destroy();
    init();
    run();
    spdlog::get(LOGGER_NAME)->info("Restart completed");
}

void InexorApplication::sighup_handler(const int signal_number)
{
    spdlog::get(LOGGER_NAME)->info("Received SIGINT signal number {}", signal_number);
    restart();
}

void InexorApplication::sigterm_handler(const int signal_number)
{
    spdlog::get(LOGGER_NAME)->info("Received SIGTERM signal number {}", signal_number);
    destroy();
    post_destroy();
}

} // namespace inexor
