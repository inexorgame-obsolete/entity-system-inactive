// Inexor entity system prototype
// (c)2018 Inexor

#ifndef INEXOR_ENTSYS_ENTITY_TYPE_CLASS_HEADER
#define INEXOR_ENTSYS_ENTITY_TYPE_CLASS_HEADER

#include <string>
#include <unordered_map>

#include "../../../return-codes/ReturnCodes.hpp"
#include "../../../typedefs/TypeDefinitions.hpp"
#include "../../../data-validation/DataValidation.hpp"

#include "../../entity-attributes-manager/entity-attribute-type/EntityAttributeType.hpp"


namespace inexor {
namespace entity_system {

	
	// A base class for types of entities.
	// This class needs to implement a data validation method!
	class EntityType : public DataValidation
    {
		private:

			// Every entity type must have a unique name.
			std::string name_of_entity_type;

			// TODO: add UUID ?

        protected:
                        
			// TODO: Add methods/members!
            
        public:

			// Make this the default constructor so 
			// the name of an entity type must be set!
            EntityType(const std::string&);

			// Remove the default constructor!
			EntityType() = delete;

			// 
            ~EntityType();

			// TODO: should get methods return const types?

			// Returns the name of the entity type;
			std::string get_entity_type_name() const;

			// Implement data validation method as required by base class inheritance!
			virtual ENTSYS_DATA_VALIDATION_RESULT validate() override;
    };

};
};

#endif // INEXOR_ENTSYS_ENTITY_TYPE_CLASS_HEADER
