#pragma once

#include "entity-system/model/entities/entity-types/EntityType.hpp"
#include "visual-scripting/model/Processor.hpp"

#include <crossguid/guid.hpp>
#include <optional>

namespace inexor {
namespace visual_scripting {

	using ProcessorPtr = std::shared_ptr<Processor>;
	using ProcessorPtrOpt = std::optional<ProcessorPtr>;
	using EntityTypePtr = std::shared_ptr<entity_system::EntityType>;

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
			void register_processor(const ProcessorPtr& processor);

			/// @brief Returns the processor by entity type.
			ProcessorPtrOpt get_processor(const EntityTypePtr& entity_type);

			/// @brief Returns true, if a processor is mapped to the given entity type.
			bool has_processor(const EntityTypePtr& entity_type);

		private:

			/// Stores the processors per entity type.
			std::unordered_map<EntityTypePtr, ProcessorPtr> processors;

	};

}
}
