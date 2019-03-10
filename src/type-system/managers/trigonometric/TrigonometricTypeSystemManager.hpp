// Inexor entity system
// (c)2018 Inexor

#pragma once

#include "type-system/providers/trigonometric/SinEntityTypeProvider.hpp"
#include "type-system/factories/trigonometric/SinFactory.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace entity_system {
namespace type_system {


	/// @class TrigonometricTypeSystemManager
    /// @brief Management of the type system.
	class TrigonometricTypeSystemManager
	{
		public:

			/// Constructor.
			TrigonometricTypeSystemManager(
				shared_ptr<SinEntityTypeProvider> sin_entity_type_provider,
				shared_ptr<SinFactory> sin_factory
			);

			/// Destructor.
			~TrigonometricTypeSystemManager();

			/// Initialization
			void init();

		private:

			/// Provider for entity type SIN.
			shared_ptr<SinEntityTypeProvider> sin_entity_type_provider;

			/// Provider for entity type SIN.
			shared_ptr<SinFactory> sin_factory;

	};


}
}
}
