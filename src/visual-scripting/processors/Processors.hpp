#pragma once

#include "visual-scripting/managers/ProcessorRegistry.hpp"
#include "visual-scripting/processors/arithmetic/ArithmeticProcessors.hpp"
#include "visual-scripting/processors/comparison/ComparisonProcessors.hpp"
#include "visual-scripting/processors/console/ConsoleProcessors.hpp"
#include "visual-scripting/processors/logger/LoggerProcessors.hpp"
#include "visual-scripting/processors/logical/LogicalProcessors.hpp"
#include "visual-scripting/processors/trigonometric/TrigonometricProcessors.hpp"
#include "visual-scripting/model/Processor.hpp"

namespace inexor {
namespace visual_scripting {

	using ProcessorRegistryPtr = std::shared_ptr<ProcessorRegistry>;
	using ArithmeticProcessorsPtr = std::shared_ptr<ArithmeticProcessors>;
	using ComparisonProcessorsPtr = std::shared_ptr<ComparisonProcessors>;
	using ConsoleProcessorsPtr = std::shared_ptr<ConsoleProcessors>;
	using LoggerProcessorsPtr = std::shared_ptr<LoggerProcessors>;
	using LogicalProcessorsPtr = std::shared_ptr<LogicalProcessors>;
	using TrigonometricProcessorsPtr = std::shared_ptr<TrigonometricProcessors>;

    /// Provides processors.
	class Processors
	{
		public:

			/// Constructs the processors.
			Processors(
				ProcessorRegistryPtr processor_registry,
				ArithmeticProcessorsPtr arithmetic_processors,
				ComparisonProcessorsPtr comparison_processors,
				ConsoleProcessorsPtr console_processors,
				LoggerProcessorsPtr logger_processors,
				LogicalProcessorsPtr logical_processors,
				TrigonometricProcessorsPtr trigonometric_processors
			);

			~Processors();

			/// Initialization of the Processors.
			void init();

		private:

			/// The registry for processors.
			ProcessorRegistryPtr processor_registry;

			/// The manager for processors for arithmetic operations.
			ArithmeticProcessorsPtr arithmetic_processors;

			/// The manager for comparison processors.
			ComparisonProcessorsPtr comparison_processors;

			/// The manager for console processors.
			ConsoleProcessorsPtr console_processors;

			/// The manager for logger processors.
			LoggerProcessorsPtr logger_processors;

			/// The manager for processors for logical operations.
			LogicalProcessorsPtr logical_processors;

			/// The manager for processors trigonometric operations.
			TrigonometricProcessorsPtr trigonometric_processors;

	};

}
}
