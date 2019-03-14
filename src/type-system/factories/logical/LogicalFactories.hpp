#pragma once

#include "type-system/factories/logical/comparison/ComparisonFactories.hpp"
#include "type-system/factories/logical/gates/GateFactories.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	using ComparisonFactoriesPtr = std::shared_ptr<ComparisonFactories>;
	using GateFactoriesPtr = std::shared_ptr<GateFactories>;

	/// The factories for logical operations.
	class LogicalFactories
	{
		public:

			/// Constructs the factories for logical operations.
			LogicalFactories(
				ComparisonFactoriesPtr comparison_factories,
				GateFactoriesPtr gate_factories
			);

			~LogicalFactories();

			/// Initializes the factories for logical operations.
			void init();

		private:

			/// The factories for comparison operations.
			ComparisonFactoriesPtr comparison_factories;

			/// The factories for logical gates.
			GateFactoriesPtr gate_factories;

	};

}
}
}
