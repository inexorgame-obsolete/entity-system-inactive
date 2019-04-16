#include "AudioManager.hpp"
#include "spdlog/spdlog.h"

// TODO: enable magnum audio support as soon as there is an magnum package with audio support (2/2)
//#include <Magnum/Audio/AbstractImporter.h>
//#include <Magnum/Audio/Buffer.h>
//#include <Magnum/Audio/Context.h>
//#include <Magnum/Audio/Listener.h>
//#include <Magnum/Audio/Playable.h>
//#include <Magnum/Audio/PlayableGroup.h>
//#include <Magnum/Audio/Source.h>

#include <string.h>
#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>

namespace inexor {
namespace audio {

	AudioManager::AudioManager(
		LogManagerPtr log_manager
	) {
		this->log_manager = log_manager;
	}

	AudioManager::~AudioManager()
	{
		shutdown();
	}

	int AudioManager::init()
	{
		// Initialise an OpenAL device.
		device = alcOpenDevice(NULL);
		if(!device)
		{
			spdlog::get(LOGGER_NAME)->critical("Failed to create an OpenAL device!");
			return -1;
		}

		// Create context.
		context = alcCreateContext(device, NULL);
		if(!alcMakeContextCurrent(context))
		{
			spdlog::get(LOGGER_NAME)->critical("Failed to set the current OpenAL context!");
			return -1;
		}
		
		// TODO: Do proper error handling!
		// TODO: Make the listener more dynamic!
		// TODO: Link listener to the entity-system!
		ALfloat listenerOri[] = { 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f };
		alListener3f(AL_POSITION, 0, 0, 1.0f);
		alListener3f(AL_VELOCITY, 0, 0, 0);
		alListenerfv(AL_ORIENTATION, listenerOri);

		// TODO: Link sources to the entity-system!
		ALuint source;
		alGenSources((ALuint)1, &source);
		alSourcef(source, AL_PITCH, 1);
		alSourcef(source, AL_GAIN, 1);
		alSource3f(source, AL_POSITION, 0, 0, 0);
		alSource3f(source, AL_VELOCITY, 0, 0, 0);
		alSourcei(source, AL_LOOPING, AL_FALSE);

		// TODO: Write a manager for buffers!
		// TODO: Link buffers to entity-system!
		ALuint buffer;
		alGenBuffers((ALuint)1, &buffer);

		// Load audio file.
		

		// Success!
		return 1;
	}
	
    void AudioManager::shutdown()
    {
    }

}
}
