#pragma once

#include "entity-system/model/data/container/DataContainer.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "type-system/providers/generators/random/RandomNextIntEntityTypeProvider.hpp"
#include "visual-scripting/managers/ProcessorRegistry.hpp"
#include "visual-scripting/model/Processor.hpp"
#include "logging/managers/LogManager.hpp"

#include "react/Event.h"

#include <random>

using namespace react;

namespace inexor {
namespace visual_scripting {

	using RandomNextIntEntityTypeProviderPtr = std::shared_ptr<entity_system::type_system::RandomNextIntEntityTypeProvider>;
	using EntityInstanceManagerPtr = std::shared_ptr<entity_system::EntityInstanceManager>;
	using LogManagerPtr = std::shared_ptr<inexor::logging::LogManager>;
	using EntityInstancePtr = std::shared_ptr<entity_system::EntityInstance>;

	/// Processor which listens on the creation of entity instances
	/// of type RANDOM_NEXT_INT. Newly created entity instances of type RANDOM_NEXT_INT
	/// will be initialized by connecting the input attributes with
	/// a calculation function and the result with the output
	/// attribute.
    class RandomNextIntProcessor
    	: public Processor,
		  public entity_system::EntityInstanceCreatedListener,
		  public entity_system::EntityInstanceDeletedListener,
		  public std::enable_shared_from_this<RandomNextIntProcessor>
    {

		public:

    		USING_REACTIVE_DOMAIN(entity_system::D)

    		/// Constructs the RANDOM_NEXT_INT processor which listens on the creation
    		/// of entity instances of type RANDOM_NEXT_INT. Newly created entity
    		/// instances of type RANDOM_NEXT_INT will be initialized by connecting the
    		/// input attributes with a calculation function and the result
    		/// with the output attribute.
			RandomNextIntProcessor(
				RandomNextIntEntityTypeProviderPtr entity_type_provider,
				EntityInstanceManagerPtr entity_instance_manager,
				LogManagerPtr log_manager
			);

			~RandomNextIntProcessor();

			/// Initializes the RANDOM_NEXT_INT processor by registering listeners
			/// on newly created entity instances of type RANDOM_NEXT_INT.
			void init();

			/// Called when an entity instance of type RANDOM_NEXT_INT has been created
			void on_entity_instance_created(EntityInstancePtr entity_instance);

			/// Called when an entity instance of type RANDOM_NEXT_INT has been deleted
			void on_entity_instance_deleted(const xg::Guid& type_GUID, const xg::Guid& inst_GUID);

			/// Initialization of the processor signals.
			void make_signals(const EntityInstancePtr& entity_instance);

		private:

			/// The entity type provider for this processor
			RandomNextIntEntityTypeProviderPtr entity_type_provider;

			/// The entity instance manager
			EntityInstanceManagerPtr entity_instance_manager;

			/// The log manager
			LogManagerPtr log_manager;

			/// The signals per entity instance.
			std::unordered_map<xg::Guid, SignalT<entity_system::DataValue> > signals;

			/// The random device.
			std::random_device random_device;

			/// The logger name of this processor.
			static constexpr char LOGGER_NAME[] = "inexor.vs.g.random.nextint";

    };

}
}
