#pragma once

#include "base/LifeCycleComponent.hpp"
#include "logging/managers/LogManager.hpp"

// OpenAL
#include <AL/al.h>
#include <AL/alc.h>

// Use glm::vec3
#include <glm/vec3.hpp>

namespace inexor::audio {

using LogManagerPtr = std::shared_ptr<inexor::logging::LogManager>;

/// @class AudioManager
/// @brief Management of the audio data.
/// @note This implementation is based on OpenAL.<br>
/// https://www.openal.org/
class AudioManager : public LifeCycleComponent, public std::enable_shared_from_this<AudioManager>
{
    public:
    /// @brief Constructor.
    /// @param log_manager The log manager.
    explicit AudioManager(LogManagerPtr log_manager);

    /// Destructor.
    ~AudioManager();

    /// Initialize OpenAL.
    void init() override;

    /// Shuts down OpenAL.
    void destroy() override;

    /// Returns the name of the component
    std::string get_component_name() override;

    /// The logger name of this service.
    static constexpr char LOGGER_NAME[] = "inexor.audio.manager";

    private:
    /// The log manager.
    LogManagerPtr log_manager;

    /// The OpenAL device.
    ALCdevice *device{};

    /// The OpenAL context.
    ALCcontext *context{};
};

} // namespace inexor::audio
