// Statically import plugins

// Import images
#include "MagnumPlugins/AnyImageImporter/importStaticPlugin.cpp"
#include "MagnumPlugins/StbImageImporter/importStaticPlugin.cpp"

// Export images
#include "MagnumPlugins/AnyImageConverter/importStaticPlugin.cpp"
#include "MagnumPlugins/StbImageConverter/importStaticPlugin.cpp"

// Fonts (FreeTypeFont is much faster than StbTrueTypeFont)
#include "MagnumPlugins/FreeTypeFont/importStaticPlugin.cpp"
