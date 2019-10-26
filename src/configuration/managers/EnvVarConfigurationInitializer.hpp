#pragma once

#include "ConfigurationManager.hpp"

#include <string>

#include <better-enums/enum.h>

namespace inexor::configuration {

/// The environment variables to import
BETTER_ENUM(EnvironmentVariables, int, DISPLAY = 0, SHELL, PATH, USERNAME, DESKTOP_SESSION, GDK_BACKEND, USER, PWD, HOME, LANGUAGE, LANG)

using ConfigurationManagerPtr = std::shared_ptr<ConfigurationManager>;

/// @class EnvVarConfigurationInitializer
/// @brief Initializes the environment variables as configuration items.
class EnvVarConfigurationInitializer
{
    public:
    /// @brief Constructor.
    /// @note The dependencies of this class will be injected automatically.
    /// @param configuration_manager The configuration manager.
    explicit EnvVarConfigurationInitializer(ConfigurationManagerPtr configuration_manager);

    /// Destructor.
    ~EnvVarConfigurationInitializer();

    /// Initialization.
    void init();

    /// Creates a configuration item for the environment variable.
    /// @param env_name The name of the enviroment variable.
    void set_by_env_var(const std::string& env_name);

    private:
    /// The configuration manager.
    ConfigurationManagerPtr configuration_manager;

    /// Returns the value of the environment variable if exists or nullopt.
    /// @param env_name The name of the enviroment variable.
    std::optional<std::string> get_env_var(std::string const &env_name);
};

} // namespace inexor::configuration
