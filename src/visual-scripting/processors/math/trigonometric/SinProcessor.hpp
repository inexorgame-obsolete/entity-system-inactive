#pragma once

#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "entity-system/managers/entities/entity-type-manager/EntityTypeManager.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/model/data/container/DataContainer.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "entity-system/model/entities/entity-types/EntityType.hpp"
#include "logging/managers/LogManager.hpp"
#include "visual-scripting/managers/ProcessorRegistry.hpp"
#include "visual-scripting/model/Processor.hpp"

#include "react/Domain.h"

// TODO: move using namespace react into namespace inexor::visual_scripting
using namespace react;

namespace inexor::visual_scripting {

using EntityTypeManagerPtr = std::shared_ptr<entity_system::EntityTypeManager>;
using EntityInstanceManagerPtr = std::shared_ptr<entity_system::EntityInstanceManager>;
using LogManagerPtr = std::shared_ptr<logging::LogManager>;
using EntityTypePtr = std::shared_ptr<entity_system::EntityType>;
using EntityInstancePtr = std::shared_ptr<entity_system::EntityInstance>;
using DataType = entity_system::DataType;
using DataValue = entity_system::DataValue;

/// @class SinProcessor
/// @brief Processor which listens on the creation of entity instances of type SIN.
/// @note Newly created entity instances of type SIN will be initialized by connecting
/// the input attributes with a calculation function and the result with the output attribute.
class SinProcessor : public Processor, public entity_system::EntityInstanceCreatedListener, public entity_system::EntityInstanceDeletedListener, public std::enable_shared_from_this<SinProcessor>
{

    public:
    USING_REACTIVE_DOMAIN(entity_system::D)

    /// @brief Constructs the SIN processor which listens on the creation of entity instances of type SIN.
    /// @note Newly created entity instances of type SIN will be initialized by connecting the input attributes
    /// with a calculation function and the result with the output attribute.
    /// @param entity_type_manager The entity type manager.
    /// @param entity_instance_manager The entity instance manager.
    /// @param log_manager The log manager.
    SinProcessor(EntityTypeManagerPtr entity_type_manager, EntityInstanceManagerPtr entity_instance_manager, LogManagerPtr log_manager);

    /// Destructor.
    ~SinProcessor() override;

    /// Initializes the processor.
    void init();

    /// Initializes the SIN processor by registering listeners on newly created entity instances of type SIN.
    void init_processor();

    /// @brief Called when an entity instance of type SIN has been created.
    /// @param entity_instance ?
    void on_entity_instance_created(EntityInstancePtr entity_instance) override;

    /// @brief Called when an entity instance of type SIN has been deleted.
    /// @param type_GUID ?
    /// @param inst_GUID ?
    void on_entity_instance_deleted(const xg::Guid &type_GUID, const xg::Guid &inst_GUID) override;

    /// @brief Initialization of the processor signals.
    /// @param entity_instance ?
    void make_signals(const EntityInstancePtr &entity_instance);

    private:
    /// The entity type manager.
    EntityTypeManagerPtr entity_type_manager;

    /// The entity instance manager.
    EntityInstanceManagerPtr entity_instance_manager;

    /// The log manager.
    LogManagerPtr log_manager;

    /// The signals per entity instance.
    std::unordered_map<xg::Guid, SignalT<entity_system::DataValue>> signals;

    /// The entity type name of this logger
    static constexpr char TYPE_NAME[] = "SIN";

    /// The name for the attribute sin_input.
    static constexpr char SIN_INPUT[] = "sin_input";

    /// The name for the attribute sin_value.
    static constexpr char SIN_VALUE[] = "sin_value";

    /// The logger name of this processor.
    static constexpr char LOGGER_NAME[] = "inexor.vs.p.t.sin";
};

} // namespace inexor::visual_scripting
