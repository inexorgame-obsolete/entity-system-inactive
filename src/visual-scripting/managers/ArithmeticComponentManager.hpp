// Inexor entity system
// (c)2018 Inexor

#pragma once

#include <crossguid/guid.hpp>

#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/util/type-definitions/TypeDefinitions.hpp"
#include "visual-scripting/managers/ActiveComponentRegistry.hpp"
#include "visual-scripting/active-components/arithmetic/AddInt.hpp"

using namespace inexor::entity_system;
using namespace std;
using namespace xg;

namespace inexor {
namespace visual_scripting {

	/// @class ArithmeticComponentManager
    /// @brief Management of the arithmetic components.
	class ArithmeticComponentManager
	{
		public:

			/// Constructor.
			ArithmeticComponentManager(
				shared_ptr<ActiveComponentRegistry> active_component_registry,
				shared_ptr<AddInt> add_int
			);

			/// Destructor.
			~ArithmeticComponentManager();

			/// Initialization of the active components.
			void init();

		private:

			// The registry for active components.
			shared_ptr<ActiveComponentRegistry> active_component_registry;

			// Addition for integers.
			shared_ptr<AddInt> add_int;

	};


};
};
