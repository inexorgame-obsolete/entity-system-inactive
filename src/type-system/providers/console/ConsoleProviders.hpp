#pragma once

#include "type-system/providers/console/StdInEntityTypeProvider.hpp"
#include "type-system/providers/console/StdOutEntityTypeProvider.hpp"
#include "type-system/providers/console/StdErrEntityTypeProvider.hpp"

#include <memory>

namespace inexor {
namespace entity_system {
namespace type_system {

	using StdInEntityTypeProviderPtr = std::shared_ptr<StdInEntityTypeProvider>;
	using StdOutEntityTypeProviderPtr = std::shared_ptr<StdOutEntityTypeProvider>;
	using StdErrEntityTypeProviderPtr = std::shared_ptr<StdErrEntityTypeProvider>;

	/// The console entity type providers.
	class ConsoleProviders
	{
		public:

			/// Constructs the entity type providers for the console handling.
			ConsoleProviders(
				StdInEntityTypeProviderPtr std_in_entity_type_provider,
				StdOutEntityTypeProviderPtr std_out_entity_type_provider,
				StdErrEntityTypeProviderPtr std_err_entity_type_provider
			);

			~ConsoleProviders();

			/// Initializes the console entity type providers for the console handling.
			void init();

		private:

			/// Provides the entity type CONSOLE_STDIN.
			StdInEntityTypeProviderPtr std_in_entity_type_provider;

			/// Provides the entity type CONSOLE_STDOUT.
			StdOutEntityTypeProviderPtr std_out_entity_type_provider;

			/// Provides the entity type CONSOLE_STDERR.
			StdErrEntityTypeProviderPtr std_err_entity_type_provider;

	};

}
}
}
