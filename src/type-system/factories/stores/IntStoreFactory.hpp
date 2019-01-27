// Inexor entity system
// (c)2018 Inexor

#pragma once

#include "entity-system/managers/entities/entity-type-builder-manager/EntityTypeBuilderManager.hpp"
#include "entity-system/managers/entities/entity-instance-builder-manager/EntityInstanceBuilderManager.hpp"
#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/util/type-definitions/TypeDefinitions.hpp"

#include "type-system/providers/stores/IntStoreEntityTypeProvider.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace entity_system {
namespace type_system {

	/// @class IntStoreFactory
    /// @brief Factory for entity instances of type INT_STORE.
	class IntStoreFactory
	{
		public:

			/// Constructor.
			IntStoreFactory(
				shared_ptr<IntStoreEntityTypeProvider> entity_type_provider,
				shared_ptr<EntityInstanceBuilderManager> entity_instance_builder_manager
			);

			/// Destructor.
			~IntStoreFactory();

			/// Creates an instance with default values
			O_ENT_INST create_instance();

			/// Creates an instance with the given name
			O_ENT_INST create_instance(const string& name, const int& input_value, const int& default_value, const int& output_value);

		private:

			/// The entity type provider
			shared_ptr<IntStoreEntityTypeProvider> entity_type_provider;

			/// The entity instance manager
			shared_ptr<EntityInstanceBuilderManager> entity_instance_builder_manager;

	};


}
}
}
