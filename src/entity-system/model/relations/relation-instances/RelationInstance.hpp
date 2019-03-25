#pragma once

#include "entity-system/model/entities/entity-instances/EntityInstance.hpp"
#include "entity-system/model/relations/relation-types/RelationType.hpp"
#include "entity-system/model/relation-attributes/relation-attribute-types/RelationAttributeType.hpp"
#include "entity-system/model/relation-attributes/relation-attribute-instances/RelationAttributeInstance.hpp"
#include "entity-system/model/base/instance/Instance.hpp"
#include "entity-system/util/uuid/GUIDBase.hpp"

namespace inexor {
namespace entity_system {

	using RelationTypePtr = std::shared_ptr<RelationType>;
	using EntityInstancePtr = std::shared_ptr<EntityInstance>;
	using RelationAttributeTypePtr = std::shared_ptr<RelationAttributeType>;
	using RelationAttributeInstancePtr = std::shared_ptr<RelationAttributeInstance>;

    /// @class RelationInstance
	/// @brief A base class for entity relation type instances.
	class RelationInstance : public InstanceBase<RelationType>, public GUIDBase
	{
		private:

			/// The relation type
			// TODO: RelationAttributeTypePtr relation_type;

			/// The source entity type instance.
			EntityInstancePtr source_entity_instance;

			/// The target entity type instance.
			EntityInstancePtr destination_entity_instance;
			
			/// Entity relation attribute type instances stored by entity relation attribute types.
			std::unordered_map<RelationAttributeTypePtr, RelationAttributeInstancePtr> relation_attribute_instances;

		public:

			/// @brief Constructor.
			/// @note The GUID of the new entity relation type instance will be created automatically by the inheritance of GUIDBase!
			/// @param rel_type A const reference to a shared pointer of an entity relation type of which an instance will be created.
			/// @param ent_inst_source A const reference to a shared pointer of an entity type instance which will be used as source entity instance.
			/// @param ent_inst_target A const reference to a shared pointer of an entity type instance which will be used as target entity instance.
			RelationInstance(const RelationTypePtr& rel_type, const EntityInstancePtr& ent_inst_source, const EntityInstancePtr& ent_inst_target);

			/// @brief Constructor.
            /// @param inst_GUID The GUID of the relation instance which will be created.
			/// @param rel_type A const reference to a shared pointer of an relation type of which an instance will be created.
			/// @param ent_inst_source A const reference to a shared pointer of an entity instance which will be used as source entity instance.
			/// @param ent_inst_target A const reference to a shared pointer of an entity instance which will be used as target entity instance.
			RelationInstance(const xg::Guid& inst_GUID, const RelationTypePtr& rel_type, const EntityInstancePtr& ent_inst_source, const EntityInstancePtr& ent_inst_target);

			/// Destructor.
			~RelationInstance();

			/// @brief Returns all entity relation attribute instances.
			/// @return A std::unordered_map of shared pointers of entity relation attribute type.
			std::unordered_map<RelationAttributeTypePtr, RelationAttributeInstancePtr> get_relation_attribute_instances() const;

            /// @brief Get the relation type.
            /// @return The relation type of the relation instance.
			RelationTypePtr get_relation_type() const;

            /// Returns the entity instance on the source side.
			EntityInstancePtr get_source_entity_instance() const;

            /// Returns the entity instance on the target side.
			EntityInstancePtr get_target_entity_instance() const;

			// TODO: Set data !

	};

}
}
