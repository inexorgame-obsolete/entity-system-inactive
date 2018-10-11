// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include <vector>
#include <string>
#include <unordered_map>

#include "../entity-types-manager/entity-type/EntityType.hpp"
#include "../../templates/TypeManagerTemplate.hpp"


namespace inexor {
namespace entity_system {


	// A manager class for types of entities.
	class EntityTypeManager : public TypeManagerTemplate<EntityType>
	{
		private:

			// This error entity type will be returned when a method fails.
			// Use C++11 class member initialisation instead of constructor.
			const std::shared_ptr<EntityType> entity_type_error = std::make_shared<EntityType>("ERROR");

		protected:

			EntityTypeManager();
			~EntityTypeManager();
		
		public:

			// Check if an entity type does already exist.
			bool does_entity_type_exist(const std::string&);
			bool does_entity_type_exist(const std::shared_ptr<EntityType>&);

			// Create a new entity type and add it to the entity system.
			std::shared_ptr<EntityType> create_entity_type(const std::string&);

			// Get the number of existing types of entities.
			const std::size_t get_entity_types_count() const;
			
			// Delete an entity type from the entity system.
			void delete_entity_type(const std::string&);
			void delete_entity_type(const std::shared_ptr<EntityType>&);
			// TODO: Delete by UUID.

			// Remove all existing types of entities.
			void delete_all_entity_types();

	};


};
};
