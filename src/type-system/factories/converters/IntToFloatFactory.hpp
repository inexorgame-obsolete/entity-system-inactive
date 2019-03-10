// Inexor entity system
// (c)2018 Inexor

#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/util/type-definitions/TypeDefinitions.hpp"

#include "type-system/providers/converters/IntToFloatEntityTypeProvider.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace entity_system {
namespace type_system {

	using EntityInstancePtrOpt = std::optional<std::shared_ptr<EntityInstance>>;

	/// @class IntToFloatFactory
    /// @brief Factory for entity instances of type INT_TO_FLOAT.
	class IntToFloatFactory
	{
		public:

			/// Constructor.
			IntToFloatFactory(
				shared_ptr<IntToFloatEntityTypeProvider> entity_type_provider,
				shared_ptr<EntityInstanceBuilderFactory> entity_instance_builder_factory
			);

			/// Destructor.
			~IntToFloatFactory();

			/// Creates an instance with default values
			EntityInstancePtrOpt create_instance();

			/// Creates an instance with the given name
			EntityInstancePtrOpt create_instance(const string& name, const int& int_value, const float& float_value);

		private:

			/// The entity type provider
			shared_ptr<IntToFloatEntityTypeProvider> entity_type_provider;

			/// The entity instance manager
			shared_ptr<EntityInstanceBuilderFactory> entity_instance_builder_factory;

	};


}
}
}
