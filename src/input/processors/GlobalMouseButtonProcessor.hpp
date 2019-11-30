#pragma once

#include <list>
#include <utility>

#include "base/LifeCycleComponent.hpp"
#include "Reactive.hpp"
#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/model/data/container/DataContainer.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "input/managers/MouseInputManager.hpp"
#include "logging/managers/LogManager.hpp"
#include "visual-scripting/managers/ProcessorRegistry.hpp"
#include "visual-scripting/model/Processor.hpp"

namespace inexor::input {

using DataValue = entity_system::DataValue;

/// Bundles the source signals of a specific mouse button.
struct GlobalMouseButtonSignals
{

    GlobalMouseButtonSignals(int mouse_button, VarSignalT<DataValue> action, VarSignalT<DataValue> mods) : button(button), action(std::move(action)), mods(std::move(mods)){};

    int button;
    VarSignalT<DataValue> action;
    VarSignalT<DataValue> mods;
};

using GlobalMouseButtonSignalsPtr = std::shared_ptr<GlobalMouseButtonSignals>;

/// @class GlobalMouseButtonProcessor
/// @brief Processor for entity instances of type GLOBAL_MOUSE_BUTTON.
class GlobalMouseButtonProcessor : public LifeCycleComponent,
    public visual_scripting::Processor,
    public entity_system::EntityInstanceCreatedListener,
    public entity_system::EntityInstanceDeletedListener,
    public MouseButtonChangedListener,
    public std::enable_shared_from_this<GlobalMouseButtonProcessor>
{

    USING_REACTIVE_DOMAIN(entity_system::D)

    using EntityTypeManagerPtr = std::shared_ptr<entity_system::EntityTypeManager>;
    using EntityInstanceManagerPtr = std::shared_ptr<entity_system::EntityInstanceManager>;
    using MouseInputManagerPtr = std::shared_ptr<MouseInputManager>;
    using LogManagerPtr = std::shared_ptr<logging::LogManager>;
    using EntityInstancePtr = std::shared_ptr<entity_system::EntityInstance>;

    public:
    /// @brief Constructs a new entity instance of type GLOBAL_MOUSE_BUTTON.
    /// @note The dependencies of this class will be injected automatically.
    /// @param entity_type_manager The entity type manager
    /// @param entity_instance_manager The entity instance manager.
    /// @param logger_manager The log manager.
    GlobalMouseButtonProcessor(EntityTypeManagerPtr entity_type_manager, EntityInstanceManagerPtr entity_instance_manager, MouseInputManagerPtr mouse_input_manager, LogManagerPtr log_manager);

    /// Destructor.
    ~GlobalMouseButtonProcessor() override;

    /// Initialization of the processor.
    void init() override;

    /// Shut down the processor.
    /// void destroy() override;

    /// Returns the name of the component
    std::string get_component_name() override;

    /// @brief Called when an entity instance of type GLOBAL_MOUSE_BUTTON has been created.
    /// @param entity_instance An entity instance of type 'GLOBAL_MOUSE_BUTTON'.
    void on_entity_instance_created(EntityInstancePtr entity_instance) override;

    /// @brief Called when an entity instance of type GLOBAL_MOUSE_BUTTON has been deleted.
    /// @param type_GUID ?
    /// @param inst_GUID ?
    void on_entity_instance_deleted(const xg::Guid &type_GUID, const xg::Guid &inst_GUID) override;

    /// @brief Called when the state of a mouse button has been changed.
    /// @param window An entity instance of type 'WINDOW'.
    /// @param button The button number.
    /// @param action The button action (pressed, released).
    /// @param mods The modifier keys (shift, ctrl).
    void on_mouse_button_changed(EntityInstancePtr window, int button, int action, int mods) override;

    /// The logger name of this processor.
    static constexpr char LOGGER_NAME[] = "inexor.input.processor.globalmousebutton";

    private:
    /// Initializes the processor by registering listeners on newly created entity instances.
    void init_processor();

    /// @brief Creates a signal for the given button number.
    /// @param button The button number.
    GlobalMouseButtonSignalsPtr get_or_create_global_mouse_button_signals(int button);

    /// @brief Creates the processor signals for the given entity instance.
    /// @param entity_instance The entity instance of type GLOBAL_MOUSE_BUTTON.
    void make_signals(const EntityInstancePtr &entity_instance);

    /// The entity type manager.
    EntityTypeManagerPtr entity_type_manager;

    /// The entity instance manager.
    EntityInstanceManagerPtr entity_instance_manager;

    /// The mouse input manager.
    MouseInputManagerPtr mouse_input_manager;

    /// The log manager.
    LogManagerPtr log_manager;

    /// The signals per entity instance.
    std::unordered_map<xg::Guid, ObserverT> observers;

    /// Each button number has a base signal.
    std::unordered_map<int, GlobalMouseButtonSignalsPtr> global_mouse_button_signals;
};

} // namespace inexor::input
