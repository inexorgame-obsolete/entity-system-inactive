#pragma once

#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "type-system/providers/inout/mouse/GlobalMouseButtonEntityTypeProvider.hpp"

#include "spdlog/common.h"

namespace inexor {
namespace entity_system {
namespace type_system {

	using EntityInstancePtr = std::shared_ptr<EntityInstance>;
	using EntityInstancePtrOpt = std::optional<EntityInstancePtr>;
	using EntityInstanceBuilderFactoryPtr = std::shared_ptr<EntityInstanceBuilderFactory>;
	using GlobalMouseButtonEntityTypeProviderPtr = std::shared_ptr<GlobalMouseButtonEntityTypeProvider>;

    /// @class GlobalMouseButtonFactory
    /// @brief Factory for creating entity instances of type GLOBAL_MOUSE_BUTTON.
	class GlobalMouseButtonFactory
	{
		public:

			/// @brief Constructor.
            /// @note The dependencies of this class will be injected automatically.
            /// @param entity_type_provider Provides the entity type GLOBAL_MOUSE_BUTTON.
            /// @param entity_instance_builder_factory Factory for creating entity instance builders.
			GlobalMouseButtonFactory(
				GlobalMouseButtonEntityTypeProviderPtr entity_type_provider,
				EntityInstanceBuilderFactoryPtr entity_instance_builder_factory
			);

			/// Destructor.
			~GlobalMouseButtonFactory();

			/// Initializes the factory.
			void init();

			/// @brief Creates an instance and sets the given name.
            /// @param button The mouse button number.
			EntityInstancePtrOpt create_instance(const int& button);

		private:

			/// Provides the entity type GLOBAL_MOUSE_BUTTON.
			GlobalMouseButtonEntityTypeProviderPtr entity_type_provider;

			/// Factory for creating entity instance builders.
			EntityInstanceBuilderFactoryPtr entity_instance_builder_factory;

	};

}
}
}
