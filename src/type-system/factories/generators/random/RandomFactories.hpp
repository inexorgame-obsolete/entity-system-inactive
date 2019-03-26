#pragma once

#include "type-system/factories/generators/random/RandomNextIntFactory.hpp"
#include "type-system/factories/generators/random/RandomNextFloatFactory.hpp"

#include <memory>

namespace inexor {
namespace entity_system {
namespace type_system {

	using RandomNextIntFactoryPtr = std::shared_ptr<RandomNextIntFactory>;
	using RandomNextFloatFactoryPtr = std::shared_ptr<RandomNextFloatFactory>;

    /// @class RandomFactories
	/// @brief Provides the factories for counters.
	class RandomFactories
	{
		public:

			/// @brief Constructs the factories for counters.
            /// @note The dependencies of this class will be injected automatically.
            /// @param random_next_int_factory Factory for creating entity instances of type COUNTER_INT.
            /// @param random_next_float_factory Factory for creating entity instances of type COUNTER_FLOAT.
			RandomFactories(
				RandomNextIntFactoryPtr random_next_int_factory,
				RandomNextFloatFactoryPtr random_next_float_factory
			);

            /// Destructor.
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
