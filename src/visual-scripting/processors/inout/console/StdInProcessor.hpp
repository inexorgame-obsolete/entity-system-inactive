#pragma once

#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/model/data/container/DataContainer.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "logging/managers/LogManager.hpp"
#include "visual-scripting/model/Processor.hpp"

#include "react/Event.h"

using namespace react;

namespace inexor::visual_scripting {

/// @class StdInProcessor
/// @brief Processor for entity instances of type CONSOLE_STDIN.
class StdInProcessor : public Processor, public entity_system::EntityInstanceCreatedListener, public entity_system::EntityInstanceDeletedListener, public std::enable_shared_from_this<StdInProcessor>
{

    using EntityTypeManagerPtr = std::shared_ptr<entity_system::EntityTypeManager>;
    using EntityInstanceManagerPtr = std::shared_ptr<entity_system::EntityInstanceManager>;
    using EntityInstancePtr = std::shared_ptr<entity_system::EntityInstance>;
    using LogManagerPtr = std::shared_ptr<inexor::logging::LogManager>;

    public:
    ///
    USING_REACTIVE_DOMAIN(entity_system::D)

    /// @brief Constructs a new entity instance of type CONSOLE_STDIN.
    /// @param entity_type_manager The entity type manager.
    /// @param entity_instance_manager The entity instance manager.
    StdInProcessor(EntityTypeManagerPtr entity_type_manager, EntityInstanceManagerPtr entity_instance_manager, LogManagerPtr log_manager);

    /// Destructor.
    ~StdInProcessor() override;

    /// Initialization of the processor.
    void init();

    /// @brief Called when an entity instance of type CONSOLE_STDIN has been created
    /// @param entity_instance ?
    void on_entity_instance_created(EntityInstancePtr entity_instance) override;

    /// Called when an entity instance of type CONSOLE_STDIN has been deleted
    /// @param type_GUID ?
    /// @param inst_GUID ?
    void on_entity_instance_deleted(const xg::Guid &type_GUID, const xg::Guid &inst_GUID) override;

    /// Initialization of the processor signals.
    /// @param entity_instance ?
    void make_signals(const EntityInstancePtr &entity_instance);

    private:
    /// Initializes the processor by registering listeners on newly created entity instances.
    void init_processor();

    /// The entity type manager.
    EntityTypeManagerPtr entity_type_manager;

    /// The entity instance manager.
    EntityInstanceManagerPtr entity_instance_manager;

    /// The signals per entity instance.
    std::unordered_map<xg::Guid, SignalT<entity_system::DataValue>> signals;

    /// The event sources per entity instance.
    std::unordered_map<xg::Guid, EventSourceT<std::string>> event_sources;

    /// The event sources per entity instance.
    std::unordered_map<xg::Guid, SignalT<std::string>> last_event_signals;

    /// The log manager.
    LogManagerPtr log_manager;
};

} // namespace inexor::visual_scripting
