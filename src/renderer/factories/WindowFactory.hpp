#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "renderer/providers/WindowEntityTypeProvider.hpp"

namespace inexor {
namespace renderer {

	using WindowEntityTypeProviderPtr = std::shared_ptr<WindowEntityTypeProvider>;
	using EntityInstanceBuilderFactoryPtr = std::shared_ptr<EntityInstanceBuilderFactory>;
	using EntityInstanceManagerPtr = std::shared_ptr<EntityInstanceManager>;
	using EntityInstancePtr = std::shared_ptr<EntityInstance>;
	using EntityInstancePtrOpt = std::optional<EntityInstancePtr>;

	/// @class WindowFactory
	/// @brief Factory for creating windows.
	class WindowFactory
	{
		public:

			/// @brief Constructor.
			/// @note The dependencies of this class will be injected automatically.
			/// @param window_entity_type_provider The entity type provider.
			/// @param entity_instance_builder_factory The entity instance builder factory.
			/// @param entity_instance_manager The entity instance manager.
			WindowFactory(
				WindowEntityTypeProviderPtr window_entity_type_provider,
				EntityInstanceBuilderFactoryPtr entity_instance_builder_factory,
				EntityInstanceManagerPtr entity_instance_manager
			);

			/// Destructor.
			~WindowFactory();

			/// Creates a new window with the given title, coordinates and dimensions.
			/// @param title The title of the window.
			/// @param x The x position of the window.
			/// @param y The y position of the window.
			/// @param width The width of the window.
			/// @param height The height of the window.
			EntityInstancePtrOpt create_instance(std::string title, int x, int y, int width, int height);

		private:

			/// The entity type provider.
			WindowEntityTypeProviderPtr window_entity_type_provider;

			/// The entity instance builder factory.
			EntityInstanceBuilderFactoryPtr entity_instance_builder_factory;

			/// The entity instance manager.
			EntityInstanceManagerPtr entity_instance_manager;

	};

}
}
