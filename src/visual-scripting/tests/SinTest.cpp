#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "visual-scripting/model/Connector.hpp"

#include <random>

#include "react/Domain.h"
#include "react/Signal.h"
#include "react/Observer.h"

#include "SinTest.hpp"

using namespace std;

using FloatConstantEntityTypeProvider = inexor::entity_system::type_system::FloatConstantEntityTypeProvider;
using SinEntityTypeProvider = inexor::entity_system::type_system::SinEntityTypeProvider;

namespace inexor {
namespace visual_scripting {


	SinTest::SinTest(
		ConnectorManagerPtr connector_manager,
		FloatConstantFactoryPtr float_constant_factory,
		SinFactoryPtr sin_factory,
		AddFloatFactoryPtr add_float_factory
	)
	{
        this->connector_manager = connector_manager;
        this->float_constant_factory = float_constant_factory;
        this->sin_factory = sin_factory;
        this->add_float_factory = add_float_factory;
	}

	
	SinTest::~SinTest()
	{
	}

	void SinTest::init()
	{
		std::thread t(&inexor::visual_scripting::SinTest::run_connector_tests, this);
		t.detach();
	}

	void SinTest::run_connector_tests()
	{
		std::this_thread::sleep_for(2s);

		std::string sin_name = "sin";
		std::cout << "Create entity instance '" << sin_name << "'" << std::endl;
		std::optional<std::shared_ptr<inexor::entity_system::EntityInstance>> o_sin = sin_factory->create_instance();

		std::string target_name = "target";
		float initial_target_value = 100.0f;
		std::cout << "Create entity instance '" << target_name << "'" << std::endl;
		std::optional<std::shared_ptr<inexor::entity_system::EntityInstance>> o_target = float_constant_factory->create_instance(target_name, initial_target_value);


		if (o_sin.has_value() && o_target.has_value())
		{
			std::shared_ptr<inexor::entity_system::EntityInstance> sin = o_sin.value();
			std::shared_ptr<inexor::entity_system::EntityInstance> target = o_target.value();

			std::cout << "Get entity instance attributes" << std::endl;

			std::optional<std::shared_ptr<inexor::entity_system::EntityAttributeInstance>> o_sin_attr_value = sin->get_attribute_instance(SinEntityTypeProvider::SIN_VALUE);
			std::optional<std::shared_ptr<inexor::entity_system::EntityAttributeInstance>> o_target_attr_value = target->get_attribute_instance(FloatConstantEntityTypeProvider::FLOAT_CONSTANT_VALUE);

			if (o_sin_attr_value.has_value() && o_target_attr_value.has_value())
			{

				std::shared_ptr<inexor::entity_system::EntityAttributeInstance> sin_attr_value = o_sin_attr_value.value();
				std::shared_ptr<inexor::entity_system::EntityAttributeInstance> target_attr_value = o_target_attr_value.value();

				std::cout << "Initial values (before connector created)" << std::endl;
				std::cout << sin_name << "." << SinEntityTypeProvider::SIN_VALUE << " = " << std::get<DataType::FLOAT>(sin_attr_value->value.Value()) << std::endl;
				std::cout << target_name << "." << FloatConstantEntityTypeProvider::FLOAT_CONSTANT_VALUE << " = " << std::get<DataType::FLOAT>(target_attr_value->value.Value()) << std::endl;

				std::cout << "Create connector " << sin_name << "." << SinEntityTypeProvider::SIN_VALUE << " ---> " << target_name << "." << FloatConstantEntityTypeProvider::FLOAT_CONSTANT_VALUE << std::endl;
				std::optional<std::shared_ptr<inexor::visual_scripting::Connector>> connector_1 = connector_manager->create_connector(sin_attr_value, target_attr_value);

				std::cout << "Initial values (after connector created)" << std::endl;
				std::cout << sin_name << "." << SinEntityTypeProvider::SIN_VALUE << " = " << std::get<DataType::FLOAT>(sin_attr_value->value.Value()) << std::endl;
				std::cout << target_name << "." << FloatConstantEntityTypeProvider::FLOAT_CONSTANT_VALUE << " = " << std::get<DataType::FLOAT>(target_attr_value->value.Value()) << std::endl;
				std::random_device rdev;
				std::mt19937 rgen(rdev());
				std::uniform_int_distribution<int> idist(0, 1000);
				int i = 0;
				while (i < 998)
				{
					std::this_thread::sleep_for(2s);
					i = idist(rgen);
					std::cout << sin_name << "." << SinEntityTypeProvider::SIN_VALUE << ".Set(" << i << ")" << std::endl;
					std::cout << sin_name << "." << SinEntityTypeProvider::SIN_VALUE << " = " << std::get<DataType::FLOAT>(sin_attr_value->value.Value()) << std::endl;
					std::cout << target_name << "." << FloatConstantEntityTypeProvider::FLOAT_CONSTANT_VALUE << " = " << std::get<DataType::FLOAT>(target_attr_value->value.Value()) << std::endl;
				}
			}
		}

	}


}
}
