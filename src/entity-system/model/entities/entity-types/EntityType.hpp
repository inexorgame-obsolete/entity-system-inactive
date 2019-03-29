#pragma once

#include "entity-system/model/entity-attributes/entity-attribute-types/EntityAttributeType.hpp"
#include "entity-system/model/base/type/TypeBase.hpp"
#include "entity-system/util/uuid/GUIDBase.hpp"

#include <mutex>
#include <string>
#include <optional>
#include <unordered_map>

namespace inexor {
namespace entity_system {

	using EntityAttributeTypePtr = std::shared_ptr<EntityAttributeType>;
	using EntityAttributeTypePtrList = std::vector<EntityAttributeTypePtr>;

    /// @class EntityType
	/// @brief A base class for entity types.
	class EntityType : public TypeBase, public GUIDBase
    {
        
        private:

            /// A vector of stored entity attribute instances.
			EntityAttributeTypePtrList entity_attribute_instances;

            /// Mutex for the entity type class.
            std::mutex entity_type_mutex;

        public:

			/// @brief Constructor.
			/// @note The GUID of the new entity type will be created automatically by the inheritance of GUIDBase!
			/// @param ent_type_name The unique name of the entity type which will be created.
			EntityType(const std::string& ent_type_name);


            /// @brief Constructor.
            /// @param ent_type_GUID The GUID of the entity type which will be created.
            /// @param ent_type_name The unique name of the entity type which will be created.
            EntityType(const xg::Guid& ent_type_GUID, const std::string& ent_type_name);


			/// Destructor.
			~EntityType();


			/// @brief Check if an entity attribute type is already linked to this entity type.
			/// @param ent_attr_type_name The name of the entity attribute type of which will be checked if it is associated with this entity type.
			/// @return True if this entity attribute type is already linked, false otherwise.
			bool has_attribute_type(const std::string& ent_attr_type_name);


			/// @brief Check if an entity attribute type is already linked to this entity type.
			/// @param ent_attr_type_GUID The GUID of the entity attribute type of which will be checked if it is associated with this entity type.
			/// @return True if this entity attribute type is already linked, false otherwise.
            bool has_attribute_type(const xg::Guid& ent_attr_type_GUID);


			/// @brief Check if an entity attribute type is already linked to this entity type.
			/// @param ent_attr_type A const reference of a shared pointer to the entity attribute type
            /// of which will be checked if it is linked with this entity type.
			/// @return True if this entity attribute type is already associated, false otherwise.
			bool has_attribute_type(const EntityAttributeTypePtr& ent_attr_type);
        

			/// @brief Links an entity attribute type to this entity type.
			/// @param ent_attr_type A const reference of a shared pointer to an entity attribute type which will be linked to this entity type.
			/// @return ENTSYS_SUCCESS if linking succeeded, ENTSYS_ERROR otherwise.
			ENTSYS_RESULT link_attribute_type(const EntityAttributeTypePtr& ent_attr_type);

            
            /// TODO!
            ENTSYS_RESULT link_attribute_type(const xg::Guid&);


            /// TODO!
            ENTSYS_RESULT link_attribute_type(const std::string&);
	

			/// @brief Returns the number of entity attribute types which are linked to this entity type.
			/// @return The number of entity attribute types which are linked to this entity type.
			std::size_t get_linked_attributes_count() const;


			/// @brief Returns a vector of entity attribute types which are linked to this entity type.
			/// @return a vector of entity attribute types which are linked to this entity type.
			std::optional<EntityAttributeTypePtrList> get_linked_attribute_types() const;
			

			/// Deletes all entity attribute types which are linked to this entity type.
			void reset_linked_attribute_types();

    };


}
}
