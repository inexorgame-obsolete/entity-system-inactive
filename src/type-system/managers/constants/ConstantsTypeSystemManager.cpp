// Inexor entity system
// (c)2018 Inexor

#include "ConstantsTypeSystemManager.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace entity_system {
namespace type_system {

	ConstantsTypeSystemManager::ConstantsTypeSystemManager(
		shared_ptr<IntConstantEntityTypeProvider> int_constant_entity_type_provider,
		shared_ptr<FloatConstantEntityTypeProvider> float_constant_entity_type_provider,
		shared_ptr<StringConstantEntityTypeProvider> string_constant_entity_type_provider,
		shared_ptr<IntConstantFactory> int_constant_factory,
		shared_ptr<FloatConstantFactory> float_constant_factory,
		shared_ptr<StringConstantFactory> string_constant_factory
	)
	{
		this->int_constant_entity_type_provider = int_constant_entity_type_provider;
		this->float_constant_entity_type_provider = float_constant_entity_type_provider;
		this->string_constant_entity_type_provider = string_constant_entity_type_provider;
		this->int_constant_factory = int_constant_factory;
		this->float_constant_factory = float_constant_factory;
		this->string_constant_factory = string_constant_factory;
	}

	ConstantsTypeSystemManager::~ConstantsTypeSystemManager()
	{
	}

	void ConstantsTypeSystemManager::init()
	{
	}

}
}
}
