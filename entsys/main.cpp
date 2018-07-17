// Inexor entity system prototype
// (c)2018 Inexor

#include <iostream>
using namespace std;

// entity system
#include "EntitySystem.hpp"
using namespace inexor;
using namespace entsys;

// create singleton instance
// a singleton class can only be instanced once!
// TODO: why does placing this in EntitySystem.hpp cause a linker error?
EntitySystem* sys = EntitySystem::create_entity_system();

int main()
{
    // ENTITY TYPE TESTS

    EntityTypeBase spawnpoint(std::string("spawnpoint"));
    sys->create_entity_type(spawnpoint);

    cout << "numer of entity types available: " << sys->get_entity_type_cound() << endl;

    EntityTypeBase i_am_duplicate(std::string("spawnpoint"));
    if(ENTSYS_RETURN_ENTITY_TYPE_ALREADY_EXISTS == sys->create_entity_type(i_am_duplicate))
    {
        cout << "this entity type does already exist (as expected)!" << endl;
    }

    cout << "numer of entity types available: " << sys->get_entity_type_cound() << endl;

    EntityTypeBase can_this_be_found;
    if(ENTSYS_RETURN_SUCCESS == sys->get_entity_type_class(std::string("spawnpoint"), can_this_be_found))
    {
        cout << "I could look up entity type 'spawnpoint' successfully!" << endl;
    }

    // create 1 million entities
    for(size_t i=0; i<1000000; i++)
    {
        EntityTypeBase i_am_duplicate(std::string(std::to_string(i)));
        sys->create_entity_type(i_am_duplicate);
    }

    cout << "numer of entity types available: " << sys->get_entity_type_cound() << endl;

    return 0;
}
