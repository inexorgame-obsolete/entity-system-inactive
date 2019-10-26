#include "EnvVarConfigurationInitializer.hpp"

#include <cstdlib>
#include <string>
#include <utility>

namespace inexor::configuration {

EnvVarConfigurationInitializer::EnvVarConfigurationInitializer(ConfigurationManagerPtr configuration_manager)
{
    this->configuration_manager = std::move(configuration_manager);
}

EnvVarConfigurationInitializer::~EnvVarConfigurationInitializer() = default;

void EnvVarConfigurationInitializer::init()
{
    for (size_t index = 0; index < EnvironmentVariables::_size(); ++index)
    {
        set_by_env_var(EnvironmentVariables::_names()[index]);
    }
}

void EnvVarConfigurationInitializer::set_by_env_var(const std::string &env_name)
{
    std::optional<std::string> env_value = get_env_var(env_name);
    if (env_value.has_value())
    {
        configuration_manager->set("ENV_" + env_name, env_value.value());
    }
}

std::optional<std::string> EnvVarConfigurationInitializer::get_env_var(std::string const &env_name)
{
    char const *env_value = std::getenv(env_name.c_str());
    return env_value == nullptr ? std::nullopt : std::optional<std::string>{std::string(env_value)};
}

} // namespace inexor::configuration
