#pragma once

#include "type-system/factories/TypeSystemFactories.hpp"
#include "type-system/providers/TypeSystemProviders.hpp"

namespace inexor::entity_system::type_system {

using TypeSystemProvidersPtr = std::shared_ptr<TypeSystemProviders>;
using TypeSystemFactoriesPtr = std::shared_ptr<TypeSystemFactories>;

/// @class TypeSystemModule
/// @brief The type system module.
class TypeSystemModule
{
    public:
    /// @brief Constructs the type system module.
    /// @note The dependencies of this class will be injected automatically.
    /// @param type_system_providers The providers of the type system.
    /// @param type_system_factories The factories of the type system.
    TypeSystemModule(TypeSystemProvidersPtr type_system_providers, TypeSystemFactoriesPtr type_system_factories);

    /// Destructor.
    ~TypeSystemModule();

    /// Initializes the type system module.
    void init();

    private:
    /// The providers of the type system.
    TypeSystemProvidersPtr type_system_providers;

    /// The factories of the type system.
    TypeSystemFactoriesPtr type_system_factories;
};

} // namespace inexor::entity_system::type_system
