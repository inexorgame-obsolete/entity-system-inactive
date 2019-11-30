#include "EqualsIntFactory.hpp"

#include <type-system/types/logical/comparison/EqualsInt.hpp>
#include <utility>

namespace inexor::entity_system::type_system {

EqualsIntFactory::EqualsIntFactory(EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
    : LifeCycleComponent()
{
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

EqualsIntFactory::~EqualsIntFactory() = default;

std::string EqualsIntFactory::get_component_name()
{
    return "EqualsIntFactory";
}

EntityInstancePtrOpt EqualsIntFactory::create_instance()
{
    return entity_instance_builder_factory->get_builder(EqualsInt::TYPE_NAME)
        ->attribute(EqualsInt::INPUT_1, 0)
        ->attribute(EqualsInt::INPUT_2, 0)
        ->attribute(EqualsInt::RESULT, true)
        ->build();
}

} // namespace inexor::entity_system::type_system
