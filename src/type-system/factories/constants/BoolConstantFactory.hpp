#pragma once

#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "type-system/providers/constants/BoolConstantEntityTypeProvider.hpp"

#include <memory>
#include <optional>

namespace inexor {
namespace entity_system {
namespace type_system {

	using EntityInstancePtrOpt = std::optional<std::shared_ptr<EntityInstance>>;
	using BoolConstantEntityTypeProviderPtr = std::shared_ptr<BoolConstantEntityTypeProvider>;
	using EntityInstanceBuilderFactoryPtr = std::shared_ptr<EntityInstanceBuilderFactory>;

    /// Factory for creating entity instances of type BOOL_CONSTANT.
	class BoolConstantFactory
	{
		public:

			/// Constructs a factory for creating entity instances of type BOOL_CONSTANT.
			BoolConstantFactory(
				BoolConstantEntityTypeProviderPtr entity_type_provider,
				EntityInstanceBuilderFactoryPtr entity_instance_builder_factory
			);

			~BoolConstantFactory();

			/// Initializes the factory.
			void init();

			/// Creates an instance with default values
			EntityInstancePtrOpt create_instance();

			/// Creates an BOOL_CONSTANT with the given constant name and the given value.
			EntityInstancePtrOpt create_instance(const std::string& name, const bool& value);

		private:

			/// Provides the entity type BOOL_CONSTANT.
			BoolConstantEntityTypeProviderPtr entity_type_provider;

			/// Factory for creating entity instance builders.
			EntityInstanceBuilderFactoryPtr entity_instance_builder_factory;

	};


}
}
}
