#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

#include <utility>

namespace inexor::renderer {

using namespace entity_system;

using EntityTypeBuilderFactoryPtr = std::shared_ptr<EntityTypeBuilderFactory>;

/// @class MonitorEntityTypeProvider
/// @brief Provides an entity type "MONITOR".
class MonitorEntityTypeProvider : public EntityTypeProvider
{
    public:
    /// @brief Constructs the specialized provider for the entity type 'MONITOR'.
    /// @note The dependencies of this class will be injected automatically.
    explicit MonitorEntityTypeProvider(EntityTypeBuilderFactoryPtr entity_type_builder_factory)
        : EntityTypeProvider(std::move(entity_type_builder_factory), TYPE_NAME,
                             {{MONITOR_TITLE, {DataType::STRING, 1 << Feature::INPUT | 1 << Feature::OUTPUT}},
                              {MONITOR_POSITION_X, {DataType::INT, 1 << Feature::INPUT | 1 << Feature::OUTPUT}},
                              {MONITOR_POSITION_Y, {DataType::INT, 1 << Feature::INPUT | 1 << Feature::OUTPUT}},
                              {MONITOR_WIDTH, {DataType::INT, 1 << Feature::INPUT | 1 << Feature::OUTPUT}},
                              {MONITOR_HEIGHT, {DataType::INT, 1 << Feature::INPUT | 1 << Feature::OUTPUT}},
                              {MONITOR_IS_PRIMARY, {DataType::BOOL, 1 << Feature::OUTPUT}}}){};

    /// Destructor.
    ~MonitorEntityTypeProvider() override = default;

    /// Defines the name of this entity type
    static constexpr char TYPE_NAME[] = "MONITOR";

    /// The name of the attribute monitor title. (glfwGetMonitorName)
    static constexpr char MONITOR_TITLE[] = "monitor_title";

    /// The name of the attribute monitor position x. (glfwGetMonitorWorkarea)
    /// https://www.glfw.org/docs/3.3/intro_guide.html#coordinate_systems
    static constexpr char MONITOR_POSITION_X[] = "monitor_position_x";

    /// The name of the attribute monitor position y. (glfwGetMonitorWorkarea)
    static constexpr char MONITOR_POSITION_Y[] = "monitor_position_y";

    /// The name of the attribute monitor width. (glfwGetMonitorWorkarea)
    static constexpr char MONITOR_WIDTH[] = "monitor_width";

    /// The name of the attribute monitor height. (glfwGetMonitorWorkarea)
    static constexpr char MONITOR_HEIGHT[] = "monitor_height";

    /// The name of the attribute monitor is primary. (glfwGetPrimaryMonitor)
    static constexpr char MONITOR_IS_PRIMARY[] = "monitor_is_primary";
};

} // namespace inexor::renderer
