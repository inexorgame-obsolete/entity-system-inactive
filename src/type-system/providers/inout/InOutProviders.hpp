#pragma once

#include "type-system/providers/inout/console/ConsoleProviders.hpp"
#include "type-system/providers/inout/logger/LoggerProviders.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	using ConsoleProvidersPtr = std::shared_ptr<ConsoleProviders>;
	using LoggerProvidersPtr = std::shared_ptr<LoggerProviders>;

	/// The providers for input and output.
	class InOutProviders
	{
		public:

			/// Constructs the providers for input and output.
			InOutProviders(
				ConsoleProvidersPtr console_providers,
				LoggerProvidersPtr logger_providers
			);

			~InOutProviders();

			/// Initializes the providers for input and output.
			void init();

		private:

			/// The providers for the console.
			ConsoleProvidersPtr console_providers;

			/// The providers for loggers.
			LoggerProvidersPtr logger_providers;

	};

}
}
}
