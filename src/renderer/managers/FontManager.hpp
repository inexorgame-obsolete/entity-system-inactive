#pragma once

#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "logging/managers/LogManager.hpp"

#include <Corrade/PluginManager/Manager.h>
#include <Magnum/GL/Renderer.h>
#include <Magnum/Text/AbstractFont.h>
#include <Magnum/Text/DistanceFieldGlyphCache.h>
#include <Magnum/Text/Renderer.h>
#include <Magnum/Shaders/DistanceFieldVector.h>

namespace inexor {
namespace renderer {

	// TODO: Move to model
	// TODO: Add cleanup which have to be called within render thread
	struct Font {

		std::string path;

		/// The font.
		Corrade::Containers::Pointer<Magnum::Text::AbstractFont> font;

		/// The cache for the glyphs.
		std::shared_ptr<Magnum::Text::DistanceFieldGlyphCache> glyph_cache;

		/// The font renderer.
		std::shared_ptr<Magnum::Text::Renderer2D> renderer;

		/// The font shader.
		std::shared_ptr<Magnum::Shaders::DistanceFieldVector2D> shader;

	};

	using LogManagerPtr = std::shared_ptr<logging::LogManager>;
	using EntityInstancePtr = std::shared_ptr<entity_system::EntityInstance>;
	using FontPtr = std::shared_ptr<Font>;

	/// @class FontManager
	/// @brief Management of fonts and text rendering.
	class FontManager
	: public std::enable_shared_from_this<FontManager>
	{
		public:

			/// @brief Constructor.
			/// @note The dependencies of this class will be injected automatically.
			/// @param log_manager The log manager.
			FontManager(
				LogManagerPtr log_manager
			);

			/// Destructor.
			~FontManager();

			/// Initialize the font manager.
			void init();

			/// Shut down the font manager.
			void shutdown();

			FontPtr get_font(std::string path, float size, std::string glyphs, int capacity, float render_size, Magnum::Text::Alignment alignment);

			/// The logger name of this service.
			static constexpr char LOGGER_NAME[] = "inexor.renderer.font";

		private:

			/// The log manager.
			LogManagerPtr log_manager;

			std::shared_ptr<Corrade::PluginManager::Manager<Magnum::Text::AbstractFont>> font_manager;

//			Corrade::PluginManager::LoadState font_plugin_state;

	};

}
}
