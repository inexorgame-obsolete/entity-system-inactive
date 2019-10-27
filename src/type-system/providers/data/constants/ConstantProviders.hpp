#pragma once

#include "type-system/providers/data/constants/BoolConstantEntityTypeProvider.hpp"
#include "type-system/providers/data/constants/FloatConstantEntityTypeProvider.hpp"
#include "type-system/providers/data/constants/IntConstantEntityTypeProvider.hpp"
#include "type-system/providers/data/constants/StringConstantEntityTypeProvider.hpp"

#include <memory>

namespace inexor::entity_system::type_system {

using BoolConstantEntityTypeProviderPtr = std::shared_ptr<BoolConstantEntityTypeProvider>;
//	using FloatConstantEntityTypeProviderPtr = std::shared_ptr<FloatConstantEntityTypeProvider>;
//	using IntConstantEntityTypeProviderPtr = std::shared_ptr<IntConstantEntityTypeProvider>;
//	using StringConstantEntityTypeProviderPtr = std::shared_ptr<StringConstantEntityTypeProvider>;

/// @class ConstantProviders
/// @brief The constant entity type providers.
class ConstantProviders
{
    public:
    /// @brief Constructs the constant entity type providers.
    /// @note The dependencies of this class will be injected automatically.
    /// @param bool_constant_entity_type_provider The entity type BOOL_CONSTANT.
    explicit ConstantProviders(BoolConstantEntityTypeProviderPtr bool_constant_entity_type_provider
                               //				FloatConstantEntityTypeProvider float_constant_entity_type_provider,
                               //				IntConstantEntityTypeProvider int_constant_entity_type_provider,
                               //				StringConstantEntityTypeProvider string_constant_entity_type_provider
    );

    /// Destructor.
    ~ConstantProviders();

    /// Initializes the constant entity type providers.
    void init();

    private:
    /// Provides the entity type BOOL_CONSTANT.
    BoolConstantEntityTypeProviderPtr bool_constant_entity_type_provider;

    //			/// Provides the entity type FLOAT_CONSTANT.
    //			FloatConstantEntityTypeProvider float_constant_entity_type_provider;
    //
    //			/// Provides the entity type INT_CONSTANT.
    //			IntConstantEntityTypeProvider int_constant_entity_type_provider;
    //
    //			/// Provides the entity type STRING_CONSTANT.
    //			StringConstantEntityTypeProvider string_constant_entity_type_provider;
};

} // namespace inexor::entity_system::type_system
