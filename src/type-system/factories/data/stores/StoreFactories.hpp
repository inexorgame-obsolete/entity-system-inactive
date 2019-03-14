#pragma once

#include "type-system/factories/data/stores/FloatStoreFactory.hpp"
#include "type-system/factories/data/stores/IntStoreFactory.hpp"
#include "type-system/factories/data/stores/StringStoreFactory.hpp"

#include <memory>

namespace inexor {
namespace entity_system {
namespace type_system {

	using FloatStoreFactoryPtr = std::shared_ptr<FloatStoreFactory>;
	using IntStoreFactoryPtr = std::shared_ptr<IntStoreFactory>;
	using StringStoreFactoryPtr = std::shared_ptr<StringStoreFactory>;

	/// The store factories.
	class StoreFactories
	{
		public:

			/// Constructs the store factories.
			StoreFactories(
				FloatStoreFactoryPtr float_store_factory,
				IntStoreFactoryPtr int_store_factory,
				StringStoreFactoryPtr string_store_factory
			);

			~StoreFactories();

			/// Initializes the store factories.
			void init();

		private:

			/// Factory for creating entity instances of type FLOAT_STORE.
			FloatStoreFactoryPtr float_store_factory;

			/// Factory for creating entity instances of type INT_STORE.
			IntStoreFactoryPtr int_store_factory;

			/// Factory for creating entity instances of type STRING_STORE.
			StringStoreFactoryPtr string_store_factory;

	};

}
}
}
