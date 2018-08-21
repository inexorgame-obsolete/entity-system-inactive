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
				                                                    const std::vector<std::shared_ptr<EntityAttributeType>>& param_vector_of_entity_attribute_types)
	{
		// TODO: Validate data!


		// Process data!
		create_entity_type(param_new_entity_type);

		for(std::size_t i=0; i<param_vector_of_entity_attribute_types.size(); i++)
		{
			link_entity_attribute_type_to_entity_type(param_new_entity_type,
				                                      param_vector_of_entity_attribute_types[i]);
		}

		return ENTSYS_SUCCESS;
	}


};
};
