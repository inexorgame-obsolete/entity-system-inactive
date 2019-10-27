#pragma once

#include "type-system/providers/inout/mouse/GlobalMouseButtonEntityTypeProvider.hpp"

#include <memory>

namespace inexor::entity_system::type_system {

using GlobalMouseButtonEntityTypeProviderPtr = std::shared_ptr<GlobalMouseButtonEntityTypeProvider>;

/// @class MouseProviders
/// @brief The entity type providers for mouse input.
class MouseProviders
{
    public:
    /// @brief Constructs the entity type providers for the mouse input.
    /// @note The dependencies of this class will be injected automatically.
    /// @param global_mouse_button_entity_type_provider Provides the entity type GLOBAL_MOUSE_BUTTON.
    explicit MouseProviders(GlobalMouseButtonEntityTypeProviderPtr global_mouse_button_entity_type_provider);

    /// Destructor.
    ~MouseProviders();

    /// Initializes the entity type providers for the mouse input.
    void init();

    private:
    /// Provides the entity type GLOBAL_MOUSE_BUTTON.
    GlobalMouseButtonEntityTypeProviderPtr global_mouse_button_entity_type_provider;
};

} // namespace inexor::entity_system::type_system
