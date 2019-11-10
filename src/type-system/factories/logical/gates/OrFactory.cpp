#include "OrFactory.hpp"

#include <type-system/types/logical/gates/Or.hpp>
#include <utility>

namespace inexor::entity_system::type_system {

OrFactory::OrFactory(EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
    : LifeCycleComponent()
{
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

OrFactory::~OrFactory() = default;

std::string OrFactory::get_component_name()
{
    return "OrFactory";
}

EntityInstancePtrOpt OrFactory::create_instance()
{
    return entity_instance_builder_factory->get_builder(Or::TYPE_NAME)
        ->attribute(Or::INPUT_1, false)
        ->attribute(Or::INPUT_2, false)
        ->attribute(Or::RESULT, false)
        ->build();
}

} // namespace inexor::entity_system::type_system
