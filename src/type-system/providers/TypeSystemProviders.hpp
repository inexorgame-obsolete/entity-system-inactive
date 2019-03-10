#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"

#include "type-system/providers/arithmetic/ArithmeticProviders.hpp"
#include "type-system/providers/constants/ConstantProviders.hpp"
#include "type-system/providers/converters/ConverterProviders.hpp"
#include "type-system/providers/logger/LoggerProviders.hpp"
#include "type-system/providers/stores/StoreProviders.hpp"
#include "type-system/providers/trigonometric/TrigonometricProviders.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	using EntityTypeBuilderFactoryPtr = std::shared_ptr<EntityTypeBuilderFactory>;
	using ArithmeticProvidersPtr = std::shared_ptr<ArithmeticProviders>;
	using ConstantProvidersPtr = std::shared_ptr<ConstantProviders>;
	using ConverterProvidersPtr = std::shared_ptr<ConverterProviders>;
	using LoggerProvidersPtr = std::shared_ptr<LoggerProviders>;
	using StoreProvidersPtr = std::shared_ptr<StoreProviders>;
	using TrigonometricProvidersPtr = std::shared_ptr<TrigonometricProviders>;

	/// The providers of the type system.
	class TypeSystemProviders
	{
		public:

			/// Constructs the providers of the type system.
			TypeSystemProviders(
				EntityTypeBuilderFactoryPtr entity_type_builder_factory,
				ArithmeticProvidersPtr arithmetic_providers,
				ConstantProvidersPtr constant_providers,
				ConverterProvidersPtr converter_providers,
				LoggerProvidersPtr logger_providers,
				StoreProvidersPtr store_providers,
				TrigonometricProvidersPtr trigonometric_providers
			);

			~TypeSystemProviders();

			/// Initializes the providers of the type system.
			void init();

		private:

			/// Factory for creating entity types.
			EntityTypeBuilderFactoryPtr entity_type_builder_factory;

			/// The providers for arithmetic operations.
			ArithmeticProvidersPtr arithmetic_providers;

			/// The providers for constants.
			ConstantProvidersPtr constant_providers;

			/// The providers for converters.
			ConverterProvidersPtr converter_providers;

			/// The providers for loggers.
			LoggerProvidersPtr logger_providers;

			/// The providers for stores.
			StoreProvidersPtr store_providers;

			/// The providers for trigonometric operations.
			TrigonometricProvidersPtr trigonometric_providers;

	};

}
}
}
