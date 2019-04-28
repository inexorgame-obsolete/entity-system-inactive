#include "AudioModule.hpp"

// Statically import the magnum audio plugins
// This is the only place to do this!
#include "audio/plugins/AudioPlugins.cpp"

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

	void AudioModule::update()
	{
		audio_manager->update();
	}

}
}
