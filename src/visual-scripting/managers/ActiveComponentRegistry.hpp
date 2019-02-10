// Inexor entity system
// (c)2018 Inexor

#pragma once

#include <crossguid/guid.hpp>

#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/util/type-definitions/TypeDefinitions.hpp"
#include "visual-scripting/model/ActiveComponent.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace visual_scripting {

	/// @class ActiveComponentRegistry
    /// @brief Registry of the active components.
	class ActiveComponentRegistry
	{
		public:

			/// Constructor.
			ActiveComponentRegistry();

			/// Destructor.
			~ActiveComponentRegistry();

			/// Initialization of the active components.
			void init();

			/// @brief Registers an active component.
			void register_active_component(const shared_ptr<ActiveComponent>& active_component);

			/// @brief Returns the active component by entity type.
			optional<shared_ptr<ActiveComponent>> get_active_component_by_entity_type(const ENT_TYPE& entity_type);

		private:

			/// Stores the active component per entity type.
			unordered_map<ENT_TYPE, shared_ptr<ActiveComponent>> active_components;

	};


};
};
