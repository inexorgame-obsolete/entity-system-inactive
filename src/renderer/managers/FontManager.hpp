#pragma once

#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "logging/managers/LogManager.hpp"

#include <Corrade/PluginManager/Manager.h>
#include <Magnum/GL/Renderer.h>
#include <Magnum/Shaders/DistanceFieldVector.h>
#include <Magnum/Text/AbstractFont.h>
#include <Magnum/Text/DistanceFieldGlyphCache.h>
#include <Magnum/Text/Renderer.h>

namespace inexor::renderer {

using LogManagerPtr = std::shared_ptr<logging::LogManager>;
using EntityInstancePtr = std::shared_ptr<entity_system::EntityInstance>;

// TODO: Move to model
// TODO: Add cleanup which have to be called within render thread
struct Font
{

    //		/// The name of the font.
    //		std::string name;

    /// The font instance.
    Corrade::Containers::Pointer<Magnum::Text::AbstractFont> font;

    /// The cache for the glyphs.
    std::shared_ptr<Magnum::Text::DistanceFieldGlyphCache> glyph_cache;

    /// The font renderer.
    std::shared_ptr<Magnum::Text::Renderer2D> renderer;

    /// The font shader.
    std::shared_ptr<Magnum::Shaders::DistanceFieldVector2D> shader;
};

using FontPtr = std::shared_ptr<Font>;
using FontPtrOpt = std::optional<FontPtr>;

/// @class FontManager
/// @brief Management of fonts and text rendering.
class FontManager : public std::enable_shared_from_this<FontManager>
{
    public:
    /// @brief Constructor.
    /// @note The dependencies of this class will be injected automatically.
    /// @param log_manager The log manager.
    explicit FontManager(LogManagerPtr log_manager);

    /// Destructor.
    ~FontManager();

    /// Initialize the font manager.
    void init();

    /// Shut down the font manager.
    void shutdown();

    /// Loads a statically included font.
    FontPtrOpt load_internal(const std::string& internal_filename, float size, const std::string& glyphs, int capacity, float render_size, Magnum::Text::Alignment alignment);

    /// Loads a font from file system.
    FontPtrOpt load(const std::string& path, float size, const std::string& glyphs, int capacity, float render_size, Magnum::Text::Alignment alignment);

    /// The resource group for statically included fonts.
    static constexpr char RESOURCE_GROUP[] = "inexor";

    /// The name of the font plugin.
    static constexpr char FONT_PLUGIN[] = "FreeTypeFont";

    /// The logger name of this service.
    static constexpr char LOGGER_NAME[] = "inexor.renderer.font";

    private:
    /// Instantiates a new font.
    FontPtrOpt instantiate();

    /// Creates glyphs and fills the glyph cache.
    void create_and_fill_glyph_cache(const FontPtr& font, const std::string& glyphs);

    /// Prepares the renderer.
    void prepare_renderer_and_shader(const FontPtr& font, int capacity, float render_size, Magnum::Text::Alignment alignment);

    /// The log manager.
    LogManagerPtr log_manager;

    /// The font plugin manager.
    std::shared_ptr<Corrade::PluginManager::Manager<Magnum::Text::AbstractFont>> font_plugin_manager;
};

} // namespace inexor::renderer
