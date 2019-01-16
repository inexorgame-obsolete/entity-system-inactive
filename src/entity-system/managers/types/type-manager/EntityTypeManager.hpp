// Inexor entity system
// (c)2018-2019 Inexor

#pragma once

#include <vector>
#include <string>
#include <optional>
#include <unordered_map>
#include <crossguid/guid.hpp>


#include "entity-system/managers/manager-templates/TypeManagerTemplate.hpp"
#include "entity-system/model/types/types/EntityType.hpp"


namespace inexor {
namespace entity_system {


	/// A manager class for entity types.
	class EntityTypeManager : public TypeManagerTemplate<EntityType>
	{
		protected:

			/// Constructor.
			EntityTypeManager();

			/// Destructor.
			~EntityTypeManager();
		
		public:

			/// Checks if an entity type does already exist.
			/// @param ent_type_name The name of the entity type.
			/// @return True if the entity type does already exist,
			/// false otherwise.
			bool does_entity_type_exist(const std::string&);
			

			/// Checks if an entity type does already exist.
			bool does_entity_type_exist(const xg::Guid&);


			/// Checks if an entity type does already exist.
			/// @param ent_type A const reference of
			/// a shared pointer to the entity type.
			/// @return True if the entity type does already exist,
			/// false otherwise.
			bool does_entity_type_exist(const ENT_TYPE&);


			/// Creates a new entity type.
			/// @param ent_type_name The name of the new entity type.
			/// @return A shared pointer to the entity type which was created.
			std::optional<ENT_TYPE> create_entity_type(const std::string&);


            // TODO!
            std::optional<ENT_TYPE> create_entity_Type(const xg::Guid&, const std::string&);


			/// Returns the number of existing entity types.
			/// @return The number of existing entity types.
			std::size_t get_entity_type_count() const;
			

            /// Deletes an entity type by name.
			/// @param ent_type_name The name of the entity type which will be deleted.
			void delete_entity_type(const std::string&);
			

			/// Deletes an entity type by GUID.
			void delete_entity_type(const xg::Guid&);


			/// Deletes an entity type by entity type.
			/// @param ent_type A const reference of a shared pointer
			/// to the entity type which will be deleted.
			void delete_entity_type(const ENT_TYPE&);


			/// Removes all types of entities.
			void delete_all_entity_types();

	};


};
};
