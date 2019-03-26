#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"
#include "entity-system/providers/EntityTypeProvider.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

    /// @class AddIntEntityTypeProvider
    /// @brief Provides an entity type "ADD_INT" which is the integer addition.
	class AddIntEntityTypeProvider : public EntityTypeProvider
	{
		public:

			/// @brief Constructs the specialized provider for the ADD_INT entity type
            /// @note The dependencies of this class will be injected automatically.
            /// @param entity_type_builder_manager The entity type builder manager.
			AddIntEntityTypeProvider(
				std::shared_ptr<EntityTypeBuilderFactory> entity_type_builder_manager
			) : EntityTypeProvider(
				entity_type_builder_manager,
				TYPE_NAME,
				{
					{ ADD_INT_AUGEND, { DataType::INT, 1 << Feature::INPUT } },
					{ ADD_INT_ADDEND, { DataType::INT, 1 << Feature::INPUT } },
					{ ADD_INT_SUM, { DataType::INT, 1 << Feature::OUTPUT } }
				}
			) {};

            /// Destructor.
			~AddIntEntityTypeProvider() {};

			/// Defines the name of this entity type.
			static constexpr char TYPE_NAME[] = "ADD_INT";

			/// The name of the input attribute augend.
			static constexpr char ADD_INT_AUGEND[] = "add_int_augend";

			/// The name of the input attribute addend.
			static constexpr char ADD_INT_ADDEND[] = "add_int_addend";

			/// The name of the output attribute sum
			static constexpr char ADD_INT_SUM[] = "add_int_sum";

	};

}
}
}
