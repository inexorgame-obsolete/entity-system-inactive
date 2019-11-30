#include "FontManager.hpp"

#include <utility>

#include "spdlog/spdlog.h"

namespace inexor::renderer {

FontManager::FontManager(LogManagerPtr log_manager)
{
    this->log_manager = std::move(log_manager);
}

FontManager::~FontManager() = default;

void FontManager::init()
{
    log_manager->register_logger(LOGGER_NAME);

    // Load font plugin
    font_plugin_manager = std::make_shared<Corrade::PluginManager::Manager<Magnum::Text::AbstractFont>>();
    // TODO: LoadState.Loaded | LoadState.Static
    font_plugin_manager->load(FONT_PLUGIN);
}

void FontManager::destroy()
{
    // TODO: unload font plugin
}

std::string FontManager::get_component_name()
{
    return "FontManager";
}

FontPtrOpt FontManager::load_internal(const std::string &internal_filename, float size, const std::string &glyphs, int capacity, float render_size, Magnum::Text::Alignment alignment)
{
    FontPtrOpt font = instantiate();
    if (font.has_value())
    {
        const Corrade::Utility::Resource rs{RESOURCE_GROUP};
        if (!font.value()->font->openData(rs.getRaw(internal_filename), size))
        {
            spdlog::get(LOGGER_NAME)->error("Failed to open internal font: {}", internal_filename);
            return std::nullopt;
        }
        create_and_fill_glyph_cache(font.value(), glyphs);
        prepare_renderer_and_shader(font.value(), capacity, render_size, alignment);
    }
    return font;
}

// TODO: Two steps: 1. open font; 2. Create glyphs, render and shader.
FontPtrOpt FontManager::load(const std::string &path, float size, const std::string &glyphs, int capacity, float render_size, Magnum::Text::Alignment alignment)
{
    FontPtrOpt font = instantiate();
    if (font.has_value())
    {
        if (!font.value()->font->openFile(path, size))
        {
            spdlog::get(LOGGER_NAME)->error("Failed to open font: {}", path);
            return std::nullopt;
        }
        create_and_fill_glyph_cache(font.value(), glyphs);
        prepare_renderer_and_shader(font.value(), capacity, render_size, alignment);
    }
    return font;
}

FontPtrOpt FontManager::instantiate()
{
    std::shared_ptr<Font> font = std::make_shared<Font>();
    font->font = font_plugin_manager->instantiate(FONT_PLUGIN);
    if (font->font)
    {
        spdlog::get(LOGGER_NAME)->debug("Successfully instantiate FreeTypeFont");
        font->font->initialize();
        return font;
    } else
    {
        spdlog::get(LOGGER_NAME)->error("Failed to instantiate FreeTypeFont");
        return std::nullopt;
    }
}

void FontManager::create_and_fill_glyph_cache(const FontPtr &font, const std::string &glyphs)
{
    font->glyph_cache = std::make_shared<Magnum::Text::DistanceFieldGlyphCache>(Magnum::Vector2i(2048), Magnum::Vector2i(512), 22);
    font->font->fillGlyphCache((*font->glyph_cache), glyphs);
    spdlog::get(LOGGER_NAME)->debug("Glyph cache contains {} glyphs", font->glyph_cache->glyphCount());
}

void FontManager::prepare_renderer_and_shader(const FontPtr &font, int capacity, float render_size, Magnum::Text::Alignment alignment)
{
    // Prepare renderer
    font->renderer = std::make_shared<Magnum::Text::Renderer2D>(*font->font, (*font->glyph_cache), render_size, alignment);

    // Reserve text size
    font->renderer->reserve(capacity, Magnum::GL::BufferUsage::DynamicDraw, Magnum::GL::BufferUsage::StaticDraw);
    spdlog::get(LOGGER_NAME)->debug("Font renderer capacity: {}", font->renderer->capacity());

    // Prepare shader
    font->shader = std::make_shared<Magnum::Shaders::DistanceFieldVector2D>();
}

} // namespace inexor::renderer
