#include <type-system/factories/logical/comparison/GreaterThanFloatFactory.hpp>

#include <type-system/types/logical/comparison/GreaterThanFloat.hpp>
#include <utility>

namespace inexor::entity_system::type_system {

GreaterThanFloatFactory::GreaterThanFloatFactory(EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
    : LifeCycleComponent()
{
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

GreaterThanFloatFactory::~GreaterThanFloatFactory() = default;

std::string GreaterThanFloatFactory::get_component_name()
{
    return "GreaterThanFloatFactory";
}

EntityInstancePtrOpt GreaterThanFloatFactory::create_instance()
{
    return entity_instance_builder_factory->get_builder(GreaterThanFloat::TYPE_NAME)
        ->attribute(GreaterThanFloat::INPUT_1, 0.0f)
        ->attribute(GreaterThanFloat::INPUT_2, 0.0f)
        ->attribute(GreaterThanFloat::RESULT, false)
        ->build();
}

} // namespace inexor::entity_system::type_system
