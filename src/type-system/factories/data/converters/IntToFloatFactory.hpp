#pragma once

#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "type-system/providers/data/converters/IntToFloatEntityTypeProvider.hpp"

namespace inexor::entity_system::type_system {

using IntToFloatEntityTypeProviderPtr = std::shared_ptr<IntToFloatEntityTypeProvider>;
using EntityInstancePtrOpt = std::optional<std::shared_ptr<EntityInstance>>;
using EntityInstanceBuilderFactoryPtr = std::shared_ptr<EntityInstanceBuilderFactory>;

/// @class IntToFloatFactory
/// @brief Factory for creating entity instances of type INT_TO_FLOAT.
class IntToFloatFactory
{
    public:
    /// @brief Constructs a factory for creating entity instances of type INT_TO_FLOAT.
    /// @note The dependencies of this class will be injected automatically.
    /// @param entity_type_provider Provides the entity type INT_TO_FLOAT.
    /// @param entity_instance_builder_factory Factory for creating entity instance builders.
    IntToFloatFactory(IntToFloatEntityTypeProviderPtr entity_type_provider, EntityInstanceBuilderFactoryPtr entity_instance_builder_factory);

    /// Destructor.
    ~IntToFloatFactory();

    /// Initializes the factory.
    void init();

    /// Creates an INT_TO_FLOAT.
    EntityInstancePtrOpt create_instance();

    /// Creates an INT_TO_FLOAT.
    /// @param name ?
    /// @param int_value ?
    /// @param float_value ?
    EntityInstancePtrOpt create_instance(const std::string &name, const int &int_value, const float &float_value);

    private:
    /// Provides the entity type INT_TO_FLOAT.
    IntToFloatEntityTypeProviderPtr entity_type_provider;

    /// Factory for creating entity instance builders.
    EntityInstanceBuilderFactoryPtr entity_instance_builder_factory;
};

} // namespace inexor::entity_system::type_system
