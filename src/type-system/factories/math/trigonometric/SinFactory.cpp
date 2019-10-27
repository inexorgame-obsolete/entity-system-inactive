#include "SinFactory.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

SinFactory::SinFactory(SinEntityTypeProviderPtr entity_type_provider, EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
{
    this->entity_type_provider = std::move(entity_type_provider);
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

SinFactory::~SinFactory() = default;

void SinFactory::init()
{
}

EntityInstancePtrOpt SinFactory::create_instance()
{
    return entity_instance_builder_factory->get_builder()->type(entity_type_provider->get_type())->attribute(SinEntityTypeProvider::SIN_INPUT, 0.0f)->attribute(SinEntityTypeProvider::SIN_VALUE, 0.0f)->build();
}

EntityInstancePtrOpt SinFactory::create_instance(float input_value)
{
    return entity_instance_builder_factory->get_builder()->type(entity_type_provider->get_type())->attribute(SinEntityTypeProvider::SIN_INPUT, input_value)->attribute(SinEntityTypeProvider::SIN_VALUE, sinf(input_value))->build();
}

} // namespace inexor::entity_system::type_system
