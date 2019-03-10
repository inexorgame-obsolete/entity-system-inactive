#pragma once

#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "type-system/providers/arithmetic/AddIntEntityTypeProvider.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	using AddIntEntityTypeProviderPtr = std::shared_ptr<AddIntEntityTypeProvider>;
	using EntityInstanceBuilderFactoryPtr = std::shared_ptr<EntityInstanceBuilderFactory>;
	using EntityInstancePtr = std::shared_ptr<EntityInstance>;
	using EntityInstancePtrOpt = std::optional<EntityInstancePtr>;

	/// @class AddIntFactory
    /// @brief Factory for entity instances of type ADD_INT.
	class AddIntFactory
	{
		public:

			/// Constructor.
			AddIntFactory(
				AddIntEntityTypeProviderPtr entity_type_provider,
				EntityInstanceBuilderFactoryPtr entity_instance_builder_factory
			);

			/// Destructor.
			~AddIntFactory();

			/// Initializes the factory.
			void init();

			/// Creates an instance with default values
			EntityInstancePtrOpt create_instance();

		private:

			/// The provider for the entity type.
			AddIntEntityTypeProviderPtr entity_type_provider;

			/// The factory for creating entity instance builders.
			EntityInstanceBuilderFactoryPtr entity_instance_builder_factory;

	};


}
}
}
