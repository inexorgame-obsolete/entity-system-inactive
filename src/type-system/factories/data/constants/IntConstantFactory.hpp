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

    /// @class IntConstantFactory
    /// @brief Factory for creating entity instances of type INT_CONSTANT.
	class IntConstantFactory
	{
		public:

			/// @brief Constructs a factory for creating entity instances of type INT_CONSTANT.
            /// @note The dependencies of this class will be injected automatically.
            /// @param entity_type_provider Provides the entity type INT_CONSTANT.
            /// @param entity_instance_builder_factory Factory for creating entity instance builders.
			IntConstantFactory(
				IntConstantEntityTypeProviderPtr entity_type_provider,
				EntityInstanceBuilderFactoryPtr entity_instance_builder_factory
			);

            /// Destructor.
			~IntConstantFactory();

			/// Initializes the factory.
			void init();

			/// Creates an instance with default values.
			EntityInstancePtrOpt create_instance();

			/// @brief Creates an INT_CONSTANT with the given constant name and the given value.
            /// @param name ?
            /// @param value ?
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
