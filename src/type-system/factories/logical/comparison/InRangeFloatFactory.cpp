#include "InRangeFloatFactory.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

InRangeFloatFactory::InRangeFloatFactory(InRangeFloatEntityTypeProviderPtr entity_type_provider, EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
{
    this->entity_type_provider = std::move(entity_type_provider);
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

InRangeFloatFactory::~InRangeFloatFactory() = default;

void InRangeFloatFactory::init()
{
}

EntityInstancePtrOpt InRangeFloatFactory::create_instance()
{
    return entity_instance_builder_factory->get_builder()
        ->type(entity_type_provider->get_type())
        ->attribute(InRangeFloatEntityTypeProvider::IN_RANGE_FLOAT_INPUT, 0.0f)
        ->attribute(InRangeFloatEntityTypeProvider::IN_RANGE_FLOAT_MIN, 0.0f)
        ->attribute(InRangeFloatEntityTypeProvider::IN_RANGE_FLOAT_MAX, 0.0f)
        ->attribute(InRangeFloatEntityTypeProvider::IN_RANGE_FLOAT_RESULT, true)
        ->build();
}

} // namespace inexor::entity_system::type_system
