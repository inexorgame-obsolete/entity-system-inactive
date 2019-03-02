// Inexor entity system
// (c)2018-2019 Inexor

#pragma once

#include <iostream>

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

			/// @brief Constructor.
			IntConstantConnectorTest(
				std::shared_ptr<inexor::visual_scripting::ConnectorManager> connector_manager,
				std::shared_ptr<inexor::entity_system::type_system::IntConstantFactory> int_constant_factory,
				std::shared_ptr<inexor::entity_system::type_system::AddIntFactory> add_int_factory
			);

			/// @brief Destructor.
			~IntConstantConnectorTest();

			/// Initialization.
			void init();

			/// Tests for the connectors
			void run_connector_tests();

		private:

			/// The connector manager.
			std::shared_ptr<inexor::visual_scripting::ConnectorManager> connector_manager;

			/// Factory for INT_CONSTANT
			std::shared_ptr<inexor::entity_system::type_system::IntConstantFactory> int_constant_factory;

			/// Factory for ADD_INT
			std::shared_ptr<inexor::entity_system::type_system::AddIntFactory> add_int_factory;
	};


};
};
