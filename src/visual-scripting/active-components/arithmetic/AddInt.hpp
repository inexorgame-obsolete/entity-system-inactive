// Inexor entity system
// (c)2018-2019 Inexor

#pragma once

#include <mutex>
#include <optional>

#include "entity-system/model/entities/entity-types/EntityType.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "type-system/providers/arithmetic/AddIntEntityTypeProvider.hpp"
#include "visual-scripting/managers/ActiveComponentRegistry.hpp"
#include "visual-scripting/model/ActiveComponent.hpp"

using namespace inexor::entity_system;
using namespace inexor::entity_system::type_system;
using namespace std;

namespace inexor {
namespace visual_scripting {


	/// A base class for active components.
    class AddInt : public ActiveComponent
    {

		public:

    		/// @brief The constructor.
			AddInt(
				shared_ptr<AddIntEntityTypeProvider> entity_type_provider
			);

			/// @brief The destructor.
			~AddInt();

			/// The execution function of the active component.
			void execute(const shared_ptr<inexor::entity_system::EntityInstance>& entity_instance) const;

			/// Returns the entity type to bind.
			shared_ptr<inexor::entity_system::EntityType> get_entity_type() const;

		private:

			/// The entity type provider for this active component.
			shared_ptr<AddIntEntityTypeProvider> entity_type_provider;

    };


};
};
