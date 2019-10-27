#include "GreaterThanFloatFactory.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

GreaterThanFloatFactory::GreaterThanFloatFactory(GreaterThanFloatEntityTypeProviderPtr entity_type_provider, EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
{
    this->entity_type_provider = std::move(entity_type_provider);
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

GreaterThanFloatFactory::~GreaterThanFloatFactory() = default;

void GreaterThanFloatFactory::init()
{
}

EntityInstancePtrOpt GreaterThanFloatFactory::create_instance()
{
    return entity_instance_builder_factory->get_builder()
        ->type(entity_type_provider->get_type())
        ->attribute(GreaterThanFloatEntityTypeProvider::GREATER_THAN_FLOAT_INPUT_1, 0.0f)
        ->attribute(GreaterThanFloatEntityTypeProvider::GREATER_THAN_FLOAT_INPUT_2, 0.0f)
        ->attribute(GreaterThanFloatEntityTypeProvider::GREATER_THAN_FLOAT_RESULT, false)
        ->build();
}

} // namespace inexor::entity_system::type_system
