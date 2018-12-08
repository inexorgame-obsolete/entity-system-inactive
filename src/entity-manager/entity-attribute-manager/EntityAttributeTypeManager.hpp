// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include <memory>
#include <string>
#include <unordered_map>

#include "entity-attribute-type/EntityAttributeType.hpp"
#include "../../data-validation/DataValidationResults.hpp"
#include "../../templates/TypeManagerTemplate.hpp"
#include "../../typedefs/TypeDefinitions.hpp"


namespace inexor {
namespace entity_system {
    

	/// A manager class for entity attribute types.
    class EntityAttributeTypeManager : public TypeManagerTemplate<EntityAttributeType>
    {
        private:

			/// This entity attribute type error will be returned when a method fails.
			const ENT_ATTR_TYPE entity_attribute_type_error
				= std::make_shared<EntityAttributeType>("ERROR", ENTSYS_DATA_TYPE_UNDEFINED);

        protected:

			/// Constructor.
			EntityAttributeTypeManager();

			/// Destructor.
            ~EntityAttributeTypeManager();

		public:

			/// Checks if an entity attribute type does already exist.
			/// @param ent_attr_type_name The name of an entity
			/// attribute type of which we will check if it does already exist.
			/// @return True if the entity attribute type
			/// does already exist, false otherwise.
			bool does_entity_attribute_type_exist(const std::string&);

			/// Checks if an entity attribute type does already exist.
			/// @param ent_attr_type A const reference to a shared pointer of
			/// an entity attribute type of which we will check if it
			/// does already exist.
			/// @return True if the entity attribute type
			/// does already exist, false otherwise.
			bool does_entity_attribute_type_exist(const ENT_ATTR_TYPE&);

			/// Creates a new entity attribute type.
			/// @param ent_attr_type_name The name of the new entity attribute type.
			/// @param ent_attr_data_type The data type of the new entity attribute type.
			/// @return A shared pointer to the entity attribute type which was created.
			/// <br>If this method fails, entity_attribute_type_error will be returned as error object.
			/// @note the GUID of the new entity attribute type will
			/// be created automatically by the inheritance of GUIDBase!
			ENT_ATTR_TYPE create_entity_attribute_type(const std::string&, const ENTSYS_DATA_TYPE&);

			/// Returns the number of available entity attribute types.
			/// @return The number of available entity attribute types.
			const std::size_t get_entity_attribute_type_count() const;

			/// Deletes an entity attribute type.
			/// @param ent_attr_type The name of the entity attribute type which will be deleted.
			void delete_entity_attribute_type(const std::string&);
			
			/// Deletes an entity attribute type.
			/// @param ent_attr_type A const reference to a shared pointer of an entity attribute type which will be deleted.
			void delete_entity_attribute_type(const ENT_ATTR_TYPE&);

			// TODO: Delete by UUID.

			/// Delete all entity attribute types.
			void delete_all_entity_attribute_types();


	};


};
};
