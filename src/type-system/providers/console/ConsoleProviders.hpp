#pragma once

#include "type-system/providers/console/StdInEntityTypeProvider.hpp"
#include "type-system/providers/console/StdOutEntityTypeProvider.hpp"

#include <memory>

namespace inexor {
namespace entity_system {
namespace type_system {

	using StdInEntityTypeProviderPtr = std::shared_ptr<StdInEntityTypeProvider>;
	using StdOutEntityTypeProviderPtr = std::shared_ptr<StdOutEntityTypeProvider>;

	/// The console entity type providers.
	class ConsoleProviders
	{
		public:

			/// Constructs the console entity type providers.
			ConsoleProviders(
				StdInEntityTypeProviderPtr std_in_entity_type_provider,
				StdOutEntityTypeProviderPtr std_out_entity_type_provider
			);

			~ConsoleProviders();

			/// Initializes the console entity type providers.
			void init();

		private:

			/// Provides the entity type CONSOLE_STDIN.
			StdInEntityTypeProviderPtr std_in_entity_type_provider;

			/// Provides the entity type CONSOLE_STDOUT.
			StdOutEntityTypeProviderPtr std_out_entity_type_provider;

	};

}
}
}
