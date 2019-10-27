#include "AndFactory.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

AndFactory::AndFactory(AndEntityTypeProviderPtr entity_type_provider, EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
{
    this->entity_type_provider = std::move(entity_type_provider);
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

AndFactory::~AndFactory() = default;

void AndFactory::init()
{
}

EntityInstancePtrOpt AndFactory::create_instance()
{
    return entity_instance_builder_factory->get_builder()
        ->type(entity_type_provider->get_type())
        ->attribute(AndEntityTypeProvider::AND_INPUT_1, false)
        ->attribute(AndEntityTypeProvider::AND_INPUT_2, false)
        ->attribute(AndEntityTypeProvider::AND_RESULT, false)
        ->build();
}

} // namespace inexor::entity_system::type_system
