#pragma once

#include "entity-system/model/relation-attributes/relation-attribute-types/RelationAttributeType.hpp"
#include "entity-system/model/entities/entity-types/EntityType.hpp"

namespace inexor {
namespace entity_system {

	/// These using instructions help to shorten the following code.
	using EntityTypePtr = std::shared_ptr<EntityType>;
	using RelationAttributeTypePtr = std::shared_ptr<RelationAttributeType>;

	/// @class RelationType
	/// @brief A base class for entity relation types.
	class RelationType : public TypeBase, public GUIDBase
	{
		private:

			/// The source entity type.
			EntityTypePtr source_entity_type;

			/// The target entity type.
			EntityTypePtr target_entity_type;

			/// Entity relation attribute types which are linked to this entity relation type.
			std::vector<RelationAttributeTypePtr> linked_rel_attr_types;

			/// The mutex of this class.
			std::mutex relation_type_mutex;

		public:

			/// @brief Constructs the relation type.
			/// @note The GUID of the relation type will be created automatically by inheriting from GUIDBase.
			/// @param rel_type_name A unique name for this realtion type.
			/// @param ent_type_source A const reference to a shared pointer of an entity type which is the source entity type from which the relation will start.
			/// @param ent_type_target A const reference to a shared pointer of an entity type which is the target entity type to which the relation will go.
			RelationType(const std::string& rel_type_name, const EntityTypePtr& ent_type_source, const EntityTypePtr& ent_type_target);
			
			/// @brief Constructs the relation type.
			/// @param ent_type_GUID The GUID of the relation type.
			/// @param rel_type_name A unique name for this realtion type.
			/// @param ent_type_source A const reference to a shared pointer of an entity type which is the source entity type from which the relation will start.
			/// @param ent_type_target A const reference to a shared pointer of an entity type which is the target entity type to which the relation will go.
			RelationType(const xg::Guid& rel_type_GUID, const std::string& rel_type_name, const EntityTypePtr& ent_type_source, const EntityTypePtr& ent_type_target);

			/// Destructs the relation type.
			~RelationType();

			/// @brief Links a relation attribute type to this relation type.
			/// @param ent_rel_attr_type A const reference to a shared pointer of an relation attribute type which will be linked to this relation type.
			void link_relation_attribute_type(const RelationAttributeTypePtr& ent_rel_attr_type);

			/// @brief Returns all linked relation attribute types.
			/// @return A std::vector of shared pointers of linked relation attribute types.
			std::vector<RelationAttributeTypePtr> get_linked_attribute_types() const;

	};

}
}
