#pragma once

#include "type-system/providers/converters/IntToFloatEntityTypeProvider.hpp"

#include <memory>

namespace inexor {
namespace entity_system {
namespace type_system {

	using IntToFloatEntityTypeProviderPtr = std::shared_ptr<IntToFloatEntityTypeProvider>;

	/// The converter entity type providers.
	class ConverterProviders
	{
		public:

			/// Constructs the converter entity type providers.
			ConverterProviders(
				IntToFloatEntityTypeProviderPtr int_to_float_entity_type_provider
			);

			~ConverterProviders();

			/// Initializes the converter entity type providers.
			void init();

		private:

			/// Provides the entity type INT_TO_FLOAT.
			IntToFloatEntityTypeProviderPtr int_to_float_entity_type_provider;

	};

}
}
}
