#include "ScriptExecutor.hpp"

namespace inexor {
namespace scripting {

	ScriptExecutor::ScriptExecutor(
		EcmaScriptExecutorPtr ecma_script_executor
	)
	{
		this->ecma_script_executor = ecma_script_executor;
	}

	ScriptExecutor::~ScriptExecutor()
	{
	}

	void ScriptExecutor::init()
	{
		ecma_script_executor->init();
	}

	void ScriptExecutor::shutdown()
	{
		ecma_script_executor->shutdown();
	}

	void ScriptExecutor::execute(int script_type, std::string path)
	{
		switch (script_type)
		{
			case 0:
				ecma_script_executor->execute(path);
				break;
			default:
				break;
		}
	}

}
}
