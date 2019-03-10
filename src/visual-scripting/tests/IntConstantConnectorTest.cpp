#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "visual-scripting/model/Connector.hpp"

#include <random>

#include "react/Domain.h"
#include "react/Signal.h"
#include "react/Observer.h"

#include "IntConstantConnectorTest.hpp"

using IntConstantEntityTypeProvider = inexor::entity_system::type_system::IntConstantEntityTypeProvider;
using AddIntEntityTypeProvider = inexor::entity_system::type_system::AddIntEntityTypeProvider;

namespace inexor {
namespace visual_scripting {


	IntConstantConnectorTest::IntConstantConnectorTest(
		ConnectorManagerPtr connector_manager,
		IntConstantFactoryPtr int_constant_factory,
		AddIntFactoryPtr add_int_factory
	)
	{
        this->connector_manager = connector_manager;
        this->int_constant_factory = int_constant_factory;
        this->add_int_factory = add_int_factory;
	}

	
	IntConstantConnectorTest::~IntConstantConnectorTest()
	{
	}

	void IntConstantConnectorTest::init()
	{
		std::thread t(&inexor::visual_scripting::IntConstantConnectorTest::run_connector_tests, this);
		t.detach();
	}

	void IntConstantConnectorTest::run_connector_tests()
	{
		std::this_thread::sleep_for(2s);


		std::string source_name = "source";
		int initial_source_value = 100;
		std::cout << "Create entity instance '" << source_name << "'" << std::endl;
		auto o_source = int_constant_factory->create_instance(source_name, initial_source_value);

		std::string target_1_name = "target1";
		int target_1_initial_value = 200;
		std::cout << "Create entity instance '" << target_1_name << "'" << std::endl;
		auto o_target_1 = int_constant_factory->create_instance(target_1_name, target_1_initial_value);

		std::string target_2_name = "target2";
		int target_2_initial_value = 300;
		std::cout << "Create entity instance '" << target_2_name << "'" << std::endl;
		auto o_target_2 = int_constant_factory->create_instance(target_2_name, target_2_initial_value);

		std::string target_3_name = "target3";
		int target_3_initial_value = 400;
		std::cout << "Create entity instance '" << target_3_name << "'" << std::endl;
		auto o_target_3 = int_constant_factory->create_instance(target_3_name, target_3_initial_value);

		std::string add_int_name = "add_int";
		std::cout << "Create entity instance '" << add_int_name << "'" << std::endl;
		auto o_add_int = add_int_factory->create_instance();


		if (o_source.has_value() && o_target_1.has_value() && o_target_2.has_value() && o_target_3.has_value() && o_add_int.has_value())
		{
			std::shared_ptr<inexor::entity_system::EntityInstance> source = o_source.value();
			std::shared_ptr<inexor::entity_system::EntityInstance> target_1 = o_target_1.value();
			std::shared_ptr<inexor::entity_system::EntityInstance> target_2 = o_target_2.value();
			std::shared_ptr<inexor::entity_system::EntityInstance> target_3 = o_target_3.value();
			std::shared_ptr<inexor::entity_system::EntityInstance> add_int = o_add_int.value();

			std::cout << "Get entity instance attributes" << std::endl;
			std::optional<std::shared_ptr<inexor::entity_system::EntityAttributeInstance>> o_source_attr_value = source->get_attribute_instance(IntConstantEntityTypeProvider::INT_CONSTANT_VALUE);
			std::optional<std::shared_ptr<inexor::entity_system::EntityAttributeInstance>> o_target_1_attr_value = target_1->get_attribute_instance(IntConstantEntityTypeProvider::INT_CONSTANT_VALUE);
			std::optional<std::shared_ptr<inexor::entity_system::EntityAttributeInstance>> o_target_2_attr_value = target_2->get_attribute_instance(IntConstantEntityTypeProvider::INT_CONSTANT_VALUE);
			std::optional<std::shared_ptr<inexor::entity_system::EntityAttributeInstance>> o_target_3_attr_value = target_3->get_attribute_instance(IntConstantEntityTypeProvider::INT_CONSTANT_VALUE);

			std::optional<std::shared_ptr<inexor::entity_system::EntityAttributeInstance>> o_add_int_attr_augend = add_int->get_attribute_instance(AddIntEntityTypeProvider::ADD_INT_AUGEND);
			std::optional<std::shared_ptr<inexor::entity_system::EntityAttributeInstance>> o_add_int_attr_addend = add_int->get_attribute_instance(AddIntEntityTypeProvider::ADD_INT_ADDEND);
			std::optional<std::shared_ptr<inexor::entity_system::EntityAttributeInstance>> o_add_int_attr_sum = add_int->get_attribute_instance(AddIntEntityTypeProvider::ADD_INT_SUM);

			if (o_source_attr_value.has_value() && o_target_1_attr_value.has_value() && o_target_2_attr_value.has_value() && o_target_3_attr_value.has_value() && o_add_int_attr_augend.has_value() && o_add_int_attr_addend.has_value() && o_add_int_attr_sum.has_value())
			{
				std::shared_ptr<inexor::entity_system::EntityAttributeInstance> source_attr_value = o_source_attr_value.value();
				std::shared_ptr<inexor::entity_system::EntityAttributeInstance> target_1_attr_value = o_target_1_attr_value.value();
				std::shared_ptr<inexor::entity_system::EntityAttributeInstance> target_2_attr_value = o_target_2_attr_value.value();
				std::shared_ptr<inexor::entity_system::EntityAttributeInstance> target_3_attr_value = o_target_3_attr_value.value();
				std::shared_ptr<inexor::entity_system::EntityAttributeInstance> add_int_attr_augend = o_add_int_attr_augend.value();
				std::shared_ptr<inexor::entity_system::EntityAttributeInstance> add_int_attr_addend = o_add_int_attr_addend.value();
				std::shared_ptr<inexor::entity_system::EntityAttributeInstance> add_int_attr_sum = o_add_int_attr_sum.value();

				std::cout << "Initial values (before connector created)" << std::endl;
				std::cout << source_name << "." << IntConstantEntityTypeProvider::INT_CONSTANT_VALUE << " = " << std::get<DataType::INT>(source_attr_value->value.Value()) << std::endl;
				std::cout << target_1_name << "." << IntConstantEntityTypeProvider::INT_CONSTANT_VALUE << " = " << std::get<DataType::INT>(target_1_attr_value->value.Value()) << std::endl;
				std::cout << target_2_name << "." << IntConstantEntityTypeProvider::INT_CONSTANT_VALUE << " = " << std::get<DataType::INT>(target_2_attr_value->value.Value()) << std::endl;
				std::cout << target_3_name << "." << IntConstantEntityTypeProvider::INT_CONSTANT_VALUE << " = " << std::get<DataType::INT>(target_3_attr_value->value.Value()) << std::endl;
				std::cout << add_int_name << "." << AddIntEntityTypeProvider::ADD_INT_AUGEND << " = " << std::get<DataType::INT>(add_int_attr_augend->value.Value()) << std::endl;
				std::cout << add_int_name << "." << AddIntEntityTypeProvider::ADD_INT_ADDEND << " = " << std::get<DataType::INT>(add_int_attr_addend->value.Value()) << std::endl;
				std::cout << add_int_name << "." << AddIntEntityTypeProvider::ADD_INT_SUM << " = " << std::get<DataType::INT>(add_int_attr_sum->value.Value()) << std::endl;

				std::cout << "Create connector " << source_name << "." << IntConstantEntityTypeProvider::INT_CONSTANT_VALUE << " ---> " << target_1_name << "." << IntConstantEntityTypeProvider::INT_CONSTANT_VALUE << ": ";
				std::optional<std::shared_ptr<inexor::visual_scripting::Connector>> connector_1 = connector_manager->create_connector(source_attr_value, target_1_attr_value);
				if (connector_1.has_value())
				{
					connector_1.value()->enable_debug();
					std::cout << "success";
				} else  {
					std::cout << "failed!";
				}
				std::cout << std::endl;

				std::cout << "Create connector " << source_name << "." << IntConstantEntityTypeProvider::INT_CONSTANT_VALUE << " ---> " << target_2_name << "." << IntConstantEntityTypeProvider::INT_CONSTANT_VALUE << ": ";
				std::optional<std::shared_ptr<inexor::visual_scripting::Connector>> connector_2 = connector_manager->create_connector(source_attr_value, target_2_attr_value);
				if (connector_2.has_value())
				{
//					connector_2.value()->enable_debug();
					std::cout << "success";
				} else  {
					std::cout << "failed!";
				}
				std::cout << std::endl;

				std::cout << "Create connector " << target_1_name << "." << IntConstantEntityTypeProvider::INT_CONSTANT_VALUE << " ---> " << target_3_name << "." << IntConstantEntityTypeProvider::INT_CONSTANT_VALUE << ": ";
				std::optional<std::shared_ptr<inexor::visual_scripting::Connector>> connector_3 = connector_manager->create_connector(target_1_attr_value, target_3_attr_value);
				if (connector_3.has_value())
				{
					connector_3.value()->enable_debug();
					std::cout << "success";
				} else  {
					std::cout << "failed!";
				}
				std::cout << std::endl;

				std::cout << "Create connector " << target_2_name << "." << IntConstantEntityTypeProvider::INT_CONSTANT_VALUE << " ---> " << add_int_name << "." << AddIntEntityTypeProvider::ADD_INT_AUGEND << ": ";
				std::optional<std::shared_ptr<inexor::visual_scripting::Connector>> connector_4 = connector_manager->create_connector(target_2_attr_value, add_int_attr_augend);
				if (connector_4.has_value())
				{
					connector_4.value()->enable_debug();
					std::cout << "success";
				} else  {
					std::cout << "failed!";
				}
				std::cout << std::endl;

				std::cout << "Create connector " << target_3_name << "." << IntConstantEntityTypeProvider::INT_CONSTANT_VALUE << " ---> " << add_int_name << "." << AddIntEntityTypeProvider::ADD_INT_ADDEND << ": ";
				std::optional<std::shared_ptr<inexor::visual_scripting::Connector>> connector_5 = connector_manager->create_connector(target_3_attr_value, add_int_attr_addend);
				if (connector_5.has_value())
				{
					connector_5.value()->enable_debug();
					std::cout << "success";
				} else  {
					std::cout << "failed!";
				}
				std::cout << std::endl;

				std::cout << "Initial values (after connector created)" << std::endl;
				std::cout << source_name << "." << IntConstantEntityTypeProvider::INT_CONSTANT_VALUE << " = " << std::get<DataType::INT>(source_attr_value->value.Value()) << std::endl;
				std::cout << target_1_name << "." << IntConstantEntityTypeProvider::INT_CONSTANT_VALUE << " = " << std::get<DataType::INT>(target_1_attr_value->value.Value()) << std::endl;
				std::cout << target_2_name << "." << IntConstantEntityTypeProvider::INT_CONSTANT_VALUE << " = " << std::get<DataType::INT>(target_2_attr_value->value.Value()) << std::endl;
				std::cout << target_3_name << "." << IntConstantEntityTypeProvider::INT_CONSTANT_VALUE << " = " << std::get<DataType::INT>(target_3_attr_value->value.Value()) << std::endl;
				std::cout << add_int_name << "." << AddIntEntityTypeProvider::ADD_INT_AUGEND << " = " << std::get<DataType::INT>(add_int_attr_augend->value.Value()) << std::endl;
				std::cout << add_int_name << "." << AddIntEntityTypeProvider::ADD_INT_ADDEND << " = " << std::get<DataType::INT>(add_int_attr_addend->value.Value()) << std::endl;
				std::cout << add_int_name << "." << AddIntEntityTypeProvider::ADD_INT_SUM << " = " << std::get<DataType::INT>(add_int_attr_sum->value.Value()) << std::endl;
				std::random_device rdev;
				std::mt19937 rgen(rdev());
				std::uniform_int_distribution<int> idist(0, 1000);
				int i = 0;
				while (i < 998)
				{
					std::this_thread::sleep_for(2s);
					i = idist(rgen);
					std::cout << "source.value.Set(" << i << ")" << std::endl;
					source_attr_value->own_value.Set(i);
					std::cout << source_name << "." << IntConstantEntityTypeProvider::INT_CONSTANT_VALUE << " = " << std::get<DataType::INT>(source_attr_value->value.Value()) << std::endl;
					std::cout << target_1_name << "." << IntConstantEntityTypeProvider::INT_CONSTANT_VALUE << " = " << std::get<DataType::INT>(target_1_attr_value->value.Value()) << std::endl;
					std::cout << target_2_name << "." << IntConstantEntityTypeProvider::INT_CONSTANT_VALUE << " = " << std::get<DataType::INT>(target_2_attr_value->value.Value()) << std::endl;
					std::cout << target_3_name << "." << IntConstantEntityTypeProvider::INT_CONSTANT_VALUE << " = " << std::get<DataType::INT>(target_3_attr_value->value.Value()) << std::endl;
					std::cout << add_int_name << "." << AddIntEntityTypeProvider::ADD_INT_AUGEND << " = " << std::get<DataType::INT>(add_int_attr_augend->value.Value()) << std::endl;
					std::cout << add_int_name << "." << AddIntEntityTypeProvider::ADD_INT_ADDEND << " = " << std::get<DataType::INT>(add_int_attr_addend->value.Value()) << std::endl;
					std::cout << add_int_name << "." << AddIntEntityTypeProvider::ADD_INT_SUM << " = " << std::get<DataType::INT>(add_int_attr_sum->value.Value()) << std::endl;
				}
			}
		}

	}


}
}
