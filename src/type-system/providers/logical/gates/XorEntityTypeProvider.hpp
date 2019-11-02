#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

/// @class XorEntityTypeProvider
/// Provides an entity type "XOR".
class XorEntityTypeProvider : public EntityTypeProvider
{
    public:
    /// Constructs the specialized provider for the entity type XOR.
    /// @note The dependencies of this class will be injected automatically.
    /// @param entity_type_builder_manager The entity type builder manager.
    explicit XorEntityTypeProvider(std::shared_ptr<EntityTypeBuilderFactory> entity_type_builder_manager)
        : EntityTypeProvider(std::move(entity_type_builder_manager), TYPE_NAME,
                             {{XOR_INPUT_1, {DataType::BOOL, Features::INPUT}}, {XOR_INPUT_2, {DataType::BOOL, Features::INPUT}}, {XOR_RESULT, {DataType::BOOL, Features::OUTPUT}}}){};

    /// Destructor.
    ~XorEntityTypeProvider() override = default;

    /// Defines the name of this entity type.
    static constexpr char TYPE_NAME[] = "XOR";

    /// The name of the attribute xor_input_1.
    static constexpr char XOR_INPUT_1[] = "xor_input_1";

    /// The name of the attribute xor_input_1.
    static constexpr char XOR_INPUT_2[] = "xor_input_2";

    /// The name of the attribute xor_result.
    static constexpr char XOR_RESULT[] = "xor_result";
};

} // namespace inexor::entity_system::type_system
