#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"

#include "type-system/providers/math/arithmetic/ArithmeticProviders.hpp"
#include "type-system/providers/math/trigonometric/TrigonometricProviders.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	using EntityTypeBuilderFactoryPtr = std::shared_ptr<EntityTypeBuilderFactory>;
	using ArithmeticProvidersPtr = std::shared_ptr<ArithmeticProviders>;
	using TrigonometricProvidersPtr = std::shared_ptr<TrigonometricProviders>;

	/// The providers for mathematical operations.
	class MathProviders
	{
		public:

			/// Constructs the providers for mathematical operations.
			MathProviders(
				EntityTypeBuilderFactoryPtr entity_type_builder_factory,
				ArithmeticProvidersPtr arithmetic_providers,
				TrigonometricProvidersPtr trigonometric_providers
			);

			~MathProviders();

			/// Initializes the providers for mathematical operations.
			void init();

		private:

			/// Factory for creating entity types.
			EntityTypeBuilderFactoryPtr entity_type_builder_factory;

			/// The providers for arithmetic operations.
			ArithmeticProvidersPtr arithmetic_providers;

			/// The providers for trigonometric operations.
			TrigonometricProvidersPtr trigonometric_providers;

	};

}
}
}
