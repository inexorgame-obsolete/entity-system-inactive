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
        shutdown();
	}

	void AudioManager::init()
	{
        spdlog::info("Initialising OpenAL.");

        // Initialise OpenAL.
        // TODO: Enumerate devices instead of using the default device!
        OpenAL_device = alcOpenDevice(NULL);

        if(!OpenAL_device)
        {
            spdlog::critical("Creating OpenAL device using alcOpenDevice method failed!");
        }
        else
        {
            // Create an OpenAL context.
            OpenAL_context = alcCreateContext(OpenAL_device, NULL);

            // Check if we can set the context.
            if(!alcMakeContextCurrent(OpenAL_context))
            {
                ALenum context_creation_error = alGetError();
                spdlog::critical("Failed to make OpenAL context current! Error code: {}", context_creation_error);
            }
            else
            {
                spdlog::info("OpenAL setup complete!");
            }
        }
	}

    void AudioManager::shutdown()
    {
        spdlog::info("Shutting down OpenAL.");
        OpenAL_device = alcGetContextsDevice(OpenAL_context);
        alcMakeContextCurrent(NULL);
        alcDestroyContext(OpenAL_context);
        alcCloseDevice(OpenAL_device);
    }

}
}
