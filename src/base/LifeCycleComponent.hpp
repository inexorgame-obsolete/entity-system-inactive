#pragma once

#include <cstdint>
#include <memory>
#include <tuple>
#include <vector>

#include <boost/range/adaptor/reversed.hpp>

#include <spdlog/spdlog.h>

namespace inexor {

/**
 * Derived classes profits from automatic initialization and destruction
 * of the sub components.
 */
class LifeCycleComponent
{
    protected:
    /// @brief Constructor.
    template <class... LifeCycleComponents>
    LifeCycleComponent(LifeCycleComponents... _sub_components) : sub_components{_sub_components...} {};

    /// @brief Destructor.
    ~LifeCycleComponent() = default;

    public:

    virtual void pre_init() {}

    void pre_init_components()
    {
        // Pre-Initialize before sub components are constructed
        pre_init();
        spdlog::info("Pre-Initializing {} sub components of {}", sub_components.size(), this->get_component_name());
        for (const std::shared_ptr<LifeCycleComponent> &sub_component : sub_components)
        {
            sub_component->pre_init_components();
        }
    }

    virtual void init() {}

    void init_components()
    {
        // Initialize before sub components are constructed
        init();
        spdlog::info("Initializing {} sub components of {}", sub_components.size(), this->get_component_name());
        for (const std::shared_ptr<LifeCycleComponent> &sub_component : sub_components)
        {
            sub_component->init_components();
        }
    }

    virtual void destroy() {}

    void destroy_components()
    {
        spdlog::info("Destroying {} sub components of {}", sub_components.size(), this->get_component_name());
        // Destruction in reverse order
        for (const std::shared_ptr<LifeCycleComponent> &sub_component : boost::adaptors::reverse(sub_components))
        {
            sub_component->destroy_components();
        }
        // Destruction after sub components are destructed
        destroy();
    }

    virtual void post_destroy() {}

    void post_destroy_components()
    {
        spdlog::info("Post-Destroying {} sub components of {}", sub_components.size(), this->get_component_name());
        // Destruction in reverse order
        for (const std::shared_ptr<LifeCycleComponent> &sub_component : boost::adaptors::reverse(sub_components))
        {
            sub_component->post_destroy_components();
        }
        // Destruction after sub components are destructed
        post_destroy();
    }

    virtual std::string get_component_name()
    {
        return typeid(this).name();
    }

    private:
    std::vector<std::shared_ptr<LifeCycleComponent>> sub_components;
};

} // namespace inexor
