#pragma once

#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "type-system/providers/data/constants/IntConstantEntityTypeProvider.hpp"

#include <memory>
#include <optional>

namespace inexor {
namespace entity_system {
namespace type_system {

	using EntityInstancePtrOpt = std::optional<std::shared_ptr<EntityInstance>>;
	using IntConstantEntityTypeProviderPtr = std::shared_ptr<IntConstantEntityTypeProvider>;
	using EntityInstanceBuilderFactoryPtr = std::shared_ptr<EntityInstanceBuilderFactory>;

    /// Factory for creating entity instances of type INT_CONSTANT.
	class IntConstantFactory
	{
		public:

			/// Constructs a factory for creating entity instances of type INT_CONSTANT.
			IntConstantFactory(
				IntConstantEntityTypeProviderPtr entity_type_provider,
				EntityInstanceBuilderFactoryPtr entity_instance_builder_factory
			);

			~IntConstantFactory();

			/// Initializes the factory.
			void init();

			/// Creates an instance with default values
			EntityInstancePtrOpt create_instance();

			/// Creates an INT_CONSTANT with the given constant name and the given value.
			EntityInstancePtrOpt create_instance(const std::string& name, const int& value);

		private:

			/// Provides the entity type INT_CONSTANT.
			IntConstantEntityTypeProviderPtr entity_type_provider;

			/// Factory for creating entity instance builders.
			EntityInstanceBuilderFactoryPtr entity_instance_builder_factory;

	};


}
}
}
