// Inexor entity system
// (c)2018 Inexor

#include "ConvertersTypeSystemManager.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace entity_system {
namespace type_system {

	ConvertersTypeSystemManager::ConvertersTypeSystemManager(
		shared_ptr<IntToFloatEntityTypeProvider> int_to_float_entity_type_provider,
		shared_ptr<IntToFloatFactory> int_to_float_factory
	)
	{
		this->int_to_float_entity_type_provider = int_to_float_entity_type_provider;
		this->int_to_float_factory = int_to_float_factory;
	}

	ConvertersTypeSystemManager::~ConvertersTypeSystemManager()
	{
	}

	void ConvertersTypeSystemManager::init()
	{
	}

}
}
}
