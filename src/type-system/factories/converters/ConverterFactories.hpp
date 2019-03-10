#pragma once

#include "type-system/factories/converters/IntToFloatFactory.hpp"

#include <memory>

namespace inexor {
namespace entity_system {
namespace type_system {

	using IntToFloatFactoryPtr = std::shared_ptr<IntToFloatFactory>;

	/// The converter factories.
	class ConverterFactories
	{
		public:

			/// Constructs the converter factories.
			ConverterFactories(
				IntToFloatFactoryPtr int_to_float_factory
			);

			~ConverterFactories();

			/// Initializes the converter factories.
			void init();

		private:

			/// Factory for creating entity instances of type INT_TO_FLOAT.
			IntToFloatFactoryPtr int_to_float_factory;

	};

}
}
}
