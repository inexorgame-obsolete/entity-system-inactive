// Inexor entity system
// (c)2018 Inexor

#pragma once

#include <crossguid/guid.hpp>

#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/util/type-definitions/TypeDefinitions.hpp"
#include "visual-scripting/managers/ActiveComponentRegistry.hpp"
#include "visual-scripting/managers/ArithmeticComponentManager.hpp"
#include "visual-scripting/model/ActiveComponent.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace visual_scripting {

	/// @class ActiveComponentManager
    /// @brief Management of the active components.
	class ActiveComponentManager
	{
		public:

			/// Constructor.
			ActiveComponentManager(
				shared_ptr<ActiveComponentRegistry> active_component_registry,
				shared_ptr<ArithmeticComponentManager> arithmetic_component_manager
			);

			/// Destructor.
			~ActiveComponentManager();

			/// Initialization of the ActiveComponentManager.
			void init();

		private:

			/// The registry for active components
			shared_ptr<ActiveComponentRegistry> active_component_registry;

			/// The active components for arithmetic operations.
			shared_ptr<ArithmeticComponentManager> arithmetic_component_manager;

	};


};
};
