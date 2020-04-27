#pragma once

#include "base/LifeCycleComponent.hpp"
#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"

#include "spdlog/common.h"

namespace inexor::entity_system::type_system {

using EntityInstancePtr = std::shared_ptr<EntityInstance>;
using EntityInstancePtrOpt = std::optional<EntityInstancePtr>;
using EntityInstanceBuilderFactoryPtr = std::shared_ptr<EntityInstanceBuilderFactory>;

/// @class GlobalMouseButtonFactory
/// @brief Factory for creating entity instances of type GLOBAL_MOUSE_BUTTON.
class GlobalMouseButtonFactory : public LifeCycleComponent
{
    public:
    /// @brief Constructor.
    /// @note The dependencies of this class will be injected automatically.
    /// @param entity_instance_builder_factory Factory for creating entity instance builders.
    GlobalMouseButtonFactory(EntityInstanceBuilderFactoryPtr entity_instance_builder_factory);

    /// Destructor.
    ~GlobalMouseButtonFactory();

    /// Returns the name of the component
    std::string get_component_name() override;

    /// @brief Creates an instance and sets the given name.
    /// @param button The mouse button number.
    EntityInstancePtrOpt create_instance(const int &button);

    private:
    /// Factory for creating entity instance builders.
    EntityInstanceBuilderFactoryPtr entity_instance_builder_factory;
};

} // namespace inexor::entity_system::type_system
