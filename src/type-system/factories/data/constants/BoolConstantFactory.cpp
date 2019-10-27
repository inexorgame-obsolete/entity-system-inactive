#include "BoolConstantFactory.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

BoolConstantFactory::BoolConstantFactory(BoolConstantEntityTypeProviderPtr entity_type_provider, EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
{
    this->entity_type_provider = std::move(entity_type_provider);
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

BoolConstantFactory::~BoolConstantFactory() = default;

void BoolConstantFactory::init()
{
}

EntityInstancePtrOpt BoolConstantFactory::create_instance()
{
    return entity_instance_builder_factory->get_builder()
        ->type(entity_type_provider->get_type())
        ->attribute(BoolConstantEntityTypeProvider::BOOL_CONSTANT_NAME, "")
        ->attribute(BoolConstantEntityTypeProvider::BOOL_CONSTANT_VALUE, false)
        ->build();
}

EntityInstancePtrOpt BoolConstantFactory::create_instance(const std::string &name, const bool &value)
{
    return entity_instance_builder_factory->get_builder()
        ->type(entity_type_provider->get_type())
        ->attribute(BoolConstantEntityTypeProvider::BOOL_CONSTANT_NAME, name)
        ->attribute(BoolConstantEntityTypeProvider::BOOL_CONSTANT_VALUE, value)
        ->build();
}

} // namespace inexor::entity_system::type_system
