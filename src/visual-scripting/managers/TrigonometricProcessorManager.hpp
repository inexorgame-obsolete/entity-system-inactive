// Inexor entity system
// (c)2018 Inexor

#pragma once

#include <crossguid/guid.hpp>

#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/util/type-definitions/TypeDefinitions.hpp"
#include "visual-scripting/managers/ProcessorRegistry.hpp"
#include "visual-scripting/processors/trigonometric/Sin.hpp"
#include "visual-scripting/processors/trigonometric/Cos.hpp"

using namespace inexor::entity_system;

namespace inexor {
namespace visual_scripting {

	/// @class TrigonometricProcessorManager
    /// @brief Management of the arithmetic processors.
	class TrigonometricProcessorManager
	{
		public:

			/// Constructor.
			TrigonometricProcessorManager(
				std::shared_ptr<inexor::visual_scripting::ProcessorRegistry> processor_registry,
				std::shared_ptr<inexor::visual_scripting::Sin> sin,
				std::shared_ptr<inexor::visual_scripting::Cos> cos
			);

			/// Destructor.
			~TrigonometricProcessorManager();

			/// Initialization of the processors.
			void init();

		private:

			/// The processor registry
			std::shared_ptr<inexor::visual_scripting::ProcessorRegistry> processor_registry;

			// The sin generator.
			std::shared_ptr<inexor::visual_scripting::Sin> sin;

			// The cos generator.
			std::shared_ptr<inexor::visual_scripting::Cos> cos;

	};


};
};
