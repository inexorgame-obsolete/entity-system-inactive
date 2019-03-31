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

	void AudioManager::set_listener_position(glm::vec3 listener_position)
	{
		alListener3f(AL_POSITION, listener_position.x, listener_position.y, listener_position.z);
	}
	
	void AudioManager::set_listener_velocity(glm::vec3 listener_velocity)
	{
		alListener3f(AL_VELOCITY, listener_velocity.x, listener_velocity.y, listener_velocity.z);
	}

	void AudioManager::set_listener_orientation(glm::vec3 at, glm::vec3 up)
	{
		ALfloat listener_orientation[] = { at.x, at.y, at.z, up.x, up.y, up.z };
		alListenerfv(AL_ORIENTATION, listener_orientation);
	}

	void AudioManager::set_listener_settings_to_standard()
	{
		set_listener_position(glm::vec3(0.0f, 0.0f, 0.0f));
		set_listener_velocity(glm::vec3(0.0f, 0.0f, 0.0f));
		set_listener_orientation(glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	}

	void AudioManager::create_sound_source(glm::vec3 position, glm::vec3 velocity, bool looping, float pitch, float gain)
	{
		spdlog::info("Creating sound source at position {}, {}, {}, velocity {}, {}, {}, looping: {}, pitch: {}, gain: {}",
					position.x, position.y, position.z, (looping) ? std::string("true") : std::string("false"), pitch, gain);
		
		// Generate a sound source.
		ALuint sound_source;
		alGenSources((ALuint)1, &sound_source);
		
		// Set options for the sound source.
		alSource3f(sound_source, AL_POSITION, position.x, position.y, position.z);
		alSource3f(sound_source, AL_VELOCITY, velocity.x, velocity.y, velocity.z);
		alSourcei(sound_source, AL_LOOPING, looping);
		alSourcef(sound_source, AL_PITCH, pitch);
		alSourcef(sound_source, AL_GAIN, gain);

		// Generate a buffer for the sound source.
		ALuint buffer;
		alGenBuffers((ALuint)1, &buffer);
		
		// Add sound source to vector
		OpenAL_sound_sources.push_back(sound_source);
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
