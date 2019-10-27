#include "FloatConstantFactory.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

FloatConstantFactory::FloatConstantFactory(FloatConstantEntityTypeProviderPtr entity_type_provider, EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
{
    this->entity_type_provider = std::move(entity_type_provider);
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

FloatConstantFactory::~FloatConstantFactory() = default;

void FloatConstantFactory::init()
{
}

EntityInstancePtrOpt FloatConstantFactory::create_instance()
{
    return entity_instance_builder_factory->get_builder()
        ->type(entity_type_provider->get_type())
        ->attribute(FloatConstantEntityTypeProvider::FLOAT_CONSTANT_NAME, "")
        ->attribute(FloatConstantEntityTypeProvider::FLOAT_CONSTANT_VALUE, 0.0f)
        ->build();
}

EntityInstancePtrOpt FloatConstantFactory::create_instance(const std::string &name, const float &value)
{
    return entity_instance_builder_factory->get_builder()
        ->type(entity_type_provider->get_type())
        ->attribute(FloatConstantEntityTypeProvider::FLOAT_CONSTANT_NAME, name)
        ->attribute(FloatConstantEntityTypeProvider::FLOAT_CONSTANT_VALUE, value)
        ->build();
}

} // namespace inexor::entity_system::type_system
