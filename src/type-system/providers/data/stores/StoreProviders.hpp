#pragma once

#include "type-system/providers/data/stores/FloatStoreEntityTypeProvider.hpp"
#include "type-system/providers/data/stores/IntStoreEntityTypeProvider.hpp"
#include "type-system/providers/data/stores/StringStoreEntityTypeProvider.hpp"

#include <memory>

namespace inexor {
namespace entity_system {
namespace type_system {

	using FloatStoreEntityTypeProviderPtr = std::shared_ptr<FloatStoreEntityTypeProvider>;
	using IntStoreEntityTypeProviderPtr = std::shared_ptr<IntStoreEntityTypeProvider>;
	using StringStoreEntityTypeProviderPtr = std::shared_ptr<StringStoreEntityTypeProvider>;

    /// @class StoreProviders
	/// @brief The store entity type providers.
	class StoreProviders
	{
		public:

			/// @brief Constructs the store entity type providers.
            /// @note The dependencies of this class will be injected automatically.
            /// @param float_store_entity_type_provider Provides the entity type FLOAT_STORE.
            /// @param int_store_entity_type_provider Provides the entity type INT_STORE.
            /// @param string_store_entity_type_provider Provides the entity type STRING_STORE.
			StoreProviders(
				FloatStoreEntityTypeProviderPtr float_store_entity_type_provider,
				IntStoreEntityTypeProviderPtr int_store_entity_type_provider,
				StringStoreEntityTypeProviderPtr string_store_entity_type_provider
			);

            /// Destructor.
			~StoreProviders();

			/// Initializes the store entity type providers.
			void init();

		private:

			/// Provides the entity type FLOAT_STORE.
			FloatStoreEntityTypeProviderPtr float_store_entity_type_provider;

			/// Provides the entity type INT_STORE.
			IntStoreEntityTypeProviderPtr int_store_entity_type_provider;

			/// Provides the entity type STRING_STORE.
			StringStoreEntityTypeProviderPtr string_store_entity_type_provider;

	};

}
}
}
