// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_ENTITY_MANAGER_CLASS_HEADER
#define INEXOR_ENTSYS_ENTITY_MANAGER_CLASS_HEADER

#include <vector>
#include "entity-types-manager\EntityTypeInstanceManager.hpp"
#include "entity-types-manager\EntityTypeManager.hpp"
#include "entity-attributes-manager\EntityAttributeTypeManager.hpp"
#include "entity-attributes-manager\EntityAttributeTypeInstanceManager.hpp"
#include "entity-relations-manager\EntityRelationTypeManager.hpp"
#include "entity-relations-manager\EntityRelationTypeInstanceManager.hpp"

namespace inexor {
namespace entsys {

    /// \class CEntityManager
    /// \brief The entity manager class is responsible for adding, modifying and removing entites.
    class EntityManager : public EntityTypeManager,
                          public EntityTypeInstanceManager,
                          public EntityAttributeTypeManager,
                          public EntityAttributeTypeInstanceManager,
                          public EntityRelationTypeManager,
                          public EntityRelationTypeInstanceManager
    {
        public:
            EntityManager();
            ~EntityManager();

    };

};
};


#endif // INEXOR_ENTSYS_ENTITY_MANAGER_CLASS_HEADER
