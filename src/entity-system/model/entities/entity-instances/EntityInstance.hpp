// Inexor entity system
// (c)2018-2019 Inexor

#pragma once

#include <mutex>
#include <optional>

#include "entity-system/model/entity-attributes/entity-attribute-instances/EntityAttributeInstance.hpp"
#include "entity-system/model/entities/entity-types/EntityType.hpp"
#include "entity-system/model/base/instance/Instance.hpp"
#include "entity-system/util/uuid/GUIDBase.hpp"


namespace inexor {
namespace entity_system {


	/// A base class for entity type instances.
    class EntityInstance : public InstanceBase<EntityType>, public GUIDBase
    {
        private:

            // A map for storing the instances by type.
            // Every EntityInstance can have only one instance of
            // a unique EntityAttributeType.
            std::unordered_map<ENT_ATTR_TYPE, ENT_ATTR_INST> instances;

            // Mutex for this entity instance.
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

            /// @brief Get the entity type.
            /// @return The entity type of the entity instance.
			ENT_TYPE get_entity_type() const;

            ///
            void add_entity_attribute_instance(const ENT_ATTR_TYPE&, const ENT_ATTR_INST&);

            /// @brief Get all the attribute instances.
            /// @return All existing attribute instances.
			std::optional<std::unordered_map<ENT_ATTR_TYPE, ENT_ATTR_INST>> get_instances() const;

            // TODO: Implement methods for setting and getting entity attribute instance data...

            /// @brief Get the attribute instance by name.
            /// @return The attribute instance with the given name.
			std::optional<ENT_ATTR_INST> get_attribute_instance(const std::string& attr_name);
    };


};
};
