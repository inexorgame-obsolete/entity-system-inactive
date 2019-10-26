#pragma once

#include "logging/managers/LogManager.hpp"

#include <boost/signals2.hpp>

namespace inexor::client {

using LogManagerPtr = std::shared_ptr<logging::LogManager>;

/// @class ClientLifecycle
/// @brief The life cycle of the client application.
class ClientLifecycle
{
    public:
    /// @brief Constructor.
    /// @note The dependencies of this class will be injected automatically.
    /// @param log_manager The log manager.
    explicit ClientLifecycle(LogManagerPtr log_manager);

    /// Destructor.
    ~ClientLifecycle();

    /// Initialize the application life cycle.
    void init();

    /// Shut down the application life cycle.
    void shutdown();

    /// Request a shutdown.
    void request_shutdown();

    /// Request a restart.
    void request_restart();

    /// Returns true, if a shutdown has been requested.
    bool is_shutdown_requested();

    /// Returns true, if a shutdown has been requested.
    bool is_restart_requested();

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
