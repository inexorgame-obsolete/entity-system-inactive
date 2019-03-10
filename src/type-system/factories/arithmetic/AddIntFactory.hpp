#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/util/type-definitions/TypeDefinitions.hpp"

#include "type-system/providers/arithmetic/AddIntEntityTypeProvider.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace entity_system {
namespace type_system {

	using EntityInstancePtrOpt = std::optional<std::shared_ptr<EntityInstance>>;

	/// @class AddIntFactory
    /// @brief Factory for entity instances of type ADD_INT.
	class AddIntFactory
	{
		public:

			/// Constructor.
			AddIntFactory(
				shared_ptr<AddIntEntityTypeProvider> entity_type_provider,
				shared_ptr<EntityInstanceBuilderFactory> entity_instance_builder_factory
			);

			/// Destructor.
			~AddIntFactory();

			/// Creates an instance with default values
			EntityInstancePtrOpt create_instance();

		private:

			/// The entity type provider
			shared_ptr<AddIntEntityTypeProvider> entity_type_provider;

			/// The entity instance manager
			shared_ptr<EntityInstanceBuilderFactory> entity_instance_builder_factory;

	};


}
}
}
