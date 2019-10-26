#pragma once

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
    class AudioManager : public std::enable_shared_from_this<AudioManager>
    {
        public:
        /// @brief Constructor.
        /// @note The dependencies of this class will be injected automatically.<br>
        /// BOOST_DI_INJECT constructor parameters is limited to BOOST_DI_CFG_CTOR_LIMIT_SIZE,<br>
        /// which by default is set to 10. Not more than 10 arguments can be passed to the DI constructor!<br>
        /// https://boost-experimental.github.io/di/user_guide/index.html
        /// @param log_manager The log manager.
        explicit AudioManager(LogManagerPtr log_manager);

        /// Destructor.
        ~AudioManager();

        /// Initialize audio module.
        int init();

        /// Shuts down OpenAL.
        void shutdown();

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

} // namespace inexor
