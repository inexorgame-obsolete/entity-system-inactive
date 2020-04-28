#include <type-system/factories/generators/random/RandomNextFloatFactory.hpp>

#include <type-system/types/generators/random/RandomNextFloat.hpp>
#include <utility>

namespace inexor::entity_system::type_system {

RandomNextFloatFactory::RandomNextFloatFactory(EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
    : LifeCycleComponent()
{
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

RandomNextFloatFactory::~RandomNextFloatFactory() = default;

std::string RandomNextFloatFactory::get_component_name()
{
    return "RandomNextFloatFactory";
}

EntityInstancePtrOpt RandomNextFloatFactory::create_instance()
{
    return entity_instance_builder_factory->get_builder(RandomNextFloat::TYPE_NAME)
        ->attribute(RandomNextFloat::ON_ACTIVATION, false)
        ->attribute(RandomNextFloat::MIN, 0.0f)
        ->attribute(RandomNextFloat::MAX, 1.0f)
        ->attribute(RandomNextFloat::VALUE, 0.0f)
        ->build();
}

EntityInstancePtrOpt RandomNextFloatFactory::create_instance(float min, float max)
{
    return entity_instance_builder_factory->get_builder(RandomNextFloat::TYPE_NAME)
        ->attribute(RandomNextFloat::ON_ACTIVATION, false)
        ->attribute(RandomNextFloat::MIN, min)
        ->attribute(RandomNextFloat::MAX, max)
        ->attribute(RandomNextFloat::VALUE, min)
        ->build();
}

} // namespace inexor::entity_system::type_system
