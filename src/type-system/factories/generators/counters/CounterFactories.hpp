#pragma once

#include "type-system/factories/generators/counters/CounterIntFactory.hpp"
#include "type-system/factories/generators/counters/CounterFloatFactory.hpp"

#include <memory>

namespace inexor {
namespace entity_system {
namespace type_system {

	using CounterIntFactoryPtr = std::shared_ptr<CounterIntFactory>;
	using CounterFloatFactoryPtr = std::shared_ptr<CounterFloatFactory>;

	/// Provides the factories for counters.
	class CounterFactories
	{
		public:

			/// Constructs the factories for counters.
			CounterFactories(
				CounterIntFactoryPtr counter_int_factory,
				CounterFloatFactoryPtr counter_float_factory
			);

			~CounterFactories();

			/// Initializes the factories for counters.
			void init();

		private:

			/// Factory for creating entity instances of type COUNTER_INT.
			CounterIntFactoryPtr counter_int_factory;

			/// Factory for creating entity instances of type COUNTER_FLOAT.
			CounterFloatFactoryPtr counter_float_factory;

	};

}
}
}
