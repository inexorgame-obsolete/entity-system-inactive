#pragma once

#include "type-system/providers/data/constants/ConstantProviders.hpp"
#include "type-system/providers/data/converters/ConverterProviders.hpp"
#include "type-system/providers/data/stores/StoreProviders.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	using ConstantProvidersPtr = std::shared_ptr<ConstantProviders>;
	using ConverterProvidersPtr = std::shared_ptr<ConverterProviders>;
	using StoreProvidersPtr = std::shared_ptr<StoreProviders>;

	/// The providers of the type system.
	class DataProviders
	{
		public:

			/// Constructs the providers of the type system.
			DataProviders(
				ConstantProvidersPtr constant_providers,
				ConverterProvidersPtr converter_providers,
				StoreProvidersPtr store_providers
			);

			~DataProviders();

			/// Initializes the providers of the type system.
			void init();

		private:

			/// The providers for constants.
			ConstantProvidersPtr constant_providers;

			/// The providers for converters.
			ConverterProvidersPtr converter_providers;

			/// The providers for stores.
			StoreProvidersPtr store_providers;

	};

}
}
}
