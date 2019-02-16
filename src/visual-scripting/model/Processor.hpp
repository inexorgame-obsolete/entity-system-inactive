// Inexor entity system
// (c)2018-2019 Inexor

#pragma once

#include <mutex>
#include <optional>

#include "entity-system/model/entities/entity-types/EntityType.hpp"
#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "entity-system/util/uuid/GUIDBase.hpp"
#include "entity-system/util/type-definitions/TypeDefinitions.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace visual_scripting {


	/// The base class for visual scripting processors.
    class Processor
    {

		public:

    		/// @brief The constructor.
    		Processor() {};

			/// @brief The destructor.
			~Processor() {};

			/// The execution function of the processor.
			virtual void execute(const shared_ptr<inexor::entity_system::EntityInstance>& entity_instance) const = 0;

			/// Returns the entity type to bind.
			virtual shared_ptr<inexor::entity_system::EntityType> get_entity_type() const = 0;

    };


};
};
