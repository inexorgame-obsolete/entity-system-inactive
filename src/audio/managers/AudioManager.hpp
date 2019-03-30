#pragma once

#include "logging/managers/LogManager.hpp"
struct GLFWwindow;

namespace inexor {
namespace audio {

	using LogManagerPtr = std::shared_ptr<inexor::logging::LogManager>;

	/// @class AudioManager
	/// @brief Management of the keyboard input data.
	class AudioManager
	: public std::enable_shared_from_this<AudioManager>
	{
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

			/// The logger name of this service.
			static constexpr char LOGGER_NAME[] = "inexor.audio.manager";

		private:

			/// The log manager.
			LogManagerPtr log_manager;

	};

}
}
