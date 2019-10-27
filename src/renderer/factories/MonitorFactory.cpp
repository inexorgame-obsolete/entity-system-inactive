#include "MonitorFactory.hpp"

#include <utility>

namespace inexor::renderer {

MonitorFactory::MonitorFactory(MonitorEntityTypeProviderPtr monitor_entity_type_provider, EntityInstanceBuilderFactoryPtr entity_instance_builder_factory, EntityInstanceManagerPtr entity_instance_manager)
{
    this->monitor_entity_type_provider = std::move(monitor_entity_type_provider);
    this->entity_instance_builder_factory = std::move(entity_instance_builder_factory);
    this->entity_instance_manager = std::move(entity_instance_manager);
}

MonitorFactory::~MonitorFactory() = default;

EntityInstancePtrOpt MonitorFactory::create_instance(const std::string &title, int x, int y, int width, int height, bool is_primary)
{
    return this->entity_instance_builder_factory->get_builder()
        ->type(monitor_entity_type_provider->get_type())
        ->attribute(MonitorEntityTypeProvider::MONITOR_TITLE, title)
        ->attribute(MonitorEntityTypeProvider::MONITOR_POSITION_X, x)
        ->attribute(MonitorEntityTypeProvider::MONITOR_POSITION_Y, y)
        ->attribute(MonitorEntityTypeProvider::MONITOR_WIDTH, width)
        ->attribute(MonitorEntityTypeProvider::MONITOR_HEIGHT, height)
        ->attribute(MonitorEntityTypeProvider::MONITOR_IS_PRIMARY, is_primary)
        ->build();
}

} // namespace inexor::renderer
