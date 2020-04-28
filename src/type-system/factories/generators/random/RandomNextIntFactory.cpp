#include <type-system/factories/generators/random/RandomNextIntFactory.hpp>

#include <type-system/types/generators/random/RandomNextInt.hpp>
#include <utility>

namespace inexor::entity_system::type_system {

RandomNextIntFactory::RandomNextIntFactory(EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
    : LifeCycleComponent()
{
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

RandomNextIntFactory::~RandomNextIntFactory() = default;

std::string RandomNextIntFactory::get_component_name()
{
    return "RandomNextIntFactory";
}

EntityInstancePtrOpt RandomNextIntFactory::create_instance()
{
    return entity_instance_builder_factory->get_builder(RandomNextInt::TYPE_NAME)
        ->attribute(RandomNextInt::ON_ACTIVATION, false)
        ->attribute(RandomNextInt::MIN, 0)
        ->attribute(RandomNextInt::MAX, 1)
        ->attribute(RandomNextInt::VALUE, 0)
        ->build();
}

EntityInstancePtrOpt RandomNextIntFactory::create_instance(int min, int max)
{
    return entity_instance_builder_factory->get_builder(RandomNextInt::TYPE_NAME)
        ->attribute(RandomNextInt::ON_ACTIVATION, false)
        ->attribute(RandomNextInt::MIN, min)
        ->attribute(RandomNextInt::MAX, max)
        ->attribute(RandomNextInt::VALUE, min)
        ->build();
}

} // namespace inexor::entity_system::type_system
