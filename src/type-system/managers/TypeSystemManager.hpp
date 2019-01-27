// Inexor entity system
// (c)2018 Inexor

#pragma once

#include "constants/ConstantsTypeSystemManager.hpp"
#include "converters/ConvertersTypeSystemManager.hpp"
#include "stores/StoresTypeSystemManager.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace entity_system {
namespace type_system {

	/// @class TypeSystemManager
    /// @brief Management of the type system.
	class TypeSystemManager
	{
		public:

			/// Constructor.
			TypeSystemManager(
				shared_ptr<ConstantsTypeSystemManager> constants_type_system_manager,
				shared_ptr<StoresTypeSystemManager> stores_type_system_manager,
				shared_ptr<ConvertersTypeSystemManager> converters_type_system_manager
			);

			/// Destructor.
			~TypeSystemManager();

			/// Initialization
			void init();

		private:

			/// The type system manager for constants.
			shared_ptr<ConstantsTypeSystemManager> constants_type_system_manager;

			/// The type system manager for stores.
			shared_ptr<StoresTypeSystemManager> stores_type_system_manager;

			/// The type system manager for converters.
			shared_ptr<ConvertersTypeSystemManager> converters_type_system_manager;

	};

}
}
}
