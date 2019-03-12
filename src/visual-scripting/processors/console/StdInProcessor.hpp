#pragma once

#include "entity-system/model/data/container/DataContainer.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "type-system/providers/console/StdInEntityTypeProvider.hpp"
#include "visual-scripting/model/Processor.hpp"

#include "react/Event.h"

using namespace react;

namespace inexor {
namespace visual_scripting {

	/// Processor for entity instances of type CONSOLE_STDIN.
    class StdInProcessor
    	: public Processor,
		  public entity_system::EntityInstanceCreatedListener,
		  public entity_system::EntityInstanceDeletedListener,
		  public std::enable_shared_from_this<StdInProcessor>
    {

    	using StdInEntityTypeProviderPtr = std::shared_ptr<entity_system::type_system::StdInEntityTypeProvider>;
    	using EntityInstanceManagerPtr = std::shared_ptr<entity_system::EntityInstanceManager>;
    	using EntityInstancePtr = std::shared_ptr<entity_system::EntityInstance>;

		public:

    		USING_REACTIVE_DOMAIN(entity_system::D)

    		/// @brief Constructs a new entity instance of type CONSOLE_STDIN.
			StdInProcessor(
				StdInEntityTypeProviderPtr entity_type_provider,
				EntityInstanceManagerPtr entity_instance_manager
			);

			~StdInProcessor();

			/// Initialization of the processor.
			void init();

			/// Called when an entity instance of type CONSOLE_STDIN has been created
			void on_entity_instance_created(EntityInstancePtr entity_instance);

			/// Called when an entity instance of type CONSOLE_STDIN has been deleted
			void on_entity_instance_deleted(const xg::Guid& type_GUID, const xg::Guid& inst_GUID);

			/// Initialization of the processor signals.
			void make_signals(const EntityInstancePtr& entity_instance);

		private:

			/// Provides the entity type CONSOLE_STDIN.
			StdInEntityTypeProviderPtr entity_type_provider;

			/// The entity instance manager
			EntityInstanceManagerPtr entity_instance_manager;

			/// The signals per entity instance.
			std::unordered_map<xg::Guid, SignalT<entity_system::DataValue> > signals;

			/// The event sources per entity instance.
			std::unordered_map<xg::Guid, EventSourceT<std::string> > event_sources;

			/// The event sources per entity instance.
			std::unordered_map<xg::Guid, SignalT<std::string> > last_event_signals;

    };

}
}