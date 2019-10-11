#include "ScreenshotManager.hpp"

#include "spdlog/spdlog.h"

namespace inexor {
namespace renderer {

	ScreenshotManager::ScreenshotManager(
		LogManagerPtr log_manager
	) {
		this->log_manager = log_manager;
	}

	ScreenshotManager::~ScreenshotManager()
	{
	}

	void ScreenshotManager::init()
	{
		log_manager->register_logger(LOGGER_NAME);
	}

	void ScreenshotManager::shutdown()
	{
	}

	void ScreenshotManager::create_screenshot()
	{
	}

}
}
