#pragma once

#include "entity-system/model/entities/entity-types/EntityType.hpp"

namespace inexor {
namespace visual_scripting {

	using EntityTypePtr = std::shared_ptr<entity_system::EntityType>;

    /// @class Processor
	/// @brief This is the base class for processors.
    class Processor
    {
		public:

            /// 
    		USING_REACTIVE_DOMAIN(inexor::entity_system::D)

    		/// @brief Constructs a new processor for the given entity type.
            /// @note The dependencies of this class will be injected automatically.
            /// @param entity_type The entity type for this processor.
    		Processor(
    			EntityTypePtr entity_type
    		);

            /// Virtual Destructor.
			virtual ~Processor();

			/// Returns the entity type for this processor.
			EntityTypePtr get_entity_type();

		protected:

			/// The entity type for this processor.
			EntityTypePtr entity_type;

    };

}
}
