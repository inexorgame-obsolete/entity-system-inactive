// Inexor entity system
// (c)2018 Inexor

#pragma once

#include <crossguid/guid.hpp>

#include "entity-system/listeners/entities/EntityInstanceCreatedListener.hpp"
#include "entity-system/listeners/entities/EntityInstanceDeletedListener.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/util/type-definitions/TypeDefinitions.hpp"
#include "visual-scripting/managers/ProcessorRegistry.hpp"
#include "visual-scripting/managers/ArithmeticProcessorManager.hpp"
#include "visual-scripting/model/Processor.hpp"

using namespace inexor::entity_system;

namespace inexor {
namespace visual_scripting {


	/// @class ProcessorManager
    /// @brief Management of the processors.
    /// The manager listens on created or deleted entity instances.
	class ProcessorManager
//		: public enable_shared_from_this<ProcessorManager>,
//		: public EntityInstanceCreatedListener,
//		  public EntityInstanceDeletedListener
	{
		public:

			/// Constructor.
			ProcessorManager(
				std::shared_ptr<ProcessorRegistry> processor_registry,
//				std::shared_ptr<inexor::entity_system::EntityInstanceManager> entity_instance_manager,
				std::shared_ptr<ArithmeticProcessorManager> arithmetic_processor_manager
			);

			/// Destructor.
			~ProcessorManager();

			/// Initialization of the ProcessorManager.
			void init();

//			/// Initializes an processor if a processor is registered
//			/// for the entity type of the created entity instance.
//			void on_entity_instance_created(std::shared_ptr<inexor::entity_system::EntityInstance> entity_instance);
//
//			void on_entity_instance_deleted(const xg::Guid& type_GUID, const xg::Guid& inst_GUID);

		private:

			/// The registry for active components
			std::shared_ptr<ProcessorRegistry> processor_registry;

//			/// The entity instance manager
//			std::shared_ptr<inexor::entity_system::EntityInstanceManager> entity_instance_manager;

			/// The manager for arithmetic processors.
			std::shared_ptr<ArithmeticProcessorManager> arithmetic_processor_manager;

	};


};
};
