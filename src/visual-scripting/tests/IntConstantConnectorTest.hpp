#pragma once

#include "type-system/factories/arithmetic/AddIntFactory.hpp"
#include "type-system/factories/constants/IntConstantFactory.hpp"
#include "visual-scripting/managers/ConnectorManager.hpp"

namespace inexor {
namespace visual_scripting {

	/// @class IntConstantConnectorTest
    /// @brief Tests for connecting INT_CONSTANT entity instances
	class IntConstantConnectorTest
	{
		public:

			using ConnectorManagerPtr = std::shared_ptr<ConnectorManager>;
			using IntConstantFactoryPtr = std::shared_ptr<inexor::entity_system::type_system::IntConstantFactory>;
			using AddIntFactoryPtr = std::shared_ptr<inexor::entity_system::type_system::AddIntFactory>;

			/// @brief Constructor.
			IntConstantConnectorTest(
				ConnectorManagerPtr connector_manager,
				IntConstantFactoryPtr int_constant_factory,
				AddIntFactoryPtr add_int_factory
			);

			/// @brief Destructor.
			~IntConstantConnectorTest();

			/// Initialization.
			void init();

			/// Tests for the connectors
			void run_connector_tests();

		private:

			/// The connector manager.
			ConnectorManagerPtr connector_manager;

			/// Factory for INT_CONSTANT
			IntConstantFactoryPtr int_constant_factory;

			/// Factory for ADD_INT
			AddIntFactoryPtr add_int_factory;
	};

}
}
