#pragma once

#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/model/data/container/DataContainer.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "logging/managers/LogManager.hpp"
#include "visual-scripting/managers/ProcessorRegistry.hpp"
#include "visual-scripting/model/Processor.hpp"

namespace inexor::visual_scripting {

using namespace react;

/// @class GreaterThanIntProcessor
/// @brief Processor for entity instances of type GREATER_THAN_INT.
class GreaterThanIntProcessor : public Processor, public LifeCycleComponent, public entity_system::EntityInstanceCreatedListener, public entity_system::EntityInstanceDeletedListener, public std::enable_shared_from_this<GreaterThanIntProcessor>
{

    using EntityTypeManagerPtr = std::shared_ptr<entity_system::EntityTypeManager>;
    using EntityInstanceManagerPtr = std::shared_ptr<inexor::entity_system::EntityInstanceManager>;
    using LogManagerPtr = std::shared_ptr<inexor::logging::LogManager>;
    using EntityInstancePtr = std::shared_ptr<inexor::entity_system::EntityInstance>;

    public:
    ///
    USING_REACTIVE_DOMAIN(entity_system::D)

    /// @brief Constructs a new entity instance of type GREATER_THAN_INT.
    /// @param entity_type_manager The entity type manager.
    /// @param entity_instance_manager The entity instance manager.
    /// @param log_manager The log manager.
    GreaterThanIntProcessor(EntityTypeManagerPtr entity_type_manager, EntityInstanceManagerPtr entity_instance_manager, LogManagerPtr log_manager);

    /// Destructor.
    ~GreaterThanIntProcessor() override;

    /// Initializes the processor.
    void init() override;

    /// Returns the name of the component
    std::string get_component_name() override;

    /// Called when an entity instance of type GREATER_THAN_INT has been created.
    void on_entity_instance_created(EntityInstancePtr entity_instance) override;

    /// Called when an entity instance of type GREATER_THAN_INT has been deleted.
    void on_entity_instance_deleted(const xg::Guid &type_GUID, const xg::Guid &inst_GUID) override;

    /// Initialization of the processor signals.
    void make_signals(const EntityInstancePtr &entity_instance);

    private:
    /// Initializes the processor by registering listeners on newly created entity instances.
    void init_processor();

    /// The entity type manager.
    EntityTypeManagerPtr entity_type_manager;

    /// The entity instance manager.
    EntityInstanceManagerPtr entity_instance_manager;

    /// The log manager.
    LogManagerPtr log_manager;

    /// The signals per entity instance.
    std::unordered_map<xg::Guid, SignalT<entity_system::DataValue>> signals;

    /// The logger name of this processor.
    static constexpr char LOGGER_NAME[] = "inexor.vs.p.c.gti";
};

} // namespace inexor::visual_scripting
