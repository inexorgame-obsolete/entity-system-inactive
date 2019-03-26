#pragma once

#include "type-system/factories/math/trigonometric/SinFactory.hpp"
#include "type-system/factories/math/trigonometric/CosFactory.hpp"
#include "type-system/factories/math/trigonometric/TanFactory.hpp"

#include <memory>

namespace inexor {
namespace entity_system {
namespace type_system {

	using SinFactoryPtr = std::shared_ptr<SinFactory>;
	using CosFactoryPtr = std::shared_ptr<CosFactory>;
	using TanFactoryPtr = std::shared_ptr<TanFactory>;

    /// @class TrigonometricFactories
	/// @brief The trigonometric factories.
	class TrigonometricFactories
	{
		public:

			/// @brief Constructs the trigonometric factories.
            /// @note The dependencies of this class will be injected automatically.
            /// @param sin_factory Factory for creating entity instances of type SIN.
            /// @param cos_factory Factory for creating entity instances of type COS.
            /// @param tan_factory Factory for creating entity instances of type TAN.
			TrigonometricFactories(
				SinFactoryPtr sin_factory,
				CosFactoryPtr cos_factory,
				TanFactoryPtr tan_factory
			);

            /// Destructor.
			~TrigonometricFactories();

			/// Initializes the trigonometric factories.
			void init();

		private:

			/// Factory for creating entity instances of type SIN.
			SinFactoryPtr sin_factory;

			/// Factory for creating entity instances of type COS.
			CosFactoryPtr cos_factory;

			/// Factory for creating entity instances of type TAN.
			TanFactoryPtr tan_factory;

	};

}
}
}
