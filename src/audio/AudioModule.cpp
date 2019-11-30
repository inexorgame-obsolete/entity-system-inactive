#include "AudioModule.hpp"

#include <utility>

namespace inexor::audio {

AudioModule::AudioModule(AudioManagerPtr audio_manager)
    : LifeCycleComponent(audio_manager)
{
    this->audio_manager = std::move(audio_manager);
}

AudioModule::~AudioModule() = default;

std::string AudioModule::get_component_name()
{
    return "AudioModule";
}

} // namespace inexor::audio
