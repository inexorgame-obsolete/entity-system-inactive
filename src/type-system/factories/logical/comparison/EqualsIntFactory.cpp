#include "EqualsIntFactory.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

EqualsIntFactory::EqualsIntFactory(EqualsIntEntityTypeProviderPtr entity_type_provider, EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
{
    this->entity_type_provider = std::move(entity_type_provider);
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

EqualsIntFactory::~EqualsIntFactory() = default;

void EqualsIntFactory::init()
{
}

EntityInstancePtrOpt EqualsIntFactory::create_instance()
{
    return entity_instance_builder_factory->get_builder()
        ->type(entity_type_provider->get_type())
        ->attribute(EqualsIntEntityTypeProvider::EQUALS_INT_INPUT_1, 0)
        ->attribute(EqualsIntEntityTypeProvider::EQUALS_INT_INPUT_2, 0)
        ->attribute(EqualsIntEntityTypeProvider::EQUALS_INT_RESULT, true)
        ->build();
}

} // namespace inexor::entity_system::type_system
