#include "RandomNextFloatFactory.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

RandomNextFloatFactory::RandomNextFloatFactory(RandomNextFloatEntityTypeProviderPtr entity_type_provider, EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
{
    this->entity_type_provider = std::move(entity_type_provider);
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

RandomNextFloatFactory::~RandomNextFloatFactory() = default;

void RandomNextFloatFactory::init()
{
}

EntityInstancePtrOpt RandomNextFloatFactory::create_instance()
{
    return entity_instance_builder_factory->get_builder()
        ->type(entity_type_provider->get_type())
        ->attribute(RandomNextFloatEntityTypeProvider::RANDOM_NEXT_FLOAT_ON_ACTIVATION, false)
        ->attribute(RandomNextFloatEntityTypeProvider::RANDOM_NEXT_FLOAT_MIN, 0.0f)
        ->attribute(RandomNextFloatEntityTypeProvider::RANDOM_NEXT_FLOAT_MAX, 1.0f)
        ->attribute(RandomNextFloatEntityTypeProvider::RANDOM_NEXT_FLOAT_VALUE, 0.0f)
        ->build();
}

EntityInstancePtrOpt RandomNextFloatFactory::create_instance(float min, float max)
{
    return entity_instance_builder_factory->get_builder()
        ->type(entity_type_provider->get_type())
        ->attribute(RandomNextFloatEntityTypeProvider::RANDOM_NEXT_FLOAT_ON_ACTIVATION, false)
        ->attribute(RandomNextFloatEntityTypeProvider::RANDOM_NEXT_FLOAT_MIN, min)
        ->attribute(RandomNextFloatEntityTypeProvider::RANDOM_NEXT_FLOAT_MAX, max)
        ->attribute(RandomNextFloatEntityTypeProvider::RANDOM_NEXT_FLOAT_VALUE, min)
        ->build();
}

} // namespace inexor::entity_system::type_system
