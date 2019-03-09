#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/util/type-definitions/TypeDefinitions.hpp"

#include "type-system/providers/stores/FloatStoreEntityTypeProvider.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace entity_system {
namespace type_system {

	using EntityInstancePtrOpt = std::optional<std::shared_ptr<EntityInstance>>;

	/// @class FloatStoreFactory
    /// @brief Factory for entity instances of type FLOAT_STORE.
	class FloatStoreFactory
	{
		public:

			/// Constructor.
			FloatStoreFactory(
				shared_ptr<FloatStoreEntityTypeProvider> entity_type_provider,
				shared_ptr<EntityInstanceBuilderFactory> entity_instance_builder_factory
			);

			/// Destructor.
			~FloatStoreFactory();

			/// Creates an instance with default values
			EntityInstancePtrOpt create_instance();

			/// Creates an instance with the given name
			EntityInstancePtrOpt create_instance(const string& name, const float& input_value, const float& default_value, const float& output_value);

		private:

			/// The entity type provider
			shared_ptr<FloatStoreEntityTypeProvider> entity_type_provider;

			/// The entity instance manager
			shared_ptr<EntityInstanceBuilderFactory> entity_instance_builder_factory;

	};


}
}
}
