#pragma once

#include "type-system/providers/trigonometric/CosEntityTypeProvider.hpp"
#include "type-system/providers/trigonometric/SinEntityTypeProvider.hpp"

#include <memory>

namespace inexor {
namespace entity_system {
namespace type_system {

	using CosEntityTypeProviderPtr = std::shared_ptr<CosEntityTypeProvider>;
	using SinEntityTypeProviderPtr = std::shared_ptr<SinEntityTypeProvider>;

	/// The trigonometric entity type providers.
	class TrigonometricProviders
	{
		public:

			/// Constructs the trigonometric entity type providers.
			TrigonometricProviders(
				CosEntityTypeProviderPtr cos_entity_type_provider,
				SinEntityTypeProviderPtr sin_entity_type_provider
			);

			~TrigonometricProviders();

			/// Initializes the trigonometric entity type providers.
			void init();

		private:

			/// Provides the entity type COS.
			CosEntityTypeProviderPtr cos_entity_type_provider;

			/// Provides the entity type SIN.
			SinEntityTypeProviderPtr sin_entity_type_provider;

	};

}
}
}
