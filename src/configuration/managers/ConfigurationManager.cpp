// Inexor entity system
// (c)2018 Inexor

#include "ConfigurationManager.hpp"

using namespace inexor::entity_system;
using namespace inexor::entity_system::type_system;
using namespace std;

namespace inexor {
namespace configuration {

	ConfigurationManager::ConfigurationManager(
		shared_ptr<IntConstantFactory> int_constant_factory,
		shared_ptr<FloatConstantFactory> float_constant_factory,
		shared_ptr<StringConstantFactory> string_constant_factory
	)
	{
		this->int_constant_factory = int_constant_factory;
		this->float_constant_factory = float_constant_factory;
		this->string_constant_factory = string_constant_factory;
	}

	ConfigurationManager::~ConfigurationManager()
	{
	}

	void ConfigurationManager::init()
	{


#ifdef _WIN32
		int_constant_factory->create_instance("PID", _getpid());
#else
		int_constant_factory->create_instance("PID", getpid());
#endif

	}


}
}
