#pragma once

#include "entity-system/listeners/relations/RelationInstanceCreatedListener.hpp"
#include "entity-system/listeners/relations/RelationInstanceDeletedListener.hpp"
#include "entity-system/managers/manager-templates/InstanceManagerTemplate.hpp"
#include "entity-system/managers/relation-attributes/relation-attribute-instance-manager/RelationAttributeInstanceManager.hpp"
#include "entity-system/managers/relations/relation-instance-manager/RelationInstanceManager.hpp"
#include "entity-system/model/relations/relation-instances/RelationInstance.hpp"
#include "entity-system/model/relations/relation-types/RelationType.hpp"

#include <boost/signals2.hpp>
#include <crossguid/guid.hpp>
#include <optional>

namespace inexor::entity_system {

/// These using instructions help to shorten the following code.
using RelationTypePtr = std::shared_ptr<RelationType>;
using RelationInstancePtr = std::shared_ptr<RelationInstance>;
using RelationInstancePtrOpt = std::optional<RelationInstancePtr>;
using EntityInstancePtr = std::shared_ptr<EntityInstance>;
using RelationAttributeTypePtr = std::shared_ptr<RelationAttributeType>;
using RelationAttributeInstancePtr = std::shared_ptr<RelationAttributeInstance>;

/// @class RelationInstanceManager
/// @brief A manager class for relation instances.
class RelationInstanceManager : public InstanceManagerTemplate<RelationInstance>
{
    public:
    /// @brief Constructor.
    /// @note The dependencies of this class will be injected automatically with the help of Boost DI.<br>
    /// For more information see https://boost-experimental.github.io/di/user_guide/index.html
    /// BOOST_DI_INJECT constructor parameters is limited to BOOST_DI_CFG_CTOR_LIMIT_SIZE,<br>
    /// which by default is set to 10. Not more than 10 arguments can be passed to the DI constructor!<br>
    /// @param relation_attribute_instance_manager The relation attribute instance manager.
    explicit RelationInstanceManager(std::shared_ptr<RelationAttributeInstanceManager> relation_attribute_instance_manager);

    /// @brief Destructor.
    ~RelationInstanceManager();

    /// @brief Creates a new entity relation instance.
    /// @param rel_type A const reference of a shared pointer to a relation type of which an instance will be created.
    /// @param ent_inst_source A const reference of a shared pointer to the entity instance which will be used as <b>source</b> entity instance.
    /// @param ent_inst_target A const reference of a shared pointer to the entity instance which will be used as <b>target</b> entity instance.
    /// @return A shared pointer to the new relation instance which was created.
    RelationInstancePtrOpt create_relation_instance(const RelationTypePtr &rel_type, const EntityInstancePtr &ent_inst_source, const EntityInstancePtr &ent_inst_target);

    /// @brief Creates a new entity relation instance.
    /// @param rel_inst_GUID The GUID of the new relation instance.
    /// @param rel_type A const reference of a shared pointer to a relation type of which an instance will be created.
    /// @param ent_inst_source A const reference of a shared pointer to the entity instance which will be used as <b>source</b> entity instance.
    /// @param ent_inst_target A const reference of a shared pointer to the entity instance which will be used as <b>target</b> entity instance.
    /// @return A shared pointer to the new relation instance which was created.
    RelationInstancePtrOpt create_relation_instance(const xg::Guid &rel_inst_GUID, const RelationTypePtr &rel_type, const EntityInstancePtr &ent_inst_source, const EntityInstancePtr &ent_inst_target);

    /// @brief Checks if a relation instance exists.
    /// @param rel_inst_GUID The GUID of the relation instance.
    /// @return True if the relation instance exists, false otherwise.
    bool does_relation_instance_exist(const xg::Guid &rel_inst_GUID);

    /// @brief Gets a relation instance by GUID.
    /// @param rel_inst_GUID The GUID of the relation instance.
    /// @return A std::optional shared pointer to the relation instance.
    RelationInstancePtrOpt get_relation_instance(const xg::Guid &rel_inst_GUID);

    /// @brief Returns the number of existing relation instances.
    /// @return The number of existing relation instances.
    std::size_t get_relation_instances_count() const;

    /// @brief Deletes a relation instance by GUID.
    /// @param rel_inst_GUID The GUID of the relation instance.
    std::size_t delete_relation_instance(const xg::Guid &rel_inst_GUID);

    /// @brief Deletes a relation instance by shared pointer.
    /// @param rel_inst The relation instance which will be deleted.
    std::size_t delete_relation_instance(const RelationInstancePtr &rel_inst);

    /// @brief Deletes all relation instances
    void delete_all_relation_instances();

    /// @brief Registers a listener which gets informed if a relation instance of the given relation type has been created.
    /// @param rel_type_GUID The GUID of the relation type.
    /// @param rel_inst_created_listener The listener.
    void register_on_created(const xg::Guid &rel_type_GUID, const std::shared_ptr<RelationInstanceCreatedListener> &rel_inst_created_listener);

    /// @brief Registers a listener which gets informed if a relation instance of the given relation type has been deleted.
    /// @param rel_type_GUID The GUID of the relation type.
    /// @param rel_inst_deleted_listener The listener.
    void register_on_deleted(const xg::Guid &rel_type_GUID, const std::shared_ptr<RelationInstanceDeletedListener> &rel_inst_deleted_listener);

    // TODO: get_all_relation_instances_of_type() const;
    // TODO: std::vector<RelationInstancePtr> get_all_relation_instances() const;
    // TODO: get_relation_instance_count_of_type() const;
    // TODO: Delete relation instances by source entity instance
    // TODO: Delete relation instances by target entity instance
    // TODO: Delete relation instances by entity instance (both: source and target)
    //		 Called by delete_entity_instance() -> also delete all relation instances of the to-be-deleted entity instance!
    // TODO: Delete relation instances by relation type

    private:
    /// The relation attribute instance manager.
    std::shared_ptr<RelationAttributeInstanceManager> relation_attribute_instance_manager;

    /// @brief Notifies all listeners that a new relation instance has been created.
    /// @param rel_inst The relation instance which has been created.
    /// @TODO use const std::shared_ptr<T>& instead?
    void notify_relation_instance_created(const RelationInstancePtr &rel_inst);

    /// @brief Notifies all listeners that a relation instance has been deleted.
    /// @param rel_type_GUID The GUID of the relation type.
    /// @param rel_inst_GUID The GUID of the relation instance.
    void notify_relation_instance_deleted(const xg::Guid &rel_type_GUID, const xg::Guid &rel_inst_GUID);

    /// The signals that an relation instance has been created.
    /// Key is the GUID of the relation type.
    /// Value is a signal with one parameter: the created relation instance
    std::unordered_map<xg::Guid, std::shared_ptr<boost::signals2::signal<void(RelationInstancePtr rel_inst)>>> signals_relation_instance_created;

    /// The signals that an relation instance has been deleted.
    /// Key is the GUID of the relation type.
    /// Value is a signal with two parameters: the GUID of the relation type, the GUID of the relation instance
    std::unordered_map<xg::Guid, std::shared_ptr<boost::signals2::signal<void(const xg::Guid &rel_type_GUID, const xg::Guid &rel_inst_GUID)>>> signals_relation_instance_deleted;

    /// The mutex of this class.
    std::mutex relation_instance_manager;
};

} // namespace inexor::entity_system
