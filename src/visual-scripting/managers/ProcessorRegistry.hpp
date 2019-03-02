// Inexor entity system
// (c)2018 Inexor

#pragma once

#include <crossguid/guid.hpp>

#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/util/type-definitions/TypeDefinitions.hpp"
#include "visual-scripting/model/Processor.hpp"

using namespace inexor::entity_system;

namespace inexor {
namespace visual_scripting {

	/// @class ProcessorRegistry
    /// @brief Registry of the visual scripting processors.
	class ProcessorRegistry
	{
		public:

			/// Constructor.
			ProcessorRegistry();

			/// Destructor.
			~ProcessorRegistry();

			/// Initialization of the active components.
			void init();

			/// @brief Registers an processor.
			void register_processor(const std::shared_ptr<Processor>& processor);

			/// @brief Returns the processor by entity type.
			std::optional<std::shared_ptr<Processor>> get_processor(const ENT_TYPE& entity_type);

			/// @brief Returns true, if a processor is mapped to the given entity type.
			bool has_processor(const ENT_TYPE& entity_type);

		private:

			/// Stores the processors per entity type.
			std::unordered_map<ENT_TYPE, std::shared_ptr<Processor>> processors;

	};


};
};
