#include "AddIntFactory.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

AddIntFactory::AddIntFactory(AddIntEntityTypeProviderPtr entity_type_provider, EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
{
    this->entity_type_provider = std::move(entity_type_provider);
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

AddIntFactory::~AddIntFactory() = default;

void AddIntFactory::init()
{
}

EntityInstancePtrOpt AddIntFactory::create_instance()
{
    return entity_instance_builder_factory->get_builder()
        ->type(entity_type_provider->get_type())
        ->attribute(AddIntEntityTypeProvider::ADD_INT_AUGEND, 0)
        ->attribute(AddIntEntityTypeProvider::ADD_INT_ADDEND, 0)
        ->attribute(AddIntEntityTypeProvider::ADD_INT_SUM, 0)
        ->build();
}

} // namespace inexor::entity_system::type_system
