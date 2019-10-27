#include "LowerThanFloatFactory.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

LowerThanFloatFactory::LowerThanFloatFactory(LowerThanFloatEntityTypeProviderPtr entity_type_provider, EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
{
    this->entity_type_provider = std::move(entity_type_provider);
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

LowerThanFloatFactory::~LowerThanFloatFactory() = default;

void LowerThanFloatFactory::init()
{
}

EntityInstancePtrOpt LowerThanFloatFactory::create_instance()
{
    return entity_instance_builder_factory->get_builder()
        ->type(entity_type_provider->get_type())
        ->attribute(LowerThanFloatEntityTypeProvider::LOWER_THAN_FLOAT_INPUT_1, 0.0f)
        ->attribute(LowerThanFloatEntityTypeProvider::LOWER_THAN_FLOAT_INPUT_2, 0.0f)
        ->attribute(LowerThanFloatEntityTypeProvider::LOWER_THAN_FLOAT_RESULT, false)
        ->build();
}

} // namespace inexor::entity_system::type_system
