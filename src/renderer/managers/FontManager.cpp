#include "FontManager.hpp"

#include "spdlog/spdlog.h"

namespace inexor {
namespace renderer {

	FontManager::FontManager(
		LogManagerPtr log_manager
	) {
		this->log_manager = log_manager;
		// this->font_plugin_state = nullptr;
	}

	FontManager::~FontManager()
	{
	}

	void FontManager::init()
	{
		log_manager->register_logger(LOGGER_NAME);

		// Load font plugin
		font_manager = std::make_shared<Corrade::PluginManager::Manager<Magnum::Text::AbstractFont>>();
		font_manager->load("FreeTypeFont");
	}

	void FontManager::shutdown()
	{
		// TODO: unload font plugin
	}

	FontPtr FontManager::get_font(std::string path, float size, std::string glyphs, int capacity, float render_size, Magnum::Text::Alignment alignment)
	{
		std::shared_ptr<Font> font = std::make_shared<Font>();
		font->path = path;
		font->font = font_manager->instantiate("FreeTypeFont");
		if (!font->font)
		{
			spdlog::error("Failed to instantiate FreeTypeFont");
		} else {
			spdlog::info("Successfully instantiate FreeTypeFont");
			font->font->initialize();
		}

		// Open font
		if (!font->font->openFile(path, size))
		{
			spdlog::error("Failed to open font: {}", path);
		} else {
			spdlog::info("Successfully opened font: {}", path);
		}

		// Create and fill glyph cache
		font->glyph_cache = std::make_shared<Magnum::Text::DistanceFieldGlyphCache>(Magnum::Vector2i(2048), Magnum::Vector2i(512), 22);
		font->font->fillGlyphCache((*font->glyph_cache), glyphs);
		spdlog::info("Glyph cache contains {} glyphs", font->glyph_cache->glyphCount());

		// Prepare renderer
		font->renderer = std::make_shared<Magnum::Text::Renderer2D>(
			*font->font,
			(*font->glyph_cache),
			render_size,
			alignment
		);

		// Reserve text size
		font->renderer->reserve(
			capacity,
			Magnum::GL::BufferUsage::DynamicDraw,
			Magnum::GL::BufferUsage::StaticDraw
		);
		spdlog::info("Font renderer capacity: {}", font->renderer->capacity());

		// Create shader
		font->shader = std::make_shared<Magnum::Shaders::DistanceFieldVector2D>();

		return font;
	}

}
}
