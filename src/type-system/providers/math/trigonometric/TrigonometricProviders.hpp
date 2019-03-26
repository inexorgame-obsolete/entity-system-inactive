#pragma once

#include "type-system/providers/math/trigonometric/SinEntityTypeProvider.hpp"
#include "type-system/providers/math/trigonometric/CosEntityTypeProvider.hpp"
#include "type-system/providers/math/trigonometric/TanEntityTypeProvider.hpp"

#include <memory>

namespace inexor {
namespace entity_system {
namespace type_system {

	using SinEntityTypeProviderPtr = std::shared_ptr<SinEntityTypeProvider>;
	using CosEntityTypeProviderPtr = std::shared_ptr<CosEntityTypeProvider>;
	using TanEntityTypeProviderPtr = std::shared_ptr<TanEntityTypeProvider>;

    /// @class TrigonometricProviders
	/// @brief The trigonometric entity type providers.
	class TrigonometricProviders
	{
		public:

			/// @brief Constructs the trigonometric entity type providers.
            /// @note The dependencies of this class will be injected automatically.
            /// @param sin_entity_type_provider Provides the entity type SIN.
            /// @param cos_entity_type_provider Provides the entity type COS.
            /// @param tan_entity_type_provider Provides the entity type TAN.
			TrigonometricProviders(
				SinEntityTypeProviderPtr sin_entity_type_provider,
				CosEntityTypeProviderPtr cos_entity_type_provider,
				TanEntityTypeProviderPtr tan_entity_type_provider
			);

            /// Destructor.
			~TrigonometricProviders();

			/// Initializes the trigonometric entity type providers.
			void init();

		private:

			/// Provides the entity type SIN.
			SinEntityTypeProviderPtr sin_entity_type_provider;

			/// Provides the entity type COS.
			CosEntityTypeProviderPtr cos_entity_type_provider;

			/// Provides the entity type TAN.
			TanEntityTypeProviderPtr tan_entity_type_provider;

	};

}
}
}
