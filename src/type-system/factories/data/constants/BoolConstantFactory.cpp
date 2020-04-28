#include <type-system/factories/data/constants/BoolConstantFactory.hpp>

#include <type-system/types/data/constants/BoolConstant.hpp>
#include <utility>

namespace inexor::entity_system::type_system {

BoolConstantFactory::BoolConstantFactory(EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
    : LifeCycleComponent()
{
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

BoolConstantFactory::~BoolConstantFactory() = default;

std::string BoolConstantFactory::get_component_name()
{
    return "BoolConstantFactory";
}

EntityInstancePtrOpt BoolConstantFactory::create_instance()
{
    return entity_instance_builder_factory
        ->get_builder(BoolConstant::TYPE_NAME)
        ->attribute(BoolConstant::NAME, "")
        ->attribute(BoolConstant::VALUE, false)
        ->build();
}

EntityInstancePtrOpt BoolConstantFactory::create_instance(const std::string &name, const bool &value)
{
    return entity_instance_builder_factory
        ->get_builder(BoolConstant::TYPE_NAME)
        ->attribute(BoolConstant::NAME, name)
        ->attribute(BoolConstant::VALUE, value)
        ->build();
}

} // namespace inexor::entity_system::type_system
