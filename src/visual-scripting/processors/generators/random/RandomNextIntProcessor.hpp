#pragma once

#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/model/data/container/DataContainer.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "logging/managers/LogManager.hpp"
#include "visual-scripting/managers/ProcessorRegistry.hpp"
#include "visual-scripting/model/Processor.hpp"

#include "react/Event.h"

#include <random>

using namespace react;

namespace inexor::visual_scripting {

/// @class RandomNextIntProcessor
/// @brief Processor which listens on the creation of entity instances of type RANDOM_NEXT_INT.
/// @note Newly created entity instances of type RANDOM_NEXT_INT will be initialized by connecting the input
/// attributes with a calculation function and the result with the output attribute.
class RandomNextIntProcessor : public Processor, public entity_system::EntityInstanceCreatedListener, public entity_system::EntityInstanceDeletedListener, public std::enable_shared_from_this<RandomNextIntProcessor>
{

    using EntityTypeManagerPtr = std::shared_ptr<entity_system::EntityTypeManager>;
    using EntityInstanceManagerPtr = std::shared_ptr<entity_system::EntityInstanceManager>;
    using LogManagerPtr = std::shared_ptr<inexor::logging::LogManager>;
    using EntityInstancePtr = std::shared_ptr<entity_system::EntityInstance>;

    public:
    ///
    USING_REACTIVE_DOMAIN(entity_system::D)

    /// @brief Constructs the RANDOM_NEXT_INT processor which listens on the creation of entity instances of type RANDOM_NEXT_INT.
    /// @note Newly created entity instances of type RANDOM_NEXT_INT will be initialized by connecting
    /// the input attributes with a calculation function and the result with the output attribute.
    /// @param entity_type_manager The entity type manager.
    /// @param entity_instance_manager The entity instance manager.
    /// @param log_manager The log manager.
    RandomNextIntProcessor(EntityTypeManagerPtr entity_type_manager, EntityInstanceManagerPtr entity_instance_manager, LogManagerPtr log_manager);

    /// Destructor.
    ~RandomNextIntProcessor() override;

    /// Initializes the RANDOM_NEXT_INT processor by registering listeners on newly created entity instances of type RANDOM_NEXT_INT.
    void init();

    /// @brief Called when an entity instance of type RANDOM_NEXT_INT has been created.
    /// @param entity_instance ?
    void on_entity_instance_created(EntityInstancePtr entity_instance) override;

    /// @brief Called when an entity instance of type RANDOM_NEXT_INT has been deleted.
    /// @param type_GUID ?
    /// @param inst_GUID ?
    void on_entity_instance_deleted(const xg::Guid &type_GUID, const xg::Guid &inst_GUID) override;

    /// @brief Initialization of the processor signals.
    /// @param entity_instance ?
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

    /// The random device.
    std::random_device random_device;

    /// The logger name of this processor.
    static constexpr char LOGGER_NAME[] = "inexor.vs.g.random.nextint";
};

} // namespace inexor::visual_scripting
