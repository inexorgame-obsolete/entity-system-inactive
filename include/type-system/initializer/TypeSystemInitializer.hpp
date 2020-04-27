#pragma once

#include <Corrade/Utility/Resource.h>

#include "base/LifeCycleComponent.hpp"
#include "entity-system/serializers/EntityTypeJsonSerializer.hpp"

namespace inexor::entity_system::type_system {

using EntityTypeJsonSerializerPtr = std::shared_ptr<serializers::EntityTypeJsonSerializer>;

/// @class TypeSystemInitializer
/// @brief Initializes the type system using static resources.
class TypeSystemInitializer : public LifeCycleComponent
{
    public:
    /// @brief Constructs the initializer of the type system.
    /// @param entity_type_json_serializer The JSON serializer for entity types.
    explicit TypeSystemInitializer(EntityTypeJsonSerializerPtr entity_type_json_serializer);

    /// Destructor.
    ~TypeSystemInitializer();

    /// Pre-Initialization of the type system module.
    void pre_init() override;

    /// Initializes the type system using static resources.
    void init() override;

    /// Returns the name of the component
    std::string get_component_name() override;

    /// Loads a type definition
    void load_type_definition(const Corrade::Utility::Resource &rs, const std::string &file);

    private:
    /// Serializer for entity types.
    EntityTypeJsonSerializerPtr entity_type_json_serializer;

    /// The resource group for statically included types.
    static constexpr char RESOURCE_GROUP[] = "inexor-type-system";
};

} // namespace inexor::entity_system::type_system
