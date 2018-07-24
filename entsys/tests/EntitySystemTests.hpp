// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_TESTING_FRAMEWORK_HEADER
#define INEXOR_ENTSYS_TESTING_FRAMEWORK_HEADER

#include "../EntitySystem.hpp"
extern inexor::entsys::EntitySystem* entity_system;

// Start and end tests with the profiler.
#include "../tests/EntitySystemProfiler.hpp"


namespace inexor {
namespace entsys {
    

    void Test_EntitySystemDataContainers()
    {
        DataContainer dc_int(0);
        DataContainer dc_bigint(std::int64_t(0));
        DataContainer dc_string(std::string(""));
        DataContainer dc_bool(false);
        DataContainer dc_float(0.0f);
        DataContainer dc_double(0.0);
    
        start_test();
        cout << "Call DataContainer::operator=(int) 1000 times:" << endl;
        for(int i=0; i<1000; i++) {
            dc_int.set(0);
            dc_int = i;
        }
        end_test();

        start_test();
        cout << "Call DataContainer::operator=(float) 1000 times:" << endl;
        for(float i=0.0f; i<1000.0f; i+=1.0f) {
            dc_float.set(0.0f);
            dc_float = i;
        }
        end_test();

        start_test();
        cout << "Call DataContainer::operator=(double) 1000 times:" << endl;
        for(double i=0.0f; i<1000.0f; i+=1.0f) {
            dc_double.set(0.0);
            dc_double = i;
        }
        end_test();

        start_test();
        cout << "Call DataContainer::operator=(bool) 1000 times:" << endl;
        for(int i=0; i<1000; i+=1) {
            dc_bool.set(false);
            dc_bool = (0==(i%2)) ? true : false;
        }
        end_test();

        start_test();
        cout << "Call DataContainer::operator=(std::int64_t) 1000 times:" << endl;
        for(int64_t i=0; i<1000; i+=1) {
            dc_bigint.set(0);
            dc_bigint = i;
        }
        end_test();

        start_test();
        cout << "Call DataContainer::operator=(std::string) 1000 times:" << endl;
        for(int i=0; i<1000; i+=1) {
            dc_string.set(std::string(""));
            dc_string = std::to_string(i);
        }
        end_test();

        // add, sub, mul, div
        // TODO: Why is this constructor call for add, sub, mul, div 
        // methods even working btw?

        start_test();
        cout << "Call DataContainer::add(int) 1000 times:" << endl;
        for(int i=0; i<1000; i+=1) dc_int.add(1);
        end_test();

        start_test();
        dc_int.set(1000);
        cout << "Call DataContainer::sub(int) 1000 times:" << endl;
        for(int i=0; i<1000; i+=1) dc_int.sub(1);
        end_test();

        start_test();
        dc_int.set(2);
        cout << "Call DataContainer::mul(int) 1000 times:" << endl;
        for(int i=0; i<1000; i+=1) dc_int.mul(2);
        end_test();

        start_test();
        cout << "Call DataContainer::mul(int) 1000 times:" << endl;
        for(int i=0; i<1000; i+=1) dc_int.div(2);
        end_test();

        start_test();
        int test_int = 0;
        cout << "Call DataContainer::get_intval() 1 million times:" << endl;
        for(int i=0; i<1000000; i++) test_int = dc_int.get_intval();
        end_test();
    
        start_test();
        cout << "Call DataContainer::get_data_type() 1 million times:" << endl;
        for(int i=0; i<1000000; i++) ENTSYS_DATA_TYPE test_type = dc_int.get_data_type();
        end_test();

        start_test();
        cout << "Call DataContainer::operator=(int) 1 million times" << endl;
        end_test();
    }


    void Test_EntityAttributeTypes()
    {
        EntityAttributeType attr1;

        cout << "Setting attribute name" << endl;
        start_test();
        attr1.set_name(std::string("color"));
        end_test();

        cout << "Setting attribute data type" << endl;
        start_test();
        attr1.set_data_type(ENTSYS_DATA_TYPE_FLOAT);
        end_test();
        
    }


    void Test_EntityTypes()
    {
        EntityAttributeType IQ;
        cout << "Creating entity attribute type 'IQ'" << endl;
        start_test();
        IQ.set_data_type(ENTSYS_DATA_TYPE_INT);
        IQ.set_name("IntelligenceQuotient");
        end_test();

        // Step 1: Create entity attribute types.
        // TODO: Validate input!
        entity_system->create_entity_attribute_type(IQ);

        EntityType IntelligentRobot;
    
        // Create entity type.
        IntelligentRobot.set_entity_type_name("ROBOT");
        // TODO: Validate input!
        entity_system->create_entity_type(IntelligentRobot);

        // Link entity attribute type to entity type.
        // TODO: Validate input!
        entity_system->link_attribute_type_to_entity_type(IntelligentRobot, IQ);

        // Create instances of entity types.
        EntityTypeInstance robots[100];

        // Initialise instances of entity types and their linked entity attribute data.

        // Entity type instance initialisation via entity type name call.
        robots[0] = entity_system->create_entity_type_instance("ROBOT");

        // Entity type instance initialisation via entity type name call 2.
        robots[1] = entity_system->create_entity_type_instance(entity_system->get_entity_type("ROBOT"));
        
        #define LOOPBEGIN 2 // !

        start_test();
        cout << "Creating 98 more robots. Preparing to take over the world (in debug mode)!" << endl;

        for(unsigned int i=LOOPBEGIN; i<100; i++) 
        {
            // We could use entity_system->create_entity_type_instance("ROBOT"); as well!
            
            // This is ok because we look up the entity type's name.
            robots[i] = entity_system->create_entity_type_instance(IntelligentRobot);
                        
            // TODO: How to write to data container ?
            robots[i].set_attribute_data(IQ, std::to_string(100*i));
        }
        end_test();

    }

};
};

#endif // INEXOR_ENTSYS_TESTING_FRAMEWORK_HEADER
