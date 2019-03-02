// Inexor entity system
// (c)2018 Inexor

#pragma once

#include <crossguid/guid.hpp>

#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/util/type-definitions/TypeDefinitions.hpp"
#include "visual-scripting/managers/ProcessorRegistry.hpp"
#include "visual-scripting/processors/arithmetic/AddInt.hpp"
#include "visual-scripting/processors/arithmetic/Sin.hpp"

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
				std::shared_ptr<inexor::visual_scripting::ProcessorRegistry> processor_registry,
				std::shared_ptr<inexor::visual_scripting::AddInt> add_int,
				std::shared_ptr<inexor::visual_scripting::Sin> sin
			);

			/// Destructor.
			~ArithmeticProcessorManager();

			/// Initialization of the processors.
			void init();

		private:

			/// The processor registry
			std::shared_ptr<inexor::visual_scripting::ProcessorRegistry> processor_registry;

			// Addition for integers.
			std::shared_ptr<inexor::visual_scripting::AddInt> add_int;

			// Addition for integers.
			std::shared_ptr<inexor::visual_scripting::Sin> sin;

	};


};
};
