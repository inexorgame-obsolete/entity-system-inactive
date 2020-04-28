#include <type-system/factories/logical/comparison/InRangeFloatFactory.hpp>

#include <type-system/types/logical/comparison/InRangeFloat.hpp>
#include <utility>

namespace inexor::entity_system::type_system {

InRangeFloatFactory::InRangeFloatFactory(EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
    : LifeCycleComponent()
{
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

InRangeFloatFactory::~InRangeFloatFactory() = default;

std::string InRangeFloatFactory::get_component_name()
{
    return "InRangeFloatFactory";
}

EntityInstancePtrOpt InRangeFloatFactory::create_instance()
{
    return entity_instance_builder_factory->get_builder(InRangeFloat::TYPE_NAME)
        ->attribute(InRangeFloat::INPUT, 0.0f)
        ->attribute(InRangeFloat::MIN, 0.0f)
        ->attribute(InRangeFloat::MAX, 0.0f)
        ->attribute(InRangeFloat::RESULT, true)
        ->build();
}

} // namespace inexor::entity_system::type_system
