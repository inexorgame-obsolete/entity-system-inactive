#include "ClientLifecycle.hpp"

#include <utility>

namespace inexor::client {

ClientLifecycle::ClientLifecycle(LogManagerPtr log_manager)
{
    this->log_manager = std::move(log_manager);
    this->shutdown_requested = false;
    this->restart_requested = false;
}

ClientLifecycle::~ClientLifecycle() = default;

void ClientLifecycle::init()
{
    log_manager->register_logger(LOGGER_NAME);
    this->shutdown_requested = false;
    this->restart_requested = false;
}

void ClientLifecycle::shutdown()
{
}

void ClientLifecycle::request_shutdown()
{
    shutdown_requested = true;
}

void ClientLifecycle::request_restart()
{
    restart_requested = true;
}

bool ClientLifecycle::is_shutdown_requested()
{
    return shutdown_requested;
}

bool ClientLifecycle::is_restart_requested()
{
    return restart_requested;
}

} // namespace inexor::client
