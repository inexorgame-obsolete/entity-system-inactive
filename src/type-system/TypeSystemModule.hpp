#pragma once

#include "type-system/providers/TypeSystemProviders.hpp"
#include "type-system/factories/TypeSystemFactories.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	using TypeSystemProvidersPtr = std::shared_ptr<TypeSystemProviders>;
	using TypeSystemFactoriesPtr = std::shared_ptr<TypeSystemFactories>;

    /// The type system module
	class TypeSystemModule
	{
		public:

			/// Constructs the type system module.
			TypeSystemModule(
				TypeSystemProvidersPtr type_system_providers,
				TypeSystemFactoriesPtr type_system_factories
			);

			~TypeSystemModule();

			/// Initializes the type system module.
			void init();

		private:

			/// The providers of the type system.
			TypeSystemProvidersPtr type_system_providers;

			/// The factories of the type system.
			TypeSystemFactoriesPtr type_system_factories;

	};

}
}
}
