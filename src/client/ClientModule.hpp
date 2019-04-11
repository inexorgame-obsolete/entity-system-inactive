#pragma once

#include "audio/AudioModule.hpp"
#include "input/InputModule.hpp"
#include "renderer/RendererModule.hpp"

namespace inexor {
namespace client {

	/// @class ClientModule
	/// @brief This module contains all modules for the Inexor Client.
	class ClientModule
	{
		using AudioModulePtr = std::shared_ptr<audio::AudioModule>;
		using InputModulePtr = std::shared_ptr<input::InputModule>;
		using RendererModulePtr = std::shared_ptr<renderer::RendererModule>;

		public:

			/// @brief Constructor.
			/// @note The dependencies of this class will be injected automatically.
			/// @param audio_module The audio module.
			/// @param input_module The input module.
			/// @param renderer_module The renderer module.
			ClientModule(
				AudioModulePtr audio_module,
				InputModulePtr input_module,
				RendererModulePtr renderer_module
			);

			/// Destructor.
			~ClientModule();

			/// Initialization of the client module.
			void init();

			/// Shut down the client module.
			void shutdown();

			/// Update the client module.
			void update();

			/// Returns true, if the application should be shut down.
			bool shall_shutdown();

		private:

			/// The audio module.
			AudioModulePtr audio_module;

			/// The input module.
			InputModulePtr input_module;

			/// The renderer module.
			RendererModulePtr renderer_module;

	};

}
}
