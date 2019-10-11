#pragma once

#include "entity-system/model/entity-attributes/entity-attribute-instances/EntityAttributeInstance.hpp"
#include "entity-system/managers/manager-templates/TypeManagerTemplate.hpp"

#include <crossguid/guid.hpp>

#include <memory>
#include <string>
#include <unordered_map>
#include <optional>

namespace inexor {
namespace entity_system {

	using EntityAttributeTypePtr = std::shared_ptr<EntityAttributeType>;
	using EntityAttributeTypePtrOpt = std::optional<EntityAttributeTypePtr>;

	/// @class EntityAttributeTypeManager
	/// @brief A manager class for entity attribute types.
	class EntityAttributeTypeManager : public TypeManagerTemplate<EntityAttributeType>
	{
		public:

			/// @brief Constructor.
			EntityAttributeTypeManager();

			/// @brief Destructor.
			~EntityAttributeTypeManager();

			/// @brief Creates a new entity attribute type.
			/// @param ent_attr_type_name The name of the new entity attribute type.
			/// @param ent_attr_type_data_type The data type of the new entity attribute type.
			/// @param ent_attr_type_features The features of the new entity attribute type.
			/// @return A std::optional shared pointer to the entity attribute type which was created.
			EntityAttributeTypePtrOpt create_entity_attribute_type(const std::string& attr_type_name, const DataType& attr_type_datatype, const EnumSet<Feature>& attr_type_features);

			/// @brief Creates a new entity attribute type.
			/// @param attr_type_GUID The GUID of the new entity attribute type.
			/// @param ent_attr_type_name The name of the new entity attribute type.
			/// @param ent_attr_type_data_type The data type of the new entity attribute type.
			/// @param ent_attr_type_features The features of the new entity attribute type.
			/// @return A std::optional shared pointer to the entity attribute type which was created.
			EntityAttributeTypePtrOpt create_entity_attribute_type(const xg::Guid& attr_type_GUID, const std::string& attr_type_name, const DataType& attr_type_datatype, const EnumSet<Feature>& attr_type_features);

			/// @brief Checks if an entity attribute type does already exist.
			/// @param attr_type_name The name of an entity attribute type of which we will check if it does already exist.
			/// @return True if the entity attribute type does already exist, false otherwise.
			bool does_entity_attribute_type_exist(const std::string& attr_type_name);

			/// @brief Checks if an entity attribute type does already exist.
			/// @param type_GUID The GUID of this type.
			/// @return True if the entity attribute type does already exist, false otherwise.
			bool does_entity_attribute_type_exist(const xg::Guid& type_GUID);

			/// Checks if an entity attribute type does already exist.
			/// @param attr_type A const reference to a shared pointer of an entity attribute type of which we will check if it does already exist.
			/// @return True if the entity attribute type does already exist, false otherwise.
			bool does_entity_attribute_type_exist(const EntityAttributeTypePtr& attr_type);

			/// @brief Get an entity attribute type by name.
			/// @param type_name The name of the type we tant to check for.
			EntityAttributeTypePtrOpt get_entity_attribute_type(const std::string&) const;

			/// @brief Get an entity attribute type by GUID.
			/// @param type_GUID The GUID of the type we tant to check for.
			EntityAttributeTypePtrOpt get_entity_attribute_type(const xg::Guid& type_GUID) const;

			/// @brief Returns the number of available entity attribute types.
			/// @return The number of available entity attribute types.
			std::size_t get_entity_attribute_type_count() const;

			/// @brief Deletes an entity attribute type.
			/// @param attr_type The name of the entity attribute type which will be deleted.
			void delete_entity_attribute_type(const std::string& attr_type);

			/// @brief Deletes an entity attribute type.
			/// @param attr_type A const reference to a shared pointer of an entity attribute type which will be deleted.
			void delete_entity_attribute_type(const EntityAttributeTypePtr& attr_type);

			/// @brief Deletes an entity attribute type.
			/// @param type_GUID The GUID of the entity attribute type.
			void delete_entity_attribute_type(const xg::Guid& type_GUID);

			/// @brief Delete all entity attribute types.
			void delete_all_entity_attribute_types();

};

}
}
