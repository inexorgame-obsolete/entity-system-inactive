#include "GreaterThanIntFactory.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

GreaterThanIntFactory::GreaterThanIntFactory(GreaterThanIntEntityTypeProviderPtr entity_type_provider, EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
{
    this->entity_type_provider = std::move(entity_type_provider);
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

GreaterThanIntFactory::~GreaterThanIntFactory() = default;

void GreaterThanIntFactory::init()
{
}

EntityInstancePtrOpt GreaterThanIntFactory::create_instance()
{
    return entity_instance_builder_factory->get_builder()
        ->type(entity_type_provider->get_type())
        ->attribute(GreaterThanIntEntityTypeProvider::GREATER_THAN_INT_INPUT_1, 0)
        ->attribute(GreaterThanIntEntityTypeProvider::GREATER_THAN_INT_INPUT_2, 0)
        ->attribute(GreaterThanIntEntityTypeProvider::GREATER_THAN_INT_RESULT, false)
        ->build();
}

} // namespace inexor::entity_system::type_system
