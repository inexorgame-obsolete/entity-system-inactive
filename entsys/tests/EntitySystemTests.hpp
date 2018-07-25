// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_TESTING_FRAMEWORK_HEADER
#define INEXOR_ENTSYS_TESTING_FRAMEWORK_HEADER

#include "../EntitySystem.hpp"
extern inexor::entity_system::EntitySystem* entsys;

// Start and end tests with the profiler.
#include "../tests/EntitySystemProfiler.hpp"


namespace inexor {
namespace entity_system {
    

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
        attr1.set_name("weight");
        end_test();

        cout << "Setting attribute data type" << endl;
        start_test();
        attr1.set_data_type(ENTSYS_DATA_TYPE_FLOAT);
        end_test();        
    }


    void Test_EntityTypes()
    {
        EntityType weapon1;
        
        cout << "Creating entity type 'rocket launcher ammo'" << endl;
        start_test();
        weapon1.set_entity_type_name("ROCKETLAUNCHER");
        end_test();
        
        entsys->create_entity_type(weapon1);    
    }


    void TestEntityTypes_and_EntityTypeAttributes()
    {
        EntityType armor_pickup;
        EntityAttributeType material;
        cout << "Creating entity attribute type 'armor material'" << endl;   

        start_test();
        material.set_data_type(ENTSYS_DATA_TYPE_STRING);
        material.set_name("armor material");
        end_test();

        cout << "entsys->link_attribute_type_to_entity_type(armor_pickup, material)" << endl;
        start_test();
        entsys->link_attribute_type_to_entity_type(armor_pickup, material);
        end_test();

        cout << "Creating entity type 'armor pickup'" << endl;
       
        start_test();
        armor_pickup.set_entity_type_name("ARMOR");
        entsys->create_entity_type(armor_pickup);
        end_test();

        cout << "Creating entity type" << endl;
        start_test();
        entsys->create_entity_type(armor_pickup);
        end_test();
        
        EntityTypeInstance shield[3];

        // There are 3 ways of initialisation available:

        cout << "entsys->create_entity_type_instance(armor_pickup) (3x)" << endl;
        start_test();
        shield[0] = entsys->create_entity_type_instance("ARMOR");
        shield[1] = entsys->create_entity_type_instance(armor_pickup);
        shield[2] = entsys->create_entity_type_instance(entsys->get_entity_type("ARMOR"));
        end_test();
        
        cout << "EntityTypeInstance::set_attribute_data(..) 3x" << endl;
        start_test();
        shield[0].set_attribute_data(material, "copper");
        shield[1].set_attribute_data(material, "steel");
        shield[2].set_attribute_data(material, "nickel");
        end_test();

        cout << "EntityTypeInstance::read_attribute_data(material) (3x)" << endl;
        start_test();
        cout << shield[0].read_attribute_data(material) << endl;
        cout << shield[1].read_attribute_data(material) << endl;
        cout << shield[2].read_attribute_data(material) << endl;
        end_test();
    }

};
};

#endif // INEXOR_ENTSYS_TESTING_FRAMEWORK_HEADER
