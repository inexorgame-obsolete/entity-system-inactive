#pragma once

#include "type-system/providers/math/arithmetic/AddIntEntityTypeProvider.hpp"
#include "type-system/providers/math/arithmetic/AddFloatEntityTypeProvider.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	using AddIntEntityTypeProviderPtr = std::shared_ptr<AddIntEntityTypeProvider>;
	using AddFloatEntityTypeProviderPtr = std::shared_ptr<AddFloatEntityTypeProvider>;

    /// @class ArithmeticProviders
	/// @brief The arithmetic entity type providers.
	class ArithmeticProviders
	{
		public:

			/// @brief Constructs the arithmetic entity type providers.
            /// @note The dependencies of this class will be injected automatically.
            /// @brief add_int_entity_type_provider Provides the entity type ADD_INT.
            /// @brief add_float_entity_type_provider Provides the entity type ADD_FLOAT.
			ArithmeticProviders(
				AddIntEntityTypeProviderPtr add_int_entity_type_provider,
				AddFloatEntityTypeProviderPtr add_float_entity_type_provider
			);

            /// Destructor.
			~ArithmeticProviders();

			/// Initializes the arithmetic entity type providers.
			void init();

		private:

			/// Provides the entity type ADD_INT.
			AddIntEntityTypeProviderPtr add_int_entity_type_provider;

			/// Provides the entity type ADD_FLOAT.
			AddFloatEntityTypeProviderPtr add_float_entity_type_provider;

	};

}
}
}
