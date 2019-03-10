#pragma once

#include "type-system/factories/arithmetic/AddIntFactory.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	using AddIntFactoryPtr = std::shared_ptr<AddIntFactory>;

	/// The arithmetic factories.
	class ArithmeticFactories
	{
		public:

			/// Constructs the arithmetic factories.
			ArithmeticFactories(
				AddIntFactoryPtr add_int_factory
			);

			~ArithmeticFactories();

			/// Initializes the arithmetic factories.
			void init();

		private:

			/// Factory for creating entity instances of type ADD_INT.
			AddIntFactoryPtr add_int_factory;

	};

}
}
}
