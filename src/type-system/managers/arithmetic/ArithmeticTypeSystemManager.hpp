// Inexor entity system
// (c)2018 Inexor

#pragma once

#include "type-system/providers/arithmetic/AddIntEntityTypeProvider.hpp"
#include "type-system/factories/arithmetic/AddIntFactory.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace entity_system {
namespace type_system {


	/// @class ArithmeticTypeSystemManager
    /// @brief Management of the type system.
	class ArithmeticTypeSystemManager
	{
		public:

			/// Constructor.
			ArithmeticTypeSystemManager(
				shared_ptr<AddIntEntityTypeProvider> add_int_entity_type_provider,
				shared_ptr<AddIntFactory> add_int_factory
			);

			/// Destructor.
			~ArithmeticTypeSystemManager();

			/// Initialization
			void init();

		private:

			/// Provider for entity type ADD_INT.
			shared_ptr<AddIntEntityTypeProvider> add_int_entity_type_provider;

			/// Provider for entity type ADD_INT.
			shared_ptr<AddIntFactory> add_int_factory;

	};


}
}
}
