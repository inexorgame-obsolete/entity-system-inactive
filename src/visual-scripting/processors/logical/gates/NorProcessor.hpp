#pragma once

#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/model/data/container/DataContainer.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "logging/managers/LogManager.hpp"
#include "type-system/providers/logical/gates/NorEntityTypeProvider.hpp"
#include "visual-scripting/managers/ProcessorRegistry.hpp"
#include "visual-scripting/model/Processor.hpp"

namespace inexor::visual_scripting {

using namespace react;

/// @class NorProcessor
/// @brief Processor for entity instances of type NOR.
class NorProcessor : public Processor, public entity_system::EntityInstanceCreatedListener, public entity_system::EntityInstanceDeletedListener, public std::enable_shared_from_this<NorProcessor>
{

    using NorEntityTypeProviderPtr = std::shared_ptr<inexor::entity_system::type_system::NorEntityTypeProvider>;
    using EntityInstanceManagerPtr = std::shared_ptr<inexor::entity_system::EntityInstanceManager>;
    using LogManagerPtr = std::shared_ptr<inexor::logging::LogManager>;
    using EntityInstancePtr = std::shared_ptr<inexor::entity_system::EntityInstance>;

    public:
    ///
    USING_REACTIVE_DOMAIN(entity_system::D)

    /// @brief Constructs a new entity instance of type NOR.
    /// @note The dependencies of this class will be injected automatically.
    /// @param entity_type_provider ?
    /// @param entity_instance_manager ?
    /// @param log_manager ?
    NorProcessor(const NorEntityTypeProviderPtr& entity_type_provider, EntityInstanceManagerPtr entity_instance_manager, LogManagerPtr log_manager);

    /// Destructor.
    ~NorProcessor() override;

    /// Initialization of the processor.
    void init();

    /// @brief Called when an entity instance of type NOR has been created.
    /// @param entity_instance ?
    void on_entity_instance_created(EntityInstancePtr entity_instance) override;

    /// @brief Called when an entity instance of type NOR has been deleted.
    /// @param type_GUID ?
    /// @param inst_GUID ?
    void on_entity_instance_deleted(const xg::Guid &type_GUID, const xg::Guid &inst_GUID) override;

    /// @brief Initialization of the processor signals.
    /// @param entity_instance ?
    void make_signals(const EntityInstancePtr &entity_instance);

    private:
    /// The entity type provider for this active component.
    NorEntityTypeProviderPtr entity_type_provider;

    /// The entity instance manager.
    EntityInstanceManagerPtr entity_instance_manager;

    /// The log manager.
    LogManagerPtr log_manager;

    /// The signals per entity instance.
    std::unordered_map<xg::Guid, SignalT<entity_system::DataValue>> signals;

    /// The logger name of this processor.
    static constexpr char LOGGER_NAME[] = "inexor.vs.p.l.nor";
};

} // namespace inexor::visual_scripting
