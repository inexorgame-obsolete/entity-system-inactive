#pragma once

#include "type-system/factories/generators/counters/CounterFactories.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	using CounterFactoriesPtr = std::shared_ptr<CounterFactories>;

	/// The factories for input and output.
	class GeneratorFactories
	{
		public:

			/// Constructs the factories for generators.
			GeneratorFactories(
				CounterFactoriesPtr counter_factories
			);

			~GeneratorFactories();

			/// Initializes the factories for generators.
			void init();

		private:

			/// The factories for counters.
			CounterFactoriesPtr counter_factories;

	};

}
}
}
