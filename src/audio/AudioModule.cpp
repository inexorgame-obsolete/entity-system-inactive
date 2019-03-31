#include "AudioModule.hpp"

namespace inexor {
namespace audio {

	AudioModule::AudioModule(
		AudioManagerPtr audio_manager
	)
	{
		this->audio_manager = audio_manager;
	}

	AudioModule::~AudioModule()
	{
	}

	void AudioModule::init()
	{
		audio_manager->init();
	}

    void AudioModule::shutdown()
    {
        audio_manager->shutdown();
    }

}
}
