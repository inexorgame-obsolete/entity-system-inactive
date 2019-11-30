#include "GlobalMouseButtonFactory.hpp"

#include <type-system/types/inout/mouse/GlobalMouseButton.hpp>
#include <utility>

namespace inexor::entity_system::type_system {

GlobalMouseButtonFactory::GlobalMouseButtonFactory(EntityInstanceBuilderFactoryPtr entity_instance_builder_factory)
    : LifeCycleComponent()
{
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
}

GlobalMouseButtonFactory::~GlobalMouseButtonFactory() = default;

std::string GlobalMouseButtonFactory::get_component_name()
{
    return "GlobalMouseButtonFactory";
}

EntityInstancePtrOpt GlobalMouseButtonFactory::create_instance(const int &button)
{
    return entity_instance_builder_factory->get_builder(GlobalMouseButton::TYPE_NAME)
        ->attribute(GlobalMouseButton::BUTTON_NUMBER, button)
        ->attribute(GlobalMouseButton::ACTION, 0)
        ->attribute(GlobalMouseButton::MODS, 0)
        ->build();
}

} // namespace inexor::entity_system::type_system
