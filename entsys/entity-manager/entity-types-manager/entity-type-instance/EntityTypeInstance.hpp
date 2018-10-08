// Inexor entity system prototype
// (c)2018 Inexor

#pragma once

#include "../../entity-types-manager/entity-type/EntityType.hpp"
#include "../../entity-attributes-manager/entity-attribute-type-instances/EntityAttributeTypeInstance.hpp"
#include "../../../base-classes/TypeInstanceBase.hpp"


namespace inexor {
namespace entity_system {


	// A base class for instances of types of entities.
	// Only EntityTypeInstanceManager can create instances!
    class EntityTypeInstance : public TypeInstanceBase<EntityType,EntityTypeInstance>
    {
		private:

			// Entity attribute type instance which are linked to this entity type instance.
			std::unordered_map<std::shared_ptr<EntityAttributeType>, std::shared_ptr<EntityAttributeTypeInstance>> linked_attributes;
			
		public:
			
			EntityTypeInstance(const std::shared_ptr<EntityType>&);
			~EntityTypeInstance();
			
			// Set data of attributes.
			void set_attribute_data(const std::shared_ptr<EntityAttributeType>&, const int&);
			void set_attribute_data(const std::shared_ptr<EntityAttributeType>&, const bool&);
			void set_attribute_data(const std::shared_ptr<EntityAttributeType>&, const float&);
			void set_attribute_data(const std::shared_ptr<EntityAttributeType>&, const double&);
			void set_attribute_data(const std::shared_ptr<EntityAttributeType>&, const std::string&);
			void set_attribute_data(const std::shared_ptr<EntityAttributeType>&, const std::int64_t&);

			// Get data from attributes
			void get_attribute_data(const std::shared_ptr<EntityAttributeType>&, int&);
			void get_attribute_data(const std::shared_ptr<EntityAttributeType>&, bool&);
			void get_attribute_data(const std::shared_ptr<EntityAttributeType>&, float&);
			void get_attribute_data(const std::shared_ptr<EntityAttributeType>&, double&);
			void get_attribute_data(const std::shared_ptr<EntityAttributeType>&, std::string&);
			void get_attribute_data(const std::shared_ptr<EntityAttributeType>&, std::int64_t&);
			

    };


};
};
