#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "type-system/providers/constants/StringConstantEntityTypeProvider.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	using EntityInstancePtrOpt = std::optional<std::shared_ptr<EntityInstance>>;

	/// @class StringConstantFactory
    /// @brief Factory for entity instances of type STRING_CONSTANT.
	class StringConstantFactory
	{
		public:

			using StringConstantEntityTypeProviderPtr = std::shared_ptr<StringConstantEntityTypeProvider>;
			using EntityInstanceBuilderFactoryPtr = std::shared_ptr<EntityInstanceBuilderFactory>;

			/// Constructor.
			StringConstantFactory(
				StringConstantEntityTypeProviderPtr entity_type_provider,
				EntityInstanceBuilderFactoryPtr entity_instance_builder_factory
			);

			/// Destructor.
			~StringConstantFactory();

			/// Creates an instance with default values
			EntityInstancePtrOpt create_instance();

			/// Creates an instance with the given name
			EntityInstancePtrOpt create_instance(const std::string& name, const std::string& value);

		private:

			/// The entity type provider
			StringConstantEntityTypeProviderPtr entity_type_provider;

			/// The entity instance manager
			EntityInstanceBuilderFactoryPtr entity_instance_builder_factory;

	};


}
}
}
