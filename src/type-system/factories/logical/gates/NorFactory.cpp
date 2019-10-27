#include "NorFactory.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

NorFactory::NorFactory(NorEntityTypeProviderPtr entity_type_provider, EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
{
    this->entity_type_provider = std::move(entity_type_provider);
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

NorFactory::~NorFactory() = default;

void NorFactory::init()
{
}

EntityInstancePtrOpt NorFactory::create_instance()
{
    return entity_instance_builder_factory->get_builder()
        ->type(entity_type_provider->get_type())
        ->attribute(NorEntityTypeProvider::NOR_INPUT_1, false)
        ->attribute(NorEntityTypeProvider::NOR_INPUT_2, false)
        ->attribute(NorEntityTypeProvider::NOR_RESULT, true)
        ->build();
}

} // namespace inexor::entity_system::type_system
