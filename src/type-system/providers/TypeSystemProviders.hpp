#pragma once

#include "entity-system/factories/entities/entity-type-builder-factory/EntityTypeBuilderFactory.hpp"

#include "type-system/providers/data/DataProviders.hpp"
#include "type-system/providers/generators/GeneratorProviders.hpp"
#include "type-system/providers/inout/InOutProviders.hpp"
#include "type-system/providers/math/MathProviders.hpp"
#include "type-system/providers/logical/LogicalProviders.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	using EntityTypeBuilderFactoryPtr = std::shared_ptr<EntityTypeBuilderFactory>;
	using DataProvidersPtr = std::shared_ptr<DataProviders>;
	using GeneratorProvidersPtr = std::shared_ptr<GeneratorProviders>;
	using InOutProvidersPtr = std::shared_ptr<InOutProviders>;
	using MathProvidersPtr = std::shared_ptr<MathProviders>;
	using LogicalProvidersPtr = std::shared_ptr<LogicalProviders>;

	/// The providers of the type system.
	class TypeSystemProviders
	{
		public:

			/// Constructs the providers of the type system.
			TypeSystemProviders(
				EntityTypeBuilderFactoryPtr entity_type_builder_factory,
				DataProvidersPtr data_providers,
				GeneratorProvidersPtr generator_providers,
				InOutProvidersPtr in_out_providers,
				MathProvidersPtr math_providers,
				LogicalProvidersPtr logical_providers
			);

			~TypeSystemProviders();

			/// Initializes the providers of the type system.
			void init();

		private:

			/// Factory for creating entity types.
			EntityTypeBuilderFactoryPtr entity_type_builder_factory;

			/// The providers for constants and stores.
			DataProvidersPtr data_providers;

			/// The providers for generators.
			GeneratorProvidersPtr generator_providers;

			/// The providers for input and output.
			InOutProvidersPtr in_out_providers;

			/// The providers for mathematical operations.
			MathProvidersPtr math_providers;

			/// The providers for logical operations.
			LogicalProvidersPtr logical_providers;

	};

}
}
}
