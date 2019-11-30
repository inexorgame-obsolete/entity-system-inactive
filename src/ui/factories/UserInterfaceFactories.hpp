#pragma once

#include "base/LifeCycleComponent.hpp"
#include "MonitorFactory.hpp"
#include "WindowFactory.hpp"

namespace inexor::ui {

/// @class UserInterfaceFactories
/// @brief The factories for creating user interface entity instances.
class UserInterfaceFactories : public LifeCycleComponent
{
    using MonitorFactoryPtr = std::shared_ptr<ui::MonitorFactory>;
    using WindowFactoryPtr = std::shared_ptr<ui::WindowFactory>;

    public:
    /// @brief Constructor.
    /// @param monitor_factory The monitor factory.
    /// @param window_factory The window factory.
    UserInterfaceFactories(MonitorFactoryPtr monitor_factory, WindowFactoryPtr window_factory);

    /// Destructor.
    ~UserInterfaceFactories();

    /// Returns the name of the component
    std::string get_component_name() override;

    private:
    /// The monitory factory.
    MonitorFactoryPtr monitor_factory;

    /// The window factory.
    WindowFactoryPtr window_factory;
};

} // namespace inexor::ui
