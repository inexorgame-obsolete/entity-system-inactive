// Inexor entity system
// (c)2018-2019 Inexor

#pragma once

#include <chrono>
#include <mutex>
#include <optional>

#include "react/Event.h"

#include "entity-system/model/data/container/DataContainer.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/model/entities/entity-types/EntityType.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "type-system/providers/arithmetic/SinEntityTypeProvider.hpp"
#include "visual-scripting/managers/ProcessorRegistry.hpp"
#include "visual-scripting/model/Processor.hpp"

using namespace react;
using namespace std::chrono;

namespace inexor {
namespace visual_scripting {


	/// A base class for active components.
    class Sin
    	: public Processor,
		  public EntityInstanceCreatedListener,
		  public EntityInstanceDeletedListener,
		  public enable_shared_from_this<Sin>
    {

		public:

    		USING_REACTIVE_DOMAIN(D)

    		/// @brief The constructor.
			Sin(
				std::shared_ptr<inexor::entity_system::type_system::SinEntityTypeProvider> entity_type_provider,
				std::shared_ptr<inexor::entity_system::EntityInstanceManager> entity_instance_manager
			);

			/// @brief The destructor.
			~Sin();

			/// Initialization of the processor.
			void init();

			/// Called when an entity instance of type SIN has been created
			void on_entity_instance_created(std::shared_ptr<inexor::entity_system::EntityInstance> entity_instance);

			/// Called when an entity instance of type SIN has been deleted
			void on_entity_instance_deleted(const xg::Guid& type_GUID, const xg::Guid& inst_GUID);

			/// Initialization of the
			void connect(const std::shared_ptr<inexor::entity_system::EntityInstance>& entity_instance);

		private:

			/// The entity type provider for this active component.
			std::shared_ptr<inexor::entity_system::type_system::SinEntityTypeProvider> entity_type_provider;

			/// The entity instance manager
			std::shared_ptr<inexor::entity_system::EntityInstanceManager> entity_instance_manager;

			/// The signals per entity instance.
			std::unordered_map<xg::Guid, SignalT<DataValue> > signals;

			/// The event sources per entity instance.
			std::unordered_map<xg::Guid, EventSourceT<int> > event_sources;

			/// The event sources per entity instance.
			std::unordered_map<xg::Guid, SignalT<int> > current_time_iterators;
    };


};
};
