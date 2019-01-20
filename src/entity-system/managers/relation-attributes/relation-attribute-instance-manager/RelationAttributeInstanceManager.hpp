// Inexor entity system
// (c)2018-2019 Inexor

#pragma once

#include <optional>

#include "entity-system/managers/manager-templates/InstanceManagerTemplate.hpp"
#include "entity-system/model/entity-attributes/entity-attribute-instances/EntityAttributeInstance.hpp"
#include "entity-system/model/relations/relation-types/RelationType.hpp"
#include "entity-system/model/relations/relation-instances/RelationInstance.hpp"
#include "entity-system/util/type-definitions/TypeDefinitions.hpp"


namespace inexor {
namespace entity_system {


	/// A manager class for relation attribute instances.
	class RelationAttributeInstanceManager : public InstanceManagerTemplate<RelationAttributeInstance>
	{
		public:

			/// Constructor.
			RelationAttributeInstanceManager();

			/// Destructor.
			~RelationAttributeInstanceManager();

			/// Creates an relation attribute instance.
			/// @param ent_rel_attr_type A const reference to a shared pointer of
			/// an relation attribute type of which an instance will be created.
		    /// @return A shared pointer to the relation attribute instance which was created.
            /// <br>If the creation fails std::nullopt will be returned.
			std::optional<REL_ATTR_INST> create_relation_attribute_instance(const REL_ATTR_TYPE&);

            // TODO!
            std::optional<REL_ATTR_INST> get_relation_attribute_instance(const xg::Guid&);

			/// Returns the number of existing relation attribute type instances.
			/// @return The number of existing relation attribute type instances.
			std::size_t get_relation_attribute_instance_count() const;

			/// Deletes all instances of relation attribute types.
			void delete_all_relation_type_attribute_instances();

	};


};
};
