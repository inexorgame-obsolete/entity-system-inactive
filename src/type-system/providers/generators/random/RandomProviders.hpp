#pragma once

#include "type-system/providers/generators/random/RandomNextIntEntityTypeProvider.hpp"
#include "type-system/providers/generators/random/RandomNextFloatEntityTypeProvider.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	using RandomNextIntEntityTypeProviderPtr = std::shared_ptr<RandomNextIntEntityTypeProvider>;
	using RandomNextFloatEntityTypeProviderPtr = std::shared_ptr<RandomNextFloatEntityTypeProvider>;

    /// @class RandomProviders
	/// @brief Provides entity type providers for random number generators.
	class RandomProviders
	{
		public:

			/// @brief Constructs the entity type providers for random number generators.
            /// @note The dependencies of this class will be injected automatically.
            /// @param random_next_int_entity_type_provider Provides the entity type RANDOM_NEXT_INT.
            /// @param random_next_float_entity_type_provider Provides the entity type RANDOM_NEXT_FLOAT.
			RandomProviders(
				RandomNextIntEntityTypeProviderPtr random_next_int_entity_type_provider,
				RandomNextFloatEntityTypeProviderPtr random_next_float_entity_type_provider
			);

            /// Destructor.
			~RandomProviders();

			/// Initializes the entity type providers for random number generators.
			void init();

		private:

			/// Provides the entity type RANDOM_NEXT_INT.
			RandomNextIntEntityTypeProviderPtr random_next_int_entity_type_provider;

			/// Provides the entity type RANDOM_NEXT_FLOAT.
			RandomNextFloatEntityTypeProviderPtr random_next_float_entity_type_provider;

	};

}
}
}
