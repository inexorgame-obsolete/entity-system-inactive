// Inexor entity system
// (c)2018-2019 Inexor

#pragma once

#include <mutex>
#include <optional>

#include "react/Observer.h"

#include "entity-system/providers/entities/entity-type-provider/EntityTypeProvider.hpp"
#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "entity-system/model/entities/entity-types/EntityType.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "entity-system/util/uuid/GUIDBase.hpp"
#include "entity-system/util/type-definitions/TypeDefinitions.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace visual_scripting {


	/// The base class for visual scripting processors.
    class Processor
//		: public EntityInstanceCreatedListener,
//		  public EntityInstanceDeletedListener
    {

		public:

    		USING_REACTIVE_DOMAIN(D)

    		/// @brief The constructor.
    		Processor(
    			std::shared_ptr<inexor::entity_system::EntityType> entity_type
//    			std::shared_ptr<inexor::entity_system::EntityTypeProvider> entity_type_provider,
//				std::shared_ptr<inexor::entity_system::EntityInstanceManager> entity_instance_manager
    		);

			/// @brief The destructor.
			virtual ~Processor();

//			/// The execution function of the processor.
//			virtual void execute(const shared_ptr<inexor::entity_system::EntityInstance>& entity_instance) const = 0;

//			/// Initializes an processor if a processor is registered
//			/// for the entity type of the created entity instance.
//			virtual void on_entity_instance_created(std::shared_ptr<inexor::entity_system::EntityInstance> entity_instance) = 0;

//			virtual void on_entity_instance_deleted(const xg::Guid& type_GUID, const xg::Guid& inst_GUID) = 0;
//
//			/// Initializes the entity instance with the processor execution function.
//			virtual void init_entity_instance(const shared_ptr<inexor::entity_system::EntityInstance>& entity_instance) = 0;
//
//			/// Returns the entity type to bind.
//			virtual shared_ptr<inexor::entity_system::EntityType> get_entity_type() const = 0;
			std::shared_ptr<inexor::entity_system::EntityType> get_entity_type();

		protected:

			/// The entity type provider for this processor
			std::shared_ptr<inexor::entity_system::EntityType> entity_type;

//			/// The entity type provider for this processor
//			std::shared_ptr<inexor::entity_system::EntityTypeProvider> entity_type_provider;
//
//			// The entity instance manager
//			std::shared_ptr<inexor::entity_system::EntityInstanceManager> entity_instance_manager;
//
//			/// The observers
//			std::unordered_map<xg::Guid, std::vector<ObserverT>> observers;

    };


};
};
