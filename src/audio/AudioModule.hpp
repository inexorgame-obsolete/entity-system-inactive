#pragma once

#include "audio/managers/AudioManager.hpp"

namespace inexor {
namespace audio {

	/// @class AudioModule
	/// @brief A module for handling audio/sound.
	class AudioModule
	{
		using AudioManagerPtr = std::shared_ptr<AudioManager>;

		public:

			/// @brief Constructor.
			/// @note The dependencies of this class will be injected automatically.<br>
			/// BOOST_DI_INJECT constructor parameters is limited to BOOST_DI_CFG_CTOR_LIMIT_SIZE,<br>
			/// which by default is set to 10. Not more than 10 arguments can be passed to the DI constructor!<br>
			/// https://boost-experimental.github.io/di/user_guide/index.html
			/// @param audio_manager The audio manager.
			AudioModule(
				AudioManagerPtr audio_manager
			);

			/// Destructor.
			~AudioModule();

			/// Initialization of the audio module.
			void init();

			/// Shutdown audio module.
			void shutdown();

			/// Update audio module.
			void update();

		private:

			/// The audio manager.
			AudioManagerPtr audio_manager;

	};

}
}
