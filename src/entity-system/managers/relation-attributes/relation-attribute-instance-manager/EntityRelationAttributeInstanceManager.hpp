// Inexor entity system
// (c)2018-2019 Inexor

#pragma once

#include <optional>

#include "entity-system/managers/manager-templates/InstanceManagerTemplate.hpp"
#include "entity-system/model/attributes/attribute-instances/EntityAttributeInstance.hpp"
#include "entity-system/model/relations/relation-instances/EntityRelationInstance.hpp"
#include "entity-system/model/relations/relation-types/EntityRelationType.hpp"
#include "entity-system/util/type-definitions/TypeDefinitions.hpp"


namespace inexor {
namespace entity_system {


	/// A manager class for entity relation attribute type instances.
	class EntityRelationAttributeInstanceManager : public InstanceManagerTemplate<EntityRelationAttributeInstance>
	{
		public:

			/// Constructor.
			EntityRelationAttributeInstanceManager();

			/// Destructor.
			~EntityRelationAttributeInstanceManager();

			/// Creates an entity relation attribute type instance.
			/// @param ent_rel_attr_type A const reference to a shared pointer of
			/// an entity relation attribute type of which an instance will be created.
		    /// @return A shared pointer to the entity relation attribute type instance which was created.
            /// <br>If the creation fails std::nullopt will be returned.
			std::optional<ENT_REL_ATTR_INST> create_entity_relation_attribute_instance(const ENT_REL_ATTR_TYPE&);

            // TODO!
            std::optional<ENT_REL_ATTR_INST> get_entity_relation_attribute_instance(const xg::Guid&);

			/// Returns the number of existing entity relation attribute type instances.
			/// @return The number of existing entity relation attribute type instances.
			std::size_t get_entity_relation_attribute_instance_count() const;

			/// Deletes all instances of entity relation attribute types.
			void delete_all_entity_relation_type_attribute_instances();

	};


};
};
