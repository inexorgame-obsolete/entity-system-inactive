// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_TESTING_FRAMEWORK_HEADER
#define INEXOR_ENTSYS_TESTING_FRAMEWORK_HEADER

// Minimum and maximum values for memory.
#include <cstdint>

#include "../EntitySystem.hpp"
extern inexor::entity_system::EntitySystem* entsys;

// Start and end tests with the profiler.
#include "../tests/EntitySystemProfiler.hpp"


namespace inexor {
namespace entity_system {
    
    
    // Test by making false API calls.

    void ErrorTest_DataContainer()
    {
        // Test constructors.
        // Undefined type and undefined memory value.
        DataContainer undefinedCont;

        // Defined type and undefined memory value.
        DataContainer undefined_dc_int(ENTSYS_DATA_TYPE_INT);
        DataContainer undefined_dc_bigint(ENTSYS_DATA_TYPE_BIG_INT);
        DataContainer undefined_dc_float(ENTSYS_DATA_TYPE_FLOAT);
        DataContainer undefined_dc_string(ENTSYS_DATA_TYPE_STRING);
        DataContainer undefined_dc_double(ENTSYS_DATA_TYPE_DOUBLE);
        DataContainer undefined_dc_bool(ENTSYS_DATA_TYPE_BOOL);

        // Defined type and defined memory value.
        DataContainer BigIntCont(std::int64_t(32842471123));
        DataContainer DoubleCont(2345423.0);
        DataContainer FloatCont(2323.0f);
        DataContainer BoolCont(true);
        DataContainer IntCont(1234);
        DataContainer StringCont("This is an example string");        
    }
    
    // Test by making correct API calls.

    void Test_EntitySystemDataContainers()
    {
        DataContainer dc_int(0);
        DataContainer dc_bigint(std::int64_t(0));
        DataContainer dc_string(std::string(""));
        DataContainer dc_bool(false);
        DataContainer dc_float(0.0f);
        DataContainer dc_double(0.0);
    
        start_test("DataContainer::set(const int&) and DataContainer::operator=(const int&); 1000 times");
        for(int i=0; i<1000; i++) {
            dc_int.set(0);
            dc_int = i;
        }
        end_test();

        start_test("DataContainer::set(const float&) and DataContainer::operator=(const float&); 1000 times");
        for(float i=0.0f; i<1000.0f; i+=1.0f) {
            dc_float.set(0.0f);
            dc_float = i;
        }
        end_test();

        start_test("DataContainer::set(const double&) and DataContainer::operator=(const double&); 1000 times");
        for(double i=0.0; i<1000.0; i+=1.0) {
            dc_double.set(0.0);
            dc_double = i;
        }
        end_test();

        start_test("DataContainer::set(const bool&) and DataContainer::operator=(const bool&); 1000 times");
        for(int i=0; i<1000; i+=1) {
            dc_bool.set(false);
            dc_bool = (0==(i%2)) ? true : false;
        }
        end_test();

        start_test("DataContainer::set(const int64_t&) and DataContainer::operator=(const int64_t&); 1000 times");
        for(int64_t i=0; i<1000; i+=1) {
            dc_bigint.set(0);
            dc_bigint = i;
        }
        end_test();

        start_test("DataContainer::set(const std::string&) and DataContainer::operator=(const std::string&); 1000 times");
        for(int i=0; i<1000; i+=1) {
            dc_string.set(std::string(""));
            dc_string = std::to_string(i);
        }
        end_test();

        start_test("DataContainer::add(const int&) 1000 times");
        for(int i=0; i<1000; i+=1) dc_int.add(1);
        end_test();

        dc_int.set(1000);

        start_test("DataContainer::sub(const int&) 1000 times");
        for(int i=0; i<1000; i+=1) dc_int.sub(1);
        end_test();

        dc_int.set(2);

        start_test("DataContainer::mul(const int&) 1000 times");
        for(int i=0; i<1000; i+=1) dc_int.mul(2);
        end_test();

        start_test("DataContainer::div(const int&) 1000 times");
        for(int i=0; i<1000; i+=1) dc_int.div(2);
        end_test();

        int test_int = 0;
        start_test("DataContainer::get_intval() 1 million times");
        for(int i=0; i<1000000; i++) test_int = dc_int.get_intval();
        end_test();
        
        ENTSYS_DATA_TYPE test_type;
        start_test("DataContainer::get_data_type() 1 million times");
        for(int i=0; i<1000000; i++) test_type = dc_int.get_data_type();
        end_test();
    }


    void Test_EntityAttributeTypes()
    {
        EntityAttributeType attr1;

        start_test("EntityAttributeType::set_name()");
        attr1.set_name("weight");
        end_test();

        start_test("EntityAttributeType::set_data_type(ENTSYS_DATA_TYPE_FLOAT)");
        attr1.set_data_type(ENTSYS_DATA_TYPE_FLOAT);
        end_test();

        start_test("entsys->create_entity_attribute_type(attr1)");
        entsys->create_entity_attribute_type(attr1);
        end_test();
    }


    void Test_EntityTypes()
    {
        EntityType weapon1;
        
        start_test("EntityType::set_entity_type_name(weapon1)");
        weapon1.set_entity_type_name("ROCKETLAUNCHER");
        end_test();
        
        start_test("entsys->create_entity_type(weapon1)");
        entsys->create_entity_type(weapon1);    
        end_test();
    }


    void TestEntityTypes_and_EntityTypeAttributes()
    {
        EntityType armor_pickup;
        EntityAttributeType material;

        start_test("EntityAttributeType::set_data_type(ENTSYS_DATA_TYPE_STRING)");
        material.set_data_type(ENTSYS_DATA_TYPE_STRING);
        end_test();

        start_test("EntityAttributeType::set_name(\"armor material\")");
        material.set_name("armor material");
        end_test();

        start_test("entsys->link_attribute_type_to_entity_type(armor_pickup, material)");
        entsys->link_attribute_type_to_entity_type(armor_pickup, material);
        end_test();

        start_test("EntityType::set_entity_type_name(\"ARMOR\")");
        armor_pickup.set_entity_type_name("ARMOR");
        end_test();

        start_test("entsys->create_entity_type(armor_pickup)");
        entsys->create_entity_type(armor_pickup);
        end_test();

        start_test("entsys->create_entity_type(armor_pickup)");
        entsys->create_entity_type(armor_pickup);
        end_test();
        
        EntityTypeInstance shield[3];

        // There are 3 ways of initialisation available:

        start_test("entsys->create_entity_type_instance(\"ARMOR\")");
        shield[0] = entsys->create_entity_type_instance("ARMOR");
        end_test();

        start_test("entsys->create_entity_type_instance(armor_pickup)");
        shield[1] = entsys->create_entity_type_instance(armor_pickup);
        end_test();

        start_test("entsys->create_entity_type_instance(entsys->get_entity_type(\"ARMOR\"))");
        shield[2] = entsys->create_entity_type_instance(entsys->get_entity_type("ARMOR"));
        end_test();
        
        start_test("EntityTypeInstance::set_attribute_data(material, \"copper\")");
        shield[0].set_attribute_data(material, "copper");
        end_test();

        start_test("EntityTypeInstance::set_attribute_data(material, \"steel\")");
        shield[1].set_attribute_data(material, "steel");
        end_test();

        start_test("EntityTypeInstance::set_attribute_data(material, \"nickel\")");
        shield[2].set_attribute_data(material, "nickel");
        end_test();

        start_test("EntityTypeInstance::read_attribute_data(material)");
        cout << shield[0].read_attribute_data(material) << endl;
        end_test();

        start_test("EntityTypeInstance::read_attribute_data(material)");
        cout << shield[1].read_attribute_data(material) << endl;
        end_test();

        start_test("EntityTypeInstance::read_attribute_data(material)");
        cout << shield[2].read_attribute_data(material) << endl;
        end_test();
    }

};
};

#endif // INEXOR_ENTSYS_TESTING_FRAMEWORK_HEADER
