// Inexor entity system
// (c)2018-2019 Inexor

#pragma once

#include <memory>
#include <string>
#include <unordered_map>
#include <optional>
#include <crossguid/guid.hpp>

#include "entity-system/model/entity-attributes/entity-attribute-instances/EntityAttributeInstance.hpp"
#include "entity-system/managers/manager-templates/TypeManagerTemplate.hpp"
#include "entity-system/model/data/validation/DataValidationResults.hpp"
#include "entity-system/util/type-definitions/TypeDefinitions.hpp"


namespace inexor {
namespace entity_system {
    

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
			/// @return ?
			O_ENT_ATTR_TYPE create_entity_attribute_type(const std::string&, const DataType&, const EnumSet<Feature>&);

            
			/// @brief Creates a new entity attribute type.
            /// @param ? 
            /// @param ? 
            /// @param ? 
            /// @return ?
			O_ENT_ATTR_TYPE create_entity_attribute_type(const xg::Guid&, const std::string&, const DataType&, const EnumSet<Feature>&);

            
			/// @brief Checks if an entity attribute type does already exist.
			/// @param ent_attr_type_name The name of an entity
			/// attribute type of which we will check if it does already exist.
			/// @return True if the entity attribute type
			/// does already exist, false otherwise.
			bool does_entity_attribute_type_exist(const std::string&);


            bool does_entity_attribute_type_exist(const xg::Guid&);


			/// Checks if an entity attribute type does already exist.
			/// @param ent_attr_type A const reference to a shared pointer of
			/// an entity attribute type of which we will check if it
			/// does already exist.
			/// @return True if the entity attribute type
			/// does already exist, false otherwise.
			bool does_entity_attribute_type_exist(const ENT_ATTR_TYPE&);


            /// Get an entity attribute type by name.
            /// @param type_name The name of the type we tant to check for.
			O_ENT_ATTR_TYPE get_entity_attribute_type(const std::string&) const;


            /// Get an entity attribute type by GUID.
            /// @param type_GUID The GUID of the type we tant to check for.
			O_ENT_ATTR_TYPE get_entity_attribute_type(const xg::Guid&) const;

            /// Returns the number of available entity attribute types.
			/// @return The number of available entity attribute types.
			std::size_t get_entity_attribute_type_count() const;


			/// Deletes an entity attribute type.
			/// @param ent_attr_type The name of the entity attribute type which will be deleted.
			void delete_entity_attribute_type(const std::string&);
			

			/// Deletes an entity attribute type.
			/// @param ent_attr_type A const reference to a shared pointer of an entity attribute type which will be deleted.
			void delete_entity_attribute_type(const ENT_ATTR_TYPE&);


			/// Deletes an entity attribute type.
            /// @param type_GUID The GUID of the entity attribute type.
            void delete_entity_attribute_type(const xg::Guid&);


			/// Delete all entity attribute types.
			void delete_all_entity_attribute_types();


	};


};
};
