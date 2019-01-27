// Inexor entity system
// (c)2018 Inexor

#pragma once

#include "type-system/providers/stores/IntStoreEntityTypeProvider.hpp"
#include "type-system/providers/stores/FloatStoreEntityTypeProvider.hpp"
#include "type-system/providers/stores/StringStoreEntityTypeProvider.hpp"

#include "type-system/factories/stores/IntStoreFactory.hpp"
#include "type-system/factories/stores/FloatStoreFactory.hpp"
#include "type-system/factories/stores/StringStoreFactory.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace entity_system {
namespace type_system {

	/// @class StoresTypeSystemManager
    /// @brief Management of the type system.
	class StoresTypeSystemManager
	{
		public:

			/// Constructor.
			StoresTypeSystemManager(
				shared_ptr<IntStoreEntityTypeProvider> int_store_entity_type_provider,
				shared_ptr<FloatStoreEntityTypeProvider> float_store_entity_type_provider,
				shared_ptr<StringStoreEntityTypeProvider> string_store_entity_type_provider,
				shared_ptr<IntStoreFactory> int_store_factory,
				shared_ptr<FloatStoreFactory> float_store_factory,
				shared_ptr<StringStoreFactory> string_store_factory
			);

			/// Destructor.
			~StoresTypeSystemManager();

			/// Initialization
			void init();

		private:

			/// Provider for entity type INT_CONSTANT.
			shared_ptr<IntStoreEntityTypeProvider> int_store_entity_type_provider;

			/// Provider for entity type FLOAT_CONSTANT.
			shared_ptr<FloatStoreEntityTypeProvider> float_store_entity_type_provider;

			/// Provider for entity type STRING_CONSTANT.
			shared_ptr<StringStoreEntityTypeProvider> string_store_entity_type_provider;

			/// Provider for entity type INT_CONSTANT.
			shared_ptr<IntStoreFactory> int_store_factory;

			/// Provider for entity type FLOAT_CONSTANT.
			shared_ptr<FloatStoreFactory> float_store_factory;

			/// Provider for entity type STRING_CONSTANT.
			shared_ptr<StringStoreFactory> string_store_factory;

	};

}
}
}
