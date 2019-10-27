#include "EqualsStringFactory.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

EqualsStringFactory::EqualsStringFactory(EqualsStringEntityTypeProviderPtr entity_type_provider, EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
{
    this->entity_type_provider = std::move(entity_type_provider);
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

EqualsStringFactory::~EqualsStringFactory() = default;

void EqualsStringFactory::init()
{
}

EntityInstancePtrOpt EqualsStringFactory::create_instance()
{
    return entity_instance_builder_factory->get_builder()
        ->type(entity_type_provider->get_type())
        ->attribute(EqualsStringEntityTypeProvider::EQUALS_STRING_INPUT_1, "")
        ->attribute(EqualsStringEntityTypeProvider::EQUALS_STRING_INPUT_2, "")
        ->attribute(EqualsStringEntityTypeProvider::EQUALS_STRING_RESULT, true)
        ->build();
}

} // namespace inexor::entity_system::type_system
