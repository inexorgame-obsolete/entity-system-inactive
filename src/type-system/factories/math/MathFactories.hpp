#pragma once

#include "type-system/factories/math/arithmetic/ArithmeticFactories.hpp"
#include "type-system/factories/math/trigonometric/TrigonometricFactories.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	using ArithmeticFactoriesPtr = std::shared_ptr<ArithmeticFactories>;
	using TrigonometricFactoriesPtr = std::shared_ptr<TrigonometricFactories>;

	/// The factories for mathematical operations.
	class MathFactories
	{
		public:

			/// Constructs the factories for mathematical operations.
			MathFactories(
				ArithmeticFactoriesPtr arithmetic_factories,
				TrigonometricFactoriesPtr trigonometric_factories
			);

			~MathFactories();

			/// Initializes the factories for mathematical operations.
			void init();

		private:

			/// The factories for arithmetic operations.
			ArithmeticFactoriesPtr arithmetic_factories;

			/// The factories for trigonometric operations.
			TrigonometricFactoriesPtr trigonometric_factories;

	};

}
}
}
