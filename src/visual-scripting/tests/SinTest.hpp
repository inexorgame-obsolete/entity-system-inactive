#pragma once

#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "type-system/factories/data/constants/FloatConstantFactory.hpp"
#include "type-system/factories/generators/counters/CounterFloatFactory.hpp"
#include "type-system/factories/math/arithmetic/AddFloatFactory.hpp"
#include "visual-scripting/managers/ConnectorManager.hpp"

namespace inexor::visual_scripting {

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
    using EntityInstanceBuilderFactoryPtr = std::shared_ptr<inexor::entity_system::EntityInstanceBuilderFactory>;
    using AddFloatFactoryPtr = std::shared_ptr<inexor::entity_system::type_system::AddFloatFactory>;
    using LogManagerPtr = std::shared_ptr<inexor::logging::LogManager>;

    /// @brief Constructor.
    /// @note The dependencies of this class will be injected automatically.
    /// @param connector_manager The connector manager.
    /// @param float_constant_factory Factory for FLOAT_CONSTANT.
    /// @param counter_float_factory Factory for COUNTER_FLOAT.
    /// @param ent_inst_builder Factory for SIN.
    /// @param add_float_factory Factory for ADD_FLOAT.
    /// @param log_manager The log manager.
    SinTest(ConnectorManagerPtr connector_manager, FloatConstantFactoryPtr float_constant_factory, CounterFloatFactoryPtr counter_float_factory, EntityInstanceBuilderFactoryPtr entity_instance_builder_factory, AddFloatFactoryPtr add_float_factory, LogManagerPtr log_manager);

    /// Destructor.
    ~SinTest();

    /// Initialization.
    void init();

    /// Shutdown.
    void shutdown();

    /// Start tests.
    void start_test();

    /// Stop tests.
    void stop_test();

    /// Run tests.
    void run_test();

    private:
    /// Running state of the test.
    bool running;

    /// The connector manager.
    ConnectorManagerPtr connector_manager;

    /// Factory for FLOAT_CONSTANT.
    FloatConstantFactoryPtr float_constant_factory;

    /// Factory for COUNTER_FLOAT.
    CounterFloatFactoryPtr counter_float_factory;

    /// Entity instance builder factory.
    EntityInstanceBuilderFactoryPtr entity_instance_builder_factory;

    /// Factory for ADD_FLOAT.
    AddFloatFactoryPtr add_float_factory;

    /// The log manager.
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

    /// The name for the attribute sin_input.
    static constexpr char TYPE_SIN[] = "SIN";

    /// The name for the attribute sin_input.
    static constexpr char SIN_INPUT[] = "sin_input";

    /// The name for the attribute sin_value.
    static constexpr char SIN_VALUE[] = "sin_value";

    /// The name of the target.
    static constexpr char TARGET_NAME[] = "target";
    static float TARGET_INITIAL_VALUE;

    /// ?
    void create_instances();

    /// ?
    void create_connectors();

    /// ?
    void create_observer();

    /// @brief ?
    /// @param entity_instance_name ?
    /// @param initial_value ?
    void log_create_entity_instance(const std::string& entity_instance_name, float initial_value);

    /// @brief ?
    /// @param output_entity_instance_name ?
    /// @param output_entity_attr_name ?
    /// @param input_entity_instance_name ?
    /// @param input_entity_attr_name ?
    void log_create_connector(const std::string& output_entity_instance_name, const std::string& output_entity_attr_name, const std::string& input_entity_instance_name, const std::string& input_entity_attr_name);

    /// @brief ?
    /// @param message ?
    void log_attrs(const std::string& message);

    /// @brief ?
    /// @param entity_instance_name ?
    /// @param entity_attr_name ?
    /// @param entity_attribute_instance ?
    void log_attr(const std::string& entity_instance_name, const std::string& entity_attr_name, const EntityAttributeInstancePtr& entity_attribute_instance);

    /// @brief ?
    /// @param prefix ?
    /// @param entity_instance_name ?
    /// @param entity_attr_name ?
    /// @param data_value ?
    void log_data_value(const std::string& prefix, const std::string& entity_instance_name, const std::string& entity_attr_name, const entity_system::DataValue& data_value);
};

} // namespace inexor::visual_scripting
