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
    // DATA CONTAINER TESTS
    DataContainer dump(ENTSYS_DATA_TYPE_STRING);
    dump.set(std::string("Hello world. I am a string in a very flexible data container class!"));

    DataContainer dump2(12.0f);
    DataContainer dump3(1212.0);
    // This does work
    dump3.set(3245.0);

    DataContainer dump4(true);
    // This does NOT work!
    dump4.set("Hello World.. This does not work sadly! It's a bool val not a string!");

    DataContainer dump5(123131523143);

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

    // create 1 million entity types
    for(size_t i=0; i<1000000; i++)
    {
        EntityTypeBase i_am_duplicate(std::string(std::to_string(i)));
        sys->create_entity_type(i_am_duplicate);
        cout << "numer of entity types available: " << sys->get_entity_type_cound() << endl;
    }


    
    // ENTITY ATTRIBUTE TESTS




    return 0;
}
