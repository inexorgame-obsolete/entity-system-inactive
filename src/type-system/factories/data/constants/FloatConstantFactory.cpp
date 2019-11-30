#include "FloatConstantFactory.hpp"

#include <type-system/types/data/constants/FloatConstant.hpp>
#include <utility>

namespace inexor::entity_system::type_system {

FloatConstantFactory::FloatConstantFactory(EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
    : LifeCycleComponent()
{
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

FloatConstantFactory::~FloatConstantFactory() = default;

std::string FloatConstantFactory::get_component_name()
{
    return "FloatConstantFactory";
}

EntityInstancePtrOpt FloatConstantFactory::create_instance()
{
    return entity_instance_builder_factory
        ->get_builder(FloatConstant::TYPE_NAME)
        ->attribute(FloatConstant::NAME, "")
        ->attribute(FloatConstant::VALUE, 0.0f)
        ->build();
}

EntityInstancePtrOpt FloatConstantFactory::create_instance(const std::string &name, const float &value)
{
    return entity_instance_builder_factory
        ->get_builder(FloatConstant::TYPE_NAME)
        ->attribute(FloatConstant::NAME, name)
        ->attribute(FloatConstant::VALUE, value)
        ->build();
}

} // namespace inexor::entity_system::type_system
