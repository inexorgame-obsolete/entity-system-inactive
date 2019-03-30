#include "AudioManager.hpp"
#include "spdlog/spdlog.h"

namespace inexor {
namespace audio {

	AudioManager::AudioManager(
	LogManagerPtr log_manager
	) {
		this->log_manager = log_manager;
	}

	AudioManager::~AudioManager()
	{
	}

	void AudioManager::init()
	{
	}

}
}
