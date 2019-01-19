// Inexor entity system
// (c)2018 Inexor

#include "LogManager.hpp"

using namespace std;

namespace inexor {
namespace logging {


	LogManager::LogManager(std::shared_ptr<inexor::entity_system::EntitySystem> entity_system) : entity_system(entity_system)
	{
	}

	LogManager::~LogManager()
	{
	}

	void LogManager::init()
	{
		spdlog::init_thread_pool(8192, 4);
		sinks.push_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
		sinks.push_back(std::make_shared<spdlog::sinks::rotating_file_sink_mt>("inexor.log", 1024 * 1024 * 10, 3));
		spdlog::register_logger(std::make_shared<spdlog::async_logger>("inexor.logging", sinks.begin(), sinks.end(), spdlog::thread_pool(), spdlog::async_overflow_policy::block));
		spdlog::get("inexor.logging")->info("Asynchronous logging initialized");
	}

	void LogManager::register_logger(std::string logger_name) {
		spdlog::register_logger(std::make_shared<spdlog::async_logger>(logger_name, sinks.begin(), sinks.end(), spdlog::thread_pool(), spdlog::async_overflow_policy::block));
		spdlog::get("inexor.logging")->info("Registered logger {}", logger_name);
	}

}
}
