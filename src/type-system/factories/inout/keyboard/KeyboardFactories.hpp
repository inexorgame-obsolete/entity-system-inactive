#pragma once

#include "base/LifeCycleComponent.hpp"
#include "type-system/factories/inout/keyboard/GlobalKeyFactory.hpp"

#include <memory>

namespace inexor::entity_system::type_system {

using GlobalKeyFactoryPtr = std::shared_ptr<GlobalKeyFactory>;

/// @class KeyboardFactories
/// @brief The factories for keyboard input.
class KeyboardFactories : public LifeCycleComponent
{
    public:
    /// @brief Constructs the factories for keyboard input.
    /// @note The dependencies of this class will be injected automatically.
    /// @param global_key_factory Factory for creating entity instances of type 'GLOBAL_KEY'.
    explicit KeyboardFactories(GlobalKeyFactoryPtr global_key_factory);

    /// Destructor.
    ~KeyboardFactories();

    /// Returns the name of the component
    std::string get_component_name() override;

    /// Returns the factory for entities of type 'GLOBAL_KEY'.
    GlobalKeyFactoryPtr get_global_key_factory();

    private:
    /// Factory for creating entity instances of type 'GLOBAL_KEY'.
    GlobalKeyFactoryPtr global_key_factory;
};

} // namespace inexor::entity_system::type_system
