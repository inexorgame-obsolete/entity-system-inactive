#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

    /// @class GlobalKeyEntityTypeProvider
	/// @brief Provides an entity type "GLOBAL_KEY".
	class GlobalKeyEntityTypeProvider : public EntityTypeProvider
	{
		public:

			/// @brief Constructs the specialized provider for the entity type GLOBAL_KEY.
            /// @note The dependencies of this class will be injected automatically.
            /// @param entity_type_builder_manager The entity type builder manager.
			GlobalKeyEntityTypeProvider(
				std::shared_ptr<EntityTypeBuilderFactory> entity_type_builder_manager
			) : EntityTypeProvider(
				entity_type_builder_manager,
				TYPE_NAME,
				{
					{ GLOBAL_KEY_KEYCODE, { DataType::INT, 1 << Feature::OUTPUT } },
					{ GLOBAL_KEY_ACTION, { DataType::INT, 1 << Feature::OUTPUT } },
					{ GLOBAL_KEY_MODS, { DataType::INT, 1 << Feature::OUTPUT } }
				}
			) {};

            /// Destructor.
			~GlobalKeyEntityTypeProvider() {};

			/// Defines the name of this entity type
			static constexpr char TYPE_NAME[] = "GLOBAL_KEY";

			/// The name of the attribute key_keycode
			static constexpr char GLOBAL_KEY_KEYCODE[] = "global_key_keycode";

			/// The name of the attribute key_action.
			static constexpr char GLOBAL_KEY_ACTION[] = "global_key_action";

			/// The name of the attribute key_mods.
			static constexpr char GLOBAL_KEY_MODS[] = "global_key_mods";

	};

}
}
}
