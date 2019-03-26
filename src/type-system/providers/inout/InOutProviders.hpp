#pragma once

#include "type-system/providers/inout/console/ConsoleProviders.hpp"
#include "type-system/providers/inout/logger/LoggerProviders.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	using ConsoleProvidersPtr = std::shared_ptr<ConsoleProviders>;
	using LoggerProvidersPtr = std::shared_ptr<LoggerProviders>;

    /// @class InOutProviders
	/// @brief The providers for input and output.
	class InOutProviders
	{
		public:

			/// @brief Constructs the providers for input and output.
            /// @note The dependencies of this class will be injected automatically.
            /// @param console_providers The providers for the console.
            /// @param logger_providers The providers for loggers.
			InOutProviders(
				ConsoleProvidersPtr console_providers,
				LoggerProvidersPtr logger_providers
			);

            /// Destructor.
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
