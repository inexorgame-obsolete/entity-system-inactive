#pragma once

#include "audio/managers/AudioManager.hpp"
#include "base/LifeCycleComponent.hpp"

namespace inexor::audio {

/// @class AudioModule
/// @brief A module for handling audio/sound.
class AudioModule : public LifeCycleComponent
{
    using AudioManagerPtr = std::shared_ptr<AudioManager>;

    public:
    /// @brief Constructor.
    /// @param audio_manager The audio manager.
    explicit AudioModule(AudioManagerPtr audio_manager);

    /// Destructor.
    ~AudioModule();

    /// Returns the name of the component
    std::string get_component_name() override;

    private:
    /// The audio manager.
    AudioManagerPtr audio_manager;
};

} // namespace inexor::audio
