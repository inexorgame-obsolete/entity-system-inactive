#include "IntConstantFactory.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

IntConstantFactory::IntConstantFactory(IntConstantEntityTypeProviderPtr entity_type_provider, EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
{
    this->entity_type_provider = std::move(entity_type_provider);
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

IntConstantFactory::~IntConstantFactory() = default;

void IntConstantFactory::init()
{
}

EntityInstancePtrOpt IntConstantFactory::create_instance()
{
    return entity_instance_builder_factory->get_builder()->type(entity_type_provider->get_type())->attribute(IntConstantEntityTypeProvider::INT_CONSTANT_NAME, "")->attribute(IntConstantEntityTypeProvider::INT_CONSTANT_VALUE, 0)->build();
}

EntityInstancePtrOpt IntConstantFactory::create_instance(const std::string &name, const int &value)
{
    return entity_instance_builder_factory->get_builder()
        ->type(entity_type_provider->get_type())
        ->attribute(IntConstantEntityTypeProvider::INT_CONSTANT_NAME, name)
        ->attribute(IntConstantEntityTypeProvider::INT_CONSTANT_VALUE, value)
        ->build();
}

} // namespace inexor::entity_system::type_system
