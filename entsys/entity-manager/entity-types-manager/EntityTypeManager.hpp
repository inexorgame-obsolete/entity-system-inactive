// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include <vector>
#include <string>
#include <unordered_map>

#include "../../data-validation/DataValidation.hpp"
#include "../entity-types-manager/entity-type/EntityType.hpp"
#include "../../error-handling/ErrorHandling.hpp"

#include "../../templates/TypeManagerTemplate.hpp"

namespace inexor {
namespace entity_system {


	class EntityTypeManager : public TypeManagerTemplate<EntityType>
	{
		private:

			// Entity type: error type.
			// This will be returned when a create method fails.
			std::shared_ptr<EntityType> error_entity;

		protected:

			// 
			EntityTypeManager();

			// 
			~EntityTypeManager();
		
		public:


			// Search through the map of available types of entities.
			bool does_entity_type_exist(const std::string&);
			
			// Create a new entity type and store it in the entity system.
			std::shared_ptr<EntityType> create_entity_type(const std::string&);

			// Returns the number of available types of entities.
			const std::size_t get_entity_types_count() const;
			
			// Deletes an entity type from the entity system.
			void delete_entity_type(const std::string&);
			
			// Deletes an entity type from the entity system.
			void delete_entity_type(const std::shared_ptr<EntityType>&);

			// 
			void delete_all_entity_types();


	};


};
};
