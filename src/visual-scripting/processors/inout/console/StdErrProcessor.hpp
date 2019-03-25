#pragma once

#include "entity-system/model/data/container/DataContainer.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "type-system/providers/inout/console/StdErrEntityTypeProvider.hpp"
#include "visual-scripting/model/Processor.hpp"

namespace inexor {
namespace visual_scripting {

	using namespace react;

    /// @class StdErrProcessor
	/// @brief Processor for entity instances of type CONSOLE_STDERR.
    class StdErrProcessor
    	: public Processor,
		  public entity_system::EntityInstanceCreatedListener,
		  public entity_system::EntityInstanceDeletedListener,
		  public std::enable_shared_from_this<StdErrProcessor>
    {

    	using StdErrEntityTypeProviderPtr = std::shared_ptr<entity_system::type_system::StdErrEntityTypeProvider>;
    	using EntityInstanceManagerPtr = std::shared_ptr<entity_system::EntityInstanceManager>;
    	using EntityInstancePtr = std::shared_ptr<entity_system::EntityInstance>;

		public:

            /// 
    		USING_REACTIVE_DOMAIN(entity_system::D)

    		/// @brief Constructs a new entity instance of type CONSOLE_STDERR.
            /// @note The dependencies of this class will be injected automatically.
            /// @param entity_type_provider Provides the entity type CONSOLE_STDERR.
            /// @param entity_instance_manager The signals per entity instance.
			StdErrProcessor(
				StdErrEntityTypeProviderPtr entity_type_provider,
				EntityInstanceManagerPtr entity_instance_manager
			);
    
            /// Destructor.
			~StdErrProcessor();

			/// Initialization of the processor.
			void init();

			/// Called when an entity instance of type CONSOLE_STDERR has been created.
            /// @param entity_instance ?
			void on_entity_instance_created(EntityInstancePtr entity_instance);

			/// Called when an entity instance of type CONSOLE_STDERR has been deleted.
            /// @param type_GUID ?
            /// @param inst_GUID ?
			void on_entity_instance_deleted(const xg::Guid& type_GUID, const xg::Guid& inst_GUID);

			/// Initialization of the processor signals.
            /// @param entity_instance ?
			void make_signals(const EntityInstancePtr& entity_instance);

		private:

			/// Provides the entity type CONSOLE_STDERR.
			StdErrEntityTypeProviderPtr entity_type_provider;

			/// The entity instance manager.
			EntityInstanceManagerPtr entity_instance_manager;

			/// The signals per entity instance.
			std::unordered_map<xg::Guid, ObserverT> observers;

    };

}
}
