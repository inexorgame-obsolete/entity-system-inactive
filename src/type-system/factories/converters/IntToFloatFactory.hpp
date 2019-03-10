#pragma once

#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "type-system/providers/converters/IntToFloatEntityTypeProvider.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	using IntToFloatEntityTypeProviderPtr = std::shared_ptr<IntToFloatEntityTypeProvider>;
	using EntityInstancePtrOpt = std::optional<std::shared_ptr<EntityInstance>>;
	using EntityInstanceBuilderFactoryPtr = std::shared_ptr<EntityInstanceBuilderFactory>;

    /// Factory for creating entity instances of type INT_TO_FLOAT.
	class IntToFloatFactory
	{
		public:

			/// Constructs a factory for creating entity instances of type INT_TO_FLOAT.
			IntToFloatFactory(
				IntToFloatEntityTypeProviderPtr entity_type_provider,
				EntityInstanceBuilderFactoryPtr entity_instance_builder_factory
			);

			~IntToFloatFactory();

			/// Initializes the factory.
			void init();

			/// Creates an INT_TO_FLOAT.
			EntityInstancePtrOpt create_instance();

			/// Creates an INT_TO_FLOAT.
			EntityInstancePtrOpt create_instance(const string& name, const int& int_value, const float& float_value);

		private:

			/// Provides the entity type INT_TO_FLOAT.
			IntToFloatEntityTypeProviderPtr entity_type_provider;

			/// Factory for creating entity instance builders.
			EntityInstanceBuilderFactoryPtr entity_instance_builder_factory;

	};


}
}
}
