#include "ScriptingModule.hpp"

namespace inexor {
namespace scripting {

	ScriptingModule::ScriptingModule(
		EcmaScriptPlatformPtr ecma_script_platform,
		ScriptExecutorPtr script_executor,
		EcmaScriptInterpreterManagerPtr ecma_script_interpreter_manager
	)
	{
        this->ecma_script_platform = ecma_script_platform;
        this->script_executor = script_executor;
        this->ecma_script_interpreter_manager = ecma_script_interpreter_manager;
	}

	ScriptingModule::~ScriptingModule()
	{
	}

	void ScriptingModule::init()
	{
		ecma_script_platform->init();
		script_executor->init();
		ecma_script_interpreter_manager->init();
	}

	void ScriptingModule::shutdown()
	{
		ecma_script_interpreter_manager->shutdown();
		script_executor->shutdown();
		ecma_script_platform->shutdown();
	}

}
}
