#include "SystemConfigurationInitializer.hpp"

namespace inexor {
namespace configuration {

	SystemConfigurationInitializer::SystemConfigurationInitializer(
		ConfigurationManagerPtr configuration_manager
	)
	{
		this->configuration_manager = configuration_manager;
	}

	SystemConfigurationInitializer::~SystemConfigurationInitializer()
	{
	}

	void SystemConfigurationInitializer::init()
	{
#ifdef _WIN32
		configuration_manager->set("PID", _getpid());
#else
		configuration_manager->set("PID", getpid());
#endif
		configuration_manager->set("SYS_NUM_CONCURRENT_THREADS", (int) std::thread::hardware_concurrency());
	}


}
}
