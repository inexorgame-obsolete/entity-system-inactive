#pragma once

#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/model/data/container/DataContainer.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "logging/managers/LogManager.hpp"
#include "type-system/providers/generators/timers/TimerTickEntityTypeProvider.hpp"
#include "visual-scripting/managers/ProcessorRegistry.hpp"
#include "visual-scripting/model/Processor.hpp"

#include "react/Event.h"

using namespace react;

namespace inexor::visual_scripting {

using TimerTickEntityTypeProviderPtr = std::shared_ptr<entity_system::type_system::TimerTickEntityTypeProvider>;
using EntityInstanceManagerPtr = std::shared_ptr<entity_system::EntityInstanceManager>;
using LogManagerPtr = std::shared_ptr<inexor::logging::LogManager>;
using EntityInstancePtr = std::shared_ptr<entity_system::EntityInstance>;

/// @class TimerTickProcessor
/// @brief Processor which listens on the creation of entity instances of type TIMER_TICK.
/// @note Newly created entity instances of type TIMER_TICK will be initialized by connecting
/// the input attributes with a calculation function and the result with the output attribute.
class TimerTickProcessor : public Processor, public entity_system::EntityInstanceCreatedListener, public entity_system::EntityInstanceDeletedListener, public std::enable_shared_from_this<TimerTickProcessor>
{

    public:
    ///
    USING_REACTIVE_DOMAIN(entity_system::D)

    /// @brief Constructs the TIMER_TICK processor which listens on the creation of entity instances of type TIMER_TICK.
    /// @note Newly created entity instances of type TIMER_TICK will be initialized by connecting the input attributes with
    /// a calculation function and the result with the output attribute.
    /// @note The dependencies of this class will be injected automatically.
    /// @param entity_type_provider The entity type provider for this processor.
    /// @param entity_instance_manager The entity instance manager.
    /// @param log_manager The log manager.
    TimerTickProcessor(const TimerTickEntityTypeProviderPtr &entity_type_provider, EntityInstanceManagerPtr entity_instance_manager, LogManagerPtr log_manager);

    /// Destructor.
    ~TimerTickProcessor() override;

    /// Initializes the TIMER_TICK processor by registering listeners on newly created entity instances of type TIMER_TICK.
    void init();

    /// @brief Called when an entity instance of type TIMER_TICK has been created.
    /// @param entity_instance ?
    void on_entity_instance_created(EntityInstancePtr entity_instance) override;

    /// @brief Called when an entity instance of type TIMER_TICK has been deleted.
    /// @param type_GUID ?
    /// @param inst_GUID ?
    void on_entity_instance_deleted(const xg::Guid &type_GUID, const xg::Guid &inst_GUID) override;

    /// @brief Initialization of the processor signals.
    /// @param entity_instance ?
    void make_signals(const EntityInstancePtr &entity_instance);

    private:
    /// The entity type provider for this processor.
    TimerTickEntityTypeProviderPtr entity_type_provider;

    /// The entity instance manager.
    EntityInstanceManagerPtr entity_instance_manager;

    /// The log manager.
    LogManagerPtr log_manager;

    /// The signals per entity instance.
    std::unordered_map<xg::Guid, SignalT<entity_system::DataValue>> signals;

    /// The event sources per entity instance.
    std::unordered_map<xg::Guid, EventSourceT<int>> event_sources;

    /// The ticks per entity instance.
    std::unordered_map<xg::Guid, SignalT<int>> ticks;

    /// The logger name of this processor.
    static constexpr char LOGGER_NAME[] = "inexor.vs.g.t.tick";
};

} // namespace inexor::visual_scripting
