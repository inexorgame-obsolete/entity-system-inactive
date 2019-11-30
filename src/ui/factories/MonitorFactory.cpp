#include "MonitorFactory.hpp"

#include <type-system/types/ui/Monitor.hpp>
#include <utility>

namespace inexor::ui {

using Monitor = entity_system::type_system::Monitor;

MonitorFactory::MonitorFactory(EntityInstanceBuilderFactoryPtr entity_instance_builder_factory, EntityInstanceManagerPtr entity_instance_manager)
    : LifeCycleComponent()
{
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
    this->entity_instance_manager = std::move(entity_instance_manager);
}

MonitorFactory::~MonitorFactory() = default;

std::string MonitorFactory::get_component_name()
{
    return "MonitorFactory";
}

EntityInstancePtrOpt MonitorFactory::create_instance(const std::string &title, int x, int y, int width, int height, bool is_primary)
{
    return this->entity_instance_builder_factory->get_builder(Monitor::TYPE_NAME)
        ->attribute(Monitor::TITLE, title)
        ->attribute(Monitor::POSITION_X, x)
        ->attribute(Monitor::POSITION_Y, y)
        ->attribute(Monitor::WIDTH, width)
        ->attribute(Monitor::HEIGHT, height)
        ->attribute(Monitor::IS_PRIMARY, is_primary)
        ->build();
}

} // namespace inexor::ui
