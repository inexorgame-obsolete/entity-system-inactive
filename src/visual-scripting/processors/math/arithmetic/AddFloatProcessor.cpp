#include <visual-scripting/processors/math/arithmetic/AddFloatProcessor.hpp>

#include <utility>

#include "type-system/types/math/arithmetic/AddFloat.hpp"

namespace inexor::visual_scripting {

using namespace inexor::entity_system;
using namespace inexor::entity_system::type_system;
using AddFloat = entity_system::type_system::AddFloat;
using EntityAttributeInstancePtrOptional = std::optional<std::shared_ptr<EntityAttributeInstance>>;

AddFloatProcessor::AddFloatProcessor(EntityTypeManagerPtr entity_type_manager, EntityInstanceManagerPtr entity_instance_manager, LogManagerPtr log_manager)
    : Processor(), LifeCycleComponent(), entity_type_manager(std::move(entity_type_manager)), entity_instance_manager(std::move(entity_instance_manager)), log_manager(std::move(log_manager))
{
}

AddFloatProcessor::~AddFloatProcessor() = default;

void AddFloatProcessor::init()
{
    log_manager->register_logger(LOGGER_NAME);
    init_processor();
}

void AddFloatProcessor::init_processor()
{
    EntityTypePtrOpt o_ent_type = entity_type_manager->get_entity_type(std::string(AddFloat::TYPE_NAME));
    if (o_ent_type.has_value()) {
        this->entity_type = o_ent_type.value();
        entity_instance_manager->register_on_created(this->entity_type->get_GUID(), shared_from_this());
        entity_instance_manager->register_on_deleted(this->entity_type->get_GUID(), shared_from_this());
    } else {
        spdlog::get(LOGGER_NAME)->error("Failed to initialize processor {}: Entity type does not exist", std::string(AddFloat::TYPE_NAME));
    }
}

std::string AddFloatProcessor::get_component_name()
{
    return "AddFloatProcessor";
}

void AddFloatProcessor::on_entity_instance_created(EntityInstancePtr entity_instance)
{
    make_signals(entity_instance);
}

void AddFloatProcessor::on_entity_instance_deleted(const xg::Guid &type_GUID, const xg::Guid &inst_GUID)
{
    // Disconnect observers with execution method
    // Delete observer for each input atttribute of the entity instance
    // TODO: remove / clear signal
    // signals[inst_GUID].clear
}

void AddFloatProcessor::make_signals(const EntityInstancePtr &entity_instance)
{
    spdlog::get(LOGGER_NAME)->debug("Initializing processor ADD_FLOAT for newly created entity instance {} of type {}", entity_instance->get_GUID().str(), entity_instance->get_entity_type()->get_type_name());

    auto o_augend = entity_instance->get_attribute_instance(AddFloat::AUGEND);
    auto o_addend = entity_instance->get_attribute_instance(AddFloat::ADDEND);
    auto o_sum = entity_instance->get_attribute_instance(AddFloat::SUM);

    if (o_augend.has_value() && o_addend.has_value() && o_sum.has_value())
    {
        signals[entity_instance->get_GUID()] =
            MakeSignal(With(o_augend.value()->value, o_addend.value()->value), [](DataValue augend, DataValue addend) { return DataValue(std::get<DataType::FLOAT>(augend) + std::get<DataType::FLOAT>(addend)); });
        o_sum.value()->value = signals[entity_instance->get_GUID()];
    } else
    {
        spdlog::get(LOGGER_NAME)
            ->error("Failed to initialize processor signals for entity instance {} of type {}: Missing one of these attributes: {} {} {}", entity_instance->get_GUID().str(), entity_instance->get_entity_type()->get_type_name(),
                    AddFloat::AUGEND, AddFloat::ADDEND, AddFloat::SUM);
    }
}

} // namespace inexor::visual_scripting
