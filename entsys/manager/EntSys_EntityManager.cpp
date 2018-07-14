#include "EntSys_EntityManager.hpp"

namespace inexor {
namespace entsys {

    CEntityManager::CEntityManager()
    {
    }

    CEntityManager::~CEntityManager()
    {
        // remove all entities
        entities.clear();
    }
    
    bool CEntityManager::validate_entity(CEntityBase newent)
    {
        // TODO: implement
        return false;
    }

    ENTSYS_RESULT_CODE CEntityManager::add_entity(CEntityBase newent)
    {
        entities.push_back(newent);
        return ENTSYS_RESULT_ERROR;
    }

    ENTSYS_RESULT_CODE CEntityManager::remove_entity()
    {
        // TODO: implement
        return ENTSYS_RESULT_ERROR;
    }

    ENTSYS_RESULT_CODE CEntityManager::remove_all_entities()
    {
        // TODO: implement
        return ENTSYS_RESULT_ERROR;
    }

};
};
