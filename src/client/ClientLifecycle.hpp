#pragma once

#include <boost/signals2.hpp>

#include "base/LifeCycleComponent.hpp"
#include "logging/managers/LogManager.hpp"

namespace inexor::client {

using LogManagerPtr = std::shared_ptr<logging::LogManager>;

/// @class ClientLifecycle
/// @brief The life cycle of the client application.
class ClientLifecycle : public LifeCycleComponent
{
    public:
    /// @brief Constructor.
    /// @param log_manager The log manager.
    explicit ClientLifecycle(LogManagerPtr log_manager);

    /// Destructor.
    ~ClientLifecycle();

    /// Initialize the application life cycle.
    void init() override;

    /// Request a shutdown.
    void request_shutdown();

    /// Request a restart.
    void request_restart();

    /// Returns true, if a shutdown has been requested.
    bool is_shutdown_requested();

    /// Returns true, if a shutdown has been requested.
    bool is_restart_requested();

    /// Returns the name of the component
    std::string get_component_name() override;

    /// The logger name of this service.
    static constexpr char LOGGER_NAME[] = "inexor.client.lifecycle";

    private:
    /// The log manager.
    LogManagerPtr log_manager;

    /// If true, a shutdown has been requested.
    bool shutdown_requested;

    /// If true, a shutdown has been requested.
    bool restart_requested;
};

} // namespace inexor::client
