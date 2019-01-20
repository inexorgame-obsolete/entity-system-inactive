// Inexor entity system
// (c)2018-2019 Inexor

#pragma once

#include <mutex>
#include <string>
#include <optional>
#include <unordered_map>

#include "entity-system/model/entity-attributes/entity-attribute-types/EntityAttributeType.hpp"
#include "entity-system/model/base/type/TypeBase.hpp"
#include "entity-system/util/type-definitions/TypeDefinitions.hpp"
#include "entity-system/util/uuid/GUIDBase.hpp"


namespace inexor {
namespace entity_system {

	
    /// @class EntityType
	/// @brief A base class for entity types.
	class EntityType : public TypeBase, public GUIDBase
    {
        
        private:

            /// A vector of stored entity attribute instances.
            std::vector<ENT_ATTR_TYPE> entity_attribute_instances;

            /// Mutex for the entity type class.
            std::mutex entity_type_mutex;

        public:

			/// @brief Constructor.
			/// @param ent_type_name The unique name of the entity type which will be created.
			/// @note The GUID of the new entity type will be created automatically by the inheritance of GUIDBase!
			EntityType(const std::string&);


            /// @brief Constructor.
            /// @param ent_type_GUID The GUID of the entity type which will be created.
            /// @param ent_type_name The unique name of the entity type which will be created.
            EntityType(const xg::Guid&, const std::string&);


			/// @brief Destructor.
			~EntityType();


			/// @brief Check if an entity attribute type is already linked to this entity type.
			/// @param ent_attr_type_name The name of the entity attribute type of which will be checked if it is associated with this entity type.
			/// @return True if this entity attribute type is already linked, false otherwise.
			bool has_attribute_type(const std::string&);


			/// @brief Check if an entity attribute type is already linked to this entity type.
			/// @param ent_attr_type_GUID The GUID of the entity attribute type of which will be checked if it is associated with this entity type.
			/// @return True if this entity attribute type is already linked, false otherwise.
            bool has_attribute_type(const xg::Guid&);


			/// Check if an entity attribute type is already linked to this entity type.
			/// @param ent_attr_type A const reference of a shared pointer to the
			/// entity attribute type of which will be checked if it is linked
			/// with this entity type.
			/// @return True if this entity attribute type is already associated,
			/// false otherwise.
			bool has_attribute_type(const ENT_ATTR_TYPE&);
        

			/// Links an entity attribute type to this entity type.
			/// @param ent_attr_type A const reference of a shared pointer to
			/// an entity attribute type which will be linked to this entity type.
			/// @return ENTSYS_SUCCESS if linking succeeded, ENTSYS_ERROR otherwise.
			ENTSYS_RESULT link_attribute_type(const ENT_ATTR_TYPE&);

            
            /// TODO!
            ENTSYS_RESULT link_attribute_type(const xg::Guid&);


            /// TODO!
            ENTSYS_RESULT link_attribute_type(const std::string&);
	

			/// Returns the number of entity attribute types which are linked to this entity type.
			/// @return The number of entity attribute types which are linked to this entity type.
			std::size_t get_linked_attributes_count() const;


			/// Returns a vector of entity attribute types which are linked to this entity type.
			/// @return a vector of entity attribute types which are linked to this entity type.
			std::optional<std::vector<ENT_ATTR_TYPE>> get_linked_attribute_types() const;
			

			/// Deletes all entity attribute types which are linked to this entity type.
			void reset_linked_attribute_types();


			/// Implement a data validation method as
			/// required by class inheritance of DataValidation
			virtual ENTSYS_DATA_VALIDATION_RESULT validate() override;

    };


};
};
