#include "AudioModule.hpp"

#include <utility>

namespace inexor::audio {

    AudioModule::AudioModule(AudioManagerPtr audio_manager)
    {
        this->audio_manager = std::move(audio_manager);
    }

    AudioModule::~AudioModule() = default;

    void AudioModule::init()
    {
        audio_manager->init();
    }

    void AudioModule::shutdown()
    {
        audio_manager->shutdown();
    }

} // namespace inexor
