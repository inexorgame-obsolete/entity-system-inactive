#include "IntToFloatFactory.hpp"

#include <type-system/types/data/converters/IntToFloat.hpp>
#include <utility>

namespace inexor::entity_system::type_system {

IntToFloatFactory::IntToFloatFactory(EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
    : LifeCycleComponent()
{
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

IntToFloatFactory::~IntToFloatFactory() = default;

std::string IntToFloatFactory::get_component_name()
{
    return "IntToFloatFactory";
}

EntityInstancePtrOpt IntToFloatFactory::create_instance()
{
    // clang-format off
    return entity_instance_builder_factory
        ->get_builder(IntToFloat::TYPE_NAME)
        ->attribute(IntToFloat::INPUT, 0)
        ->attribute(IntToFloat::VALUE, 0.0f)
        ->build();
    // clang-format on
}

EntityInstancePtrOpt IntToFloatFactory::create_instance(const std::string &name, const int &int_value, const float &float_value)
{
    // clang-format off
    return entity_instance_builder_factory
        ->get_builder(IntToFloat::TYPE_NAME)
        ->attribute(IntToFloat::INPUT, int_value)
        ->attribute(IntToFloat::VALUE, float_value)
        ->build();
    // clang-format on
}

} // namespace inexor::entity_system::type_system
