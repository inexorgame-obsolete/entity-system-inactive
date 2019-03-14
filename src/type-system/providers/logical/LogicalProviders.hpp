#pragma once

#include "type-system/providers/logical/comparison/ComparisonProviders.hpp"
#include "type-system/providers/logical/gates/GateProviders.hpp"

#include <memory>

namespace inexor {
namespace entity_system {
namespace type_system {

	using ComparisonProvidersPtr = std::shared_ptr<ComparisonProviders>;
	using GateProvidersPtr = std::shared_ptr<GateProviders>;

	/// The entity type providers for logical operations.
	class LogicalProviders
	{
		public:

			/// Constructs the entity type providers for logical operations.
			LogicalProviders(
				ComparisonProvidersPtr comparison_providers,
				GateProvidersPtr gate_providers
			);

			~LogicalProviders();

			/// Initializes the providers for logical operations.
			void init();

		private:

			/// The providers for the comparison operations.
			ComparisonProvidersPtr comparison_providers;

			/// The providers for the logical gates.
			GateProvidersPtr gate_providers;

	};

}
}
}
