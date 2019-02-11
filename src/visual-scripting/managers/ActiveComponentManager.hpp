// Inexor entity system
// (c)2018 Inexor

#pragma once

#include <crossguid/guid.hpp>

#include "entity-system/listeners/entities/EntityInstanceCreatedListener.hpp"
#include "entity-system/listeners/entities/EntityInstanceDeletedListener.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/util/type-definitions/TypeDefinitions.hpp"
#include "visual-scripting/managers/ActiveComponentRegistry.hpp"
#include "visual-scripting/managers/ArithmeticComponentManager.hpp"
#include "visual-scripting/model/ActiveComponent.hpp"

using namespace inexor::entity_system;

namespace inexor {
namespace visual_scripting {

	/// @class ActiveComponentManager
    /// @brief Management of the active components.
    /// The manager listens on created or deleted entity instances.
	class ActiveComponentManager
		: public enable_shared_from_this<ActiveComponentManager>,
		  public EntityInstanceCreatedListener,
		  public EntityInstanceDeletedListener
	{
		public:

			/// Constructor.
			ActiveComponentManager(
				std::shared_ptr<ActiveComponentRegistry> active_component_registry,
				std::shared_ptr<ArithmeticComponentManager> arithmetic_component_manager
			);

			/// Destructor.
			~ActiveComponentManager();

			/// Initialization of the ActiveComponentManager.
			void init();

			void on_entity_instance_created(std::shared_ptr<inexor::entity_system::EntityInstance> entity_instance);
			void on_entity_instance_deleted(const xg::Guid& type_GUID, const xg::Guid& inst_GUID);

		private:

			/// The registry for active components
			std::shared_ptr<ActiveComponentRegistry> active_component_registry;

			/// The active components for arithmetic operations.
			std::shared_ptr<ArithmeticComponentManager> arithmetic_component_manager;

	};


};
};
