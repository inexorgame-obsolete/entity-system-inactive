// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include <vector>
#include <string>
#include <unordered_map>

#include "../entity-type-manager/entity-type/EntityType.hpp"
#include "../../templates/TypeManager.hpp"


namespace inexor {
namespace entity_system {


	/// A manager class for entity types.
	class EntityTypeManager : public TypeManager<EntityType>
	{
		private:

			/// The error entity type which will be returned when a method fails.
			const ENT_TYPE entity_type_error = std::make_shared<EntityType>("ERROR");

		protected:

			/// Constructor.
			EntityTypeManager();

			/// Destructor.
			~EntityTypeManager();
		
		public:

			/// @brief Checks if an entity type does already exist.
			/// @param ?
			bool does_entity_type_exist(const std::string&);
			
			/// @brief Checks if an entity type does already exist.
			/// @param ?
			bool does_entity_type_exist(const ENT_TYPE&);

			// TODO: Check by UUID!

			/// @brief Creates a new entity type.
			/// @param ent_type_name The name of the new entity type.
			ENT_TYPE create_entity_type(const std::string&);

			/// @brief Returns the number of existing types of entities.
			std::size_t get_entity_types_count() const;
			
			/// Deletes an entity type by name.
			/// @param ent_type_name The name of the entity type which will be deleted.
			void delete_entity_type(const std::string&);

			/// Deletes an entity type by entity type.
			/// @param ent_type A reference to a shared pointer of the entity type which will be deleted.
			void delete_entity_type(const ENT_TYPE&);
			
			// TODO: Delete by UUID.

			/// Removes all types of entities.
			void delete_all_entity_types();

	};


};
};
