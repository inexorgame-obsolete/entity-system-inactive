#pragma once

#include "type-system/factories/data/constants/FloatConstantFactory.hpp"
#include "type-system/factories/generators/counters/CounterFloatFactory.hpp"
#include "type-system/factories/math/arithmetic/AddFloatFactory.hpp"
#include "type-system/factories/math/trigonometric/SinFactory.hpp"
#include "visual-scripting/managers/ConnectorManager.hpp"

namespace inexor {
namespace visual_scripting {

	using EntityInstancePtr = std::shared_ptr<entity_system::EntityInstance>;
	using EntityInstancePtrOpt = std::optional<EntityInstancePtr>;
	using EntityAttributeInstancePtr = std::shared_ptr<entity_system::EntityAttributeInstance>;
	using EntityAttributeInstancePtrOpt = std::optional<EntityAttributeInstancePtr>;
	using ConnectorPtr = std::shared_ptr<Connector>;
	using ConnectorPtrOpt = std::optional<ConnectorPtr>;

	/// @class SinTest
    /// @brief Tests for the SIN type.
	class SinTest
	{
		public:

    		USING_REACTIVE_DOMAIN(entity_system::D)

			using ConnectorManagerPtr = std::shared_ptr<ConnectorManager>;
			using FloatConstantFactoryPtr = std::shared_ptr<inexor::entity_system::type_system::FloatConstantFactory>;
			using CounterFloatFactoryPtr = std::shared_ptr<inexor::entity_system::type_system::CounterFloatFactory>;
			using SinFactoryPtr = std::shared_ptr<inexor::entity_system::type_system::SinFactory>;
			using AddFloatFactoryPtr = std::shared_ptr<inexor::entity_system::type_system::AddFloatFactory>;
			using LogManagerPtr = std::shared_ptr<inexor::logging::LogManager>;

			/// @brief Constructor.
			SinTest(
				ConnectorManagerPtr connector_manager,
				FloatConstantFactoryPtr float_constant_factory,
				CounterFloatFactoryPtr counter_float_factory,
				SinFactoryPtr sin_factory,
				AddFloatFactoryPtr add_float_factory,
				LogManagerPtr log_manager
			);

			/// @brief Destructor.
			~SinTest();

			/// Initialization.
			void init();

			void start_test();

			void stop_test();

			void run_test();

		private:

			bool running;

			/// The connector manager.
			ConnectorManagerPtr connector_manager;

			/// Factory for FLOAT_CONSTANT
			FloatConstantFactoryPtr float_constant_factory;

			/// Factory for COUNTER_FLOAT
			CounterFloatFactoryPtr counter_float_factory;

			/// Factory for SIN
			SinFactoryPtr sin_factory;

			/// Factory for ADD_FLOAT
			AddFloatFactoryPtr add_float_factory;

			/// The log manager
			LogManagerPtr log_manager;

			EntityInstancePtrOpt o_counter;
			EntityInstancePtrOpt o_sin;
			EntityInstancePtrOpt o_target;

			EntityAttributeInstancePtr counter_attr_count;
			EntityAttributeInstancePtr sin_attr_input;
			EntityAttributeInstancePtr sin_attr_value;
			EntityAttributeInstancePtr target_attr_value;

			ConnectorPtrOpt connector_1;
			ConnectorPtrOpt connector_2;

			ObserverT observer;

			/// The logger name of this service.
			static constexpr char LOGGER_NAME[] = "inexor.vs.test.sin";

			/// The name of the counter.
			static constexpr char COUNTER_NAME[] = "counter";

			/// The name of the sin.
			static constexpr char SIN_NAME[] = "sin";

			/// The name of the target.
			static constexpr char TARGET_NAME[] = "target";
			static float TARGET_INITIAL_VALUE;

			void create_instances();

			void create_connectors();

			void create_observer();

			void log_create_entity_instance(std::string entity_instance_name, float initial_value);

			void log_create_connector(std::string output_entity_instance_name, std::string output_entity_attr_name, std::string input_entity_instance_name, std::string input_entity_attr_name);

			void log_attrs(std::string message);

			void log_attr(std::string entity_instance_name, std::string entity_attr_name, EntityAttributeInstancePtr entity_attribute_instance);

			void log_data_value(std::string prefix, std::string entity_instance_name, std::string entity_attr_name, entity_system::DataValue data_value);

	};

}
}
