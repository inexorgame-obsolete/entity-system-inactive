// Inexor entity system
// (c)2018 Inexor

#include "ConfigurationManager.hpp"

using namespace std;

namespace inexor {
namespace configuration {

	ConfigurationManager::ConfigurationManager(
		shared_ptr<inexor::entity_system::type_system::BoolConstantFactory> bool_constant_factory,
		shared_ptr<inexor::entity_system::type_system::IntConstantFactory> int_constant_factory,
		shared_ptr<inexor::entity_system::type_system::FloatConstantFactory> float_constant_factory,
		shared_ptr<inexor::entity_system::type_system::StringConstantFactory> string_constant_factory
	)
	{
		this->bool_constant_factory = bool_constant_factory;
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
		set("PID", _getpid());
#else
		set("PID", getpid());
#endif
	}

	void ConfigurationManager::set(string name, bool value)
	{
		bool_constant_factory->create_instance(name, value);
	}

	void ConfigurationManager::set(string name, int value)
	{
		int_constant_factory->create_instance(name, value);
	}

	void ConfigurationManager::set(string name, float value)
	{
		float_constant_factory->create_instance(name, value);
	}

	void ConfigurationManager::set(string name, string value)
	{
		string_constant_factory->create_instance(name, value);
	}

	bool ConfigurationManager::get_bool(string config_name)
	{
		return false;
	}

	int ConfigurationManager::get_int(string config_name)
	{
		return 0;
	}

	float ConfigurationManager::get_float(string config_name)
	{
		return 0.0f;
	}

	string ConfigurationManager::get_string(string config_name)
	{
		return "";
	}

}
}
