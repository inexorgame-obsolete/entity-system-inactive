#include "LowerThanFloatFactory.hpp"

#include <type-system/types/logical/comparison/LowerThanFloat.hpp>
#include <utility>

namespace inexor::entity_system::type_system {

LowerThanFloatFactory::LowerThanFloatFactory(EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
    : LifeCycleComponent()
{
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

LowerThanFloatFactory::~LowerThanFloatFactory() = default;

std::string LowerThanFloatFactory::get_component_name()
{
    return "LowerThanFloatFactory";
}

EntityInstancePtrOpt LowerThanFloatFactory::create_instance()
{
    return entity_instance_builder_factory->get_builder(LowerThanFloat::TYPE_NAME)
        ->attribute(LowerThanFloat::INPUT_1, 0.0f)
        ->attribute(LowerThanFloat::INPUT_2, 0.0f)
        ->attribute(LowerThanFloat::RESULT, false)
        ->build();
}

} // namespace inexor::entity_system::type_system
