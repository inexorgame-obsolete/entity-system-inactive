#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"

#include "type-system/providers/math/MathProviders.hpp"
#include "type-system/providers/generators/counters/CounterProviders.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	using EntityTypeBuilderFactoryPtr = std::shared_ptr<EntityTypeBuilderFactory>;
	using CounterProvidersPtr = std::shared_ptr<CounterProviders>;

	/// The providers of the type system.
	class GeneratorProviders
	{
		public:

			/// Constructs the providers of the type system.
			GeneratorProviders(
				EntityTypeBuilderFactoryPtr entity_type_builder_factory,
				CounterProvidersPtr counter_providers
			);

			~GeneratorProviders();

			/// Initializes the providers of the type system.
			void init();

		private:

			/// Factory for creating entity types.
			EntityTypeBuilderFactoryPtr entity_type_builder_factory;

			/// The providers for counters.
			CounterProvidersPtr counter_providers;

	};

}
}
}
