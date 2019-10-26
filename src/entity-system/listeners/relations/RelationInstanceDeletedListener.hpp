#pragma once

#include <crossguid/guid.hpp>

namespace inexor::entity_system {

/// @class RelationInstanceDeletedListener
/// @brief Listener for deleted relation instances.
class RelationInstanceDeletedListener
{
    public:
    /// @brief Called if a relation instance has been deleted.
    /// @param type_GUID The GUID of the relation type of which a relation instance was deleted.
    /// @param instance_GUID The GUID of the relation instance which was deleted.
    virtual void on_relation_instance_deleted(const xg::Guid &type_GUID, const xg::Guid &instance_GUID) = 0;
};

} // namespace inexor::entity_system
