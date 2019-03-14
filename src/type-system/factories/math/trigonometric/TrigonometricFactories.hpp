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

	/// The trigonometric factories.
	class TrigonometricFactories
	{
		public:

			/// Constructs the trigonometric factories.
			TrigonometricFactories(
				SinFactoryPtr sin_factory,
				CosFactoryPtr cos_factory,
				TanFactoryPtr tan_factory
			);

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
