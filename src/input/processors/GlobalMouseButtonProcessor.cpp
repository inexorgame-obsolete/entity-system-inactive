#include <input/processors/GlobalMouseButtonProcessor.hpp>

#include <utility>

#include "react/Algorithm.h"
#include "react/Domain.h"
#include "react/Event.h"
#include "react/Observer.h"

#include "type-system/types/inout/mouse/GlobalMouseButton.hpp"

namespace inexor::input {

using GlobalMouseButton = entity_system::type_system::GlobalMouseButton;
using EntityAttributeInstancePtr = std::shared_ptr<entity_system::EntityAttributeInstance>;
using EntityAttributeInstancePtrOptional = std::optional<EntityAttributeInstancePtr>;
using EntityTypePtr = std::shared_ptr<entity_system::EntityType>;
using EntityTypePtrOpt = std::optional<EntityTypePtr>;

GlobalMouseButtonProcessor::GlobalMouseButtonProcessor(EntityTypeManagerPtr entity_type_manager, EntityInstanceManagerPtr entity_instance_manager, MouseInputManagerPtr mouse_input_manager,
                                                       LogManagerPtr log_manager)
    : LifeCycleComponent(), Processor(), entity_type_manager(std::move(entity_type_manager)), entity_instance_manager(std::move(entity_instance_manager)), mouse_input_manager(std::move(mouse_input_manager)),
      log_manager(std::move(log_manager))
{
}

GlobalMouseButtonProcessor::~GlobalMouseButtonProcessor() = default;

void GlobalMouseButtonProcessor::init()
{
    log_manager->register_logger(LOGGER_NAME);
    init_processor();
}

void GlobalMouseButtonProcessor::init_processor()
{
    EntityTypePtrOpt o_ent_type = entity_type_manager->get_entity_type(GlobalMouseButton::TYPE_NAME);
    if (o_ent_type.has_value()) {
        this->entity_type = o_ent_type.value();
        entity_instance_manager->register_on_created(this->entity_type->get_GUID(), shared_from_this());
        entity_instance_manager->register_on_deleted(this->entity_type->get_GUID(), shared_from_this());
        mouse_input_manager->register_on_mouse_button_changed(shared_from_this());
    } else {
        spdlog::get(LOGGER_NAME)->error("Failed to initialize processor {}: Entity type does not exist", GlobalMouseButton::TYPE_NAME);
    }
}

std::string GlobalMouseButtonProcessor::get_component_name()
{
    return "GlobalMouseButtonProcessor";
}

void GlobalMouseButtonProcessor::on_entity_instance_created(EntityInstancePtr entity_instance)
{
    make_signals(entity_instance);
}

void GlobalMouseButtonProcessor::on_entity_instance_deleted(const xg::Guid &type_GUID, const xg::Guid &inst_GUID)
{
}

void GlobalMouseButtonProcessor::on_mouse_button_changed(EntityInstancePtr window, int button, int action, int mods)
{
    if (global_mouse_button_signals.find(button) != global_mouse_button_signals.end())
    {
        spdlog::get(LOGGER_NAME)->debug("Signal GLOBAL_MOUSE_BUTTON {}", button);
        // Change both signals at the same time!
        // TODO: AsyncTransaction ?
        DoTransaction<entity_system::D>([this, button, action, mods] {
            global_mouse_button_signals[button]->action.Set(action);
            global_mouse_button_signals[button]->mods.Set(mods);
        });
    } else
    {
        spdlog::get(LOGGER_NAME)->trace("No signal for button number {}", button);
    }
}

void GlobalMouseButtonProcessor::make_signals(const EntityInstancePtr &entity_instance)
{
    spdlog::get(LOGGER_NAME)->debug("Initializing processor GLOBAL_MOUSE_BUTTON for newly created entity instance {} of type {}", entity_instance->get_GUID().str(), entity_instance->get_entity_type()->get_type_name());

    auto o_button_number = entity_instance->get_attribute_instance(GlobalMouseButton::BUTTON_NUMBER);
    auto o_action = entity_instance->get_attribute_instance(GlobalMouseButton::ACTION);
    auto o_mods = entity_instance->get_attribute_instance(GlobalMouseButton::MODS);

    if (o_button_number.has_value() && o_action.has_value() && o_mods.has_value())
    {
        EntityAttributeInstancePtr button_number = o_button_number.value();
        int button = std::get<entity_system::DataType::INT>(button_number->value.Value());
        spdlog::get(LOGGER_NAME)->debug("Reactively connect source signals for mouse button number {} with entity attributes", button);
        GlobalMouseButtonSignalsPtr global_mouse_button_signals = get_or_create_global_mouse_button_signals(button);
        o_action.value()->signal_wrapper <<= global_mouse_button_signals->action;
        o_mods.value()->signal_wrapper <<= global_mouse_button_signals->mods;
        // TODO: observe GLOBAL_MOUSE_BUTTON_NUMBER -> remove signal for old button number; add signal for new button number
    } else
    {
        spdlog::get(LOGGER_NAME)
            ->error("Failed to initialize processor signals for entity instance {} of type {}: Missing one of these attributes {} {} {}", entity_instance->get_GUID().str(), entity_instance->get_entity_type()->get_type_name(),
                    GlobalMouseButton::BUTTON_NUMBER, GlobalMouseButton::ACTION, GlobalMouseButton::MODS);
    }
}

GlobalMouseButtonSignalsPtr GlobalMouseButtonProcessor::get_or_create_global_mouse_button_signals(int button)
{
    if (global_mouse_button_signals.find(button) == global_mouse_button_signals.end())
    {
        spdlog::get(LOGGER_NAME)->debug("Create source signals for button number {}", button);
        global_mouse_button_signals[button] = std::make_shared<GlobalMouseButtonSignals>(button, MakeVar<entity_system::D>(DataValue(0)), MakeVar<entity_system::D>(DataValue(0)));
    }
    return global_mouse_button_signals[button];
}

} // namespace inexor::input
