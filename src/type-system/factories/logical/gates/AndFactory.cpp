#include "AndFactory.hpp"

#include <type-system/types/logical/gates/And.hpp>
#include <utility>

namespace inexor::entity_system::type_system {

AndFactory::AndFactory(EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
    : LifeCycleComponent()
{
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

AndFactory::~AndFactory() = default;

std::string AndFactory::get_component_name()
{
    return "AndFactory";
}

EntityInstancePtrOpt AndFactory::create_instance()
{
    return entity_instance_builder_factory->get_builder(And::TYPE_NAME)
        ->attribute(And::INPUT_1, false)
        ->attribute(And::INPUT_2, false)
        ->attribute(And::RESULT, false)
        ->build();
}

} // namespace inexor::entity_system::type_system
