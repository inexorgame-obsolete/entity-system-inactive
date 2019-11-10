#include "StringConstantFactory.hpp"

#include <type-system/types/data/constants/StringConstant.hpp>
#include <utility>

namespace inexor::entity_system::type_system {

StringConstantFactory::StringConstantFactory(EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
    : LifeCycleComponent()
{
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

StringConstantFactory::~StringConstantFactory() = default;

std::string StringConstantFactory::get_component_name()
{
    return "StringConstantFactory";
}

EntityInstancePtrOpt StringConstantFactory::create_instance()
{
    return entity_instance_builder_factory
        ->get_builder(StringConstant::TYPE_NAME)
        ->attribute(StringConstant::NAME, std::string(""))
        ->attribute(StringConstant::VALUE, std::string(""))
        ->build();
}

EntityInstancePtrOpt StringConstantFactory::create_instance(const std::string &name)
{
    return entity_instance_builder_factory
        ->get_builder(StringConstant::TYPE_NAME)
        ->attribute(StringConstant::NAME, name)
        ->attribute(StringConstant::VALUE, std::string(""))
        ->build();
}

EntityInstancePtrOpt StringConstantFactory::create_instance(const std::string &name, const std::string &value)
{
    return entity_instance_builder_factory
        ->get_builder(StringConstant::TYPE_NAME)
        ->attribute(StringConstant::NAME, name)
        ->attribute(StringConstant::VALUE, value)
        ->build();
}

} // namespace inexor::entity_system::type_system
