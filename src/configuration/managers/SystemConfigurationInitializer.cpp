#include "SystemConfigurationInitializer.hpp"

#include <utility>

namespace inexor::configuration {

SystemConfigurationInitializer::SystemConfigurationInitializer(ConfigurationManagerPtr configuration_manager)
{
    this->configuration_manager = std::move(configuration_manager);
}

SystemConfigurationInitializer::~SystemConfigurationInitializer() = default;

void SystemConfigurationInitializer::init()
{
#ifdef _WIN32
    configuration_manager->set("PID", _getpid());
#else
    configuration_manager->set("PID", getpid());
#endif
    configuration_manager->set("SYS_NUM_CONCURRENT_THREADS", (int)std::thread::hardware_concurrency());
}

} // namespace inexor::configuration
