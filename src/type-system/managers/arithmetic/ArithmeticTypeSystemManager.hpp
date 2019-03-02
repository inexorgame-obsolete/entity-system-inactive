// Inexor entity system
// (c)2018 Inexor

#pragma once

#include "type-system/providers/arithmetic/AddIntEntityTypeProvider.hpp"
#include "type-system/factories/arithmetic/AddIntFactory.hpp"
#include "type-system/providers/arithmetic/SinEntityTypeProvider.hpp"
#include "type-system/factories/arithmetic/SinFactory.hpp"

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
				shared_ptr<SinEntityTypeProvider> sin_entity_type_provider,
				shared_ptr<AddIntFactory> add_int_factory,
				shared_ptr<SinFactory> sin_factory
			);

			/// Destructor.
			~ArithmeticTypeSystemManager();

			/// Initialization
			void init();

		private:

			/// Provider for entity type ADD_INT.
			shared_ptr<AddIntEntityTypeProvider> add_int_entity_type_provider;

			/// Provider for entity type SIN.
			shared_ptr<SinEntityTypeProvider> sin_entity_type_provider;

			/// Provider for entity type ADD_INT.
			shared_ptr<AddIntFactory> add_int_factory;

			/// Provider for entity type SIN.
			shared_ptr<SinFactory> sin_factory;

	};


}
}
}
