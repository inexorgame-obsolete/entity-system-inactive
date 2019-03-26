#pragma once

#include "type-system/factories/data/converters/IntToFloatFactory.hpp"

#include <memory>

namespace inexor {
namespace entity_system {
namespace type_system {

	using IntToFloatFactoryPtr = std::shared_ptr<IntToFloatFactory>;

    /// @class ConverterFactories
	/// @brief The converter factories.
	class ConverterFactories
	{
		public:

			/// @brief Constructs the converter factories.
            /// @note The dependencies of this class will be injected automatically.
            /// @param int_to_float_factory Factory for creating entity instances of type INT_TO_FLOAT.
			ConverterFactories(
				IntToFloatFactoryPtr int_to_float_factory
			);

            /// Destructor.
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
