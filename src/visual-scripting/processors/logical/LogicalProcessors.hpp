#pragma once

#include "visual-scripting/processors/logical/comparison/ComparisonProcessors.hpp"
#include "visual-scripting/processors/logical/gates/GateProcessors.hpp"

namespace inexor {
namespace visual_scripting {

	using ComparisonProcessorsPtr = std::shared_ptr<ComparisonProcessors>;
	using GateProcessorsPtr = std::shared_ptr<GateProcessors>;

    /// Provides processors.
	class LogicalProcessors
	{
		public:

			/// Constructs the processors for logical operations.
			LogicalProcessors(
				ComparisonProcessorsPtr comparison_processors,
				GateProcessorsPtr gate_processors
			);

			~LogicalProcessors();

			/// Initialization of the processors for logical operations.
			void init();

		private:

			/// The processors for comparison operations.
			ComparisonProcessorsPtr comparison_processors;

			/// The processors logical gates.
			GateProcessorsPtr gate_processors;

	};

}
}
