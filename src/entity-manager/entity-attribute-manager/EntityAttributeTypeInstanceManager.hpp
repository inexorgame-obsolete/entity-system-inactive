// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include "../entity-attribute-manager/entity-attribute-type-instances/EntityAttributeTypeInstance.hpp"
#include "../../templates/TypeInstanceManagerTemplate.hpp"
#include "../../typedefs/TypeDefinitions.hpp"


namespace inexor {
namespace entity_system {


	/// A manager class for entity attribute type instances.
    class EntityAttributeTypeInstanceManager : public TypeInstanceManagerTemplate<EntityAttributeTypeInstance>
    {
		private:

			/// We need this entity attribute type error
			/// to create the entity attribute type instance error.
			const ENT_ATTR_TYPE entity_attribute_type_error
				= std::make_shared<EntityAttributeType>("ERROR", ENTSYS_DATA_TYPE_UNDEFINED);

			/// This entity attribute type instance error
			/// will be returned when a method fails.
			const ENT_ATTR_TYPE_INST entity_attribute_type_instance_error
				= std::make_shared<EntityAttributeTypeInstance>(entity_attribute_type_error);

		protected:
            
			/// Constructor.
			EntityAttributeTypeInstanceManager();

			/// Destructor.
			~EntityAttributeTypeInstanceManager();

		public:

			/// Creates an entity attribute type instance.
			/// @param ent_attr_type A const reference to a shared pointer of
			/// an entity attribute type of which an instance will be created.
			/// @return A shared pointer to the entity attribute type instance
			/// which was created.
			/// <br>If this method fails, entity_attribute_type_instance_error will be
			/// returned as error object.
			/// @note the GUID of the entity attribute type will be created
			/// automatically because EntityAttributeType inherits from GUIDBase!
			ENT_ATTR_TYPE_INST create_entity_attribute_type_instance(const ENT_ATTR_TYPE&);

			/// Returns the number of existing entity attribute type instances.
			/// @return The number of existing entity attribute type instances.
			const std::size_t get_entity_attribute_type_instance_count() const;

			/// Deletes all entity attribute type instances.
			void delete_all_entity_attribute_type_instances();

	};


};
};
