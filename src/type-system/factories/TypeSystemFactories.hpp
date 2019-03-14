#pragma once

#include "type-system/factories/data/DataFactories.hpp"
#include "type-system/factories/inout/InOutFactories.hpp"
#include "type-system/factories/generators/GeneratorFactories.hpp"
#include "type-system/factories/logical/LogicalFactories.hpp"
#include "type-system/factories/math/MathFactories.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	using DataFactoriesPtr = std::shared_ptr<DataFactories>;
	using InOutFactoriesPtr = std::shared_ptr<InOutFactories>;
	using GeneratorFactoriesPtr = std::shared_ptr<GeneratorFactories>;
	using LogicalFactoriesPtr = std::shared_ptr<LogicalFactories>;
	using MathFactoriesPtr = std::shared_ptr<MathFactories>;

	/// The factories of the type system-
	class TypeSystemFactories
	{
		public:

			/// Constructs the factories of the type system.
			TypeSystemFactories(
				DataFactoriesPtr data_factories,
				InOutFactoriesPtr in_out_factories,
				GeneratorFactoriesPtr generator_factories,
				LogicalFactoriesPtr logical_factories,
				MathFactoriesPtr math_factories
			);

			~TypeSystemFactories();

			/// Initializes the factories of the type system.
			void init();

		private:

			/// The factories for data objects like constants and stores.
			DataFactoriesPtr data_factories;

			/// The factories for input and output like console and loggers.
			InOutFactoriesPtr in_out_factories;

			/// The factories for generators like counters and timers.
			GeneratorFactoriesPtr generator_factories;

			/// The factories for the logical operations like comparisons and gates.
			LogicalFactoriesPtr logical_factories;

			/// The factories for mathematical operations like arithmetic and trigonometric operations.
			MathFactoriesPtr math_factories;

	};

}
}
}
