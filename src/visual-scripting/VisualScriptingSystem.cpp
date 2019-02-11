// Inexor visual scripting
// (c)2018-2019 Inexor

#include <random>

#include "VisualScriptingSystem.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"

using namespace std;

namespace inexor {
namespace visual_scripting {


	VisualScriptingSystem::VisualScriptingSystem(
		std::shared_ptr<inexor::visual_scripting::ConnectorManager> connector_manager,
		std::shared_ptr<inexor::visual_scripting::ActiveComponentManager> active_component_manager,
		shared_ptr<inexor::entity_system::type_system::IntConstantFactory> int_constant_factory
	)
	{
        this->connector_manager = connector_manager;
        this->active_component_manager = active_component_manager;
        this->int_constant_factory = int_constant_factory;
	}

	
	VisualScriptingSystem::~VisualScriptingSystem()
	{
	}

	void VisualScriptingSystem::init()
	{
		connector_manager->init();
		active_component_manager->init();

		std::thread t(&inexor::visual_scripting::VisualScriptingSystem::run_connector_tests, this);
		t.detach();
	}

	/// Tests for the connectors
	void VisualScriptingSystem::init_connector_tests()
	{
	}

	void VisualScriptingSystem::run_connector_tests()
	{
		std::this_thread::sleep_for(5s);
		std::string source_name = "source";
		int initial_source_value = 100;
		std::cout << "Create entity instance '" << source_name << "'" << std::endl;
		std::optional<std::shared_ptr<inexor::entity_system::EntityInstance>> o_source = int_constant_factory->create_instance(source_name, initial_source_value);

		std::string target_1_name = "target1";
		int target_1_initial_value = 200;
		std::cout << "Create entity instance '" << target_1_name << "'" << std::endl;
		std::optional<std::shared_ptr<inexor::entity_system::EntityInstance>> o_target_1 = int_constant_factory->create_instance(target_1_name, target_1_initial_value);

		std::string target_2_name = "target2";
		int target_2_initial_value = 300;
		std::cout << "Create entity instance '" << target_2_name << "'" << std::endl;
		std::optional<std::shared_ptr<inexor::entity_system::EntityInstance>> o_target_2 = int_constant_factory->create_instance(target_2_name, target_2_initial_value);

		std::string target_3_name = "target3";
		int target_3_initial_value = 400;
		std::cout << "Create entity instance '" << target_3_name << "'" << std::endl;
		std::optional<std::shared_ptr<inexor::entity_system::EntityInstance>> o_target_3 = int_constant_factory->create_instance(target_3_name, target_3_initial_value);

		if (o_source.has_value() && o_target_1.has_value() && o_target_2.has_value() && o_target_3.has_value())
		{
			std::shared_ptr<inexor::entity_system::EntityInstance> source = o_source.value();
			std::shared_ptr<inexor::entity_system::EntityInstance> target_1 = o_target_1.value();
			std::shared_ptr<inexor::entity_system::EntityInstance> target_2 = o_target_2.value();
			std::shared_ptr<inexor::entity_system::EntityInstance> target_3 = o_target_3.value();

			std::cout << "Get entity instance attributes" << std::endl;
			std::string value_attribute_name = "value";
			std::optional<std::shared_ptr<inexor::entity_system::EntityAttributeInstance>> o_source_attr_value = source->get_attribute_instance(value_attribute_name);
			std::optional<std::shared_ptr<inexor::entity_system::EntityAttributeInstance>> o_target_1_attr_value = target_1->get_attribute_instance(value_attribute_name);
			std::optional<std::shared_ptr<inexor::entity_system::EntityAttributeInstance>> o_target_2_attr_value = target_2->get_attribute_instance(value_attribute_name);
			std::optional<std::shared_ptr<inexor::entity_system::EntityAttributeInstance>> o_target_3_attr_value = target_3->get_attribute_instance(value_attribute_name);

			if (o_source_attr_value.has_value() && o_target_1_attr_value.has_value() && o_target_2_attr_value.has_value() && o_target_3_attr_value.has_value())
			{
				std::shared_ptr<inexor::entity_system::EntityAttributeInstance> source_attr_value = o_source_attr_value.value();
				std::shared_ptr<inexor::entity_system::EntityAttributeInstance> target_1_attr_value = o_target_1_attr_value.value();
				std::shared_ptr<inexor::entity_system::EntityAttributeInstance> target_2_attr_value = o_target_2_attr_value.value();
				std::shared_ptr<inexor::entity_system::EntityAttributeInstance> target_3_attr_value = o_target_3_attr_value.value();

				std::cout << "Initial values (before connector created)" << std::endl;
				std::cout << source_name << "." << value_attribute_name << " = " << std::get<DataType::INT>(source_attr_value->value.Value()) << std::endl;
				std::cout << target_1_name << "." << value_attribute_name << " = " << std::get<DataType::INT>(target_1_attr_value->value.Value()) << std::endl;
				std::cout << target_2_name << "." << value_attribute_name << " = " << std::get<DataType::INT>(target_2_attr_value->value.Value()) << std::endl;
				std::cout << target_3_name << "." << value_attribute_name << " = " << std::get<DataType::INT>(target_3_attr_value->value.Value()) << std::endl;

				std::cout << "Create connector " << source_name << "." << value_attribute_name << " ---> " << target_1_name << "." << value_attribute_name << std::endl;
				std::optional<std::shared_ptr<inexor::visual_scripting::Connector>> connector_1 = connector_manager->create_connector(source_attr_value, target_1_attr_value);

				std::cout << "Create connector " << source_name << "." << value_attribute_name << " ---> " << target_2_name << "." << value_attribute_name << std::endl;
				std::optional<std::shared_ptr<inexor::visual_scripting::Connector>> connector_2 = connector_manager->create_connector(source_attr_value, target_2_attr_value);

				std::cout << "Create connector " << target_1_name << "." << value_attribute_name << " ---> " << target_3_name << "." << value_attribute_name << std::endl;
				std::optional<std::shared_ptr<inexor::visual_scripting::Connector>> connector_3 = connector_manager->create_connector(target_1_attr_value, target_3_attr_value);

				std::cout << "Initial values (after connector created)" << std::endl;
				std::cout << source_name << "." << value_attribute_name << " = " << std::get<DataType::INT>(source_attr_value->value.Value()) << std::endl;
				std::cout << target_1_name << "." << value_attribute_name << " = " << std::get<DataType::INT>(target_1_attr_value->value.Value()) << std::endl;
				std::cout << target_2_name << "." << value_attribute_name << " = " << std::get<DataType::INT>(target_2_attr_value->value.Value()) << std::endl;
				std::cout << target_3_name << "." << value_attribute_name << " = " << std::get<DataType::INT>(target_3_attr_value->value.Value()) << std::endl;
				std::random_device rdev;
				std::mt19937 rgen(rdev());
				std::uniform_int_distribution<int> idist(0, 1000);
				int i = 0;
				while (i < 998)
				{
					std::this_thread::sleep_for(10s);
					i = idist(rgen);
					std::cout << "source.value.Set(" << i << ")" << std::endl;
					source_attr_value->value.Set(i);
					std::cout << source_name << "." << value_attribute_name << " = " << std::get<DataType::INT>(source_attr_value->value.Value()) << std::endl;
					std::cout << target_1_name << "." << value_attribute_name << " = " << std::get<DataType::INT>(target_1_attr_value->value.Value()) << std::endl;
					std::cout << target_2_name << "." << value_attribute_name << " = " << std::get<DataType::INT>(target_2_attr_value->value.Value()) << std::endl;
					std::cout << target_3_name << "." << value_attribute_name << " = " << std::get<DataType::INT>(target_3_attr_value->value.Value()) << std::endl;
				}
			}
		}
	}


};
};
