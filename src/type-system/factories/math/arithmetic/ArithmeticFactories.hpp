#pragma once

#include "type-system/factories/math/arithmetic/AddIntFactory.hpp"
#include "type-system/factories/math/arithmetic/AddFloatFactory.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	using AddIntFactoryPtr = std::shared_ptr<AddIntFactory>;
	using AddFloatFactoryPtr = std::shared_ptr<AddFloatFactory>;

	/// The arithmetic factories.
	class ArithmeticFactories
	{
		public:

			/// Constructs the arithmetic factories.
			ArithmeticFactories(
				AddIntFactoryPtr add_int_factory,
				AddFloatFactoryPtr add_float_factory
			);

			~ArithmeticFactories();

			/// Initializes the arithmetic factories.
			void init();

		private:

			/// Factory for creating entity instances of type ADD_INT.
			AddIntFactoryPtr add_int_factory;

			/// Factory for creating entity instances of type ADD_FLOAT.
			AddFloatFactoryPtr add_float_factory;

	};

}
}
}
