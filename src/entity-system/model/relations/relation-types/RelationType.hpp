#pragma once

#include "entity-system/model/relation-attributes/relation-attribute-types/RelationAttributeType.hpp"
#include "entity-system/model/entities/entity-types/EntityType.hpp"

namespace inexor {
namespace entity_system {

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

		public:

			/// @brief Constructor.
			/// @note The dependencies of this class will be injected automatically.
			/// @note The GUID of the new entity relation type will be created automatically by the inheritance of GUIDBase!
			/// @param rel_type_name The name of the new relation type name.
			/// @param ent_type_source A const reference to a shared pointer of an entity type which is the source entity from which the relation will start.
			/// @param ent_type_target A const reference to a shared pointer of an entity type which is the target entity to which the relation will go.
			RelationType(const std::string& rel_type_name, const EntityTypePtr& ent_type_source, const EntityTypePtr& ent_type_target);

			/// @brief Constructor.
			/// @note The dependencies of this class will be injected automatically.
			/// @note The GUID of the new entity relation type will be created automatically by the inheritance of GUIDBase!
			/// @param ent_type_GUID The GUID of the entity type which will be created.
			/// @param rel_type_name The unique name of the realtion type which will be created.
			/// @param ent_type_source A const reference to a shared pointer of an entity type which is the source entity from which the relation will start.
			/// @param ent_type_target A const reference to a shared pointer of an entity type which is the target entity to which the relation will go.
			RelationType(const xg::Guid& rel_type_GUID, const std::string& rel_type_name, const EntityTypePtr& ent_type_source, const EntityTypePtr& ent_type_target);

			/// Destructor.
			~RelationType();

			/// @brief Links an relation attribute type to this relation type.
			/// @param ent_rel_attr_type A const reference to a shared pointer of an relation attribute type which will be linked to this relation type.
			void link_relation_attribute_type(const RelationAttributeTypePtr& ent_rel_attr_type);

			/// @brief Returns all linked relation attribute types.
			/// @return A std::vector of shared pointers of relation attribute type.
			std::vector<RelationAttributeTypePtr> get_linked_attribute_types() const;

	};

}
}
