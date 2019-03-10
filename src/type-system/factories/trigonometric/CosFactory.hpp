#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/factories/entities/entity-instance-builder-factory/EntityInstanceBuilderFactory.hpp"
#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/util/type-definitions/TypeDefinitions.hpp"

#include "type-system/providers/trigonometric/CosEntityTypeProvider.hpp"

using namespace std;

namespace inexor {
namespace entity_system {
namespace type_system {

	using EntityInstancePtrOpt = std::optional<std::shared_ptr<EntityInstance>>;

	/// @class CosFactory
    /// @brief Factory for entity instances of type SIN.
	class CosFactory
	{
		public:

			using CosEntityTypeProviderPtr = std::shared_ptr<CosEntityTypeProvider>;
			using EntityInstanceBuilderFactoryPtr = std::shared_ptr<EntityInstanceBuilderFactory>;

			/// Constructor.
			CosFactory(
				CosEntityTypeProviderPtr entity_type_provider,
				EntityInstanceBuilderFactoryPtr entity_instance_builder_factory
			);

			/// Destructor.
			~CosFactory();

			/// Creates an instance with default values
			EntityInstancePtrOpt create_instance();

		private:

			/// The entity type provider
			CosEntityTypeProviderPtr entity_type_provider;

			/// The entity instance manager
			EntityInstanceBuilderFactoryPtr entity_instance_builder_factory;

	};


}
}
}
