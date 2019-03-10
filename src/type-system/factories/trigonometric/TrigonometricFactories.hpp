#pragma once

#include "type-system/factories/trigonometric/CosFactory.hpp"
#include "type-system/factories/trigonometric/SinFactory.hpp"

#include <memory>

namespace inexor {
namespace entity_system {
namespace type_system {

	using CosFactoryPtr = std::shared_ptr<CosFactory>;
	using SinFactoryPtr = std::shared_ptr<SinFactory>;

	/// The trigonometric factories.
	class TrigonometricFactories
	{
		public:

			/// Constructs the trigonometric factories.
			TrigonometricFactories(
				CosFactoryPtr cos_factory,
				SinFactoryPtr sin_factory
			);

			~TrigonometricFactories();

			/// Initializes the trigonometric factories.
			void init();

		private:

			/// Factory for creating entity instances of type COS.
			CosFactoryPtr cos_factory;

			/// Factory for creating entity instances of type SIN.
			SinFactoryPtr sin_factory;

	};

}
}
}
