#pragma once

#include "type-system/factories/arithmetic/AddFloatFactory.hpp"
#include "type-system/factories/trigonometric/SinFactory.hpp"
#include "type-system/factories/constants/FloatConstantFactory.hpp"
#include "visual-scripting/managers/ConnectorManager.hpp"

namespace inexor {
namespace visual_scripting {

	/// @class SinTest
    /// @brief Tests for the SIN type.
	class SinTest
	{
		public:

    		USING_REACTIVE_DOMAIN(entity_system::D)

			using ConnectorManagerPtr = std::shared_ptr<ConnectorManager>;
			using FloatConstantFactoryPtr = std::shared_ptr<inexor::entity_system::type_system::FloatConstantFactory>;
			using SinFactoryPtr = std::shared_ptr<inexor::entity_system::type_system::SinFactory>;
			using AddFloatFactoryPtr = std::shared_ptr<inexor::entity_system::type_system::AddFloatFactory>;
			using LogManagerPtr = std::shared_ptr<inexor::logging::LogManager>;

			/// @brief Constructor.
			SinTest(
				ConnectorManagerPtr connector_manager,
				FloatConstantFactoryPtr float_constant_factory,
				SinFactoryPtr sin_factory,
				AddFloatFactoryPtr add_float_factory,
				LogManagerPtr log_manager
			);

			/// @brief Destructor.
			~SinTest();

			/// Initialization.
			void init();

			/// Tests for the connectors
			void run_connector_tests();

		private:

			/// The connector manager.
			ConnectorManagerPtr connector_manager;

			/// Factory for FLOAT_CONSTANT
			FloatConstantFactoryPtr float_constant_factory;

			/// Factory for SIN
			SinFactoryPtr sin_factory;

			/// Factory for ADD_FLOAT
			AddFloatFactoryPtr add_float_factory;

			/// The log manager
			LogManagerPtr log_manager;

			/// The logger name of this service.
			static constexpr char LOGGER_NAME[] = "inexor.vs.test.sin";

			/// The name of the source sin.
			static constexpr char SIN_NAME[] = "sin";

			/// The name of the target.
			static constexpr char TARGET_NAME[] = "target";
			static float TARGET_INITIAL_VALUE;

			void log_create_entity_instance(std::string entity_instance_name, float initial_value);

			void log_create_connector(std::string output_entity_instance_name, std::string output_entity_attr_name, std::string input_entity_instance_name, std::string input_entity_attr_name);

			void log_attr(std::string entity_instance_name, std::string entity_attr_name, EntityAttributeInstancePtr entity_attribute_instance);

			void log_data_value(std::string prefix, std::string entity_instance_name, std::string entity_attr_name, entity_system::DataValue data_value);

			void enable_connector_debug(ConnectorPtrOpt connector);

	};

}
}
