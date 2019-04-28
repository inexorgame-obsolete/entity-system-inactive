#pragma once

#include "logging/managers/LogManager.hpp"

#include <Corrade/Containers/Array.h>
#include <Corrade/PluginManager/Manager.h>
#include <Magnum/Audio/AbstractImporter.h>
#include <Magnum/Audio/Buffer.h>

// OpenAL
#include <AL/al.h>
#include <AL/alc.h>


namespace inexor {
namespace audio {

	using LogManagerPtr = std::shared_ptr<inexor::logging::LogManager>;

	// TODO: Move to model
	struct AudioBuffer {

		/// The importer.
		Corrade::Containers::Pointer<Magnum::Audio::AbstractImporter> importer;

		/// The buffer data.
		Corrade::Containers::Array<char> buffer_data;

		/// The cache for the glyphs.
		std::shared_ptr<Magnum::Audio::Buffer> buffer;

	};

	struct Listener{};
	struct Source{};

	using AudioBufferPtr = std::shared_ptr<AudioBuffer>;
	using AudioBufferPtrOpt = std::optional<AudioBufferPtr>;

	using ListenerPtr = std::shared_ptr<Listener>;
	using ListenerPtrOpt = std::optional<ListenerPtr>;

	using SourcePtr = std::shared_ptr<Source>;
	using SourcePtrOpt = std::optional<SourcePtr>;

	/// @class AudioManager
	/// @brief Management of the audio data.
	/// @note This implementation is based on OpenAL.<br>
	/// https://www.openal.org/<br>
	/// https://en.wikipedia.org/wiki/OpenAL
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

			/// Shuts down OpenAL.
			void shutdown();

			/// Update.
			void update();

			/// Detects the audio devices.
			void detect_audio_devices();

			/// Detects the extensions.
			void detect_extensions();

			/// Loads a statically included audio file.
			AudioBufferPtrOpt load_internal(std::string internal_filename);

			/// Loads an audio file from the file system.
			AudioBufferPtrOpt load(std::string path);

			std::shared_ptr<Source> create_source();

			// TODO: play(EntityInstancePtr sound)
			void play(SourcePtr source);

			// TODO: stop(EntityInstancePtr sound)
			void stop(SourcePtr source);

			/// The resource group for statically included audio files.
			static constexpr char RESOURCE_GROUP[] = "inexor";

			/// The name of the audio importer plugin.
			static constexpr char AUDIO_IMPORTER_PLUGIN[] = "StbVorbisAudioImporter";

			/// The logger name of this service.
			static constexpr char LOGGER_NAME[] = "inexor.audio.manager";

		private:

			std::shared_ptr<Listener> create_listener();

			/// The log manager.
			LogManagerPtr log_manager;

			std::shared_ptr<Corrade::PluginManager::Manager<Magnum::Audio::AbstractImporter>> audio_plugin_manager;

			std::shared_ptr<Magnum::Audio::Context> context;

//			std::shared_ptr<Magnum::Audio::Listener3D> listener;
//
//			std::shared_ptr<Magnum::Audio::PlayableGroup3D> playables;
//
//			std::shared_ptr<Magnum::Audio::Playable3D> playable;

//			/// The OpenAL device.
//			ALCdevice *device;
//
//			/// The OpenAL context.
//			ALCcontext *context2;

	};

}
}
