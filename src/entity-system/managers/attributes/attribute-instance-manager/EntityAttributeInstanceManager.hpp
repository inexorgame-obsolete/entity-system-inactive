// Inexor entity system prototype
// (c)2018-2019 Inexor

#pragma once

#include "entity-system/managers/manager-templates/InstanceManagerTemplate.hpp"
#include "entity-system/model/attributes/attribute-instances/EntityAttributeInstance.hpp"
#include "entity-system/util/type-definitions/TypeDefinitions.hpp"


namespace inexor {
namespace entity_system {


	/// A manager class for entity attribute type instances.
    class EntityAttributeInstanceManager : public InstanceManagerTemplate<EntityAttributeInstance>
    {
		private:

			/// We need this entity attribute type error
			/// to create the entity attribute type instance error.
			const ENT_ATTR_TYPE entity_attribute_type_error = std::make_shared<EntityAttributeType>("ERROR", ENTSYS_DATA_TYPE_UNDEFINED);

			/// This entity attribute type instance error
			/// will be returned when a method fails.
			const ENT_ATTR_INST entity_attribute_instance_error = std::make_shared<EntityAttributeInstance>(entity_attribute_type_error);

		protected:
            
			/// Constructor.
			EntityAttributeInstanceManager();

			/// Destructor.
			~EntityAttributeInstanceManager();

		public:

			/// Creates an entity attribute type instance.
			/// @param ent_attr_type A const reference to a shared pointer of
			/// an entity attribute type of which an instance will be created.
			/// @return A shared pointer to the entity attribute type instance
			/// which was created.
			/// <br>If this method fails, entity_attribute_instance_error will be
			/// returned as error object.
			/// @note the GUID of the entity attribute type will be created
			/// automatically because EntityAttributeType inherits from GUIDBase!
			ENT_ATTR_INST create_entity_attribute_instance(const ENT_ATTR_TYPE&);

			/// Returns the number of existing entity attribute type instances.
			/// @return The number of existing entity attribute type instances.
			const std::size_t get_entity_attribute_instance_count() const;

			/// Deletes all entity attribute type instances.
			void delete_all_entity_attribute_instances();

	};


};
};
