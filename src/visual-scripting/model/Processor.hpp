// Inexor entity system
// (c)2018-2019 Inexor

#pragma once

#include <mutex>
#include <optional>

#include "react/Observer.h"

#include "entity-system/providers/entities/entity-type-provider/EntityTypeProvider.hpp"
#include "entity-system/managers/entities/entity-instance-manager/EntityInstanceManager.hpp"
#include "entity-system/model/entities/entity-types/EntityType.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "entity-system/util/uuid/GUIDBase.hpp"
#include "entity-system/util/type-definitions/TypeDefinitions.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace visual_scripting {


	/// This is the base class for processors.
    class Processor
    {

		public:

    		USING_REACTIVE_DOMAIN(D)

    		/// @brief Constructs a new processor.
    		Processor(
    			std::shared_ptr<inexor::entity_system::EntityType> entity_type
    		);

			/// @brief The destructor.
			virtual ~Processor();

			/// Returns the entity type for this processor.
			std::shared_ptr<inexor::entity_system::EntityType> get_entity_type();

		protected:

			/// The entity type for this processor.
			std::shared_ptr<inexor::entity_system::EntityType> entity_type;

    };


};
};
