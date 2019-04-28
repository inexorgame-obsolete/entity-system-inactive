#include "AudioManager.hpp"
#include "spdlog/spdlog.h"

#include <Magnum/Audio/AbstractImporter.h>
#include <Magnum/Audio/Buffer.h>
#include <Magnum/Audio/Context.h>
#include <Magnum/Audio/Listener.h>
#include <Magnum/Audio/Playable.h>
#include <Magnum/Audio/PlayableGroup.h>
#include <Magnum/Audio/Source.h>
#include <Magnum/SceneGraph/Object.h>

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
	}

	void AudioManager::init()
	{
		log_manager->register_logger(LOGGER_NAME);

		context = std::make_shared<Magnum::Audio::Context>();

		spdlog::get(LOGGER_NAME)->info("Open AL:");
		spdlog::get(LOGGER_NAME)->info("  Renderer: {}", context->rendererString());
		spdlog::get(LOGGER_NAME)->info("  Vendor:   {}", context->vendorString());
		spdlog::get(LOGGER_NAME)->info("  Version:  {}", context->versionString());
		spdlog::get(LOGGER_NAME)->info("  Device:   {}", context->deviceSpecifierString());
		spdlog::get(LOGGER_NAME)->info("  HRTF:     {}{}", context->isHrtfEnabled() ? "Enabled " : "Disabled ", context->hrtfSpecifierString());

		// List all audio devices.
		detect_audio_devices();

		// List all extensions
		detect_extensions();

//		playables = std::make_shared<Magnum::Audio::PlayableGroup3D>();

//		listener = std::make_shared<Magnum::Audio::Listener3D>();

//		// Initialise an OpenAL device.
//		device = alcOpenDevice(NULL);
//		if(!device)
//		{
//			spdlog::get(LOGGER_NAME)->critical("Failed to create an OpenAL device!");
//			return;
//		}
//
//		// Create context.
//		context2 = alcCreateContext(device, NULL);
//		if(!alcMakeContextCurrent(context2))
//		{
//			spdlog::get(LOGGER_NAME)->critical("Failed to set the current OpenAL context!");
//			return;
//		}

//		create_listener();

//		// TODO: Link sources to the entity-system!
//		ALuint source;
//		alGenSources((ALuint)1, &source);
//		alSourcef(source, AL_PITCH, 1);
//		alSourcef(source, AL_GAIN, 1);
//		alSource3f(source, AL_POSITION, 0, 0, 0);
//		alSource3f(source, AL_VELOCITY, 0, 0, 0);
//		alSourcei(source, AL_LOOPING, AL_FALSE);
//
//		// TODO: Write a manager for buffers!
//		// TODO: Link buffers to entity-system!
//		ALuint buffer;
//		alGenBuffers((ALuint)1, &buffer);

		// Load vorbis audio importer plugin
		audio_plugin_manager = std::make_shared<Corrade::PluginManager::Manager<Magnum::Audio::AbstractImporter>>();
		// TODO: LoadState.Loaded | LoadState.Static
		audio_plugin_manager->load(AUDIO_IMPORTER_PLUGIN);

		load_internal("idle.ogg");
	}
	
	void AudioManager::shutdown()
	{
		context = nullptr;
//		if (context2)
//		{
//			alcDestroyContext(context2);
//		}
//		if (device)
//		{
//			alcCloseDevice(device);
//		}
	}


	void AudioManager::update()
	{
		// listener->update({});
	}

	AudioBufferPtrOpt AudioManager::load_internal(std::string internal_filename)
	{
		AudioBufferPtr audio_buffer = std::make_shared<AudioBuffer>();
		audio_buffer->importer = audio_plugin_manager->instantiate(AUDIO_IMPORTER_PLUGIN);
		if (audio_buffer->importer)
		{
			const Corrade::Utility::Resource rs{RESOURCE_GROUP};
			audio_buffer->importer->openData(rs.getRaw(internal_filename));
			// Get the data from importer and add them to the buffer
			// Be sure to keep a copy to avoid dangling reference
			audio_buffer->buffer_data = audio_buffer->importer->data();
			audio_buffer->buffer = std::make_shared<Magnum::Audio::Buffer>();
			audio_buffer->buffer->setData(audio_buffer->importer->format(), audio_buffer->buffer_data, audio_buffer->importer->frequency());
			return audio_buffer;
		} else {
			spdlog::get(LOGGER_NAME)->error("Failed to load internal audio file {}", internal_filename);
			return std::nullopt;
		}
	}

	void AudioManager::detect_audio_devices()
	{
		spdlog::get(LOGGER_NAME)->info("Audio devices:");
		for (std::string device_specifier : context->deviceSpecifierStrings())
		{
			spdlog::get(LOGGER_NAME)->info("  [{}]", device_specifier);
		}
//		const ALCchar *devices = alcGetString(NULL, ALC_DEVICE_SPECIFIER);
//		const ALCchar *device = devices, *next = devices + 1;
//		size_t len = 0;
//		spdlog::get(LOGGER_NAME)->info("Audio devices:");
//		while (device && *device != '\0' && next && *next != '\0') {
//			spdlog::get(LOGGER_NAME)->info("  [{}]", device);
//			len = strlen(device);
//			device += (len + 1);
//			next += (len + 2);
//		}
	}

	void AudioManager::detect_extensions()
	{
		spdlog::get(LOGGER_NAME)->info("Audio extensions:");
		for (std::string extension : context->extensionStrings())
		{
			spdlog::get(LOGGER_NAME)->info("  [{}]", extension);
		}
	}

	ListenerPtr AudioManager::create_listener()
	{
		// TODO: Do proper error handling!
		// TODO: Make the listener more dynamic!
		// TODO: Link listener to the entity-system!
		ALfloat listenerOri[] = { 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f };
		alListener3f(AL_POSITION, 0, 0, 1.0f);
		alListener3f(AL_VELOCITY, 0, 0, 0);
		alListenerfv(AL_ORIENTATION, listenerOri);
	}

	SourcePtr AudioManager::create_source()
	{
	}

	void AudioManager::play(SourcePtr audio)
	{
		SourcePtr source = create_source();
		// std::shared_ptr<Magnum::Audio::Playable3D>
		// playable = std::make_shared<Magnum::Audio::Playable3D>({}, playables.get());
		// playables->add((*playable));
		// alSourcei(source, AL_BUFFER, buffer);
	}

}
}
