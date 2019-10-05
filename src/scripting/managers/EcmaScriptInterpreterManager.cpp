#include "EcmaScriptInterpreterManager.hpp"

namespace inexor {
namespace scripting {

	EcmaScriptInterpreterManager::EcmaScriptInterpreterManager(
		EcmaScriptPlatformPtr ecma_script_platform
	)
	{
		this->ecma_script_platform = ecma_script_platform;
	}

	EcmaScriptInterpreterManager::~EcmaScriptInterpreterManager()
	{
	}

	void EcmaScriptInterpreterManager::init()
	{
	}

	void EcmaScriptInterpreterManager::shutdown()
	{
		for (auto kv : interpreters)
		{
			// Shutdown interpreter instance
			kv.second->exit();
			// Wait for interpreter instance's thread to be exited...
			while (kv.second->is_running())
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(50));
			}
			// Wait for interpreter instance's to be deinitialized
			while (kv.second->is_initialized())
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(50));
			}
			// Remove interpreter instance
			interpreters.erase(kv.first);
		}
	}

	EcmaScriptInterpreterPtr EcmaScriptInterpreterManager::create_interpreter(std::string name)
	{
		// TODO: check for existence
		// TODO: return existing instance if interpreter with this name exists already
		spdlog::info("EcmaScriptInterpreterManager [{}] Create Interpreter", name);
		interpreters[name] = std::make_shared<EcmaScriptInterpreter>(name, ecma_script_platform);
		std::thread ecma_script_thread([this, name]() {
			// Runs the main loop of the interpreter instance in it's own thread
			interpreters[name]->run_context();
		});
		ecma_script_thread.detach();
		// Wait for interpreter instance's thread to be initialized...
		spdlog::info("EcmaScriptInterpreterManager [{}] Wait for initialized", name);
		while (!interpreters[name]->is_initialized())
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(50));
		}
		spdlog::info("EcmaScriptInterpreterManager [{}] Initialized", name);
		return interpreters[name];
	}

	EcmaScriptInterpreterPtr EcmaScriptInterpreterManager::get_interpreter(std::string name)
	{
		// TODO: check for existence
		// TODO: std::optional
		return interpreters[name];
	}

	void EcmaScriptInterpreterManager::destroy_interpreter(std::string name)
	{
		spdlog::info("EcmaScriptInterpreterManager [{}] destroy_interpreter", name);
		// Shutdown interpreter instance
		interpreters[name]->exit();
		// Wait for interpreter instance's to being destroyed
		spdlog::info("EcmaScriptInterpreterManager [{}] wait for initialized = false", name);
		while (interpreters[name]->is_initialized())
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(50));
		}
		// Remove interpreter instance
		spdlog::info("EcmaScriptInterpreterManager [{}] remove interpreter instance", name);
		interpreters.erase(name);
	}


}
}
