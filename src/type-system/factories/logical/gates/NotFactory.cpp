#include "NotFactory.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

NotFactory::NotFactory(NotEntityTypeProviderPtr entity_type_provider, EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
{
    this->entity_type_provider = std::move(entity_type_provider);
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

NotFactory::~NotFactory() = default;

void NotFactory::init()
{
}

EntityInstancePtrOpt NotFactory::create_instance()
{
    return entity_instance_builder_factory->get_builder()->type(entity_type_provider->get_type())->attribute(NotEntityTypeProvider::NOT_INPUT, false)->attribute(NotEntityTypeProvider::NOT_RESULT, true)->build();
}

} // namespace inexor::entity_system::type_system
