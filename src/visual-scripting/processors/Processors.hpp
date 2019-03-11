#pragma once

#include <crossguid/guid.hpp>

#include "entity-system/listeners/entities/EntityInstanceCreatedListener.hpp"
#include "entity-system/listeners/entities/EntityInstanceDeletedListener.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/util/type-definitions/TypeDefinitions.hpp"
#include "visual-scripting/managers/ProcessorRegistry.hpp"
#include "visual-scripting/processors/arithmetic/ArithmeticProcessors.hpp"
#include "visual-scripting/processors/trigonometric/TrigonometricProcessors.hpp"
#include "visual-scripting/model/Processor.hpp"

using namespace inexor::entity_system;

namespace inexor {
namespace visual_scripting {

	using ProcessorRegistryPtr = std::shared_ptr<ProcessorRegistry>;
	using ArithmeticProcessorsPtr = std::shared_ptr<ArithmeticProcessors>;
	using TrigonometricProcessorsPtr = std::shared_ptr<TrigonometricProcessors>;

    /// Management of the processors.
    /// The manager listens on created or deleted entity instances.
	class Processors
	{
		public:

			/// Constructor.
			Processors(
				ProcessorRegistryPtr processor_registry,
				ArithmeticProcessorsPtr arithmetic_processors,
				TrigonometricProcessorsPtr trigonometric_processors
			);

			/// Destructor.
			~Processors();

			/// Initialization of the Processors.
			void init();

		private:

			/// The registry for active components
			std::shared_ptr<ProcessorRegistry> processor_registry;

			/// The manager for arithmetic processors.
			std::shared_ptr<ArithmeticProcessors> arithmetic_processors;

			/// The manager for trigonometric processors.
			std::shared_ptr<TrigonometricProcessors> trigonometric_processors;

	};


};
};
