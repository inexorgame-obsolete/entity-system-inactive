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
        EntityAttributeType weight;
        EntityAttributeType color;
        EntityAttributeType IQ;
 
        cout << "Creating entity attribute type 'weight'" << endl;
        start_test();
        weight.set_data_type(ENTSYS_DATA_TYPE_FLOAT);
        weight.set_name("weight");
        end_test();

        cout << "Trying to cause error by overwriting data type" << endl;
        start_test();
        weight.set_data_type(ENTSYS_DATA_TYPE_STRING);
        end_test();

        cout << "Creating entity attribute type 'color'" << endl;
        start_test();
        color.set_data_type(ENTSYS_DATA_TYPE_STRING);
        color.set_name("color");
        end_test();

        cout << "Creating entity attribute type 'IQ'" << endl;
        start_test();
        IQ.set_data_type(ENTSYS_DATA_TYPE_INT);
        IQ.set_name("IntelligenceQuotient");
        end_test();

        // TODO: Implement entity attribute type manager.
        // TODO: Add those entity attribute types to the entity attribute type manager.
        entity_system->add(weight);
        entity_system->add(color);
        entity_system->add(IQ);

        EntityTypeBase IntelligentRobot;
        IntelligentRobot.set_entity_type_name("ROBOT");
        IntelligentRobot.link_entity_attribute_type(IQ);
        IntelligentRobot.link_entity_attribute_type(color);
        IntelligentRobot.link_entity_attribute_type(weight);

        // Register this type
        entity_system->add_entity_type(IntelligentRobot);

        EntityTypeInstance robot1;
        robot1 = entity_system->create_entity_type_instance("ROBOT");

        EntityTypeInstance robots[100];

        start_test();
        cout << "Creating 100 robots. Preparing to take over the world!" << endl;
        for(size_t i=0; i<100; i++)
        {
            robots[i] = entity_system->create_entity_type_instance("ROBOT");
        }
        end_test();

        EntityTypeInstance robots2[244];

        start_test();
        for(size_t i=0; i<244; i++)
        {
            robots2[i] = entity_system->create_entity_type_instance(IntelligentRobot);
        }
        end_test();
    }

};
};

#endif // INEXOR_ENTSYS_TESTING_FRAMEWORK_HEADER
