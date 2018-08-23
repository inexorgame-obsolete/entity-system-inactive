// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include <vector>
#include <string>
#include <unordered_map>

#include "entity-type\EntityType.hpp"
#include "../../typedefs/TypeDefinitions.hpp"
#include "../../error-handling/ErrorHandling.hpp"


namespace inexor {
namespace entity_system {


	// A manager class for types of entities
    class EntityTypeManager : public EntitySystemErrorHandler
    {
        private:

			// In this unordered map all available types 
			// of entites in the entity system will be stored.
			std::unordered_map<std::string, std::shared_ptr<EntityType>> map_of_entity_types;

		protected:

            EntityTypeManager();

            ~EntityTypeManager();

			void delete_all_entity_types_and_entity_type_instances();

        public:

			// Search through the map of available types of entities.
			bool does_entity_type_exist(const std::string&);

			// Create a new entity type and store it in the entity system.
			ENTSYS_RESULT create_entity_type(const std::shared_ptr<EntityType>&);

			// Returns the number of available types of entities.
			std::size_t get_entity_types_count() const;

			// Deletes an entity type from the entity system.
			ENTSYS_RESULT delete_entity_type(const std::string&);
			ENTSYS_RESULT delete_entity_type(const std::shared_ptr<EntityType>&);


    };

};
};
