#include "InexorApplication.hpp"

#include <graphqlservice/JSONResponse.h>
#include <utility>

#include "spdlog/spdlog.h"

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
    this->query = query;
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

void InexorApplication::init()
{
    spdlog::get(LOGGER_NAME)->info("Starting Inexor...");

    // Initialize the visual scripting.
    visual_scripting_system_module->init_components();

    // Initialize the command module
    command_module->init_components();

    // Initialize the rendering.
    client_module->init_components();


    // TODO: Move the GraphQL to it's own component

    auto service = std::make_shared<graphql::entities::Operations>(query);
    try
    {
        std::string query_string = "{ entity_types { uuid name } }";
        spdlog::get(LOGGER_NAME)->info("GraphQL query string: {}", query_string);
        graphql::peg::ast graphql_query = graphql::peg::parseString(std::move(query_string));
        if (!graphql_query.root)
        {
            throw std::runtime_error("Unknown error: No query root");
        }
        spdlog::get(LOGGER_NAME)->info("Executing GraphQL query...");
        spdlog::get(LOGGER_NAME)->info("GraphQL response: {}",
        graphql::response::toJSON(service->resolve(nullptr, *graphql_query.root, "", graphql::response::Value(graphql::response::Type::Map)).get()));
    }
    catch (const std::runtime_error& ex)
    {
        spdlog::get(LOGGER_NAME)->error("GraphQL query failed: {}", ex.what());
    }

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
