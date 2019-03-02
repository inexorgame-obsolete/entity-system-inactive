// Inexor entity system
// (c)2018-2019 Inexor

#pragma once

#include <iostream>

#include "type-system/factories/arithmetic/SinFactory.hpp"
#include "type-system/factories/constants/FloatConstantFactory.hpp"
#include "visual-scripting/managers/ConnectorManager.hpp"

namespace inexor {
namespace visual_scripting {


	/// @class SinTest
    /// @brief Tests for the SIN type.
	class SinTest
	{
		public:

			/// @brief Constructor.
			SinTest(
				std::shared_ptr<inexor::visual_scripting::ConnectorManager> connector_manager,
				std::shared_ptr<inexor::entity_system::type_system::FloatConstantFactory> float_constant_factory,
				std::shared_ptr<inexor::entity_system::type_system::SinFactory> sin_factory
			);

			/// @brief Destructor.
			~SinTest();

			/// Initialization.
			void init();

			/// Tests for the connectors
			void run_connector_tests();

		private:

			/// The connector manager.
			std::shared_ptr<inexor::visual_scripting::ConnectorManager> connector_manager;

			/// Factory for FLOAT_CONSTANT
			std::shared_ptr<inexor::entity_system::type_system::FloatConstantFactory> float_constant_factory;

			/// Factory for SIN
			std::shared_ptr<inexor::entity_system::type_system::SinFactory> sin_factory;
	};


};
};
