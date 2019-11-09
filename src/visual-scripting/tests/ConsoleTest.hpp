#pragma once

#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "visual-scripting/managers/ConnectorManager.hpp"

namespace inexor::visual_scripting {

	using ConnectorManagerPtr = std::shared_ptr<ConnectorManager>;
	using EntityInstanceBuilderFactoryPtr = std::shared_ptr<entity_system::EntityInstanceBuilderFactory>;

	using EntityInstancePtr = std::shared_ptr<entity_system::EntityInstance>;
	using EntityInstancePtrOpt = std::optional<EntityInstancePtr>;

	/// @class ConsoleTest
    /// @brief Tests for the CONSOLE_STDIN and CONSOLE_STDOUT.
	class ConsoleTest
	{
		public:

            /// 
    		USING_REACTIVE_DOMAIN(entity_system::D)

            /// @brief Constructor.
            /// @note The dependencies of this class will be injected automatically.
            /// @param connector_manager ?
            /// @param entity_instance_builder_factory ?
			ConsoleTest(
				ConnectorManagerPtr connector_manager,
				EntityInstanceBuilderFactoryPtr entity_instance_builder_factory
			);

            /// Destructor.
			~ConsoleTest();

            /// Initialisation.
			void init();

			/// Shutdown.
			void shutdown();

            /// Start test.
			void start_test();

            /// Stop test.
			void stop_test();

		private:
            
            /// Running state of the console test.
			bool running;

			ConnectorManagerPtr connector_manager;
			EntityInstanceBuilderFactoryPtr entity_instance_builder_factory;

			EntityInstancePtrOpt o_stdin;
			EntityInstancePtrOpt o_stdout;
			EntityInstancePtrOpt o_stderr;

			ConnectorPtr stdin_stdout_connector;
			ConnectorPtr stdin_stderr_connector;

	};

}
