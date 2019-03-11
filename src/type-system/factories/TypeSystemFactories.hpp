#pragma once

#include "type-system/factories/arithmetic/ArithmeticFactories.hpp"
#include "type-system/factories/constants/ConstantFactories.hpp"
#include "type-system/factories/converters/ConverterFactories.hpp"
#include "type-system/factories/logger/LoggerFactories.hpp"
#include "type-system/factories/logical/LogicalFactories.hpp"
#include "type-system/factories/stores/StoreFactories.hpp"
#include "type-system/factories/trigonometric/TrigonometricFactories.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	using ArithmeticFactoriesPtr = std::shared_ptr<ArithmeticFactories>;
	using ConstantFactoriesPtr = std::shared_ptr<ConstantFactories>;
	using ConverterFactoriesPtr = std::shared_ptr<ConverterFactories>;
	using LoggerFactoriesPtr = std::shared_ptr<LoggerFactories>;
	using LogicalFactoriesPtr = std::shared_ptr<LogicalFactories>;
	using StoreFactoriesPtr = std::shared_ptr<StoreFactories>;
	using TrigonometricFactoriesPtr = std::shared_ptr<TrigonometricFactories>;

	/// The factories of the type system-
	class TypeSystemFactories
	{
		public:

			/// Constructs the factories of the type system.
			TypeSystemFactories(
				ArithmeticFactoriesPtr arithmetic_factories,
				ConstantFactoriesPtr constant_factories,
				ConverterFactoriesPtr converter_factories,
				LoggerFactoriesPtr logger_factories,
				LogicalFactoriesPtr logical_factories,
				StoreFactoriesPtr store_factories,
				TrigonometricFactoriesPtr trigonometric_factories
			);

			~TypeSystemFactories();

			/// Initializes the factories of the type system.
			void init();

		private:

			/// The factories for arithmetic operations.
			ArithmeticFactoriesPtr arithmetic_factories;

			/// The factories for constants.
			ConstantFactoriesPtr constant_factories;

			/// The factories for converters.
			ConverterFactoriesPtr converter_factories;

			/// The factories for loggers.
			LoggerFactoriesPtr logger_factories;

			/// The factories for the logical operations.
			LogicalFactoriesPtr logical_factories;

			/// The factories for stores.
			StoreFactoriesPtr store_factories;

			/// The factories for trigonometric operations.
			TrigonometricFactoriesPtr trigonometric_factories;

	};

}
}
}
