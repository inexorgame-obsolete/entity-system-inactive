#include "IntConstantFactory.hpp"

#include <type-system/types/data/constants/IntConstant.hpp>
#include <utility>

namespace inexor::entity_system::type_system {

IntConstantFactory::IntConstantFactory(EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
    : LifeCycleComponent()
{
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

IntConstantFactory::~IntConstantFactory() = default;

std::string IntConstantFactory::get_component_name()
{
    return "IntConstantFactory";
}

EntityInstancePtrOpt IntConstantFactory::create_instance()
{
    return entity_instance_builder_factory
        ->get_builder(IntConstant::TYPE_NAME)
        ->attribute(IntConstant::NAME, "")
        ->attribute(IntConstant::VALUE, 0)
        ->build();
}

EntityInstancePtrOpt IntConstantFactory::create_instance(const std::string &name, const int &value)
{
    return entity_instance_builder_factory->get_builder(IntConstant::TYPE_NAME)
        ->attribute(IntConstant::NAME, name)
        ->attribute(IntConstant::VALUE, value)
        ->build();
}

} // namespace inexor::entity_system::type_system
