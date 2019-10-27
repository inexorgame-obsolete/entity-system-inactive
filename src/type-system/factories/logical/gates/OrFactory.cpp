#include "OrFactory.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

OrFactory::OrFactory(OrEntityTypeProviderPtr entity_type_provider, EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
{
    this->entity_type_provider = std::move(entity_type_provider);
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

OrFactory::~OrFactory() = default;

void OrFactory::init()
{
}

EntityInstancePtrOpt OrFactory::create_instance()
{
    return entity_instance_builder_factory->get_builder()
        ->type(entity_type_provider->get_type())
        ->attribute(OrEntityTypeProvider::OR_INPUT_1, false)
        ->attribute(OrEntityTypeProvider::OR_INPUT_2, false)
        ->attribute(OrEntityTypeProvider::OR_RESULT, false)
        ->build();
}

} // namespace inexor::entity_system::type_system
