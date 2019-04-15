#pragma once

#include "type-system/providers/inout/keyboard/GlobalKeyEntityTypeProvider.hpp"

#include <memory>

namespace inexor {
namespace entity_system {
namespace type_system {

	using GlobalKeyEntityTypeProviderPtr = std::shared_ptr<GlobalKeyEntityTypeProvider>;

    /// @class KeyboardProviders
	/// @brief The entity type providers for keyboard input.
	class KeyboardProviders
	{
		public:

			/// @brief Constructs the entity type providers for keyboard input.
            /// @note The dependencies of this class will be injected automatically.
            /// @param key_entity_type_provider Provides the entity type GLOBAL_KEY.
			KeyboardProviders(
				GlobalKeyEntityTypeProviderPtr global_key_entity_type_provider
			);

            /// Destructor.
			~KeyboardProviders();

			/// Initializes the entity type providers for keyboard input.
			void init();

		private:

			/// Provides the entity type GLOBAL_KEY.
			GlobalKeyEntityTypeProviderPtr global_key_entity_type_provider;

	};

}
}
}
