#pragma once

#include <crossguid/guid.hpp>

namespace inexor::entity_system {

/// @class EntityTypeDeletedListener
/// @brief Listener for newly created entity types.
class EntityTypeDeletedListener
{
    public:
    /// @brief Called if an entity type has been deleted.
    /// @param type_GUID The GUID of the entity type which was deleted.
    virtual void on_entity_type_deleted(const xg::Guid &type_GUID) = 0;
};

} // namespace inexor::entity_system
