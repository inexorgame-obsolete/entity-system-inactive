#include "InRangeFloatProcessor.hpp"

#include <type-system/types/logical/comparison/InRangeFloat.hpp>
#include <utility>

namespace inexor::visual_scripting {

using namespace inexor::entity_system;
using namespace inexor::entity_system::type_system;

using InRangeFloat = entity_system::type_system::InRangeFloat;
using EntityTypePtrOpt = std::optional<EntityTypePtr>;
using EntityAttributeInstancePtrOptional = std::optional<std::shared_ptr<EntityAttributeInstance>>;

InRangeFloatProcessor::InRangeFloatProcessor(EntityTypeManagerPtr entity_type_manager, EntityInstanceManagerPtr entity_instance_manager, LogManagerPtr log_manager)
    : Processor(), LifeCycleComponent(), entity_type_manager(std::move(entity_type_manager)), entity_instance_manager(std::move(entity_instance_manager)), log_manager(std::move(log_manager))
{
}

InRangeFloatProcessor::~InRangeFloatProcessor() = default;

void InRangeFloatProcessor::init()
{
    log_manager->register_logger(LOGGER_NAME);
    init_processor();
}

void InRangeFloatProcessor::init_processor()
{
    EntityTypePtrOpt o_ent_type = entity_type_manager->get_entity_type(InRangeFloat::TYPE_NAME);
    if (o_ent_type.has_value()) {
        this->entity_type = o_ent_type.value();
        entity_instance_manager->register_on_created(this->entity_type->get_GUID(), shared_from_this());
        entity_instance_manager->register_on_deleted(this->entity_type->get_GUID(), shared_from_this());
    } else {
        spdlog::get(LOGGER_NAME)->error("Failed to initialize processor {}: Entity type does not exist", InRangeFloat::TYPE_NAME);
    }
}

std::string InRangeFloatProcessor::get_component_name()
{
    return "InRangeFloatProcessor";
}

void InRangeFloatProcessor::on_entity_instance_created(EntityInstancePtr entity_instance)
{
    make_signals(entity_instance);
}

void InRangeFloatProcessor::on_entity_instance_deleted(const xg::Guid &type_GUID, const xg::Guid &inst_GUID)
{
    // Disconnect observers with execution method
    // Delete observer for each input atttribute of the entity instance
    // TODO: remove / clear signal
    // signals[inst_GUID].clear
}

void InRangeFloatProcessor::make_signals(const EntityInstancePtr &entity_instance)
{
    spdlog::get(LOGGER_NAME)->debug("Initializing processor IN_RANGE_FLOAT for newly created entity instance {} of type {}", entity_instance->get_GUID().str(), entity_instance->get_entity_type()->get_type_name());

    auto o_in_range_float_input = entity_instance->get_attribute_instance(InRangeFloat::INPUT);
    auto o_in_range_float_min = entity_instance->get_attribute_instance(InRangeFloat::MIN);
    auto o_in_range_float_max = entity_instance->get_attribute_instance(InRangeFloat::MAX);
    auto o_in_range_float_result = entity_instance->get_attribute_instance(InRangeFloat::RESULT);

    if (o_in_range_float_input.has_value() && o_in_range_float_min.has_value() && o_in_range_float_max.has_value() && o_in_range_float_result.has_value())
    {
        signals[entity_instance->get_GUID()] =
            MakeSignal(With(o_in_range_float_input.value()->value, o_in_range_float_min.value()->value, o_in_range_float_max.value()->value), [](DataValue in_range_float_input, DataValue in_range_float_min, DataValue in_range_float_max) {
                float input = std::get<DataType::FLOAT>(in_range_float_input);
                float min = std::get<DataType::FLOAT>(in_range_float_min);
                float max = std::get<DataType::FLOAT>(in_range_float_max);
                return DataValue(input > min && input < max);
            });
        o_in_range_float_result.value()->value = signals[entity_instance->get_GUID()];
    } else
    {
        spdlog::get(LOGGER_NAME)
            ->error("Failed to initialize processor signals for entity instance {} of type {}: Missing one of these attributes: {} {} {} {}", entity_instance->get_GUID().str(), entity_instance->get_entity_type()->get_type_name(),
                    InRangeFloat::INPUT, InRangeFloat::MIN, InRangeFloat::MAX, InRangeFloat::RESULT);
    }
}

} // namespace inexor::visual_scripting
