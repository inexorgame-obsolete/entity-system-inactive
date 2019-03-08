// Inexor entity system
// (c)2018-2019 Inexor

#pragma once

#include <mutex>
#include <optional>

#include "entity-system/model/data/container/DataContainer.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "type-system/providers/arithmetic/AddIntEntityTypeProvider.hpp"
#include "visual-scripting/managers/ProcessorRegistry.hpp"
#include "visual-scripting/model/Processor.hpp"


namespace inexor {
namespace visual_scripting {

	using namespace react;

	/// Processor for entity instances of type ADD_INT.
    class AddInt
    	: public Processor,
		  public EntityInstanceCreatedListener,
		  public EntityInstanceDeletedListener,
		  public enable_shared_from_this<AddInt>
    {

    	using AddIntEntityTypeProviderPtr = std::shared_ptr<inexor::entity_system::type_system::AddIntEntityTypeProvider>;
    	using EntityInstanceManagerPtr = std::shared_ptr<inexor::entity_system::EntityInstanceManager>;
    	using EntityInstancePtr = std::shared_ptr<inexor::entity_system::EntityInstance>;

		public:

    		USING_REACTIVE_DOMAIN(D)

    		/// @brief Constructs a new entity instance of type ADD_INT.
			AddInt(
				AddIntEntityTypeProviderPtr entity_type_provider,
				EntityInstanceManagerPtr entity_instance_manager
			);

			~AddInt();

			/// Initialization of the processor.
			void init();

			/// Called when an entity instance of type ADD_INT has been created
			void on_entity_instance_created(EntityInstancePtr entity_instance);

			/// Called when an entity instance of type ADD_INT has been deleted
			void on_entity_instance_deleted(const xg::Guid& type_GUID, const xg::Guid& inst_GUID);

			/// Initialization of the processor signals.
			void make_signals(const EntityInstancePtr& entity_instance);

		private:

			/// The entity type provider for this active component.
			AddIntEntityTypeProviderPtr entity_type_provider;

			/// The entity instance manager
			EntityInstanceManagerPtr entity_instance_manager;

			/// The signals per entity instance.
			std::unordered_map<xg::Guid, SignalT<DataValue> > signals;

    };


};
};
