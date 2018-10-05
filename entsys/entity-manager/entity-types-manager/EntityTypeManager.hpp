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

			std::shared_ptr<EntityType> error_entity;

		protected:

			// 
			EntityTypeManager()
			{
				error_entity = std::make_shared<EntityType>("ERROR");
			}

			// 
			~EntityTypeManager()
			{

			}
		
		public:

			// IMPLEMENTATION.
			// THE FOLLOWING METHODS ARE LAYERS FOR THE TEMPLATE CLASS.

			void delete_all_entity_types()
			{
				// Call template class method.
				delete_all_types();
			}


			// Search through the map of available types of entities.
			bool does_entity_type_exist(const std::string& param_entity_type_name)
			{
				return does_type_exist(param_entity_type_name);
			}


			// Create a new entity type and store it in the entity system.
			std::shared_ptr<EntityType> create_entity_type(const std::string& param_new_entity_type_name)
			{
				// Check if type with this name does already exist
				if(does_type_exist(param_new_entity_type_name))
				{
					// This type does already exist
					// TODO: Throw error message!
					return error_entity;
				}

				if (0 == param_new_entity_type_name.compare(std::string("")))
				{
					// This type does already exist
					// TODO: Throw error message!
					return error_entity;
				}
				// TODO: Further validation!!

				std::shared_ptr<EntityType> new_entity_type = std::make_shared<EntityType>(param_new_entity_type_name);
				type_map[param_new_entity_type_name] = new_entity_type;
				return new_entity_type;
			}


			// Returns the number of available types of entities.
			const std::size_t get_entity_types_count() const
			{
				return get_type_count();
			}

			// Deletes an entity type from the entity system.
			void delete_entity_type(const std::string& param_entity_type_name)
			{
				// TODO: Delete all instances!
				delete_type(param_entity_type_name);
			}


			// Deletes an entity type from the entity system.
			void delete_entity_type(const std::shared_ptr<EntityType>& param_entity_type)
			{
				// TODO: Delete all instances!
				delete_type(param_entity_type->get_type_name());
			}


	};


};
};
