#pragma once

#include "entity-system/managers/relations/relation-type-manager/RelationTypeManager.hpp"
#include "entity-system/managers/relation-attributes/relation-attribute-type-manager/RelationAttributeTypeManager.hpp"
#include "entity-system/managers/relation-attributes/relation-attribute-instance-manager/RelationAttributeInstanceManager.hpp"
#include "entity-system/model/data/DataTypes.hpp"
#include "entity-system/model/entities/entity-types/EntityType.hpp"
#include "entity-system/model/relations/relation-types/RelationType.hpp"

namespace inexor {
namespace entity_system {

	/// These using instructions help to shorten the following code.
	using AttributeList = std::unordered_map<std::string, std::pair<DataType, EnumSet<Feature>>>;
	class RelationTypeBuilder;
	using RelationTypeBuilderPtr = std::shared_ptr<RelationTypeBuilder>;
	using RelationTypePtrOpt = std::optional<std::shared_ptr<RelationType>>;

	/// @class RelationTypeBuilder
	/// @brief Builder for relation types.
	class RelationTypeBuilder : public std::enable_shared_from_this<RelationTypeBuilder>
	{
		public:
			
			/// These using instructions help to shorten the following code.
			using RelationTypeManagerPtr = std::shared_ptr<RelationTypeManager>;
			using RelationAttributeTypeManagerPtr = std::shared_ptr<RelationAttributeTypeManager>;
			using RelationAttributeInstanceManagerPtr = std::shared_ptr<RelationAttributeInstanceManager>;
			using EntityTypePtr = std::shared_ptr<EntityType>;

			/// Constructor.
			RelationTypeBuilder(
				RelationTypeManagerPtr relation_type_manager,
				RelationAttributeTypeManagerPtr relation_attribute_type_manager,
				RelationAttributeInstanceManagerPtr relation_attribute_instance_manager
			);

			/// Destructor.
			~RelationTypeBuilder();

			/// Sets the name of the relation type.
			RelationTypeBuilderPtr name(std::string relation_type_name);

			/// Sets the uuid of the relation type.
			RelationTypeBuilderPtr uuid(std::string relation_type_uuid);

			/// Sets the source entity type.
			RelationTypeBuilderPtr source(EntityTypePtr ent_type_source);

			/// Sets the target entity type.
			RelationTypeBuilderPtr target(EntityTypePtr ent_type_target);

			/// Sets the uuid of the relation type.
			RelationTypeBuilderPtr attribute(std::string attribute_name, DataType attribute_datatype, const EnumSet<Feature>& attribute_features);

			/// Builds and returns the created relation type.
			RelationTypePtrOpt build();

		private:

			/// The relation type manager
			RelationTypeManagerPtr relation_type_manager;

			/// The relation attribute instance manager
			RelationAttributeTypeManagerPtr relation_attribute_type_manager;

			/// The relation attribute instance manager
			RelationAttributeInstanceManagerPtr relation_attribute_instance_manager;

			/// The name of the new relation type.
			std::string relation_type_name;

			/// The UUID of the new relation type.
			std::string relation_type_uuid;

			/// The source entity type.
			EntityTypePtr ent_type_source;

			/// The target entity type.
			EntityTypePtr ent_type_target;

			/// The attribute definitions.
			AttributeList relation_type_attributes;

			/// The mutex of this class.
			std::mutex relation_type_builder_mutex;

	};

}
}
