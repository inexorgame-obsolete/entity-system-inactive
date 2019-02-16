// Inexor entity system
// (c)2018 Inexor

#pragma once

#include <crossguid/guid.hpp>

#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/util/type-definitions/TypeDefinitions.hpp"
#include "visual-scripting/managers/ProcessorRegistry.hpp"
#include "visual-scripting/processors/arithmetic/AddInt.hpp"

using namespace inexor::entity_system;

namespace inexor {
namespace visual_scripting {

	/// @class ArithmeticProcessorManager
    /// @brief Management of the arithmetic processors.
	class ArithmeticProcessorManager
	{
		public:

			/// Constructor.
			ArithmeticProcessorManager(
				std::shared_ptr<ProcessorRegistry> processor_registry,
				std::shared_ptr<AddInt> add_int
			);

			/// Destructor.
			~ArithmeticProcessorManager();

			/// Initialization of the active components.
			void init();

		private:

			// The registry for active components.
			std::shared_ptr<ProcessorRegistry> processor_registry;

			// Addition for integers.
			std::shared_ptr<AddInt> add_int;

	};


};
};
