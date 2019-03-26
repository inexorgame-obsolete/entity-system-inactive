#pragma once

#include "type-system/providers/data/converters/IntToFloatEntityTypeProvider.hpp"

#include <memory>

namespace inexor {
namespace entity_system {
namespace type_system {

	using IntToFloatEntityTypeProviderPtr = std::shared_ptr<IntToFloatEntityTypeProvider>;

    /// @class ConverterProviders
	/// @brief The converter entity type providers.
	class ConverterProviders
	{
		public:

			/// @brief Constructs the converter entity type providers.
            /// @note The dependencies of this class will be injected automatically.
            /// @param int_to_float_entity_type_provider Provides the entity type INT_TO_FLOAT.
			ConverterProviders(
				IntToFloatEntityTypeProviderPtr int_to_float_entity_type_provider
			);

            /// Destructor.
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
