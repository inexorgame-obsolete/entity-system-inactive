#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

#include <utility>

namespace inexor::entity_system::type_system {

    /// @class GlobalMouseButtonEntityTypeProvider
	/// @brief Provides an entity type "GLOBAL_MOUSE_BUTTON".
	class GlobalMouseButtonEntityTypeProvider : public EntityTypeProvider
	{
		public:

			/// @brief Constructs the specialized provider for the entity type GLOBAL_MOUSE_BUTTON.
            /// @note The dependencies of this class will be injected automatically.
            /// @param entity_type_builder_manager The entity type builder manager.
			explicit GlobalMouseButtonEntityTypeProvider(
				std::shared_ptr<EntityTypeBuilderFactory> entity_type_builder_manager
			) : EntityTypeProvider(
				std::move(entity_type_builder_manager),
				TYPE_NAME,
				{
					{ GLOBAL_MOUSE_BUTTON_NUMBER, { DataType::INT, 1 << Feature::OUTPUT } },
					{ GLOBAL_MOUSE_BUTTON_ACTION, { DataType::INT, 1 << Feature::OUTPUT } },
					{ GLOBAL_MOUSE_BUTTON_MODS, { DataType::INT, 1 << Feature::OUTPUT } }
				}
			) {};

            /// Destructor.
			~GlobalMouseButtonEntityTypeProvider() override = default;

			/// Defines the name of this entity type
			static constexpr char TYPE_NAME[] = "GLOBAL_MOUSE_BUTTON";

			/// The name of the attribute global_mouse_button_number.
			static constexpr char GLOBAL_MOUSE_BUTTON_NUMBER[] = "global_mouse_button_number";

			/// The name of the attribute global_mouse_button_action.
			static constexpr char GLOBAL_MOUSE_BUTTON_ACTION[] = "global_mouse_button_action";

			/// The name of the attribute global_mouse_button_mods.
			static constexpr char GLOBAL_MOUSE_BUTTON_MODS[] = "global_mouse_button_mods";

	};

}
