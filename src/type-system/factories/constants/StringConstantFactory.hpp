#pragma once

#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "type-system/providers/constants/StringConstantEntityTypeProvider.hpp"

#include <memory>
#include <optional>

namespace inexor {
namespace entity_system {
namespace type_system {

	using EntityInstancePtrOpt = std::optional<std::shared_ptr<EntityInstance>>;
	using StringConstantEntityTypeProviderPtr = std::shared_ptr<StringConstantEntityTypeProvider>;
	using EntityInstanceBuilderFactoryPtr = std::shared_ptr<EntityInstanceBuilderFactory>;

    /// Factory for creating entity instances of type STRING_CONSTANT.
	class StringConstantFactory
	{
		public:

			/// Constructs a factory for creating entity instances of type STRING_CONSTANT.
			StringConstantFactory(
				StringConstantEntityTypeProviderPtr entity_type_provider,
				EntityInstanceBuilderFactoryPtr entity_instance_builder_factory
			);

			~StringConstantFactory();

			/// Initializes the factory.
			void init();

			/// Creates an instance with default values
			EntityInstancePtrOpt create_instance();

			/// Creates an STRING_CONSTANT with the given constant name and the given value.
			EntityInstancePtrOpt create_instance(const std::string& name, const std::string& value);

		private:

			/// Provides the entity type STRING_CONSTANT.
			StringConstantEntityTypeProviderPtr entity_type_provider;

			/// Factory for creating entity instance builders.
			EntityInstanceBuilderFactoryPtr entity_instance_builder_factory;

	};


}
}
}
