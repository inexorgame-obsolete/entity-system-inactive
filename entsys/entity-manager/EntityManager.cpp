// Inexor entity system prototype
// (c)2018 Inexor

#include "EntityManager.hpp"


namespace inexor {
namespace entity_system {


    EntityManager::EntityManager()
    {
		// TODO: implement!
    }


    EntityManager::~EntityManager()
    {
		// TODO: implement!
    }


	ENTSYS_RESULT EntityManager::add_attribute_type_to_entity_type(const std::shared_ptr<EntityType>& param_entity_type,
		                                                           const std::shared_ptr<EntityAttributeType>& param_entity_attribute_type)
	{
		return link_entity_attribute_type_to_entity_type(param_entity_type, param_entity_attribute_type);
	}
	
	
    ENTSYS_RESULT EntityManager::create_entity_type_with_attributes(const std::shared_ptr<EntityType>& param_new_entity_type,
		                                                            std::size_t argument_count,
		                                                            ...)
	{
		// All linked entity attribute types will be stored in this vector.
		std::vector<std::shared_ptr<EntityAttributeType>> temp_new_linked_attribute_types;
		
		// Start variable argument list
		va_list variable_argument_list;
		va_start(variable_argument_list, argument_count);

		// Parse parameters
		for(std::size_t i=0; i<argument_count; i++)
		{
			temp_new_linked_attribute_types.push_back(va_arg(variable_argument_list, std::shared_ptr<EntityAttributeType>));
		}

		// End variable argument list
		va_end(variable_argument_list);

		// Validate data
		// TODO: Validate!

		// Process data!
		create_entity_type(param_new_entity_type);

		for(std::size_t i=0; i<argument_count; i++)
		{
			link_entity_attribute_type_to_entity_type(param_new_entity_type, temp_new_linked_attribute_types[i]);
		}

		return ENTSYS_SUCCESS;
	}


};
};
