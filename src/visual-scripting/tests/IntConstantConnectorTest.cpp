// Inexor visual scripting
// (c)2018-2019 Inexor

#include <random>

#include "react/Domain.h"
#include "react/Signal.h"
#include "react/Observer.h"

#include "IntConstantConnectorTest.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "visual-scripting/model/Connector.hpp"

using namespace std;

namespace inexor {
namespace visual_scripting {


	IntConstantConnectorTest::IntConstantConnectorTest(
		std::shared_ptr<inexor::visual_scripting::ConnectorManager> connector_manager,
		std::shared_ptr<inexor::entity_system::type_system::IntConstantFactory> int_constant_factory,
		std::shared_ptr<inexor::entity_system::type_system::AddIntFactory> add_int_factory
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


//		std::cout << "=== Creating Unconnected Signals ===" << std::endl;
//
//		VarSignalT<int> predecessor = MakeVar<D>(111);
//
//		SignalT<int> source = MakeSignal(predecessor, [] (int v) {
//			std::cout << "predecessor -> source: " << v << std::endl;
//			return v;
//		});
//
//
//		VarSignalT<int> dummy_source = MakeVar<D>(222);
//
//		auto signal_pack_for_target = With(dummy_source);
//		// TempSignal<D, int, int(int v)>
//		SignalT<int> target = MakeSignal(signal_pack_for_target, [] (int v) {
//			std::cout << "target became: " << v << std::endl;
//			return v;
//		});
//
//
//		SignalT<int> successor = MakeSignal(target, [] (int v) {
//			std::cout << "target -> successor: " << v << std::endl;
//			return v;
//		});
//
////
////		std::cout << "=== Connect source with target (as replacement for dummy_source) ===" << std::endl;
////		std::cout << "Type of signal in signal pack: " << typeid(std::get<0> (signal_pack_for_target.Data)).name() << std::endl;
////		std::get<0> (signal_pack_for_target.Data) = SignalT<int>(source);
//		std::cout << "=== Connect source with target (replace target's point on its predecessor) ===" << std::endl;
//		auto &predecssor_ptr = GetNodePtr(target); // target->ptr (const <-)
//		auto &source_ptr = GetNodePtr(source);
//		predecssor_ptr = source_ptr;
//
//
//
//		std::cout << "=== Test Connection ===" << std::endl;
//
//		std::cout << "predecessor.Set(11111)" << std::endl;
//		predecessor.Set(11111);
//
//		std::cout << "predecessor == 11111 ???" << std::endl;
//		assert(predecessor.Value() == 11111);
//		std::cout << "source == 11111 ???" << std::endl;
//		assert(source.Value() == 11111);
//		std::cout << "target == 11111 ???" << std::endl;
//		assert(target.Value() == 11111);
//		std::cout << "successor == 11111 ???" << std::endl;
//		assert(successor.Value() == 11111);

		/// ////////////////////////////
		// old try:

//
//
//		std::cout << "=== Creating Signals ===" << std::endl;
//
//		VarSignalT<int> predecessor = MakeVar<D>(111);
//
//		std::cout << "predecessor == 111 ???" << std::endl;
//		assert(predecessor.Value() == 111);
//
//		SignalT<int> source = MakeSignal(predecessor, [] (int v) {
//			std::cout << "predecessor -> source: " << v << std::endl;
//			return v;
//		});
//
//		std::cout << "source == 111 ???" << std::endl;
//		assert(source.Value() == 111);
//
//		VarSignalT<int> dummy_source = MakeVar<D>(222);
//
//		std::cout << "dummy_source == 222 ???" << std::endl;
//		assert(dummy_source.Value() == 222);
//
//		// TempSignal<D, int, int(int v)>
//		// SignalT<int> target =
//		TempSignal<D, int, int(int v)> target = MakeSignal(dummy_source, [] (int v) {
//			std::cout << "dummy_source -> (old) target: " << v << std::endl;
//			return v;
//		});
//		target.modifyValue()
//
//		std::cout << "target == 222 ???" << std::endl;
//		assert(target.Value() == 222);
//
//		SignalT<int> successor = MakeSignal(target, [] (int v) {
//			std::cout << "target -> successor: " << v << std::endl;
//			return v;
//		});
//
//		std::cout << "successor == 222 ???" << std::endl;
//		assert(successor.Value() == 222);
//
//
//
//
//
//		std::cout << "=== Phase 1 ===" << std::endl;
//
//		std::cout << "predecessor.Set(1111)" << std::endl;
//		predecessor.Set(1111);
//
//		std::cout << "predecessor == 1111 ???" << std::endl;
//		assert(predecessor.Value() == 1111);
//		std::cout << "source == 1111 ???" << std::endl;
//		assert(source.Value() == 1111);
//
//		std::cout << "dummy_source.Set(2222)" << std::endl;
//		dummy_source.Set(2222);
//
//		std::cout << "dummy_source == 2222 ???" << std::endl;
//		assert(dummy_source.Value() == 2222);
//		std::cout << "target == 2222 ???" << std::endl;
//		assert(target.Value() == 2222);
//		std::cout << "successor == 2222 ???" << std::endl;
//		assert(successor.Value() == 2222);
//
//
//
//
//
//		std::cout << "=== Update signal ===" << std::endl;
//
//		auto new_target = MakeSignal(source, [] (int v) {
//			std::cout << "source -> (new) target: " << v << std::endl;
//			return v;
//		});
//		// target = Signal(new_target);
//
//		target = make_shared();
//
//
//
//
//		std::cout << "=== Phase 2 ===" << std::endl;
//
//		std::cout << "predecessor.Set(11111)" << std::endl;
//		predecessor.Set(11111);
////		std::cout << "dummy_source.Set(22222)" << std::endl;
////		dummy_source.Set(22222);
//
//		std::cout << "predecessor == 11111 ???" << std::endl;
//		assert(predecessor.Value() == 11111);
//		std::cout << "source == 11111 ???" << std::endl;
//		assert(source.Value() == 11111);
//		std::cout << "target == 11111 ???" << std::endl;
//		assert(target.Value() == 11111);
//		std::cout << "successor == 11111 ???" << std::endl;
//		assert(successor.Value() == 11111);

//		DataValue int_value_2 = 222;
//		VarSignalT<DataValue> predessor_2 = MakeVar<D>(int_value_2);
//
//		// connector_signal = MakeSignal(*output_attr->value, [] (inexor::entity_system::DataValue v) { return v; });
//
//    	/// The data container value (Signal) is not able to set the attribute value.
//    	// SignalT<DataValue> value = MakeSignal(, [] (inexor::entity_system::DataValue v) { return v; });
//
//
//		DataValue add_value_1 = 333;
//		SignalT<DataValue> add_1 = MakeVar<D>(add_value_1);
//
//		DataValue add_value_2 = 444;
//		SignalT<DataValue> add_2 = MakeVar<D>(add_value_2);
//
//		SignalT<DataValue> sum = MakeSignal(
//			With(add_1, add_2),
//			[] (inexor::entity_system::DataValue augend, inexor::entity_system::DataValue addend)
//			{
//				int result = std::get<DataType::INT>(augend) + std::get<DataType::INT>(addend);
//				std::cout << "ADD_INT: " << std::get<DataType::INT>(augend) << " + " << std::get<DataType::INT>(addend) << " = " << result << std::endl;
//				return DataValue(result);
//			}
//		);
//
//
//    	/// The data container initial value (VarSignal) is able to set the attribute value.
//    	VarSignalT<DataValue> own_value;


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

		std::string add_int_name = "add_int";
		std::cout << "Create entity instance '" << add_int_name << "'" << std::endl;
		std::optional<std::shared_ptr<inexor::entity_system::EntityInstance>> o_add_int = add_int_factory->create_instance();

		if (o_source.has_value() && o_target_1.has_value() && o_target_2.has_value() && o_target_3.has_value() && o_add_int.has_value())
		{
			std::shared_ptr<inexor::entity_system::EntityInstance> source = o_source.value();
			std::shared_ptr<inexor::entity_system::EntityInstance> target_1 = o_target_1.value();
			std::shared_ptr<inexor::entity_system::EntityInstance> target_2 = o_target_2.value();
			std::shared_ptr<inexor::entity_system::EntityInstance> target_3 = o_target_3.value();
			std::shared_ptr<inexor::entity_system::EntityInstance> add_int = o_add_int.value();

			std::cout << "Get entity instance attributes" << std::endl;
			std::string value_attribute_name = "value";
			std::optional<std::shared_ptr<inexor::entity_system::EntityAttributeInstance>> o_source_attr_value = source->get_attribute_instance(value_attribute_name);
			std::optional<std::shared_ptr<inexor::entity_system::EntityAttributeInstance>> o_target_1_attr_value = target_1->get_attribute_instance(value_attribute_name);
			std::optional<std::shared_ptr<inexor::entity_system::EntityAttributeInstance>> o_target_2_attr_value = target_2->get_attribute_instance(value_attribute_name);
			std::optional<std::shared_ptr<inexor::entity_system::EntityAttributeInstance>> o_target_3_attr_value = target_3->get_attribute_instance(value_attribute_name);

			std::string augend_attribute_name = "augend";
			std::string addend_attribute_name = "addend";
			std::string sum_attribute_name = "sum";
			std::optional<std::shared_ptr<inexor::entity_system::EntityAttributeInstance>> o_add_int_attr_augend = add_int->get_attribute_instance(augend_attribute_name);
			std::optional<std::shared_ptr<inexor::entity_system::EntityAttributeInstance>> o_add_int_attr_addend = add_int->get_attribute_instance(addend_attribute_name);
			std::optional<std::shared_ptr<inexor::entity_system::EntityAttributeInstance>> o_add_int_attr_sum = add_int->get_attribute_instance(sum_attribute_name);

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
				std::cout << source_name << "." << value_attribute_name << " = " << std::get<DataType::INT>(source_attr_value->value.Value()) << std::endl;
				std::cout << target_1_name << "." << value_attribute_name << " = " << std::get<DataType::INT>(target_1_attr_value->value.Value()) << std::endl;
				std::cout << target_2_name << "." << value_attribute_name << " = " << std::get<DataType::INT>(target_2_attr_value->value.Value()) << std::endl;
				std::cout << target_3_name << "." << value_attribute_name << " = " << std::get<DataType::INT>(target_3_attr_value->value.Value()) << std::endl;
				std::cout << add_int_name << "." << augend_attribute_name << " = " << std::get<DataType::INT>(add_int_attr_augend->value.Value()) << std::endl;
				std::cout << add_int_name << "." << addend_attribute_name << " = " << std::get<DataType::INT>(add_int_attr_addend->value.Value()) << std::endl;
				std::cout << add_int_name << "." << sum_attribute_name << " = " << std::get<DataType::INT>(add_int_attr_sum->value.Value()) << std::endl;

				std::cout << "Create connector " << source_name << "." << value_attribute_name << " ---> " << target_1_name << "." << value_attribute_name << std::endl;
				std::optional<std::shared_ptr<inexor::visual_scripting::Connector>> connector_1 = connector_manager->create_connector(source_attr_value, target_1_attr_value);

				std::cout << "Create connector " << source_name << "." << value_attribute_name << " ---> " << target_2_name << "." << value_attribute_name << std::endl;
				std::optional<std::shared_ptr<inexor::visual_scripting::Connector>> connector_2 = connector_manager->create_connector(source_attr_value, target_2_attr_value);

				std::cout << "Create connector " << target_1_name << "." << value_attribute_name << " ---> " << target_3_name << "." << value_attribute_name << std::endl;
				std::optional<std::shared_ptr<inexor::visual_scripting::Connector>> connector_3 = connector_manager->create_connector(target_1_attr_value, target_3_attr_value);

				std::cout << "Create connector " << target_2_name << "." << value_attribute_name << " ---> " << add_int_name << "." << augend_attribute_name << std::endl;
				std::optional<std::shared_ptr<inexor::visual_scripting::Connector>> connector_4 = connector_manager->create_connector(target_2_attr_value, add_int_attr_augend);

				std::cout << "Create connector " << target_3_name << "." << value_attribute_name << " ---> " << add_int_name << "." << addend_attribute_name << std::endl;
				std::optional<std::shared_ptr<inexor::visual_scripting::Connector>> connector_5 = connector_manager->create_connector(target_3_attr_value, add_int_attr_addend);

				std::cout << "Initial values (after connector created)" << std::endl;
				std::cout << source_name << "." << value_attribute_name << " = " << std::get<DataType::INT>(source_attr_value->value.Value()) << std::endl;
				std::cout << target_1_name << "." << value_attribute_name << " = " << std::get<DataType::INT>(target_1_attr_value->value.Value()) << std::endl;
				std::cout << target_2_name << "." << value_attribute_name << " = " << std::get<DataType::INT>(target_2_attr_value->value.Value()) << std::endl;
				std::cout << target_3_name << "." << value_attribute_name << " = " << std::get<DataType::INT>(target_3_attr_value->value.Value()) << std::endl;
				std::cout << add_int_name << "." << augend_attribute_name << " = " << std::get<DataType::INT>(add_int_attr_augend->value.Value()) << std::endl;
				std::cout << add_int_name << "." << addend_attribute_name << " = " << std::get<DataType::INT>(add_int_attr_addend->value.Value()) << std::endl;
				std::cout << add_int_name << "." << sum_attribute_name << " = " << std::get<DataType::INT>(add_int_attr_sum->value.Value()) << std::endl;
				std::random_device rdev;
				std::mt19937 rgen(rdev());
				std::uniform_int_distribution<int> idist(0, 1000);
				int i = 0;
				while (i < 998)
				{
					std::this_thread::sleep_for(10s);
					i = idist(rgen);
					std::cout << "source.value.Set(" << i << ")" << std::endl;
					source_attr_value->own_value.Set(i);
					std::cout << source_name << "." << value_attribute_name << " = " << std::get<DataType::INT>(source_attr_value->value.Value()) << std::endl;
					std::cout << target_1_name << "." << value_attribute_name << " = " << std::get<DataType::INT>(target_1_attr_value->value.Value()) << std::endl;
					std::cout << target_2_name << "." << value_attribute_name << " = " << std::get<DataType::INT>(target_2_attr_value->value.Value()) << std::endl;
					std::cout << target_3_name << "." << value_attribute_name << " = " << std::get<DataType::INT>(target_3_attr_value->value.Value()) << std::endl;
					std::cout << add_int_name << "." << augend_attribute_name << " = " << std::get<DataType::INT>(add_int_attr_augend->value.Value()) << std::endl;
					std::cout << add_int_name << "." << addend_attribute_name << " = " << std::get<DataType::INT>(add_int_attr_addend->value.Value()) << std::endl;
					std::cout << add_int_name << "." << sum_attribute_name << " = " << std::get<DataType::INT>(add_int_attr_sum->value.Value()) << std::endl;
				}
			}
		}

	}


};
};
