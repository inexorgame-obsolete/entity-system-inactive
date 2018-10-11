// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include "../entity-relations-manager/entity-relation-type/EntityRelationType.hpp"
#include "../../templates/TypeManagerTemplate.hpp"


namespace inexor {
namespace entity_system {


	// A manager class for types of entity relations.
    class EntityRelationTypeManager : public TypeManagerTemplate<EntityRelationType>
    {
		private:

			// This entity relation error type will be returned when a method fails.
			std::shared_ptr<EntityRelationType> entity_relation_type_error = std::make_shared<EntityRelationType>("ERROR", nullptr, nullptr);

        protected:

			EntityRelationTypeManager();
			~EntityRelationTypeManager();

		public:

			// Check if an entity relation type does already exist.
			bool does_entity_relation_type_exist(const std::string&);
			bool does_entity_relation_type_exist(const std::shared_ptr<EntityRelationType>&);
			// TODO: check by UUID!

			// Create a new entity relation type and store it in the entity system.
			std::shared_ptr<EntityRelationType> create_entity_relation_type(const std::string&,
				                                                            const std::shared_ptr<EntityType>&,
				                                                            const std::shared_ptr<EntityType>&);

			// Return the number of available entity relation types.
			const std::size_t get_entity_relation_types_count() const;

			// Delete an entity relation type.
			void delete_entity_relation_type(const std::string&);
			void delete_entity_relation_type(const std::shared_ptr<EntityRelationType>&);
			// TODO: Delete by UUID.

			// Delete all entity relation types.
			void delete_all_entity_relation_types();

	};

};
};
