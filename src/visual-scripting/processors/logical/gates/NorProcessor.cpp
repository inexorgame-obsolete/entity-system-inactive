#include "NorProcessor.hpp"

#include <type-system/types/logical/gates/Nor.hpp>
#include <utility>

namespace inexor::visual_scripting {

using namespace inexor::entity_system;
using namespace inexor::entity_system::type_system;

using Nor = entity_system::type_system::Nor;
using EntityTypePtrOpt = std::optional<EntityTypePtr>;
using EntityAttributeInstancePtrOptional = std::optional<std::shared_ptr<EntityAttributeInstance>>;

NorProcessor::NorProcessor(EntityTypeManagerPtr entity_type_manager, EntityInstanceManagerPtr entity_instance_manager, LogManagerPtr log_manager)
    : Processor(), entity_type_manager(std::move(entity_type_manager)), entity_instance_manager(std::move(entity_instance_manager)), log_manager(std::move(log_manager))
{
}

NorProcessor::~NorProcessor() = default;

void NorProcessor::init()
{
    log_manager->register_logger(LOGGER_NAME);
    init_processor();
}

void NorProcessor::init_processor()
{
    EntityTypePtrOpt o_ent_type = entity_type_manager->get_entity_type(Nor::TYPE_NAME);
    if (o_ent_type.has_value()) {
        this->entity_type = o_ent_type.value();
        entity_instance_manager->register_on_created(this->entity_type->get_GUID(), shared_from_this());
        entity_instance_manager->register_on_deleted(this->entity_type->get_GUID(), shared_from_this());
    } else {
        spdlog::get(LOGGER_NAME)->error("Failed to initialize processor {}: Entity type does not exist", Nor::TYPE_NAME);
    }
}

void NorProcessor::on_entity_instance_created(EntityInstancePtr entity_instance)
{
    make_signals(entity_instance);
}

void NorProcessor::on_entity_instance_deleted(const xg::Guid &type_GUID, const xg::Guid &inst_GUID)
{
    // Disconnect observers with execution method
    // Delete observer for each input atttribute of the entity instance
    // TODO: remove / clear signal
    // signals[inst_GUID].clear
}

void NorProcessor::make_signals(const EntityInstancePtr &entity_instance)
{
    spdlog::get(LOGGER_NAME)->debug("Initializing processor NOR for newly created entity instance {} of type {}", entity_instance->get_GUID().str(), entity_instance->get_entity_type()->get_type_name());

    auto o_nor_input_1 = entity_instance->get_attribute_instance(Nor::INPUT_1);
    auto o_nor_input_2 = entity_instance->get_attribute_instance(Nor::INPUT_2);
    auto o_nor_result = entity_instance->get_attribute_instance(Nor::RESULT);

    if (o_nor_input_1.has_value() && o_nor_input_2.has_value() && o_nor_result.has_value())
    {
        signals[entity_instance->get_GUID()] = MakeSignal(With(o_nor_input_1.value()->value, o_nor_input_2.value()->value),
                                                          [](DataValue nor_input_1, DataValue nor_input_2) { return DataValue(!(std::get<DataType::BOOL>(nor_input_1) || std::get<DataType::BOOL>(nor_input_2))); });
        o_nor_result.value()->value = signals[entity_instance->get_GUID()];
    } else
    {
        spdlog::get(LOGGER_NAME)
            ->error("Failed to initialize processor signals for entity instance {} of type {}: Missing one of these attributes: {} {} {}", entity_instance->get_GUID().str(), entity_instance->get_entity_type()->get_type_name(),
                    Nor::INPUT_1, Nor::INPUT_2, Nor::RESULT);
    }
}

} // namespace inexor::visual_scripting
