#pragma once

#include "visual-scripting/managers/ProcessorRegistry.hpp"
#include "visual-scripting/processors/arithmetic/ArithmeticProcessors.hpp"
#include "visual-scripting/processors/console/ConsoleProcessors.hpp"
#include "visual-scripting/processors/logger/LoggerProcessors.hpp"
#include "visual-scripting/processors/trigonometric/TrigonometricProcessors.hpp"
#include "visual-scripting/model/Processor.hpp"

namespace inexor {
namespace visual_scripting {

	using ProcessorRegistryPtr = std::shared_ptr<ProcessorRegistry>;
	using ArithmeticProcessorsPtr = std::shared_ptr<ArithmeticProcessors>;
	using ConsoleProcessorsPtr = std::shared_ptr<ConsoleProcessors>;
	using LoggerProcessorsPtr = std::shared_ptr<LoggerProcessors>;
	using TrigonometricProcessorsPtr = std::shared_ptr<TrigonometricProcessors>;

    /// Provides processors.
	class Processors
	{
		public:

			/// Constructs the processors.
			Processors(
				ProcessorRegistryPtr processor_registry,
				ArithmeticProcessorsPtr arithmetic_processors,
				ConsoleProcessorsPtr console_processors,
				LoggerProcessorsPtr logger_processors,
				TrigonometricProcessorsPtr trigonometric_processors
			);

			~Processors();

			/// Initialization of the Processors.
			void init();

		private:

			/// The registry for processors.
			ProcessorRegistryPtr processor_registry;

			/// The manager for arithmetic processors.
			ArithmeticProcessorsPtr arithmetic_processors;

			/// The manager for console processors.
			ConsoleProcessorsPtr console_processors;

			/// The manager for logger processors.
			LoggerProcessorsPtr logger_processors;

			/// The manager for trigonometric processors.
			TrigonometricProcessorsPtr trigonometric_processors;

	};

}
}
