#include "EqualsBoolFactory.hpp"

#include <type-system/types/logical/comparison/EqualsBool.hpp>
#include <utility>

namespace inexor::entity_system::type_system {

EqualsBoolFactory::EqualsBoolFactory(EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
    : LifeCycleComponent()
{
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

EqualsBoolFactory::~EqualsBoolFactory() = default;

std::string EqualsBoolFactory::get_component_name()
{
    return "EqualsBoolFactory";
}

EntityInstancePtrOpt EqualsBoolFactory::create_instance()
{
    return entity_instance_builder_factory->get_builder(EqualsBool::TYPE_NAME)
        ->attribute(EqualsBool::INPUT_1, false)
        ->attribute(EqualsBool::INPUT_2, false)
        ->attribute(EqualsBool::RESULT, true)
        ->build();
}

} // namespace inexor::entity_system::type_system
