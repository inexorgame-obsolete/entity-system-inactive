// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include "../entity-attribute-manager/entity-attribute-type-instances/EntityAttributeTypeInstance.hpp"
#include "../../templates/TypeInstanceManager.hpp"
#include "../../typedefs/TypeDefinitions.hpp"


namespace inexor {
namespace entity_system {


	/// A manager class for instances of attributes of entity types.
    class EntityAttributeTypeInstanceManager : public TypeInstanceManager<EntityAttributeTypeInstance>
    {
		protected:
            
			/// Constructor.
			EntityAttributeTypeInstanceManager();

			/// Destructor.
			~EntityAttributeTypeInstanceManager();

		public:

			/// Creates an entity attribute type instance.
			/// @param ? TODO
			ENT_ATTR_TYPE_INST create_entity_attribute_type_instance(const ENT_ATTR_TYPE&);

			/// Returns the number of existing entity attribute type instances.
			const std::size_t get_entity_attribute_type_instance_count() const;

			/// Deletes all entity attribute type instances.
			void delete_all_entity_attribute_type_instances();

	};


};
};
