#pragma once

#include "entity-system/managers/entities/entity-type-manager/EntityTypeManager.hpp"
#include "entity-system/managers/entity-attributes/entity-attribute-type-manager/EntityAttributeTypeManager.hpp"
#include "entity-system/managers/entity-attributes/entity-attribute-instance-manager/EntityAttributeInstanceManager.hpp"
#include "entity-system/model/entities/entity-types/EntityType.hpp"
#include "entity-system/model/data/DataTypes.hpp"

namespace inexor {
namespace entity_system {

	using string = std::string;
	using AttributeList = std::unordered_map<string, std::pair<DataType, EnumSet<Feature>>>;
	class EntityTypeBuilder;
	using EntityTypeBuilderPtr = std::shared_ptr<EntityTypeBuilder>;
	using EntityTypePtr = std::shared_ptr<EntityType>;
	using EntityTypePtrOpt = std::optional<EntityTypePtr>;

	/// @class EntityTypeBuilder
    /// @brief Management of the loggers.
	class EntityTypeBuilder : public std::enable_shared_from_this<EntityTypeBuilder>
	{
		public:

			using EntityTypeManagerPtr = std::shared_ptr<EntityTypeManager>;
			using EntityAttributeTypeManagerPtr = std::shared_ptr<EntityAttributeTypeManager>;
			using EntityAttributeInstanceManagerPtr = std::shared_ptr<EntityAttributeInstanceManager>;

			/// Constructor.
			EntityTypeBuilder(
				EntityTypeManagerPtr entity_type_manager,
				EntityAttributeTypeManagerPtr entity_attribute_type_manager,
				EntityAttributeInstanceManagerPtr entity_attribute_instance_manager
			);

			/// Destructor.
			~EntityTypeBuilder();

			/// Sets the name of the entity type.
			EntityTypeBuilderPtr name(string entity_type_name);

			/// Sets the uuid of the entity type.
			EntityTypeBuilderPtr uuid(string entity_type_uuid);

			/// Adds an attribute
			EntityTypeBuilderPtr attribute(const string& attribute_name, const DataType& attribute_datatype, const EnumSet<Feature>& attribute_features);

			/// Adds an input attribute
			EntityTypeBuilderPtr input(const string& attribute_name, const DataType& attribute_datatype);

			/// Adds an output attribute
			EntityTypeBuilderPtr output(const string& attribute_name, const DataType& attribute_datatype);

			/// Adds an attribute which is an input and output at the same time
			EntityTypeBuilderPtr inout(const string& attribute_name, const DataType& attribute_datatype);

			/// Builds and returns the created entity type.
			EntityTypePtrOpt build();

		private:

			/// The entity type manager
			EntityTypeManagerPtr entity_type_manager;

			/// The entity attribute instance manager
			EntityAttributeTypeManagerPtr entity_attribute_type_manager;

			/// The entity attribute instance manager
			EntityAttributeInstanceManagerPtr entity_attribute_instance_manager;

			/// The name of the new entity type.
			string entity_type_name;

			/// The UUID of the new entity type.
			string entity_type_uuid;

			/// The attribute definitions.
			AttributeList entity_type_attributes;

	};


}
}
