#include "XorFactory.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

XorFactory::XorFactory(XorEntityTypeProviderPtr entity_type_provider, EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
{
    this->entity_type_provider = std::move(entity_type_provider);
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

XorFactory::~XorFactory() = default;

void XorFactory::init()
{
}

EntityInstancePtrOpt XorFactory::create_instance()
{
    return entity_instance_builder_factory->get_builder()
        ->type(entity_type_provider->get_type())
        ->attribute(XorEntityTypeProvider::XOR_INPUT_1, false)
        ->attribute(XorEntityTypeProvider::XOR_INPUT_2, false)
        ->attribute(XorEntityTypeProvider::XOR_RESULT, false)
        ->build();
}

} // namespace inexor::entity_system::type_system
