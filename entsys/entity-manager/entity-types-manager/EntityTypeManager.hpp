// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_ENTITY_TYPE_MANAGER_CLASS_HEADER
#define INEXOR_ENTSYS_ENTITY_TYPE_MANAGER_CLASS_HEADER


#include <vector>
#include <string>
#include <unordered_map>

#include "entity-type\EntityType.hpp"
#include "../../typedefs/TypeDefinitions.hpp"
#include "../../error-handling/ErrorHandling.hpp"


namespace inexor {
namespace entity_system {


	// 
    class EntityTypeManager : public EntitySystemErrorHandler
    {
        private:

			// In this unordered map all available types 
			// of entites of the entity system will be stored.
			std::unordered_map<std::string, std::shared_ptr<EntityType>> map_of_entity_types;

		protected:

			// 
            EntityTypeManager();

			// 
            ~EntityTypeManager();

        public:

			// Search through the map of available types of entities.
			bool does_entity_type_exist(const std::string&);

			// create a new entity type and register it to the entity system.
			ENTSYS_RESULT create_entity_type(const std::shared_ptr<EntityType>&);

			// Returns the number of available types of entities.
			std::size_t get_entity_types_count() const;

			// Deletes an entity type from the entity system.
			ENTSYS_RESULT delete_entity_type(const std::string&);


    };

};
};

#endif // INEXOR_ENTSYS_ENTITY_TYPE_MANAGER_CLASS_HEADER
