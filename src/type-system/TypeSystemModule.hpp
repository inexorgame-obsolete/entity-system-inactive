#pragma once

#include "type-system/factories/TypeSystemFactories.hpp"
#include "type-system/providers/TypeSystemProviders.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	using TypeSystemFactoriesPtr = std::shared_ptr<TypeSystemFactories>;
	using TypeSystemProvidersPtr = std::shared_ptr<TypeSystemProviders>;

    /// The type system module
	class TypeSystemModule
	{
		public:

			/// Constructs the type system module.
			TypeSystemModule(
				TypeSystemFactoriesPtr type_system_factories,
				TypeSystemProvidersPtr type_system_providers
			);

			~TypeSystemModule();

			/// Initializes the type system module.
			void init();

		private:

			/// The factories of the type system.
			TypeSystemFactoriesPtr type_system_factories;

			/// The providers of the type system.
			TypeSystemProvidersPtr type_system_providers;

	};

}
}
}
