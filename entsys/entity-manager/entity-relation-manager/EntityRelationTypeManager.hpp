// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include "../entity-relation-manager/entity-relation-type/EntityRelationType.hpp"
#include "../../templates/TypeManager.hpp"


namespace inexor {
namespace entity_system {


	// A manager class for types of entity relations.
    class EntityRelationTypeManager : public TypeManager<EntityRelationType>
    {
		private:

			// This entity relation error type will be returned when a method fails.
			ENT_REL_TYPE entity_relation_type_error = std::make_shared<EntityRelationType>("ERROR", nullptr, nullptr);

        protected:

			// 
			EntityRelationTypeManager();

			// 
			~EntityRelationTypeManager();

		public:

			// Check if an entity relation type does already exist.
			bool does_entity_relation_type_exist(const std::string&);
			bool does_entity_relation_type_exist(const ENT_REL_TYPE&);
			// TODO: check by UUID!

			// Create a new entity relation type and store it in the entity system.
			ENT_REL_TYPE create_entity_relation_type(const std::string&, const ENT_TYPE&, const ENT_TYPE&);

			// Return the number of available entity relation types.
			const std::size_t get_entity_relation_types_count() const;

			// Delete an entity relation type.
			void delete_entity_relation_type(const std::string&);
			void delete_entity_relation_type(const ENT_REL_TYPE&);
			// TODO: Delete by UUID.

			// Delete all entity relation types.
			void delete_all_entity_relation_types();

	};

};
};
