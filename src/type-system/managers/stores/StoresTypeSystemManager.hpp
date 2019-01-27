// Inexor entity system
// (c)2018 Inexor

#pragma once

#include "type-system/providers/stores/IntStoreEntityTypeProvider.hpp"

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
				shared_ptr<IntStoreEntityTypeProvider> int_store_entity_type_provider
			);

			/// Destructor.
			~StoresTypeSystemManager();

			/// Initialization of the loggers
			void init();

		private:

			/// Provider for entity type INT_CONSTANT.
			shared_ptr<IntStoreEntityTypeProvider> int_store_entity_type_provider;

	};

}
}
}
