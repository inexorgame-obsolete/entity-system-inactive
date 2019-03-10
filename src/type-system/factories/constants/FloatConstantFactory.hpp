#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/util/type-definitions/TypeDefinitions.hpp"

#include "type-system/providers/constants/FloatConstantEntityTypeProvider.hpp"

using namespace std;

namespace inexor {
namespace entity_system {
namespace type_system {

	using EntityInstancePtrOpt = std::optional<std::shared_ptr<EntityInstance>>;

	/// @class FloatConstantFactory
    /// @brief Factory for entity instances of type FLOAT_CONSTANT.
	class FloatConstantFactory
	{
		public:

			using FloatConstantEntityTypeProviderPtr = std::shared_ptr<FloatConstantEntityTypeProvider>;
			using EntityInstanceBuilderFactoryPtr = std::shared_ptr<EntityInstanceBuilderFactory>;

			/// Constructor.
			FloatConstantFactory(
				FloatConstantEntityTypeProviderPtr entity_type_provider,
				EntityInstanceBuilderFactoryPtr entity_instance_builder_factory
			);

			/// Destructor.
			~FloatConstantFactory();

			/// Creates an instance with default values
			EntityInstancePtrOpt create_instance();

			/// Creates an instance with the given name
			EntityInstancePtrOpt create_instance(const string& name, const float& value);

		private:

			/// The entity type provider
			FloatConstantEntityTypeProviderPtr entity_type_provider;

			/// The entity instance manager
			EntityInstanceBuilderFactoryPtr entity_instance_builder_factory;

	};


}
}
}
