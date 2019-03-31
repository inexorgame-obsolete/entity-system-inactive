#pragma once

#include "logging/managers/LogManager.hpp"

// OpenAL
#include <AL/al.h>
#include <AL/alc.h>

// Use glm::vec3
#include <glm/vec3.hpp>


namespace inexor {
namespace audio {

	using LogManagerPtr = std::shared_ptr<inexor::logging::LogManager>;

	/// @class AudioManager
	/// @brief Management of the audio data.
    /// @note This implementation is based on OpenAL.<br>
	/// https://www.openal.org/
    class AudioManager
	: public std::enable_shared_from_this<AudioManager>
	{
        private:

            /// The OpenAL audio device.
            ALCdevice *OpenAL_device;

            /// The OpenAL context.
            ALCcontext *OpenAL_context;

			/// Sound sources.
			/// TODO: Link this to the entity-system!
			std::vector<ALuint> OpenAL_sound_sources;

			/// Sound buffers.
			/// TODO: Link this to the entity-system!
			std::vector<ALuint> OpenAL_sound_buffers;

		public:

			/// @brief Constructor.
			/// @note The dependencies of this class will be injected automatically.<br>
			/// BOOST_DI_INJECT constructor parameters is limited to BOOST_DI_CFG_CTOR_LIMIT_SIZE,<br>
			/// which by default is set to 10. Not more than 10 arguments can be passed to the DI constructor!<br>
			/// https://boost-experimental.github.io/di/user_guide/index.html
			/// @param log_manager The log manager.
			AudioManager(
				LogManagerPtr log_manager
			);

			/// Destructor.
			~AudioManager();

			/// Initialize audio module.
			void init();

			/// @brief Sets the position of the listener.
			/// @param listener_position The listener's position.
			void set_listener_position(glm::vec3 listener_position);
			
			/// @brief Sets the velocity of the listener.
			/// @param listener_velocity The listener's velocity.
			void set_listener_velocity(glm::vec3 listener_velocity);

			/// @brief Sets the listeners orientation.
			/// @param at The position of the listener's orientation.
			/// @param up A vector which describes where the upside is.
			void set_listener_orientation(glm::vec3 at, glm::vec3 up);

			/// Set the listener's options to standard values.
			void set_listener_settings_to_standard();

			/// @brief Creates a new sound source.
			/// @param position The position of the sound source.
			/// @param velocity The velocity of the sound source.
			/// @param looping If set to true, the sound will be looped when played.
			/// @param pitch ?
			/// @param gain ?
			void create_sound_source(glm::vec3 position, glm::vec3 velocity, bool looping = false, float pitch = 1.0f, float gain = 1.0f);

            /// Shuts down OpenAL.
            void shutdown();

			/// The logger name of this service.
			static constexpr char LOGGER_NAME[] = "inexor.audio.manager";

		private:

			/// The log manager.
			LogManagerPtr log_manager;

	};

}
}
