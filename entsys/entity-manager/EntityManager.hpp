// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_ENTITY_MANAGER_CLASS_HEADER
#define INEXOR_ENTSYS_ENTITY_MANAGER_CLASS_HEADER

#include <vector>

// Variadic functions (variable parameter lists for initialisation)
#include <cstdarg>

// Entity system debugging.
#include "../../entsys/tests/EntitySystemDebugging.hpp"

// Entity types and instances of those.
#include "entity-types-manager\EntityTypeManager.hpp"
#include "entity-types-manager\EntityTypeInstanceManager.hpp"

// Entity attribute types and instances of those.
#include "entity-attributes-manager\EntityAttributeTypeManager.hpp"
#include "entity-attributes-manager\EntityAttributeTypeInstanceManager.hpp"

// Entity relation types and instances of those.
#include "entity-relations-manager\EntityRelationTypeManager.hpp"
#include "entity-relations-manager\EntityRelationTypeInstanceManager.hpp"


namespace inexor {
namespace entity_system {


    // The entity manager class is responsible for adding, modifying and removing entity types,
    // entity attributes, entity relations and instances of these.
    class EntityManager : public EntityTypeManager,
                          public EntityTypeInstanceManager,
                          public EntityAttributeTypeManager,
                          public EntityAttributeTypeInstanceManager,
                          public EntityRelationTypeManager,
                          public EntityRelationTypeInstanceManager
    {

		private:

		protected:
        
			//
            EntityManager();

			//
            ~EntityManager();

			ENTSYS_RESULT add_attribute_type_to_entity_type(const std::shared_ptr<EntityType>&,
				                                            const std::shared_ptr<EntityAttributeType>&);
			
			// TODO: Implement!
			//ENTSYS_RESULT add_attribute_type_to_entity_type(const std::string&, const std::string&);
			//ENTSYS_RESULT add_attribute_type_to_entity_type(const std::shared_ptr<EntityType>&, const std::string&);
			//ENTSYS_RESULT add_attribute_type_to_entity_type(const std::string&, const std::shared_ptr<EntityAttributeType>&);

	public:

			// TODO: Rename this method?
			ENTSYS_RESULT create_entity_type_with_attributes(const std::shared_ptr<EntityType>&,
				                                             const std::vector<std::shared_ptr<EntityAttributeType>>&);


    };

};
};

#endif // INEXOR_ENTSYS_ENTITY_MANAGER_CLASS_HEADER
