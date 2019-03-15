#pragma once

#include "type-system/factories/generators/random/RandomNextIntFactory.hpp"
#include "type-system/factories/generators/random/RandomNextFloatFactory.hpp"

#include <memory>

namespace inexor {
namespace entity_system {
namespace type_system {

	using RandomNextIntFactoryPtr = std::shared_ptr<RandomNextIntFactory>;
	using RandomNextFloatFactoryPtr = std::shared_ptr<RandomNextFloatFactory>;

	/// Provides the factories for counters.
	class RandomFactories
	{
		public:

			/// Constructs the factories for counters.
			RandomFactories(
				RandomNextIntFactoryPtr random_next_int_factory,
				RandomNextFloatFactoryPtr random_next_float_factory
			);

			~RandomFactories();

			/// Initializes the factories for counters.
			void init();

		private:

			/// Factory for creating entity instances of type COUNTER_INT.
			RandomNextIntFactoryPtr random_next_int_factory;

			/// Factory for creating entity instances of type COUNTER_FLOAT.
			RandomNextFloatFactoryPtr random_next_float_factory;

	};

}
}
}
