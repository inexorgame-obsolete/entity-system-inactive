#include "IntToStringFactory.hpp"

#include <type-system/types/data/converters/IntToString.hpp>
#include <utility>

namespace inexor::entity_system::type_system {

IntToStringFactory::IntToStringFactory(EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
    : LifeCycleComponent()
{
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

IntToStringFactory::~IntToStringFactory() = default;

std::string IntToStringFactory::get_component_name()
{
    return "IntToStringFactory";
}

EntityInstancePtrOpt IntToStringFactory::create_instance()
{
    // clang-format off
    return entity_instance_builder_factory
        ->get_builder(IntToString::TYPE_NAME)
        ->attribute(IntToString::INPUT, 0)
        ->attribute(IntToString::VALUE, std::string(""))
        ->build();
    // clang-format off
}

EntityInstancePtrOpt IntToStringFactory::create_instance(const std::string &name, const int &int_value, const std::string &string_value)
{
    // clang-format off
    return entity_instance_builder_factory
        ->get_builder(IntToString::TYPE_NAME)
        ->attribute(IntToString::INPUT, int_value)
        ->attribute(IntToString::VALUE, string_value)
        ->build();
    // clang-format on
}

} // namespace inexor::entity_system::type_system
