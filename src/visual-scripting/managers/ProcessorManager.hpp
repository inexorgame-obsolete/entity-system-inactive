// Inexor entity system
// (c)2018 Inexor

#pragma once

#include <crossguid/guid.hpp>

#include "entity-system/listeners/entities/EntityInstanceCreatedListener.hpp"
#include "entity-system/listeners/entities/EntityInstanceDeletedListener.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/util/type-definitions/TypeDefinitions.hpp"
#include "visual-scripting/managers/ProcessorRegistry.hpp"
#include "visual-scripting/managers/ArithmeticProcessorManager.hpp"
#include "visual-scripting/managers/TrigonometricProcessorManager.hpp"
#include "visual-scripting/model/Processor.hpp"

using namespace inexor::entity_system;

namespace inexor {
namespace visual_scripting {


	/// @class ProcessorManager
    /// @brief Management of the processors.
    /// The manager listens on created or deleted entity instances.
	class ProcessorManager
	{
		public:

			/// Constructor.
			ProcessorManager(
				std::shared_ptr<ProcessorRegistry> processor_registry,
				std::shared_ptr<ArithmeticProcessorManager> arithmetic_processor_manager,
				std::shared_ptr<TrigonometricProcessorManager> trigonometric_processor_manager
			);

			/// Destructor.
			~ProcessorManager();

			/// Initialization of the ProcessorManager.
			void init();

		private:

			/// The registry for active components
			std::shared_ptr<ProcessorRegistry> processor_registry;

			/// The manager for arithmetic processors.
			std::shared_ptr<ArithmeticProcessorManager> arithmetic_processor_manager;

			/// The manager for trigonometric processors.
			std::shared_ptr<TrigonometricProcessorManager> trigonometric_processor_manager;

	};


};
};
