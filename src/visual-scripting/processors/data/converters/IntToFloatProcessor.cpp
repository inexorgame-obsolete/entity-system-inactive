#include "IntToFloatProcessor.hpp"

#include <utility>

#include "type-system/types/data/converters/IntToFloat.hpp"

namespace inexor::visual_scripting {

using namespace inexor::entity_system;
using namespace inexor::entity_system::type_system;
using IntToFloat = entity_system::type_system::IntToFloat;
using EntityAttributeInstancePtrOptional = std::optional<std::shared_ptr<EntityAttributeInstance>>;

IntToFloatProcessor::IntToFloatProcessor(EntityTypeManagerPtr entity_type_manager, EntityInstanceManagerPtr entity_instance_manager, LogManagerPtr log_manager)
    : Processor(), entity_type_manager(std::move(entity_type_manager)), entity_instance_manager(std::move(entity_instance_manager)), log_manager(std::move(log_manager))
{
}

IntToFloatProcessor::~IntToFloatProcessor() = default;

void IntToFloatProcessor::init()
{
    log_manager->register_logger(LOGGER_NAME);
    init_processor();
}

void IntToFloatProcessor::init_processor()
{
    EntityTypePtrOpt o_ent_type = entity_type_manager->get_entity_type(std::string(IntToFloat::TYPE_NAME));
    if (o_ent_type.has_value()) {
        this->entity_type = o_ent_type.value();
        entity_instance_manager->register_on_created(this->entity_type->get_GUID(), shared_from_this());
        entity_instance_manager->register_on_deleted(this->entity_type->get_GUID(), shared_from_this());
    } else {
        spdlog::get(LOGGER_NAME)->error("Failed to initialize processor {}: Entity type does not exist", std::string(IntToFloat::TYPE_NAME));
    }
}

void IntToFloatProcessor::shutdown()
{
}

void IntToFloatProcessor::on_entity_instance_created(EntityInstancePtr entity_instance)
{
    make_signals(entity_instance);
}

void IntToFloatProcessor::on_entity_instance_deleted(const xg::Guid &type_GUID, const xg::Guid &inst_GUID)
{
    // Disconnect observers with execution method
    // Delete observer for each input atttribute of the entity instance
    // TODO: remove / clear signal
    // signals[inst_GUID].clear
}

void IntToFloatProcessor::make_signals(const EntityInstancePtr &entity_instance)
{
    spdlog::get(LOGGER_NAME)->debug("Initializing processor ADD_INT for newly created entity instance {} of type {}", entity_instance->get_GUID().str(), entity_instance->get_entity_type()->get_type_name());

    auto o_input = entity_instance->get_attribute_instance(IntToFloat::INPUT);
    auto o_value = entity_instance->get_attribute_instance(IntToFloat::VALUE);

    if (o_input.has_value() && o_value.has_value())
    {
        signals[entity_instance->get_GUID()] =
            MakeSignal(With(o_input.value()->value), [](DataValue input) { return DataValue((float) std::get<DataType::INT>(input)); });
        o_value.value()->value = signals[entity_instance->get_GUID()];
    } else
    {
        spdlog::get(LOGGER_NAME)
            ->error("Failed to initialize processor signals for entity instance {} of type {}: Missing one of these attributes: {} {}", entity_instance->get_GUID().str(), entity_instance->get_entity_type()->get_type_name(),
                    IntToFloat::INPUT, IntToFloat::VALUE);
    }
}

} // namespace inexor::visual_scripting
