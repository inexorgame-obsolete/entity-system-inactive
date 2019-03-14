#pragma once

#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "type-system/providers/data/constants/FloatConstantEntityTypeProvider.hpp"

#include <memory>
#include <optional>

namespace inexor {
namespace entity_system {
namespace type_system {

	using EntityInstancePtrOpt = std::optional<std::shared_ptr<EntityInstance>>;
	using FloatConstantEntityTypeProviderPtr = std::shared_ptr<FloatConstantEntityTypeProvider>;
	using EntityInstanceBuilderFactoryPtr = std::shared_ptr<EntityInstanceBuilderFactory>;

    /// Factory for creating entity instances of type FLOAT_CONSTANT.
	class FloatConstantFactory
	{
		public:

			/// Constructs a factory for creating entity instances of type FLOAT_CONSTANT.
			FloatConstantFactory(
				FloatConstantEntityTypeProviderPtr entity_type_provider,
				EntityInstanceBuilderFactoryPtr entity_instance_builder_factory
			);

			~FloatConstantFactory();

			/// Initializes the factory.
			void init();

			/// Creates an instance with default values
			EntityInstancePtrOpt create_instance();

			/// Creates an FLOAT_CONSTANT with the given constant name and the given value.
			EntityInstancePtrOpt create_instance(const std::string& name, const float& value);

		private:

			/// Provides the entity type FLOAT_CONSTANT.
			FloatConstantEntityTypeProviderPtr entity_type_provider;

			/// Factory for creating entity instance builders.
			EntityInstanceBuilderFactoryPtr entity_instance_builder_factory;

	};


}
}
}
