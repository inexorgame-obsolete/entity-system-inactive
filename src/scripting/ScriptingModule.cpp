#include "ScriptingModule.hpp"

namespace inexor {
namespace scripting {

	ScriptingModule::ScriptingModule(
		ScriptExecutorPtr script_executor
	)
	{
        this->script_executor = script_executor;
	}

	ScriptingModule::~ScriptingModule()
	{
	}

	void ScriptingModule::init()
	{
		script_executor->init();
	}

	void ScriptingModule::shutdown()
	{
		script_executor->shutdown();
	}

}
}
