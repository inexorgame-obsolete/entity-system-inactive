#pragma once

#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/model/data/container/DataContainer.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "logging/managers/LogManager.hpp"
#include "type-system/providers/inout/console/StdOutEntityTypeProvider.hpp"
#include "visual-scripting/model/Processor.hpp"

namespace inexor::visual_scripting {

using namespace react;

/// @class StdOutProcessor
/// @brief Processor for entity instances of type CONSOLE_STDOUT.
class StdOutProcessor : public Processor, public entity_system::EntityInstanceCreatedListener, public entity_system::EntityInstanceDeletedListener, public std::enable_shared_from_this<StdOutProcessor>
{

    using StdOutEntityTypeProviderPtr = std::shared_ptr<entity_system::type_system::StdOutEntityTypeProvider>;
    using EntityInstanceManagerPtr = std::shared_ptr<entity_system::EntityInstanceManager>;
    using EntityInstancePtr = std::shared_ptr<entity_system::EntityInstance>;
    using LogManagerPtr = std::shared_ptr<inexor::logging::LogManager>;

    public:
    ///
    USING_REACTIVE_DOMAIN(entity_system::D)

    /// @brief Constructs a new entity instance of type CONSOLE_STDOUT.
    /// @note The dependencies of this class will be injected automatically.
    /// @param entity_type_provider Provides the entity type CONSOLE_STDOUT.
    /// @param entity_instance_manager The entity instance manager.
    StdOutProcessor(const StdOutEntityTypeProviderPtr& entity_type_provider, EntityInstanceManagerPtr entity_instance_manager, LogManagerPtr log_manager);

    /// Destructor
    ~StdOutProcessor() override;

    /// Initialization of the processor.
    void init();

    /// @brief Called when an entity instance of type CONSOLE_STDOUT has been created
    /// @param entity_instance ?
    void on_entity_instance_created(EntityInstancePtr entity_instance) override;

    /// @brief Called when an entity instance of type CONSOLE_STDOUT has been deleted
    /// @param type_GUID ?
    /// @param inst_GUID ?
    void on_entity_instance_deleted(const xg::Guid &type_GUID, const xg::Guid &inst_GUID) override;

    /// @brief Initialization of the processor signals.
    /// @param entity_instance
    void make_signals(const EntityInstancePtr &entity_instance);

    private:
    /// Provides the entity type CONSOLE_STDOUT.
    StdOutEntityTypeProviderPtr entity_type_provider;

    /// The entity instance manager.
    EntityInstanceManagerPtr entity_instance_manager;

    /// The signals per entity instance.
    std::unordered_map<xg::Guid, ObserverT> observers;

    /// The log manager.
    LogManagerPtr log_manager;
};

} // namespace inexor::visual_scripting
