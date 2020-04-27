#pragma once

#include "entity-system/factories/BuilderFactories.hpp"
#include "entity-system/managers/EntityManager.hpp"
#include "entity-system/managers/RelationManager.hpp"
#include "entity-system/serializers/EntitySystemSerializers.hpp"
#include "logging/managers/LogManager.hpp"

namespace inexor::entity_system {

/// @class EntitySystemModule
/// @brief The entity system module.
class EntitySystemModule
{
    public:
    /// These using instructions help to shorten the following code.
    using EntityManagerPtr = std::shared_ptr<EntityManager>;
    using RelationManagerPtr = std::shared_ptr<RelationManager>;
    using BuilderFactoriesPtr = std::shared_ptr<BuilderFactories>;
    using TypeSystemSerializersPtr = std::shared_ptr<serializers::EntitySystemSerializers>;
    using LogManagerPtr = std::shared_ptr<logging::LogManager>;

    /// @brief Constructs the entity system module.
    /// @note The dependencies of this class will be injected automatically.<br>
    /// BOOST_DI_INJECT constructor parameters is limited to BOOST_DI_CFG_CTOR_LIMIT_SIZE,<br>
    /// which by default is set to 10. Not more than 10 arguments can be passed to the DI constructor!<br>
    /// https://boost-experimental.github.io/di/user_guide/index.html
    /// @param entity_manager The manager for entity types, entity instances, attribute types and attribute instances.
    /// @param relation_manager The manager for relation types, relation instances, relation attribute types and relation attribute instances.
    /// @param builder_factories The manager for the builder factories.
    /// @param type_system_serializers The serializers of the type system.
    /// @param log_manager The log manager.
    EntitySystemModule(EntityManagerPtr entity_manager, RelationManagerPtr relation_manager, BuilderFactoriesPtr builder_factories, TypeSystemSerializersPtr type_system_serializers, LogManagerPtr log_manager);

    /// @brief Destructs the entity system module.
    ~EntitySystemModule();

    /// @brief Completely resets the entity system.
    /// @note Order of destruction:
    /// <ol>
    ///   <li> relation attribute instances
    ///   <li> relation attribute types
    ///   <li> relation instances
    ///   <li> relation types
    ///   <li> entity attribute instances
    ///   <li> entity attribute types
    ///   <li> entity instances
    ///   <li> entity types
    /// </ol>
    void reset_entity_system();

    private:
    /// The manager for entity types, entity instances, attribute types and attribute instances.
    EntityManagerPtr entity_manager;

    /// The manager for relation types, relation instances, relation attribute types and relation attribute instances.
    RelationManagerPtr relation_manager;

    /// The manager for the builder factories.
    BuilderFactoriesPtr builder_factories;

    /// The type system serializers.
    TypeSystemSerializersPtr type_system_serializers;

    /// The manager for logging.
    LogManagerPtr log_manager;

    /// The logger name of this service.
    static constexpr char LOGGER_NAME[] = "inexor.entsys";

    /// The mutex of this class.
    std::mutex entity_system_module;
};

} // namespace inexor::entity_system
