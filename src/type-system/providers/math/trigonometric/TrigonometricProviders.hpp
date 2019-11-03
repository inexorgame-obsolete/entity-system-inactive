#pragma once

#include "type-system/providers/math/trigonometric/CosEntityTypeProvider.hpp"
#include "type-system/providers/math/trigonometric/SinEntityTypeProvider.hpp"

#include <memory>

namespace inexor::entity_system::type_system {

using SinEntityTypeProviderPtr = std::shared_ptr<SinEntityTypeProvider>;
using CosEntityTypeProviderPtr = std::shared_ptr<CosEntityTypeProvider>;

/// @class TrigonometricProviders
/// @brief The trigonometric entity type providers.
class TrigonometricProviders
{
    public:
    /// @brief Constructs the trigonometric entity type providers.
    /// @note The dependencies of this class will be injected automatically.
    /// @param sin_entity_type_provider Provides the entity type SIN.
    /// @param cos_entity_type_provider Provides the entity type COS.
    TrigonometricProviders(SinEntityTypeProviderPtr sin_entity_type_provider, CosEntityTypeProviderPtr cos_entity_type_provider);

    /// Destructor.
    ~TrigonometricProviders();

    /// Initializes the trigonometric entity type providers.
    void init();

    private:
    /// Provides the entity type SIN.
    SinEntityTypeProviderPtr sin_entity_type_provider;

    /// Provides the entity type COS.
    CosEntityTypeProviderPtr cos_entity_type_provider;
};

} // namespace inexor::entity_system::type_system
