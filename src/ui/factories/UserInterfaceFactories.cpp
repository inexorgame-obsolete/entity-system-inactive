#include "UserInterfaceFactories.hpp"

namespace inexor::ui {

UserInterfaceFactories::UserInterfaceFactories(MonitorFactoryPtr monitor_factory, WindowFactoryPtr window_factory)
    : LifeCycleComponent(monitor_factory, window_factory)

{
    this->monitor_factory = std::move(monitor_factory);
    this->window_factory = std::move(window_factory);
}

UserInterfaceFactories::~UserInterfaceFactories() = default;

std::string UserInterfaceFactories::get_component_name()
{
    return "UserInterfaceFactories";
}

} // namespace inexor::ui
