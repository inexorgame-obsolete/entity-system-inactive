// Inexor entity system prototype
// (c)2018 Inexor

#include "EntSys_EntityManagerClass.hpp"

namespace inexor {
namespace entsys {

    CEntityManager::CEntityManager()
    {
    }

    CEntityManager::~CEntityManager()
    {
        remove_all_entities();
    }

    ENTSYS_RESULT_CODE CEntityManager::add_entity(CEntityBase newent)
    {
        entities.push_back(newent);
        return ENTSYS_RESULT_ERROR;
    }

    size_t CEntityManager::entity_count()
    {
        return entities.size();
    }

    ENTSYS_RESULT_CODE CEntityManager::remove_entity()
    {
        // TODO: implement
        return ENTSYS_RESULT_ERROR;
    }

    void CEntityManager::remove_all_entities()
    {
        entities.clear();
    }

};
};
