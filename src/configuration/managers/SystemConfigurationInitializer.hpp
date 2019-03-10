#pragma once

#include "ConfigurationManager.hpp"

#include <memory>

namespace inexor {
namespace configuration {

	using ConfigurationManagerPtr = std::shared_ptr<ConfigurationManager>;

	/// Initializes the environment variables as configuration items.
	class SystemConfigurationInitializer
	{

		public:

			SystemConfigurationInitializer(
				ConfigurationManagerPtr configuration_manager
			);

			~SystemConfigurationInitializer();

			/// Initialization
			void init();

		private:

			/// The configuration manager
			ConfigurationManagerPtr configuration_manager;

	};

}
}
