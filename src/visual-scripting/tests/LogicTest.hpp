#pragma once

#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "type-system/factories/logical/comparison/EqualsStringFactory.hpp"
#include "type-system/providers/inout/console/StdInEntityTypeProvider.hpp"
#include "type-system/providers/logical/comparison/EqualsStringEntityTypeProvider.hpp"
#include "visual-scripting/managers/ConnectorManager.hpp"

namespace inexor {
namespace visual_scripting {

	using ConnectorManagerPtr = std::shared_ptr<ConnectorManager>;
	using StdInEntityTypeProvider = entity_system::type_system::StdInEntityTypeProvider;
	using StdInEntityTypeProviderPtr = std::shared_ptr<StdInEntityTypeProvider>;
	using EqualsStringEntityTypeProvider = entity_system::type_system::EqualsStringEntityTypeProvider;
	using EqualsStringEntityTypeProviderPtr = std::shared_ptr<EqualsStringEntityTypeProvider>;
	using EntityInstanceBuilderFactoryPtr = std::shared_ptr<entity_system::EntityInstanceBuilderFactory>;
	using Builder = std::shared_ptr<entity_system::EntityInstanceBuilder>;

	using EntityInstance = std::shared_ptr<entity_system::EntityInstance>;
	using EntityInstanceOpt = std::optional<EntityInstance>;
	using Attribute = std::shared_ptr<entity_system::EntityAttributeInstance>;
	using AttributeOpt = std::optional<Attribute>;
	using ConnectorPtr = std::shared_ptr<Connector>;
	using ConnectorPtrOpt = std::optional<ConnectorPtr>;

	using DataType = entity_system::DataType;
	using DataValue = entity_system::DataValue;

	using EqualsStringFactoryPtr = std::shared_ptr<entity_system::type_system::EqualsStringFactory>;

	/// @class LogicTest
    /// @brief Tests for the logical operations.
	class LogicTest
	{
		public:

            /// 
    		USING_REACTIVE_DOMAIN(entity_system::D)

            /// @brief Constructor.
            /// @note The dependencies of this class will be injected automatically.
            /// @param connector_manager ?
            /// @param stdin_entity_type_provider ?
            /// @param equals_string_factory ?
            /// @param entity_instance_builder_factory ?
			LogicTest(
				ConnectorManagerPtr connector_manager,
				StdInEntityTypeProviderPtr stdin_entity_type_provider,
				EqualsStringFactoryPtr equals_string_factory,
				EntityInstanceBuilderFactoryPtr entity_instance_builder_factory
			);

            /// Destructor.
			~LogicTest();

            /// ?
			void init();

			/// Shutdown.
			void shutdown();

            /// ?
			void start_test();

            /// ?
			void stop_test();

            /// ?
			void run_test();

		private:

            /// The running state of the logic test.
			bool running;

			/// ?
            ConnectorManagerPtr connector_manager;
            
            /// ?
			StdInEntityTypeProviderPtr stdin_entity_type_provider;

            /// ?
			EqualsStringFactoryPtr equals_string_factory;

            /// ?
			EntityInstanceBuilderFactoryPtr entity_instance_builder_factory;

	};

}
}
