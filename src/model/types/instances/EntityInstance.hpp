// Inexor entity system prototype
// (c)2018-2019 Inexor

#pragma once

#include <mutex>

#include "../../../model/attributes/attribute-instances/EntityAttributeInstance.hpp"
#include "../../../model/types/types/EntityType.hpp"
#include "../../../model/base/instance/Instance.hpp"
#include "../../../util/uuid/GUIDBase.hpp"


namespace inexor {
namespace entity_system {


	/// A base class for entity type instances.
    class EntityInstance : public InstanceBase<EntityType>, public GUIDBase
    {
        private:

            /// 
            std::unordered_map<std::shared_ptr<EntityAttributeType>, std::shared_ptr<EntityAttributeInstance>> instances;

            /// 
            std::mutex entity_type_mutex;

		public:
			
			/// Constructor.
			/// @param ent_type A const reference of a shared pointer
			/// to the entity type of which an instance will be created.
			/// @note The GUID of the new entity type instance will
			/// be created automatically by the inheritance of GUIDBase!
			EntityInstance(const ENT_TYPE&);

			/// Destructor.
			~EntityInstance();

            ///
            void add_entity_attribute_instance(const std::shared_ptr<EntityAttributeType>&, const std::shared_ptr<EntityAttributeInstance>&);

            // TODO: Implement methods for setting and getting entity attribute instance data...

    };


};
};
