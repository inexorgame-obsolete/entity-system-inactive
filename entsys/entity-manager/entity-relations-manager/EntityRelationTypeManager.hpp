// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include "../entity-relations-manager/entity-relation-type/EntityRelationType.hpp"

namespace inexor {
namespace entity_system {


	// A manager class for types of entity relations.
    class EntityRelationTypeManager
    {
		private:

			// 
			std::unordered_map<std::string, std::shared_ptr<EntityRelationType>> entity_relation_type_map;

        protected:

			// 
			EntityRelationTypeManager();

			// 
			~EntityRelationTypeManager();

			// TODO: Should this be public ?
			void delete_all_entity_relation_types();

		public:

			// Search through the map of available types of relations of entities.
			bool does_entity_relation_type_exist(const std::string&);
			
			// Create a new entity relation type and store it in the entity system.
			std::shared_ptr<EntityRelationType> create_entity_relation_type(const std::string&,
				                                                            const std::shared_ptr<EntityType>&,
				                                                            const std::shared_ptr<EntityType>&);

			// Returns the number of available types of entity relations.
			const std::size_t get_entity_relation_types_count() const;

			// Deletes an entity type from the entity system.
			ENTSYS_RESULT delete_entity_relation_type(const std::string&);
			ENTSYS_RESULT delete_entity_relation_type(const std::shared_ptr<EntityRelationType>&);

	};

};
};
