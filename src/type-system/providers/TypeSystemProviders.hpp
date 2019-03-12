#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"

#include "type-system/providers/arithmetic/ArithmeticProviders.hpp"
#include "type-system/providers/comparison/ComparisonProviders.hpp"
#include "type-system/providers/console/ConsoleProviders.hpp"
#include "type-system/providers/constants/ConstantProviders.hpp"
#include "type-system/providers/converters/ConverterProviders.hpp"
#include "type-system/providers/logger/LoggerProviders.hpp"
#include "type-system/providers/logical/LogicalProviders.hpp"
#include "type-system/providers/stores/StoreProviders.hpp"
#include "type-system/providers/trigonometric/TrigonometricProviders.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	using EntityTypeBuilderFactoryPtr = std::shared_ptr<EntityTypeBuilderFactory>;
	using ArithmeticProvidersPtr = std::shared_ptr<ArithmeticProviders>;
	using ComparisonProvidersPtr = std::shared_ptr<ComparisonProviders>;
	using ConsoleProvidersPtr = std::shared_ptr<ConsoleProviders>;
	using ConstantProvidersPtr = std::shared_ptr<ConstantProviders>;
	using ConverterProvidersPtr = std::shared_ptr<ConverterProviders>;
	using LoggerProvidersPtr = std::shared_ptr<LoggerProviders>;
	using LogicalProvidersPtr = std::shared_ptr<LogicalProviders>;
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
				ComparisonProvidersPtr comparison_providers,
				ConsoleProvidersPtr console_providers,
				ConstantProvidersPtr constant_providers,
				ConverterProvidersPtr converter_providers,
				LoggerProvidersPtr logger_providers,
				LogicalProvidersPtr logical_providers,
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

			/// The providers for the comparison operations.
			ComparisonProvidersPtr comparison_providers;

			/// The providers for the console.
			ConsoleProvidersPtr console_providers;

			/// The providers for constants.
			ConstantProvidersPtr constant_providers;

			/// The providers for converters.
			ConverterProvidersPtr converter_providers;

			/// The providers for loggers.
			LoggerProvidersPtr logger_providers;

			/// The providers for logical operations.
			LogicalProvidersPtr logical_providers;

			/// The providers for stores.
			StoreProvidersPtr store_providers;

			/// The providers for trigonometric operations.
			TrigonometricProvidersPtr trigonometric_providers;

	};

}
}
}
