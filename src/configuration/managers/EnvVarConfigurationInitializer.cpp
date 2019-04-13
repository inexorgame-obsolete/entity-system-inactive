#include "EnvVarConfigurationInitializer.hpp"

#include <cstdlib>
#include <string>

namespace inexor {
namespace configuration {

	EnvVarConfigurationInitializer::EnvVarConfigurationInitializer(
		ConfigurationManagerPtr configuration_manager
	)
	{
		this->configuration_manager = configuration_manager;
	}

	EnvVarConfigurationInitializer::~EnvVarConfigurationInitializer()
	{
	}

	void EnvVarConfigurationInitializer::init()
	{
		for(size_t index = 0; index < EnvironmentVariables::_size(); ++index)
		{
			set_by_env_var(EnvironmentVariables::_names()[index]);
		}
	}

	void EnvVarConfigurationInitializer::set_by_env_var(std::string env_name)
	{
		std::optional<std::string> env_value = get_env_var(env_name);
		if(env_value.has_value())
		{
			configuration_manager->set("ENV_" + env_name, env_value.value());
		}
	}

	std::optional<std::string> EnvVarConfigurationInitializer::get_env_var(std::string const& env_name)
	{
		char const* env_value = std::getenv(env_name.c_str());
		return env_value == NULL ? std::nullopt : std::optional<std::string> { std::string(env_value) };
	}

}
}
