// Inexor entity system
// (c)2018-2019 Inexor

#pragma once

#include <mutex>
#include <optional>

//#include "react/Domain.h"
//#include "react/Observer.h"

//#include "react/Algorithm.h"
//#include "react/Event.h"
//#include "react/Signal.h"

#include "entity-system/model/data/container/DataContainer.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/model/entities/entity-types/EntityType.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "type-system/providers/arithmetic/AddIntEntityTypeProvider.hpp"
#include "visual-scripting/managers/ProcessorRegistry.hpp"
#include "visual-scripting/model/Processor.hpp"

using namespace react;

namespace inexor {
namespace visual_scripting {


	/// A base class for active components.
    class AddInt
    	: public Processor,
		  public EntityInstanceCreatedListener,
		  public EntityInstanceDeletedListener,
		  public enable_shared_from_this<AddInt>
    {

		public:

    		USING_REACTIVE_DOMAIN(D)

    		/// @brief The constructor.
			AddInt(
				std::shared_ptr<inexor::entity_system::type_system::AddIntEntityTypeProvider> entity_type_provider,
				std::shared_ptr<inexor::entity_system::EntityInstanceManager> entity_instance_manager
			);

			/// @brief The destructor.
			~AddInt();

			/// Initialization of the processor.
			void init();

//			/// The execution function of the active component.
//			void execute(const std::shared_ptr<inexor::entity_system::EntityInstance>& entity_instance) const;

			/// Initializes the entity instance with the processor execution function.
//			void init_entity_instance(const std::shared_ptr<inexor::entity_system::EntityInstance>& entity_instance) const;

//			/// The execution function.
//			static inexor::entity_system::DataValue add(inexor::entity_system::DataValue augend, inexor::entity_system::DataValue addend);

			/// Returns the entity type to bind.
//			std::shared_ptr<inexor::entity_system::EntityType> get_entity_type();
//			std::shared_ptr<inexor::entity_system::EntityType> get_entity_type() const
//			{
//				return entity_type_provider->get_type();
//			}

			/// Initializes an processor if a processor is registered
			/// for the entity type of the created entity instance.
			void on_entity_instance_created(std::shared_ptr<inexor::entity_system::EntityInstance> entity_instance);

			void on_entity_instance_deleted(const xg::Guid& type_GUID, const xg::Guid& inst_GUID);

			void connect(const std::shared_ptr<inexor::entity_system::EntityInstance>& entity_instance);

		private:

			/// The entity type provider for this active component.
			std::shared_ptr<inexor::entity_system::type_system::AddIntEntityTypeProvider> entity_type_provider;

			// The entity instance manager
			std::shared_ptr<inexor::entity_system::EntityInstanceManager> entity_instance_manager;

			std::unordered_map<std::shared_ptr<inexor::entity_system::EntityInstance>, SignalT<DataValue> > signals;

    };


};
};
