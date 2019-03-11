#pragma once

#include "entity-system/model/entities/entity-types/EntityType.hpp"

namespace inexor {
namespace visual_scripting {

	using EntityTypePtr = std::shared_ptr<entity_system::EntityType>;

	/// This is the base class for processors.
    class Processor
    {

		public:

    		USING_REACTIVE_DOMAIN(inexor::entity_system::D)

    		/// Constructs a new processor for the given entity type.
    		Processor(
    			EntityTypePtr entity_type
    		);

			virtual ~Processor();

			/// Returns the entity type for this processor.
			EntityTypePtr get_entity_type();

		protected:

			/// The entity type for this processor.
			EntityTypePtr entity_type;

    };

}
}
